#!/usr/bin/env bash

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

which g++ && CXX_COMPILER=g++
[ -z "$CXX_COMPILER" ] && which clang++ && CXX_COMPILER=clang++

which ld && LINKER=ld
[ -z "$LINKER" ] && which ldd && CXX_COMPILER=ldd

[ -d "$SCRIPT_DIR/out/build" ] || mkdir -p "$SCRIPT_DIR/out/build"


BUILD_DIR="$SCRIPT_DIR/out/build"
OUT_DIR="$SCRIPT_DIR/out"
OUT_NAME="coast_input_simulation"



$CXX_COMPILER -c -I"$SCRIPT_DIR" -o $BUILD_DIR/$OUT_NAME.o "$SCRIPT_DIR/linux/input_sim_linux.cc"
ar rvs $OUT_DIR/lib$OUT_NAME.a $BUILD_DIR/$OUT_NAME.o
$CXX_COMPILER -o $SCRIPT_DIR/out/$OUT_NAME "input_sim_test.cc" -Wl,-Bstatic,-L$OUT_DIR,-l$OUT_NAME,-Bdynamic,-lX11