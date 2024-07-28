#!/bin/bash

g++ -std=c++17 src.cpp -o ./src && gdbserver :9091 ./src
