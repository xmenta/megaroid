/*
 * prime4.c
 *
 * Get prime numbers using The sieve of Eratosthenes 
 *
 */
#include <stdio.h>
#include <math.h>

// 0 ... prime
// 1 ... composite
int p[10001] = { 0, 1, 0, };

void sieve_of_eratosthenes(int n)
{
  int i;
  int j;
  int sqrt_n = (int)sqrt(n);

  for (i = 2; i <= sqrt(n); i++) {
    if (p[i] == 1){
      continue;
    }
    for (j = i * 2; j <= n; j += i) {
      p[j] = 1;
    }
  }
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

  sieve_of_eratosthenes(n);

  for (i = 2; i <= n; i++) {
    if (p[i] == 0) {
      printf(" %d", i);
    }
  }
  printf("\n");
  return 0;
}

