/*
va-arg-23.c from the execute part of the gcc torture tests.
*/

#include <testfwk.h>

#pragma disable_warning 85

/* PR 9700 */
/* Alpha got the base address for the va_list incorrect when there was
   a structure that was passed partially in registers and partially on
   the stack.  */

#include <stdarg.h>

struct two { long x, y; };

#if !defined(__SDCC_ds390) && !defined(__SDCC_mos6502) && !defined(__SDCC_hc08) && !defined(__SDCC_s08) // Todo: enable when struct parameters are supported!
void foo(int a, int b, int c, int d, int e, struct two f, int g, ...)
{
  va_list args;
  int h;

  va_start(args, g);
  h = va_arg(args, int);
  if (g != 1 || h != 2)
    ASSERT (0);
}
#endif

void
testTortureExecute (void)
{
#if !defined(__SDCC_ds390) && !defined(__SDCC_mos6502) && !defined(__SDCC_hc08) && !defined(__SDCC_s08) // Todo: enable when struct parameters are supported!
  struct two t = { 0, 0 };
  foo(0, 0, 0, 0, 0, t, 1, 2);
  return;
#endif
}
