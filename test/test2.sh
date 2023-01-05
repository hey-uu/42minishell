#!/bin/bash


export var="a b c";
for alphabet in $var
do
	echo $alphabet;
done

echo "\nusing \$* in loop";
for files in $*
do
	echo "files: $files"
done

echo "\nusing \$@ in loop";
for files in $@
do
	echo "files: $files"
done
