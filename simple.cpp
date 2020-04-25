#include <iostream>

#include "simple.h"

using namespace std;

Simple::Simple(int n) : a_(n) {
  cout << "Simple(" << a_ << ") constructor" << endl;
}

Simple::Simple(const Simple& rhs) {
  cout << "Simple(" << rhs.a_ << ") copy constructor" << endl;
  a_ = rhs.a_;
}