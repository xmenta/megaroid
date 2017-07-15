#ifndef __RATIONAL_H__
#define __RATIONAL_H__

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
};
typedef struct rational Q;

/* Support only 5 concurrent output */
const char* str(const Q* r)
{
  static char buffer[100];
  static char buffer_idx = 0;

  buffer_idx = (buffer_idx + 20 ) % 100;
  if (r->m == 1) {
    sprintf(&buffer[buffer_idx], "%d", r->n);
  } else {
    sprintf(&buffer[buffer_idx], "(%d/%d)", r->n, r->m);
  }
  return &buffer[buffer_idx];
}

void reduce(Q* r)
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

Q multiply(const Q* r1, const Q* r2)
{
  Q r;
  r.n = r1->n * r2->n;
  r.m = r1->m * r2->m;
  reduce(&r);
  return r;
}

Q divide(const Q* r1, const Q* r2)
{
  Q r;
  r.n = r1->n * r2->m;
  r.m = r1->m * r2->n;
  reduce(&r);
  return r;
}

Q add(const Q* r1, const Q* r2)
{
  Q r;
  int lcm = r1->m * r2->m / get_gcd(r1->m, r2->m);
  r.n = lcm / r1->m * r1->n + lcm / r2->m * r2->n;
  r.m = lcm;
  reduce(&r);
  return r;
}

Q subtract(const Q* r1, const Q* r2)
{
  Q r;
  int lcm = r1->m * r2->m / get_gcd(r1->m, r2->m);
  r.n = lcm / r1->m * r1->n - lcm / r2->m * r2->n;
  r.m = lcm;
  reduce(&r);
  return r;
}

#endif /* rational.h */
