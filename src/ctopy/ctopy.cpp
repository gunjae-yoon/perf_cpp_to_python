#include <ctopy/ctopy.h>

namespace ctopy {
	CToPy CToPy::instance = CToPy();	

	CToPy::CToPy(void) {
		count.store(0);
	}

	CToPy::~CToPy(void) {
	}

	CToPy& CToPy::getInstance(void) {
		return instance;
	}

	void CToPy::access(void) {
		count++;
	}

	void CToPy::start(void) {
		count.store(0);
		tBegin = std::chrono::system_clock::now();
	}

	void CToPy::end(void) {
		tEnd = std::chrono::system_clock::now();
	}

	uint64_t CToPy::getElapsedTime(void) {
		std::chrono::nanoseconds ns = tEnd - tBegin;
		return ns.count();
	}

	double CToPy::getElapsedTimePerAccess(void) {
		if (count.load() == 0) {
			return 0.;
		}

		std::chrono::nanoseconds ns = tEnd - tBegin;
		return ns.count() / count.load();
	}
}

extern "C" {
	void c_access(void) {
		ctopy::CToPy::getInstance().access();
	}

	void c_start(void) {
		ctopy::CToPy::getInstance().start();
	}

	void c_end(void) {
		ctopy::CToPy::getInstance().end();
	}

	uint64_t c_get_elapsed_time(void) {
		return ctopy::CToPy::getInstance().getElapsedTime();
	}

	double c_get_elapsed_time_per_access(void) {
		return ctopy::CToPy::getInstance().getElapsedTimePerAccess();
	}
}
