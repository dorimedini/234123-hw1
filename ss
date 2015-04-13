#!/bin/bash

echo "fuck"
a=1
while read line
do
    name=$line
    echo "$a: $name"
	let a++
done




