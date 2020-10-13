#!/bin/bash

IFS=$'\n'


echo "$(cppcheck *.cpp --enable=warning --output-file=cppcheck_errors.txt)"
	if  [ ! -s .cppcheck_errors.txt ]
	then
			echo "$(cppcheck *.cpp --enable=performance, style --output-file=cppcheck_performance.txt)"
		
		if [ ! -s cppcheck_performance.txt ]
		then
			echo "Not found any performance and style errors."
		fi
	else
			exit 1
	fi 