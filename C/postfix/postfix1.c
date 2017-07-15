/* postfix1.c */

#include <stdio.h>
#include <ctype.h>
#include "stack.h"

DEFINE_STACK(int, 100)

void stack_int_print(const stack_int* S)
{
  printf("(%d) ", S->size);
  for (int i = 0; i < S->size; i++) {
    printf("%d ", S->data[i]);
  }
  printf("\n");
}

int main()
{
  stack_int S;
  char c;

  stack_int_init(&S);

  while (c != '.') {

    stack_int_print(&S);

    scanf("%c", &c);
    printf("Input '%c' ==> ", c);

    if (isdigit(c)) {
      stack_int_push(&S, c - '0');
    } else if (c == '+') {
      int op2 = stack_int_pop(&S);
      int op1 = stack_int_pop(&S);
      stack_int_push(&S, op1 + op2);
    } else if (c == '-') {
      int op2 = stack_int_pop(&S);
      int op1 = stack_int_pop(&S);
      stack_int_push(&S, op1 - op2);
    } else if (c == '*') {
      int op2 = stack_int_pop(&S);
      int op1 = stack_int_pop(&S);
      stack_int_push(&S, op1 * op2);
    } else if (c == '/') {
      int op2 = stack_int_pop(&S);
      int op1 = stack_int_pop(&S);
      stack_int_push(&S, op1 / op2);
    }
  }

  if (S.size != 1) {
    fprintf(stderr, "The size of the STACK(%d) must be 1.\n\n", S.size);
    exit(1);
  }
  printf("The answer is %d\n\n", stack_int_pop(&S));

  return 0;
}


