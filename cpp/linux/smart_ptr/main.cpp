
#include <memory>
#include <utility>
using namespace std;
#include <iostream>

struct Mystruct {
  Mystruct()
      : val { count }
  {
    std::cout << (void*)this << "Hello, " << val << std::endl;
    Mystruct::count++;
  }

  ~Mystruct()
  {
    std::cout << (void*)this << "Good bye, " << val << std::endl;
    Mystruct::count--;
  }

  private:
  int val;
  static int count;
};

int Mystruct::count = 0;

struct Myint {
  Myint(int i)
      : _i(i) { };

  ~Myint()
  {
    std::cout << "Good bye from " << _i << std::endl;
  }

  private:
  int _i;
};

int main(int argc, char** argv)
{
  int b = 11;
  int a = 32;
  std::unique_ptr<int> intptr(&a);
  std::cout << intptr.release() << endl;
  intptr.reset(&b);
  std::cout << *intptr.release() << endl;

  unique_ptr<Myint> umyint { new Myint(12) };
  std::cout << umyint.get() << std::endl;
  unique_ptr<Myint> umyint2 { std::move(umyint) };
  std::cout << umyint.get() << std::endl;
  std::cout << umyint2.get() << std::endl;
  {
    unique_ptr<Myint> c { new Myint(89) };
  }
  umyint2.reset(new Myint { 1879 });
  Myint* i = umyint2.release();
  delete i;

  // swap
  unique_ptr<Myint> p3 { new Myint(99) };
  unique_ptr<Myint> p4 { new Myint(399) };
  std::cout << "p3 is " << p3.get() << std::endl;
  std::cout << "p4 is " << p4.get() << std::endl;
  p3.swap(p4);
  std::cout << "p3 is " << p3.get() << std::endl;
  std::cout << "p4 is " << p4.get() << std::endl;
  // unique_ptr to array
  unique_ptr<Mystruct[]> oo{new Mystruct[4]};
  return (EXIT_SUCCESS);
}
