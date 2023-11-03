#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
  int i = 1234;
  double j = 1.23453453523424;
  char *str = "dsdsdsd";
  int p;

  p = argc;
  printf(argv[1], str[0]);
  return (0);
}