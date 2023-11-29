#distutils: language = c++
from libcpp cimport bool
from libcpp.string cimport string

cdef extern from 'ctopy/ctopy.h':
	void c_access()
	void c_start()
	void c_end()
	unsigned long long c_get_elapsed_time()
	double c_get_elapsed_time_per_access()

cdef class CToPy:
	def access(self):
		c_access()
	
	def start(self):
		c_start()

	def end(self):
		c_end()
	
	def get_elapsed_time(self):
		return c_get_elapsed_time()
	
	def get_elapsed_time_per_access(self):
		return c_get_elapsed_time_per_access()
