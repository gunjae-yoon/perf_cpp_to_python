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

namespace ctopy {
	void Access(void) {
		CToPy::getInstance().access();
	}

	void Start(void) {
		CToPy::getInstance().start();
	}

	void End(void) {
		CToPy::getInstance().end();
	}

	uint64_t GetElapsedTime(void) {
		return CToPy::getInstance().getElapsedTime();
	}

	double GetElapsedTimePerAccess(void) {
		return CToPy::getInstance().getElapsedTimePerAccess();
	}
}
