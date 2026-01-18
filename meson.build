project('pokedex_kawaii', 'cpp',
	version : '0.1',
	default_options : [
		'warning_level=3',
		'cpp_std=c++23'
	]
)

cc = meson.get_compiler('cpp')

subdir('src')

executable('pokedex-cli',
	pokedex_cli_src,
	install : false,
	include_directories: [
		'include'
	],
)