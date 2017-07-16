/*
 * Infix to Postfix 
 *
 */
#include <stdio.h>
#include "infix_to_postfix.h"

int main()
{
  ITP itp;
  char buf[10];

  ITP_init(&itp);

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

  return 0;
}
