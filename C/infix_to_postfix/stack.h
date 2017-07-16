#include <stdlib.h>

#ifndef __STACK_H__
#define __STACK_H__

#define DECLARE_STACK(T, MAX_SIZE) \
   typedef struct { \
     int size; \
     T data[MAX_SIZE]; \
   } stack_##T; \
   void stack_##T##_init(stack_##T* s); \
   void stack_##T##_push(stack_##T* s, T value); \
   T stack_##T##_pop(stack_##T* s); \
   T stack_##T##_top(stack_##T* s); \
   int stack_##T##_empty(stack_##T* s);  \
   int stack_##T##_full(stack_##T* s); 

#define DEFINE_STACK(T,MAX_SIZE) \
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
   int stack_##T##_empty(stack_##T* s)  \
   { \
     return s->size == 0; \
   } \
   int stack_##T##_full(stack_##T* s) \
   { \
     return s->size >= MAX_SIZE; \
   } 

#endif /* __STACK_H__ */
