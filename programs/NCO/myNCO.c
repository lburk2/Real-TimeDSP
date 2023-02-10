#include "stdint.h"
#include "LUT.h"
#include "myNCO.h"
#include "math.h"

static double freqDelta;
static int attFactor = 0;
uint32_t index;
uint32_t pa = 0;
double f = 0;
//static double phase = 0;

void nco_set_frequency(double freq)
{
	double fs = 48000.0;
	f = freq;

	freqDelta = freq * 4294967295.0 / fs;

}
void nco_set_attenuation(int att)
{
	attFactor = att;

}

int16_t nco_run_sinusoid(void)
{

	pa = pa + freqDelta;
	index = pa >> 24;
	if(index >= 255)
		pa = 0;
	// return a 16-bit signed integer
	return (sinusoid[index]>>attFactor);

}

int16_t nco_run_triangle(void)
{

	pa = pa + freqDelta;
	index = pa >> 24;
	if(index >= 255)
		pa = 0;
	// return a 16-bit signed integer
	return (triangle[index]);

}

