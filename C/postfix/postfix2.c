/* postfix2.c */

#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#include "rational.h"

DEFINE_STACK(Q, 100)

void stack_Q_print(const stack_Q* S)
{
  printf("(%d) ", S->size);
  for (int i = 0; i < S->size; i++) {
    printf("%s ", str(&S->data[i]));
  }
  printf("\n");
}

Q (*operators[])(const Q*, const Q*) = { multiply, add, NULL, subtract, NULL, divide };

int main()
{
  stack_Q S;
  char buffer[10];
  Q (*oper)(const Q*, const Q*);

  stack_Q_init(&S);

  while (buffer[0] != '.' && buffer[0] != '=') {
    stack_Q_print(&S);
    scanf("%s", buffer);
    printf("Input '%s' ==> ", buffer);

    if (isdigit(buffer[0])) {
      int n = atoi(buffer);
      Q q = { n , 1 }; /* n / 1 */
      stack_Q_push(&S, q);
    } else if (buffer[0] >= 42 && buffer[0] <= 47) {
      oper = operators[buffer[0] - 42];
      if (oper != NULL) {
        Q op2 = stack_Q_pop(&S);
        Q op1 = stack_Q_pop(&S);
        Q res = oper(&op1, &op2);
        stack_Q_push(&S, res);
      }
    } 
  }

  if (S.size != 1) {
    fprintf(stderr, "The size of the STACK(%d) must be 1.\n\n", S.size);
    exit(1);
  }

  Q awnser = stack_Q_pop(&S);
  printf("The answer is %s\n\n", str(&awnser));

  return 0;
}

