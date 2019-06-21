
#include <time.h>

class TimeElapsedAspect
{
public:
	TimeElapsedAspect();
	~TimeElapsedAspect();

	void Before(int i);
	void After(int i);
private:
	double m_last_time;
	time_t m_t;
};


