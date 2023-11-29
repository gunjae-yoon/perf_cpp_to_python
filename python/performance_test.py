import sys
import pybind as pb
import ctopy
import ctypes
from ctypes import c_double

def perf_pybind(cnt):
	print('    PyBind11 --------------------------------------')
	pb.start()
	for i in range(cnt):
		pb.access()
	pb.end()
	elapsed = pb.get_elapsed_time()
	per = pb.get_elapsed_time_per_access()
	print(f'        elapsed time: {elapsed:,} ns')
	print(f'        elapsed time per access: {per:,} ns')

def perf_cython(cnt):
	print('    Cython ----------------------------------------')
	cython = ctopy.CToPy()
	cython.start()
	for i in range(cnt):
		cython.access()
	cython.end()
	elapsed = cython.get_elapsed_time()
	per = cython.get_elapsed_time_per_access()
	print(f'        elapsed time: {elapsed:,} ns')
	print(f'        elapsed time per access: {per:,} ns')

def perf_ctypes(cnt):
	print('    Ctypes ----------------------------------------')
	cpplib = ctypes.cdll.LoadLibrary('./libctopy.so')
	cpplib.c_start()
	for i in range(cnt):
		cpplib.c_access()
	cpplib.c_end()
	elapsed = cpplib.c_get_elapsed_time()
	cpplib.c_get_elapsed_time_per_access.restype = c_double
	per = cpplib.c_get_elapsed_time_per_access()
	print(f'        elapsed time: {elapsed:,} ns')
	print(f'        elapsed time per access: {per:,} ns')

test_count = 1000 * 1000 * 10
for i in range(10):
	print(f'TEST [{i}] ==============================================')
	perf_pybind(test_count)
	perf_cython(test_count)
	perf_ctypes(test_count)
	print()
