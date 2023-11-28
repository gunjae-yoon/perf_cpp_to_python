#distutils: language = c++
from libcpp cimport bool
from libcpp.string cimport string

cdef extern from 'ctopy/ctopy.h' namespace 'ctopy':
	void Access()
	void Start()
	void End()
	unsigned long long GetElapsedTime()
	double GetElapsedTimePerAccess()

cdef class CToPy:
	def access(self):
		Access()
	
	def start(self):
		Start()

	def end(self):
		End()
	
	def get_elapsed_time(self):
		return GetElapsedTime()
	
	def get_elapsed_time_per_access(self):
		return GetElapsedTimePerAccess()
