#!/usr/bin/env python

import ctypes
import sys


if len(sys.argv) <= 1 or len(sys.argv) > 3:
	print("Usage: ex.py LSD_FILE [N_ITERATIONS]")
	exit(1)

if len(sys.argv) == 3:
	iterations = int(sys.argv[2])
else:
	iterations = -1

liblsysgen = ctypes.cdll.LoadLibrary('build/liblsysgen.so')
generateLSystem = liblsysgen.generateLSystem
generateLSystem.argtypes = (ctypes.c_char_p, ctypes.c_int)
generateLSystem.restype = ctypes.c_char_p

result = generateLSystem(sys.argv[1].encode(), iterations)

print(result.decode())

