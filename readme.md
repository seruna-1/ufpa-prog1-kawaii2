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

**Building:**

```sh
meson setup build
ninja -C build
```

**Building without meson:**

```sh
clang++ -I include/ src/command_line/main.cpp src/command_line/pokedex.cpp  src/pokemon.cpp src/pokedex.cpp -o pokedex-cli
``` 

**Aspects:**

 - C++23 standard.

 - C style IO (cstdio library) rather than C++ style IO (iostream), proeminently for printing and scanning.

 - Optional graphical interface (probably either GTK or Raylib).

 - Handmade linked list instead of std::vector :/

## License

Unlicense (public domain)
