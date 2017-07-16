/* infix_to_postfix.h */

#ifndef __INFIX_TO_POSTFIX_H__
#define __INFIX_TO_POSTFIX_H__

#include "rational.h"
#include "stack.h"

DECLARE_STACK(char, 100);

typedef struct {
  char op;
  Q value;
} term;

typedef struct infix_to_postfix {
  stack_char op_stack;
  term terms[100];
  int terms_count;
} ITP;

void ITP_init(ITP* itp);
void ITP_add_expr(ITP* itp, const char* expr);
void ITP_finish(ITP* itp);
void ITP_print(ITP* itp);

#endif /* __INFIX_TO_POSTFIX_H_ */
