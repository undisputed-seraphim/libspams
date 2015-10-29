#include "utils.h"

int gettimeofday(struct timeval *tv)
{
	FILETIME ft;
	unsigned __int64 tmpres = 0;
	static int tzflag = 0;

	if (NULL != tv) {
		GetSystemTimeAsFileTime(&ft);

		tmpres |= ft.dwHighDateTime;
		tmpres <<= 32;
		tmpres |= ft.dwLowDateTime;

		tmpres /= 10;  /*convert into microseconds*/
		/*converting file time to unix epoch*/
		tmpres -= DELTA_EPOCH_IN_MICROSECS;
		tv->tv_sec = (long)(tmpres / 1000000UL);
		tv->tv_usec = (long)(tmpres % 1000000UL);
	}

	struct timezone *tz = NULL;

	if (NULL != tz) {
		if (!tzflag) {
			_tzset();
			tzflag++;
		}
		tz->tz_minuteswest = _timezone / 60;
		tz->tz_dsttime = _daylight;
	}

	return 0;
}

// Constructor
Timer::Timer() :_running(false), _cumul(0)
{
	_time1 = (struct timeval*)malloc(sizeof(struct timeval));
	_time2 = (struct timeval*)malloc(sizeof(struct timeval));
}

// Destructor
Timer::~Timer()
{
	free(_time1);
	free(_time2);
}

// start the time
void Timer::start()
{
	_running = true;
	gettimeofday(_time1);
}

// stop the time
void Timer::stop()
{
	gettimeofday(_time2);
	_running = false;
	_cumul += static_cast<double>((_time2->tv_sec - (_time1->tv_sec)) * 1000000 + _time2->tv_usec - _time1->tv_usec) / 1000000.0;
}

// reset the timer
void Timer::reset()
{
	_cumul = 0;
	gettimeofday(_time1);
}

// print the elapsed time
void Timer::printElapsed()
{
	if (_running) {
		gettimeofday(_time2);
		cerr << "Time elapsed : " << _cumul + static_cast<double>((_time2->tv_sec -
			_time1->tv_sec) * 1000000 + _time2->tv_usec - _time1->tv_usec) / 1000000.0 << endl;
	} else {
		cerr << "Time elapsed : " << _cumul << endl;
	}
}

// print the elapsed time
double Timer::getElapsed() const
{
	if (_running) {
		gettimeofday(_time2);
		return _cumul +
			static_cast<double>((_time2->tv_sec -
			_time1->tv_sec) * 1000000 + _time2->tv_usec -
			_time1->tv_usec) / 1000000.0;
	} else {
		return _cumul;
	}
}