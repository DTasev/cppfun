#!/usr/bin/env python
# -*- coding: utf-8 -*-
heart_face = u'😍'
kissy = u'😘'
width = " " * 9

A = def A(emoji):
    width * 2 + emoji + width * 2 + "\n" + \
        width + emoji * 3 + width + "\n" + \
        emoji + width * 3 + emoji + "\n"

with open("kiss.ys", "w") as f:
    f.write(A(kissy).encode('utf-8'))
