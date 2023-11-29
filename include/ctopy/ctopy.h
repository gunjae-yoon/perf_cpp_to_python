#ifndef __perf_cpp_to_python_ctopy_h__
#define __perf_cpp_to_python_ctopy_h__

#include <chrono>
#include <atomic>
#include <stdint.h>

namespace ctopy {
	// cpp type interface
	class CToPy {
	private:
		static CToPy instance;
		std::chrono::system_clock::time_point tBegin;
		std::chrono::system_clock::time_point tEnd;
		std::atomic<uint64_t> count;
	
	public:
		static CToPy& getInstance(void);
		
		void access(void);
		
		void start(void);
		void end(void);
		
		uint64_t getElapsedTime(void);
		double getElapsedTimePerAccess(void);

	private:
		CToPy(void);
		~CToPy(void);
	};
}

extern "C" {
	void c_access(void);
	void c_start(void);
	void c_end(void);
	uint64_t c_get_elapsed_time(void);
	double c_get_elapsed_time_per_access(void);
}
#endif
