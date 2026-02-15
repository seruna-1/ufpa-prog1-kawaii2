require 'kramdown'
require 'prawn'

def process_element(pdf, element)
  case element.type
  when :root
    # Start the recursion
    element.children.each { |child| process_element(pdf, child) }

  when :header
    # element.value contains the text for simple headers
    # element.options[:level] gives you the H1, H2, etc.
    size = 30 - (element.options[:level] * 4)
    pdf.text element.children.map(&:value).join, size: size, style: :bold
    pdf.move_down 10

  when :p
    # Paragraphs often contain nested :text or :em elements
    element.children.each { |child| process_element(pdf, child) }
    pdf.move_down 5

  when :text
    # The actual string content
    pdf.text element.value, inline_format: true

  when :blank
    pdf.move_down 5
  end
end

# Main

pdf = Prawn::Document.new
doc = Kramdown::Document.new(File.read("relatorio.md"))

pdf.font_families.update("Inconsolata" => {
  normal: '/usr/share/fonts/TTF/Inconsolata-Regular.ttf',
  bold: '/usr/share/fonts/TTF/Inconsolata-Bold.ttf'
})
pdf.font 'Inconsolata'

institutional = [
	"Universidade Federal do Pará",
	"Instituto de Ciências Exatas e Naturais",
	"Programação I"
]

authors = [
	"Mateus Cezário Barreto",
	"Nicolas Alho",
	"Yuri Gabriel Delgado"
]

pdf.text institutional.join("\n"), size: 14, style: :bold, align: :center, valign: :top
pdf.formatted_text(
	[
		{ text: "CLI Pokedex\n\n", size: 30, styles: [:bold] },
		{ text: authors.join("\n") }
	],
	align: :center,
	valign: :center
)
pdf.text "Belém - Pará\n2026", align: :center, valign: :bottom
pdf.start_new_page

process_element(pdf, doc.root)

pdf.render_file "build/relatorio.pdf"

