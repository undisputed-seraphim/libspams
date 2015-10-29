#pragma once
/*!
 * \file
 *                toolbox Linalg
 *
 *                by Julien Mairal
 *                julien.mairal@inria.fr
 *
 *                File utils.h
 * \brief Contains various variables and class timer */

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include <limits>

#ifdef _OPENMP
#include <omp.h>
#endif

#ifndef MATLAB_MEX_FILE
typedef int mwSize;
#endif

#ifndef MAX_THREADS
#define MAX_THREADS 64
#endif

// MIN, MAX macros
#ifndef MIN
#define MIN(a,b) (((a) > (b)) ? (b) : (a))
#endif
#ifndef MAX
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#endif
#define SIGN(a) (((a) < 0) ? -1.0 : 1.0)
#define ABS(a) (((a) < 0) ? -(a) : (a))
// DEBUG macros
#define PRINT_I(name) printf(#name " : %d\n",name);
#define PRINT_F(name) printf(#name " : %g\n",name);
#define PRINT_S(name) printf("%s\n",name);
#define FLAG(a) printf("flag : %d \n",a);

// ALGORITHM constants
#define EPSILON 10e-10
#ifndef INFINITY
#define INFINITY 10e20
#endif
#define EPSILON_OMEGA 0.001
#define TOL_CGRAD 10e-6
#define MAX_ITER_CGRAD 40

#if defined(_MSC_VER) || defined(_WIN32)

#include <time.h>
#include <windows.h>
#define random rand
#define srandom srand

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif

struct timezone
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval *tv);

#else
#include <sys/time.h>
#endif

//#include "linalg.h"

using namespace std;

// Class Timer 
class Timer
{
public:
	// Empty constructor
	Timer();
	// Destructor
	~Timer();

	// start the time
	void inline start();
	// stop the time
	void inline stop();
	// reset the timer
	void inline reset();
	// print the elapsed time
	void inline printElapsed();
	// print the elapsed time
	double inline getElapsed() const;

private:
	struct timeval* _time1;
	struct timeval* _time2;
	bool _running;
	double _cumul;
};