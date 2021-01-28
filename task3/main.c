#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *outp;

float arb_func (float x)
{
  return x * log10 (x) - 1.2;
}

void rf (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{
  *x = ((x0 * fx1) - (x1 * fx0)) / (fx1 - fx0);
  ++(*itr);
  printf ("iteration %d %.5f\n", *itr, *x);
  fprintf (outp, "iteration %d %.5f \n", *itr, *x);
}

int main ()
{
  outp = fopen ("output.txt", "w");
  int itr, maxitr;
  float x0, x1, x_curr, x_next, error;
  printf("Enter interval values [x0,x1] allowed error and number of iterations\n");
  scanf ("%f %f %f %d", &x0, &x1, &error, &maxitr);
  rf (&x_curr, x0, x1, arb_func (x0), arb_func (x1), &itr);

  do {
      if (arb_func (x0) * arb_func (x_curr) < 0)
	        x1 = x_curr;
      else
	        x0 = x_curr;

      rf (&x_next, x0, x1, arb_func (x0), arb_func (x1), &itr);

      if (fabs (x_next - x_curr) < error)
	  {
    	  printf ("Root %f you reached %d \n", x_curr, itr);
    	  fprintf (outp, "Root %f you reached %d\n", x_curr, itr);
    	  return 0;
	  }
      else
	x_curr = x_next;
    } while (itr < maxitr);
  printf ("You cannot converge and also output it to your file.");
  fprintf (outp, "You cannot converge and also output it to your file.");
  return (1);
}
