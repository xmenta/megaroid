/* simplecalc5.c */

#include <stdio.h>
#include <stdlib.h>

int add(int op1, int op2) { return op1 + op2; }
int subtract(int op1, int op2) { return op1 - op2; }
int multiply(int op1, int op2) { return op1 * op2; }
int divide(int op1, int op2) { return op1 / op2; }

typedef int (*OPERATOR)(int, int);

OPERATOR operators[] = {
  multiply, /* '*' 42 */
  add, /* '+' 43 */
  NULL,
  subtract, /* '-' 45 */
  NULL,
  divide /* '/' 47 */
};

int main()
{
  int op1, op2;
  char op;
  int result;

  OPERATOR oper = NULL;

  printf("Input two integers and a operator : ");
  scanf("%d %d %c", &op1, &op2, &op);

  if (op >= 42 && op <= 47) {
    oper = operators[op - 42];
  }
  if (oper == NULL) {
      fprintf(stderr, "Invalid operator '%c'\n", op);
      exit(1);
  }
  result = oper(op1, op2);

  /* Print the result. */
  printf("%d %c %d = %d \n", op1, op, op2, result);

  return 0;
}
