#!/usr/bin/env python

import ctypes
import sys


liblsysgen = ctypes.cdll.LoadLibrary('build/liblsysgen.so')

c_lsystem_create = liblsysgen.lsystem_create
c_lsystem_create.argtypes = (ctypes.c_char_p, ctypes.c_int)
c_lsystem_create.restype = ctypes.c_void_p

c_lsystem_generate = liblsysgen.lsystem_generate
c_lsystem_generate.argtypes = (ctypes.c_void_p,)

c_lsystem_iterate = liblsysgen.lsystem_iterate
c_lsystem_iterate.argtypes = (ctypes.c_void_p, ctypes.c_int)

c_lsystem_get_iteration_number = liblsysgen.lsystem_get_iteration_number
c_lsystem_get_iteration_number.argtypes = (ctypes.c_void_p,)
c_lsystem_get_iteration_number.restype = ctypes.c_int

c_lsystem_get_result_string = liblsysgen.lsystem_get_result_string
c_lsystem_get_result_string.argtypes = (ctypes.c_void_p,)
c_lsystem_get_result_string.restype = ctypes.c_char_p

c_lsystem_to_svg = liblsysgen.lsystem_to_svg
c_lsystem_to_svg.argtypes = (ctypes.c_void_p,)
c_lsystem_to_svg.restype = ctypes.c_char_p

class LSystem:
	def __init__(self, filename, iterations=-1):
		self.filename = filename
		self.iterations = iterations
		self.c_lsystem = c_lsystem_create(filename.encode(), iterations)
	def generate(self):
		c_lsystem_generate(self.c_lsystem)
	def iterate(self, iterations=1):
		c_lsystem_iterate(self.c_lsystem, iterations)
	def iteration(self):
		return c_lsystem_get_iteration_number(self.c_lsystem)
	def result_to_str(self):
		return c_lsystem_get_result_string(self.c_lsystem).decode()
	def result_to_svg(self):
		return c_lsystem_to_svg(self.c_lsystem).decode()

def main():
	if len(sys.argv) <= 1 or len(sys.argv) > 3:
		print("Usage: ex.py LSD_FILE [N_ITERATIONS]")
		exit(1)

	if len(sys.argv) == 3:
		iterations = int(sys.argv[2])
	else:
		iterations = -1

	lsys = LSystem(sys.argv[1], iterations)
	lsys.generate()

	print(lsys.result_to_str())

	# lsys.iterate(1)
	# print(lsys.result_to_str())

	print(lsys.result_to_svg())

if __name__ == '__main__':
	main()

