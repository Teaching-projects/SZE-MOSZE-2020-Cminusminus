#!/bin/bash

IFS=$'\n'

DIRECTORY=units

for file1 in `ls $DIRECTORY`
do
    for file2 in `ls $DIRECTORY`
    do
        if [[ $file1 != $file2 ]]
        then
            ./$1 $DIRECTORY/$file1 $DIRECTORY/$file2 >> $2
        fi
    done
done