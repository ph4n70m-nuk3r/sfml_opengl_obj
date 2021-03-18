#!/usr/bin/env bash

set -e

function finish
{
    printf '\n'
    popd
    exit 0
}

make clean
make
pushd bin
./a.out || finish
finish

