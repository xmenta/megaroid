/* simplecalc4.c */

#include <stdio.h>
#include <stdlib.h>

int add(int op1, int op2) { return op1 + op2; }
int subtract(int op1, int op2) { return op1 - op2; }
int multiply(int op1, int op2) { return op1 * op2; }
int divide(int op1, int op2) { return op1 / op2; }

typedef int (*OPERATOR)(int, int);

int main()
{
  int op1, op2;
  char op;
  int result;

  OPERATOR oper;

  printf("Input two integers and a operator : ");
  scanf("%d %d %c", &op1, &op2, &op);

  switch (op) {
    case '+':
      oper = add;
      break;
    case '-':
      oper = subtract;
      break;
    case '*':
      oper = multiply;
      break;
    case '/':
      oper = divide;
      break;
    default:
      fprintf(stderr, "Invalid operator '%c'\n", op);
      exit(1);
  }
  result = oper(op1, op2);

  /* Print the result. */
  printf("%d %c %d = %d \n", op1, op, op2, result);

  return 0;
}
