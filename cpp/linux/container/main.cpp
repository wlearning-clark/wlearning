
#include <array>
#include <cstdio>
#include <numeric>
#include <utility>
using namespace std;
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main(int argc, char** argv)
{
  vector<int> vc1 { 2, 9, 18, 33, 70 };
  map<string, int> m1 { { "boook", 199 }, { "cute", 18 }, { "quotion", 1897 } };
  for (auto v : m1)
    std::cout << v.first << "-" << v.second << std::endl;
  for (auto v : vc1)
    std::cout << v << std::endl;

  // size
  vector<int> vc2 = vc1;
  std::cout << "vc1's size " << vc1.size() << endl;
  std::cout << "vc1's max_size " << vc1.max_size() << endl;
  std::cout << "vc2's size " << vc2.size() << endl;

  vector<int> vc3 = std::move(vc2);
  std::cout << "vc1's size " << vc1.size() << endl;
  std::cout << "vc2's size " << vc2.size() << endl;
  std::cout << "vc3's size " << vc3.size() << endl;

  vc3.clear();
  std::cout << "vc3's size " << vc3.size() << endl;

  // set
  set<int> iset { 19, 8 };

  cout << "iset.empty: " <<  iset.empty() << endl;
  iset.clear();
  cout << "iset.empty: " <<  iset.empty() << endl;

  // assess
  std::vector<int> ivect;
  ivect.assign({12, 99, 73, 55});
  cout << "ivect.size() : " << ivect.size() << endl;
  for (auto v : ivect) cout << v << " ";  // 12 99 73 55
  ivect.insert(ivect.begin(), 0);
  puts("");
  for (auto v : ivect) cout << v << " ";  // 0 12 99 73 55
  ivect.pop_back();                                              
  puts("");
  for (auto v : ivect) cout << v << " ";  // 0 12 99 73
  puts("");
  // compare
  vector<int> iv2{12, 81, 74 , 11};
  vector<int> iv3{12, 81, 74 , 11};

  cout << (iv2 == iv3) << endl;
  
  set<int> s1{2, 1, 3, 4};
  set<int> s2{1, 2, 3, 4};
  cout << (s1 == s2) << endl;
  set<int> s3{2, 3, 4};
  set<int> s4{1, 2, 3, 4};
  cout << (s3 > s4) << endl;

  // array
  std::array<int,4> a1{18, 90, 19, 3};
  auto sum =  std::accumulate(a1.begin(),a1.end(),0);
  cout << "sum of a1 is " << sum << endl;

  return (EXIT_SUCCESS);
}
