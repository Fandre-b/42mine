#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h> 
#include <stdbool.h> 
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <fcntl.h> 
 
/*
int main(void)
{
  const char *string = "-10sresto da str";
  char *flags = "rnd string";
  int i;
  
  i = get_flags(&string, &flags);
  printf("%s\n %s", string, flags);
  return (i);
}*/
/*
int main(int argc, char *argv[])
{
  int i = 1234;
  double j = 1.23453453523424;
  char *str = NULL;
  int p;

  p = argc;
  printf(argv[1], str);
  return (0);
}*/

int main(void)
{
  int i;

  i = ft_printf("teste %s", "str");
  return (0);
}