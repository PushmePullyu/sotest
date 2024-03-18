#!/bin/sh

g++ -Wall -fPIC -shared -o libfoo.so libfoo.cpp testclass.cpp && \
g++ -Wall -o sotest sotest.cpp testclass.cpp $(sdl2-config --cflags) $(sdl2-config --libs)
