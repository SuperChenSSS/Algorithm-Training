/* strtold example */
#include "stdio.h"      /* printf, NULL */
#include "stdlib.h"     /* strtold */

int main ()
{
  char szOrbits[] = "90613.305 365.24";
  char * pEnd;
  long double f1, f2;
  f1 = strtold (szOrbits, &pEnd);
  f2 = strtold (pEnd, NULL);
  printf ("Pluto takes %.2Lf years to complete an orbit.\n", f1/f2);
  return 0;
}
