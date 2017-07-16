/* postfix.c */

#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
#include "stack.h"

DECLARE_STACK(Q, 100)
DEFINE_STACK(Q, 100)

void stack_Q_print(const stack_Q* S)
{
  int i;
  printf("(%d) ", S->size);
  for (i = 0; i < S->size; i++) {
    printf("%s ", str(&S->data[i]));
  }
  printf("\n");
}

Q (*operators[])(const Q*, const Q*) = {
  multiply,
  add,
  NULL,
  subtract,
  NULL,
  divide
 };

Q solve_postfix(const term* terms, int count)
{
  int i;
  stack_Q S;
  Q (*oper)(const Q*, const Q*);
  
  printf("----------------------------------------\n");

  stack_Q_init(&S);

  for (i = 0; i < count; i++) {
    stack_Q_print(&S);
    term t = terms[i];

    if (t.op) {
      printf("Input '%c' ==> ", t.op);
    } else {
      printf("Input '%s' ==> ", str(&t.value));
    }

    if (t.op) {
      oper = operators[t.op - 42];
      if (oper != NULL) {
        Q op2 = stack_Q_pop(&S);
        Q op1 = stack_Q_pop(&S);
        Q res = oper(&op1, &op2);
        stack_Q_push(&S, res);
      }
    } else {
      stack_Q_push(&S, t.value);
    }
  }

  if (S.size != 1) {
    fprintf(stderr, "The size of the STACK(%d) must be 1.\n\n", S.size);
    exit(1);
  }

  Q answer = stack_Q_pop(&S);
  return answer;
}

