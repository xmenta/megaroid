#include <stdio.h>

#define AAA "Hello, World!\n"

#define ADD(a,b) (a+b)

#define PRINT_ADD(a,b) printf(#a " + " #b " = %d\n", ADD(a,b))

#define NAME(x,y) x##y 

void test1()
{
  printf(AAA);
}

void test2()
{
  printf("%d + %d = %d\n", 10, 20, ADD(10,20));
}

void test3()
{
  PRINT_ADD(1,2);
  PRINT_ADD(3,4);
}

void test4()
{
  int NAME(Hello,World) = 10;

  printf("Hello, World = %d\n", HelloWorld);
}

int main()
{
  test1();
  test2();
  test3();
  test4();
  return 0;
}



