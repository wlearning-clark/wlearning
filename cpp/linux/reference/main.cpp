
#include <functional>
using namespace std;
#include <iostream>

int main(int argc, char** argv)
{
  int a = 2;
  std::cout << a << std::endl;
  int b = a;
  std::cout << b << std::endl;
  // change b
  b = 12;
  std::cout << b << std::endl;
  // the a has not change
  std::cout << a << std::endl;

  // reference 
  std::reference_wrapper<int> ra = a;
  std::cout << ra << std::endl;
  b = ra;
  std::cout << "b is " << b << std::endl;
  // change a to 99
  a = 99;
  std::cout << "b is " << b << std::endl;
  std::cout << "a is " << a << std::endl;
  // ra has been changed with a 
  std::cout << "ra is " << ra << std::endl;

  return (EXIT_SUCCESS);
}
