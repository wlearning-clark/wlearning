#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <winnt.h>
#include <wtypesbase.h>

extern void hello_world();
extern void absolute_value();
extern LPLONG get_absolute_value_passptr(LPLONG);
extern LONG get_absolute_value_passval(LONG);
extern void sizeof_datatypes();

int main(int argc, char** argv)
{
  // hello_world();
  absolute_value();
  sizeof_datatypes();
  return (EXIT_SUCCESS);
}

void hello_world()
{
  printf("Hello World.\n");
}

void absolute_value()
{
  LONG the_answer = -41;
  LPLONG abs_val = get_absolute_value_passptr(&the_answer);
  LONG abs_val_ref = get_absolute_value_passval(the_answer);
  printf("the answer is: %ld, and the absolute value of it is %ld\n", the_answer, abs_val_ref);
}
LPLONG get_absolute_value_passptr(LPLONG val)
{
  LONG ret = *val;
  if (ret >= 0) {
    return val;
  }
  *val = ~(ret - 1); // return a -val if the val < 0
  return val;
}

LONG get_absolute_value_passval(LONG val)
{
  if (val >= 0) {
    return val;
  }
  val = ~(val - 1); // return a -val if the val < 0
  return val;
}

void sizeof_datatypes()
{
  unsigned long long ull;
  long double ld;
  LONG l; // same as signed int
  LONGLONG ll;
  INT i;
  INT16 i16;
  INT32 i32;
  INT64 i64;
  LONG32 l32;
  LONG64 l64;
  SHORT s;
  CHAR c;
  WCHAR wc;
  DWORD dw;
  DWORDLONG dwl;
  FLOAT f;
  FLOAT128 f128;
  DOUBLE d;

  printf("the size of unsigned long long is : %zd byte \n", sizeof(ull));
  printf("the size of long double is : %zd byte \n", sizeof(ld));
  printf("the size of LONG is : %zd byte \n", sizeof(l));
  printf("the size of LONGLONG is : %zd byte \n", sizeof(ll));
  printf("the size of INT is : %zd byte \n", sizeof(i));
  printf("the size of INT16 is : %zd byte \n", sizeof(i16));
  printf("the size of INT32 is : %zd byte \n", sizeof(i32));
  printf("the size of INT64 is : %zd byte \n", sizeof(i64));
  printf("the size of LONG32 is : %zd byte \n", sizeof(l32));
  printf("the size of LONG64 is : %zd byte \n", sizeof(l64));
  printf("the size of SHORT is : %zd byte \n", sizeof(s));
  printf("the size of CHAR is : %zd byte \n", sizeof(c));
  printf("the size of WCHAR is : %zd byte \n", sizeof(wc));
  printf("the size of DWORD is : %zd byte \n", sizeof(dw));
  printf("the size of DWORDLONG is : %zd byte \n", sizeof(dwl));
  printf("the size of FLOAT is : %zd byte \n", sizeof(f));
  printf("the size of FLOAT128 is : %zd byte \n", sizeof(f128));
  printf("the size of DOUBLE is : %zd byte \n", sizeof(d));
}
