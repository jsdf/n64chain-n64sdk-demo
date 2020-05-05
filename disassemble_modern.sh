#!/bin/bash
set -eu
 
 mips64-elf-objdump  --disassemble-all --source  --wide --all-header squaresdemo.out > disassembly.txt