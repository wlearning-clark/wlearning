
#include <chrono>
#include <functional>
#include <memory>
#include <utility>
#include <vector>
using namespace std;
#include <iostream>

int main(int argc, char** argv)
{
  auto a =  std::chrono::system_clock::now();
  auto b =  a.time_since_epoch();
  std::cout << b.count() << "ns" << std::endl;

  std::vector<int> v1(100000, 2000);
  std::vector<int> v2;
  auto begin = std::chrono::high_resolution_clock::now();
  v2 = v1;
  auto end = std::chrono::high_resolution_clock::now() - begin;

  auto c =   std::chrono::duration<double>(end).count();
  std::cout << c << std::endl;

  return (EXIT_SUCCESS);
}
