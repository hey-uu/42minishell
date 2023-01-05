#!/bin/bash

i=0

for param in "$*"
do
	let "i+=1"
	echo "Param #$i= $param"
done

i=0

for param in $*
do
	let "i+=1"
	echo "Param #$i= $param"
done

i=0

echo "\n"
for param in "$@"
do
	let "i+=1"
	echo "Param #$i= $param"
done

i=0

echo "\n"
for param in $@
do
	let "i+=1"
	echo "Param #$i= $param"
done
