/* prime2.c
 *
 */
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
  int i;
  int sqrt_n = (int)sqrt(n);
  for (i = 2; i <= sqrt_n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int i;
  int n;
  printf("Input a number: ");
  scanf("%d", &n);
  if (n < 2 || n > 10000) {
    fprintf(stderr, "n must be between 2 and 10000\n");
    return 1;
  }

  for (i = 2; i <= n; i++) {
    if (is_prime(i)) {
      printf(" %d", i);
    }
  }
  printf("\n");
  return 0;
}

