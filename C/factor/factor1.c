/* factor1.c 
 *
 * Compile with -lm  option (gcc)
 */

#include <stdio.h>
#include <math.h>

int main()
{
  int number;
  int sqrt_n;
  int i;

  printf("Input a number: ");
  scanf("%d", &number);
  
  if (number < 2) {
    printf("Input a number greater than two.\n");
    return -1;
  }
  printf("Factors: ");

  sqrt_n = (int)sqrt(number);
  for (i=2; i<=sqrt_n; i++) {
    if ((number % i) == 0) {
      printf(" %d %d", i, number / i);
    }
  }
  printf("\n");

  return 0;
}
