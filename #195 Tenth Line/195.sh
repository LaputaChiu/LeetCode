#!/bin/bash
declare -i count=1

while read -r line
do
    if [ $count -eq 10 ]; then
        echo "$line"
        break
    fi
    count=$((count + 1))
done < "file.txt"