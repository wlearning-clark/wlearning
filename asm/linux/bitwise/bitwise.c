

#include <stdio.h>
int main()
{
  printf("binary of 7: %0b\n", 7);
  printf("binary of -7: %0b\n", -7);
  printf("binary of ~7: %0b\n", ~7);
  printf("binary of ~(-7): %0b\n", ~(-7));
  return ~(7);
}
