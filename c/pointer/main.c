#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int8_t a = 3;
  int8_t b = 9;

  int8_t* const iptr = &a;
  // can't change the address of itself
  iptr = &b;
  const int8_t * iptr2 = &b;
  // can't modifiy value through ptr
  *iptr2 = 33;

  printf("iptr is %p\n", iptr);
  printf("iptr's val is %d\n", *iptr);
  printf("iptr2 is %p\n", iptr2);
  printf("iptr2's val is %d\n", *iptr2);
  return (EXIT_SUCCESS);
}
