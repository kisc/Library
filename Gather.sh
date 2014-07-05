#!/bin/sh

function Print() {
    echo $1
    cat -n $1
    echo ""
}

for src in $(find * | grep .cpp | grep -v main.cpp); do
    Print $src
done
