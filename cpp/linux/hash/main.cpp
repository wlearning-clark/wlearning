
#include <charconv>
using namespace std;
#include <iostream>

extern int myhash(const std::string& str){
  size_t v;
  size_t h = 2984732048498640947ULL;
  for (auto c: str){
    v = c << 0x10;
    v ^= h;
    v *= h;
  }
  v %= 0xffffffff;
  return v;
}

int main(int argc, char** argv)
{
  auto h1 = myhash("santehu");
  h1 = myhash("hello world");
  cout << "0x" << std::hex << h1 << endl;
  return (EXIT_SUCCESS);
}
