#!/bin/bash

let a=1
while read line
do
    echo "$a: $line"
    let a++
done

