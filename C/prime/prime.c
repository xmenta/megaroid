/* prime.c 
 *
 * Find prime numbers using 'Sieve of Eratosthenes'
 *
 * */
#include <stdio.h>
#include <math.h>

int numbers[100] = { 1, };

void sieve_of_eratosthenes()
{
  int i, j;

  for (i=2; i<=10; i++) {
    if (numbers[i-1] == 1) {
      continue;
    }
    for (j=i*2; j<=100; j+=i) {
      numbers[j-1] = 1;
    }
  }
}

void print_numbers()
{
  int i;
  for (i=0; i<100; i++) {
    if (numbers[i] == 0) {
      printf("%4d", i+1);
    } else {
      printf(" ---");
    }
    if (i%10 == 9) {
      printf("\n");
    }
  }
}

int main()
{
  sieve_of_eratosthenes();
  print_numbers();
  return 0;
}
