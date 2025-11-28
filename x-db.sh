#!/usr/bin/env sh

set -e 

(
  cmake -B build -S . -G Ninja 
  cmake --build ./build 
)

exec "./build/x-db"
