/* gcd1.c
 *  Greateast Common Divisor
 */
#include <stdio.h>
#include <math.h>

void get_factors(int n, int f[])
{
  int i;
  int count = 0; /* The number of factors */
  int sqrt_n = (int)sqrt(n);
  for (i = 1; i <= sqrt_n; i++) {
    if (n % i == 0) {
      f[count++] = i;
      printf(" %d", i);
      if (i != n / i) {
        f[count++] = n / i;
        printf(" %d", n / i);
      }
    }
  }
  printf("\n");
}

int get_gcd(int m, int n)
{
  int m_factors[1000] = { 0 }; /* Initialized with Zero  - C99 */
  int n_factors[1000] = { 0 }; /* Initialized with Zero  - C99 */
  int i, j;
  int max_cd = 1;

  get_factors(m, m_factors);
  get_factors(n, n_factors);

  for (int i=0; m_factors[i]; i++) {
    for (int j=0; n_factors[j]; j++) {
      if (m_factors[i] == n_factors[j] && max_cd < m_factors[i]) {
        max_cd = m_factors[i];
      }
    }
  }

  return max_cd;
}

int main()
{
  int m, n;
  int gcd;

  printf("Input two numbers: ");
  scanf("%d %d", &m, &n);

  gcd = get_gcd(m, n);

  printf("The GCD is %d\n\n", gcd);

  return 0;
}



