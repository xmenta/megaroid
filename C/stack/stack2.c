/* stack2.c
 */

#include <stdio.h>
#include <stdlib.h>

#define DEFINE_STACK(T,MAX_SIZE) \
   typedef struct { \
     int size; \
     T data[MAX_SIZE]; \
   } stack_##T; \
   void stack_##T##_init(stack_##T* s) \
   { s->size = 0; } \
   void stack_##T##_push(stack_##T* s, T value) \
   { \
     if (s->size >= MAX_SIZE) { \
       fprintf(stderr, "The STACK is FULL !\n"); \
       exit(1); \
     } \
     s->data[s->size++] = value; \
   } \
   T stack_##T##_pop(stack_##T* s) \
   { \
     if (s->size == 0) { \
       fprintf(stderr, "The STACK is EMPTY !\n"); \
       exit(1); \
     } \
     return s->data[--s->size]; \
   } \
   T stack_##T##_top(stack_##T* s) \
   { \
     if (s->size == 0) { \
       fprintf(stderr, "The STACK is EMPTY !\n"); \
       exit(1); \
     } \
     return s->data[s->size - 1]; \
   } \
   int stack_empty(stack_##T* s)  \
   { \
     return s->size == 0; \
   } \
   int stack_full(stack_int* s) \
   { \
     return s->size >= MAX_SIZE; \
   } 

DEFINE_STACK(int, 1000)

void stack_int_print(const stack_int* s)
{
  printf("The size of the stack: %d\n", s->size);
  for (int i=0; i<s->size; i++) {
    printf("[%d] ", s->data[i]);
  }
  printf("\n\n");
}

int main()
{
  stack_int S;
  int cmd = 1;
  int n;

  stack_int_init(&S);

  while( cmd ) {
    stack_int_print(&S);
    printf("0...Exit 1..Push 2..Pop : ");
    scanf("%d", &cmd);
    switch (cmd) {
    case 1:
      printf("Number: ");
      scanf("%d", &n);
      stack_int_push(&S, n);
      break;
    case 2:
      n = stack_int_pop(&S);
      printf("pop = %d\n", n);
      break;
    }
  }

  return 0;
}
