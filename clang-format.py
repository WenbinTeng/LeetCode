#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
path = os.getcwd()
for root, dirs, files in os.walk(path):
    for name in files:
        if (name.endswith(".cpp")):
            localpath = root + '/' + name
            print(localpath)
            os.system("clang-format -i %s -style=file" %(localpath))
