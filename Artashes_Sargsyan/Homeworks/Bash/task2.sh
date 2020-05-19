#!/bin/bash
str=$1
sed '/^#/d;/^\//d;/^$/d' $str | cat > ~/tmp
cat ~/tmp > $str
rm ~/tmp
#for remove comentaries enter the "./task2 text"
