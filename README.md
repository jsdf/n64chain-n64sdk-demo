# modern gcc n64 sdk demo


## Compile the GCC toolchain

Clone the n64chain repo found here: https://github.com/tj90241/n64chain

Run the `build-linux64-toolchain.sh` script for linux/macOS or
`build-windows64-toolchain.sh` for Windows. This will build GCC, which takes a while.
If you're missing any of the [prerequistes for GCC](https://gcc.gnu.org/install/prerequisites.html) it will fail, but you can just wait until it fails, see what you need to install (eg. gmp, libmpc, etc), install it and re-run the script, which will restart from the step that failed.

After running this command, add `N64CHAIN` to your path (or create a script to be sourced whenever you want to run the tools):

```bash
N64CHAIN=/path/to/n64chain # adjust this to point to your clone of n64chain
export PATH="$N64CHAIN/tools/bin:$PATH"
```


## building the code in this repo

This demo codebase is a typical NuSystem app. It calls from stage00.c (compiled with exeGCC) into Game_update() (defined in game.c, compiled with modern gcc).

`./build_modern.sh` builds some source files using modern GCC

`./build.sh` runs `./build_modern.sh`, then invokes the old SDK toolchain to build the remaining source files and link the binary. This means the binary a combination of code objects compiled using the old and modern compilers.

The compiled ROM file is squaresdemo.n64. It can be run with an emulator or an N64 flashcart.

`./disassemble_modern.sh` invokes the objdump utility from the modern GCC toolchain to disassemble the final binary. This means it can take advantage of the debugging symbols from the modern GCC compiler, for example to get C source interspersed into the disassembly.

The disassembly is output into disassembly.txt. For example to see the disassembly of the Game_update() function: 

```bash
cat disassembly.txt | grep  'Game_update()' --after=30 --color=always
```


 