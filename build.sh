#!/bin/bash

cmake .
make

if [ "$1" = "run" ]; then
    ./engine/engine
fi