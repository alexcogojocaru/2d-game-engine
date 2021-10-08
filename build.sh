#!/bin/bash

rm -rf build
mkdir build
g++ -Iinclude/ -Llib/ main.cpp -lbox2d -lsfml-graphics -lsfml-window -lsfml-system -o build/engine-debug
./build/engine-debug
