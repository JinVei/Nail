#!/usr/bin/env bash
set -x
set -e
function build() {
    local current_dir=$(pwd)
    local project_dir=$(dirname "$0")
    cd ${project_dir}
    project_dir=$(pwd)

    #git submodule update --init --recursive

    #./3rd/build_lua.sh

    cd ${project_dir}

    cp -R ./3rd/KHR/* ./3rd/include/KHR

    cmake_build_dir="./build"
    [ -d "${cmake_build_dir}" ] && rm -rf "${cmake_build_dir}"
    mkdir -p "${cmake_build_dir}"

    cd "${cmake_build_dir}"
    cmake ../ -DCMAKE_INSTALL_PREFIX="${project_dir}/3rd"
    make
    make install

    cd ${project_dir}

    [ ! -d "./bin" ] && mkdir -p "./bin"
    pwd
    mv "./build/src/Nail" "./bin/Nail"
    cp -r ./src/driver/opengl/shader/ ./bin/shader/
    cd "$current_dir"
    echo "Build done!"
}

build

