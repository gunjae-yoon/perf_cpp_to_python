import sys
import pybind as pb
import ctopy

def perf_pybind(cnt):
	print('performance of PyBind11')
	pb.start()
	for i in range(cnt):
		pb.access()
	pb.end()
	elapsed = pb.get_elapsed_time()
	print(f'	elapsed time: {elapsed:,} ns')
	print('	elapsed time per access: ', pb.get_elapsed_time_per_access(), ' ns')

def perf_cython(cnt):
	print('performance of Cython')
	cython = ctopy.CToPy()
	cython.start()
	for i in range(cnt):
		cython.access()
	cython.end()
	elapsed = cython.get_elapsed_time()
	print(f'	elapsed time: {elapsed:,} ns')
	print('	elapsed time per access: ', cython.get_elapsed_time_per_access(), ' ns')

test_count = 1000 * 1000 * 10
perf_pybind(test_count)
print()
perf_cython(test_count)
print()
