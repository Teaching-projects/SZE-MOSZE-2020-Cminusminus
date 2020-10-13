#!/bin/bash

IFS=$'\n'


echo "$(cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt)"
	if  [ ! -s .cppcheck_errors.txt ]
	then
		exit 1
	else
		echo "$(cppcheck *.cpp --enable=performance, style --output-file=cppcheck_performance.txt)"
	fi