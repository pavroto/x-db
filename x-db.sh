#!/usr/bin/env sh

set -e 

(
  cmake -B build -S . -G "Ninja Multi-Config"
  cmake --build ./build 
)

exec "./build/Debug/x-db"
