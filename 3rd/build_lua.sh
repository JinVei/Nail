#!/usr/bin/env bash
set -x
set -e
function build_lua() {
    local platform=""
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        platform="linux"
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        platform="macosx"
    elif [[ "$OSTYPE" == "win32" ]]; then
        echo "TODO: win32"
        exit 1
    else
        echo "Unknown platform"
        exit 1
    fi

    local current_dir=$(pwd)

    local BASEDIR=$(dirname "$0")

    cd "$BASEDIR"/lua5.3

    make clean
    make "$platform"
    make local
    make clean
    cp -R ./install/include ../include/lua
    cp ./install/lib/liblua.a ../lib/liblua.a

    cd "$current_dir"
}

build_lua