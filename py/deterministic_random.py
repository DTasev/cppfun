from __future__ import (absolute_import, division, print_function)

import random as rd

target = "yourecute"
int_target = [ord(c) for c in target]
length = len(int_target)
imin = min(int_target)
imax = max(int_target)

print("Looking for", target, "with len", length,
      "ascii values, min:", imin, "max", imax)


success = True
seed = 0
while True:
    # for seed in xrange(10):
    rd.seed(seed)
    # assume success
    success = True
    for i in xrange(length):
        if int_target[i] != rd.randint(imin, imax):
            success = False
            break
    if success:
        print("Found the string", target, "with seed", seed)
        break
    else:
        seed += 1
