/* infix_to_postfix.c*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "infix_to_postfix.h"

DEFINE_STACK(char, 100);

static int is_operator(char op)
{
  return op == '+' || op == '-' || op == '*' || op == '/';
}

static int get_priority(char op)
{
  if (op == '+' || op == '-') {
    return 1;
  } else if (op == '*' || op == '/') {
    return 2;
  }
  return 0;
}

void ITP_init(ITP* itp)
{
  stack_char_init(&itp->op_stack);
  itp->terms_count = 0;
}

void ITP_add_expr(ITP* itp, const char* expr)
{
  if (isdigit(expr[0])) {
    term t;
    t.op = 0;
    t.value.n = atoi(expr);
    t.value.m = 1;
    itp->terms[itp->terms_count++] = t;
  } else if (expr[0] == '(') {
    stack_char_push(&itp->op_stack, '(');
  } else if (expr[0] == ')') {
    while (1) {
      char op = stack_char_pop(&itp->op_stack);
      if (op == '(') {
        break;
      }
      term t;
      t.op = op;
      itp->terms[itp->terms_count++] = t;
    }
  } else if (is_operator(expr[0])) {
    while (!stack_char_empty(&itp->op_stack)) {
      char op = stack_char_top(&itp->op_stack);
      if (is_operator(op) && get_priority(op) >= get_priority(expr[0])) {
        stack_char_pop(&itp->op_stack);
        term t;
        t.op = op;
        itp->terms[itp->terms_count++] = t;
      } else {
        break;
      }
    }
    stack_char_push(&itp->op_stack, expr[0]);
  }
}

void ITP_finish(ITP* itp)
{
  while (!stack_char_empty(&itp->op_stack)) {
    char op = stack_char_pop(&itp->op_stack);
    if (is_operator(op)) {
      term t;
      t.op = op;
      itp->terms[itp->terms_count++] = t;
    }
  }
}

void ITP_print(ITP* itp)
{
  int i;
  printf("op_stack( ");
  for (i = 0; i < itp->op_stack.size; i++)
  {
    printf("%c ", itp->op_stack.data[i]);
  }
  printf(") terms( ");
  for (i = 0; i < itp->terms_count; i++)
  {
    if (itp->terms[i].op == 0) {
      if (itp->terms[i].value.m == 1) {
        printf("%d ", itp->terms[i].value.n);
      } else {
        printf("(%d/%d) ", itp->terms[i].value.n, itp->terms[i].value.m);
      }
    } else {
      printf("'%c' ", itp->terms[i].op);
    }
  }
  printf(")\n");
}

