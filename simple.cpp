#include <iostream>

#include "simple.h"

using namespace std;

Simple::Simple(int n) : a_{n} {
  cout << "Simple(" << a_ << ") constructor" << endl;
}

Simple::Simple(const Simple& rhs) {
  cout << "Simple(" << rhs.a_ << ") copy constructor" << endl;
  a_ = rhs.a_;
}

Simple::Simple(Simple&& rhs) noexcept : a_{rhs.a_} {
  cout << "Simple(" << a_ << ") move constructor" << endl;
  rhs.a_ = {};
}

void Simple::print() {
  cout << "Simple: a_= " << a_ << endl;
}