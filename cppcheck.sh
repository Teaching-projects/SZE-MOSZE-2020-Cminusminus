#!/bin/bash

IFS=$'\n'


$(cppcheck *.cpp --enable = warning --output-file = cppcheck_errors.txt)
	if ![-s .cppcheck_errors.txt]
	then
		exit 1
	else
		$(cppcheck *.cpp --enable = performance, style --output-file = cppcheck_performance.txt)