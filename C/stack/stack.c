/* stack.c
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 1000

typedef struct {
  int size;
  int data[MAX_STACK];
} stack_int;

void stack_init(stack_int* s) 
{
  s->size = 0;
}

void stack_push(stack_int* s, int value)
{
  if (s->size >= MAX_STACK) {
    fprintf(stderr, "The STACK is FULL !\n");
    exit(1);
  }
  s->data[s->size++] = value;
}

int stack_pop(stack_int* s)
{
  if (s->size == 0) {
    fprintf(stderr, "The STACK is EMPTY !\n");
    exit(1);
  }
  return s->data[--s->size];
}

int stack_empty(stack_int* s) 
{
  return s->size == 0;
}

int stack_full(stack_int* s) 
{
  return s->size >= MAX_STACK;
}

void stack_print(stack_int* s)
{
  if (stack_empty(s)) {
    printf(" (Empty) \n");
    return;
  } 
  printf(" (The count of the stack is %d) ", s->size);
  for (int i = 0; i < s->size; i++) {
    printf(" [%d]", s->data[i]);
  }
  printf("\n");
}

int main()
{
  stack_int S;
  int cmd = 1;
  int n;

  stack_init(&S);

  while( cmd ) {
    stack_print(&S);
    printf("0...Exit 1..Push 2..Pop : ");
    scanf("%d", &cmd);
    switch (cmd) {
    case 1:
      printf("Number: ");
      scanf("%d", &n);
      stack_push(&S, n);
      break;
    case 2:
      n = stack_pop(&S);
      printf("pop = %d\n", n);
      break;
    }
  }

  return 0;
}
