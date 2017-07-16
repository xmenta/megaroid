/* postfix.h */

#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "rational.h"
#include "infix_to_postfix.h"

Q solve_postfix(const term* terms, int count);

#endif /*  __POSTFIX_H__ */
