#!/usr/bin/env python

import os

directory = "units/"
for filename1 in os.listdir(directory):
    if filename1.endswith(".json") == False:
        continue
    for filename2 in os.listdir(directory):
        if(filename1 != filename2):
            if filename2.endswith(".json"):
                os.system("./mosze_01 " + directory + filename1 + " " + directory + filename2)
        else:
            continue