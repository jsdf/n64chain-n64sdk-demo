#!/bin/bash
set -eux

rm -f *.o

export ROOT="/Users/jfriend/code/n64sdk20l/n64sdk"

make -f brewmakefile
