#!/usr/bin/env python3

import os

directory = "."
for filename1 in os.listdir(directory):
    if filename1.endswith(".json") == False:
        continue
    for filename2 in os.listdir(directory):
        if(filename1 != filename2):
            if filename2.endswith(".json"):
                os.system("../../build-mosze_01-Desktop_Qt_5_14_1_GCC_64bit-Debug/mosze_01 " + filename1 + " " + filename2)
                #print(filename1 + " " +filename2)
        else:
            continue