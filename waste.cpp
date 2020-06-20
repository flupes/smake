#include <vector>
#include <iostream>

#include "simple.h"

using namespace std;

int main() {
  vector<Simple> v;
  // v.reserve(3);
  cout << "==> push back a first element:" << endl;
  v.push_back(Simple(1));
  cout << "==> push back a second element:" << endl;
  v.push_back(Simple(2));
  cout << "First element is copied again: what a waste!" << endl;
  cout << "Please implement a move constructor next time ;-)" << endl;
  Simple s1{3};
  auto s2 = s1;
  s1.print();
  Simple s3{4};
  auto s4 = std::move(s3);
  s3.print();
  s4.print();
}