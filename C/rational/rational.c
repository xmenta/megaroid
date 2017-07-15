/* 
 * rational.c
 *
 */
#include <stdio.h>

int get_gcd(int m, int n)
{
  int q;
  while ( n ) {
    q = n;
    n = m % n;
    m = q;
  }
  return m;
}

struct rational {
  int n;  /* numerator */
  int m;  /* denominator */
  char buf[20]; /* buffer for printf */
};

typedef struct rational R;

/*
void print(R r)
{
  if (r.m == 1) {
    printf("%d", r.n);
  } else {
    printf("(%d/%d)", r.n, r.m);
  }
}
*/

void print(const R* r)
{
  if (r->m == 1) {
    printf("%d", r->n);
  } else {
    printf("(%d/%d)", r->n, r->m);
  }
}

const char* str(R* r)
{
  if (r->m == 1) {
    sprintf(r->buf, "%d", r->n);
  } else {
    sprintf(r->buf, "(%d/%d)", r->n, r->m);
  }
  return r->buf;
}

void reduce(R* r)
{
  int sign = 1;
  if (r->m < 0) {
    r->m = -r->m;
    sign = -sign;
  }
  if (r->n < 0) {
    r->n = -r->n;
    sign = -sign;
  }

  int gcd = get_gcd(r->m, r->n);
  r->m /= gcd;
  r->n /= gcd;

  r->n *= sign;
}

R multiply(const R* r1, const R* r2)
{
  R r;
  r.n = r1->n * r2->n;
  r.m = r1->m * r2->m;
  reduce(&r);
  return r;
}

R divide(const R* r1, const R* r2)
{
  R r;
  r.n = r1->n * r2->m;
  r.m = r1->m * r2->n;
  reduce(&r);
  return r;
}

R add(const R* r1, const R* r2)
{
  R r;
  int lcm = r1->m * r2->m / get_gcd(r1->m, r2->m);
  r.n = lcm / r1->m * r1->n + lcm / r2->m * r2->n;
  r.m = lcm;
  reduce(&r);
  return r;
}

R subtract(const R* r1, const R* r2)
{
  R r;
  int lcm = r1->m * r2->m / get_gcd(r1->m, r2->m);
  r.n = lcm / r1->m * r1->n - lcm / r2->m * r2->n;
  r.m = lcm;
  reduce(&r);
  return r;
}

void test1()
{
  R r1 = { 1, 6 };
  printf("1/6 = ");
  print(&r1);
  printf("\n");
}

void test2_mul()
{
  R r1 = { 2, 3 }; /* 2/3 */
  R r2 = { 3, 4 }; /* 3/4 */ 
  R r3 = multiply(&r1, &r2); 

  printf("2/3 * 3/4 = ");
  print(&r3);
  printf("\n");
}

void test3_div()
{
  R r1 = { 1, 3 }; /* 1/3 */
  R r2 = { 2, 3 }; /* 2/3 */ 
  R r3 = divide(&r1, &r2); 

  printf("1/3 % 2/3 = ");
  print(&r3);
  printf("\n");
}

void test4_add()
{
  R r1 = { 1, 4 }; /* 1/4 */
  R r2 = { 1, 12 }; /* 1/12 */ 
  R r3 = add(&r1, &r2); 

  printf("1/4 + 1/12 = ");
  print(&r3);
  printf("\n");
}

void test5_sub()
{
  R r1 = { 1, 6 }; /* 1/6 */
  R r2 = { 1, 2 }; /* 1/2 */ 
  R r3 = subtract(&r1, &r2); 

  printf("1/6 - 1/2 = ");
  print(&r3);
  printf("\n");
}

void test6()
{
  R r1 = { 4 , 9 }; /* 4/9 */
  R r2 = { 5 , 12 }; /* 5/ 12 */

  R r3 = add(&r1, &r2);
  R r4 = subtract(&r1, &r2);
  R r5 = multiply(&r1, &r2);
  R r6 = divide(&r1, &r2);

  printf("%s + %s = %s\n", str(&r1), str(&r2), str(&r3));
  printf("%s - %s = %s\n", str(&r1), str(&r2), str(&r4));
  printf("%s * %s = %s\n", str(&r1), str(&r2), str(&r5));
  printf("%s / %s = %s\n", str(&r1), str(&r2), str(&r6));
}

int main()
{
  test1();
  test2_mul();
  test3_div();
  test4_add();
  test5_sub();
  test6();

  return 0;
}


