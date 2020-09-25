#!/bin/sh


if ! [ -d images/examples ]
then
	mkdir images/examples
fi

for ex in examples/*.lsd
do
	./build/lsys2svg $ex 1> images/$ex.svg
done
