/*
 *  prime3.c
 *
 */
#include <stdio.h>
#include <math.h>

int p[10000];
int count = 0;

int is_prime(int n)
{
  int i;
  int sqrt_n = (int)sqrt(n);
  for (i = 0; p[i] > 0 && p[i] <= sqrt_n; i++) {
    if (n % p[i] == 0) {
      return 0;
    }
  }
  p[count++] = n;
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

