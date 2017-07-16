/* rational.h */

#ifndef __RATIONAL_H__
#define __RATIONAL_H__

int get_gcd(int m, int n);

struct rational {
  int n;  /* numerator */
  int m;  /* denominator */
};
typedef struct rational Q;

/* Support only 5 concurrent output */
const char* str(const Q* r);
void reduce(Q* r);
Q multiply(const Q* r1, const Q* r2);
Q divide(const Q* r1, const Q* r2);
Q add(const Q* r1, const Q* r2);
Q subtract(const Q* r1, const Q* r2);

#endif /* rational.h */
