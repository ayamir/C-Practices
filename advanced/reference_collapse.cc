#include <iostream>
#include <ostream>

class Test {
public:
  Test() : Test(0) {}
  Test(int v) : v(v) {}
  friend std::ostream &operator<<(std::ostream &os, const Test &t) {
    return os << t.v;
  }
  friend std::istream &operator>>(std::istream &in, Test &t) {
    in >> t.v;
    return in;
  }

private:
  int v;
};

template <typename T> void f(T &v) { std::cout << v << std::endl; }

int main(int argc, char *argv[]) {
  Test a{10};
  f<Test &>(a);
  return 0;
}
