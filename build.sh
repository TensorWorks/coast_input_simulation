#!/usr/bin/env bash

INSTALL_PREFIX=$(realpath $1)
[ -z $INSTALL_PREFIX ] && INSTALL_PREFIX="$SCRIPT_DIR/dist"

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

[ -d "$SCRIPT_DIR/build" ] || mkdir "$SCRIPT_DIR/build"

pushd "$SCRIPT_DIR/build"
    echo "Generating Cmake files"
    cmake ../

    echo "Building library and tests"
    cmake --build .

    echo "Installing redistribable files"
    cmake --install . --prefix $INSTALL_PREFIX
popd