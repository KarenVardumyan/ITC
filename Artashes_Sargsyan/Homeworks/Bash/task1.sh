#!/bin/bash
read -p "Insert magic word: " key
read -p "Insert dir for search(by default ~/Desktop): " dir
read -p "Enter the name of the directory where the result will be saved: " res
if [[ $dir -eq "" ]]
then
	dir=~/Desktop
fi	
if [[ ! -d ~/Desktop/Bash ]]
then
	mkdir ~/Desktop/Bash
fi
if [[ ! -f "~Desktop/Bash/result.txt" ]]
then
touch ~/Desktop/Bash/result.txt
fi
find /$dir -name "*$key*" >> ~/Desktop/Bash/result.txt
if [[ ! -d ~/Desktop/Bash/$res ]]
then
	mkdir ~/Desktop/Bash/$res
fi
while read LINE
do cp $LINE ~/Desktop/Bash/$res
done < ~/Desktop/Bash/result.txt
cd ~/Desktop/Bash
zip -r ~/Desktop/$res.zip $res/
rm -fr ~/Desktop/Bash
