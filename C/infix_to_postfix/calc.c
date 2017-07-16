/*
 * Infix to Postfix 
 *
 */
#include <stdio.h>
#include "infix_to_postfix.h"
#include "postfix.h"

int main()
{
  ITP itp;
  char buf[10];

  ITP_init(&itp);

  printf("Input an expression : ");

  while (1) {
    scanf("%s", buf);
    if (buf[0] == '=' || buf[0] == '.') {
      break;
    }

    ITP_add_expr(&itp, buf);
    ITP_print(&itp);
  }
  ITP_finish(&itp);
  ITP_print(&itp);

  Q answer = solve_postfix(itp.terms, itp.terms_count);

  printf("The answer is %s.\n\n", str(&answer));

  return 0;
}
