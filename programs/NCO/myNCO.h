#include "stdint.h"


extern void nco_set_frequency(double freq);
extern void nco_set_attenuation(int att);
extern int16_t nco_run_sinusoid(void);
extern int16_t nco_run_triangle(void);

