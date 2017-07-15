/* gcd2.c
 * GCD by Euclidean Algorithm
 * */

#include <stdio.h>

int get_gcd(int m, int n)
{
  int q;
  while ( n > 0 ) {
    q = m % n; 
    m = n;
    n = q;
  }
  return m;
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



