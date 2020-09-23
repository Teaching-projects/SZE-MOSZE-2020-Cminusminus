#!/usr/bin/env python3

import os

directory = "."
for filename1 in os.listdir(directory):
    if filename1.endswith(".json") == False:
        continue
    for filename2 in os.listdir(directory):
        if(filename1 != filename2):
            if filename2.endswith(".json"):
                os.system("mosze_01 " + filename1 + " " + filename2)
        else:
            continue