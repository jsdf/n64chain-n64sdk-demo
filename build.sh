#!/bin/bash
set -eu

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
rm -f *.o
./build_modern.sh
wine cmd /c $DIR/compile.bat
