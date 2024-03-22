#!/bin/sh

EXEFILE="dsotest"
DSOFILE="somelib.so"
CC="g++"

CFLAGS=(-Wall -Wpedantic -std=c++11 -fno-gnu-unique)
CFLAGS+=("-DDSOFILE=\"${DSOFILE}\"")
# CFLAGS+=(-athread=native)

DSOFLAGS=(-fPIC -shared)
EXEFLAGS=("-Wl,-rpath,\$ORIGIN")
# EXEFLAGS+=(-use-dynld)

echo "Building DSO \"${DSOFILE}\"..." && \
"${CC}" "${CFLAGS[@]}" "${DSOFLAGS[@]}" -o "${DSOFILE}" somelib.cpp && \
echo "Building main executable \"${EXEFILE}\"..." && \
"${CC}" "${CFLAGS[@]}" "${EXEFLAGS[@]}" -o "${EXEFILE}" dsotest.cpp
