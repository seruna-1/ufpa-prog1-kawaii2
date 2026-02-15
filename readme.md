**Simple dummy pokedéx were you can list your favorite pokemons :3**

Pokemon entry structure:

 - int: global pokedex index (`global_id`)

 - string: name

 - string list: abilities

 - int: evolution stage (`evolution`)

 - float: weight

 - int: generation

 - string list: weaknesses

 - string list: strengths

 - string list: immunities

 - string list: egg group (`breeding`)

Entries are persisted in a text database, with key value pairs, each on a line. A blank line separates the pokedéx entries.

Example:

```
global: 45;
name: vileplume;
evolution state: 3;
weight: 18.6;
breeding: grass;
```

**Aspects:**

 - C++23 standard.

 - C style IO (cstdio library) rather than C++ style IO (iostream) in many cases, proeminently for simple printing.

 - Handmade linked list instead of std::vector.

**To do:**

 - Optional graphical interface (Raylib).

## Building

**With meson:**

```sh
meson setup build
ninja -C build
```

**Without meson:**

```sh
clang++ -I include/ src/command_line/main.cpp src/command_line/pokedex.cpp  src/pokemon.cpp src/pokedex.cpp -o pokedex-cli
``` 

## Testing

For simple testing, `test/` comes with `smalldex.txt` that has a few entries for testing.

For intensive testing, `test/bigdex.rb` generates a file named `bigdex.txt` by fetching and converting a json file from [olitreadwell](https://github.com/olitreadwell/pokemon-classic-json/blob/main/pokedex.json), which reunites 151 classic pokemons.

## License

Unlicense (public domain)
