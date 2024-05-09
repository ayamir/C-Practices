#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Vector {
public:
  Vector() : capacity(10), length(0), base(new T[capacity]) {}
  Vector(int capacity) : capacity(capacity), length(0), base(new T[capacity]) {}
  ~Vector() {
    delete[] base;
    length = capacity = 0;
  }
  void push_back(T ele) {
    if (length == capacity) {
      resize(capacity * factor);
    }
    *(base + length) = ele;
    length++;
  }
  void pop_back() {
    if (length == 0) {
      throw std::out_of_range("Vector is empty");
    }
    length--;
  }
  const int size() const { return length; }
  T &operator[](int index) {
    if (index > length)
      throw std::out_of_range("index out of range");
    return *(base + index);
  }

private:
  void resize(int newCapacity) {
    T *newBase = new T[newCapacity];
    for (size_t i = 0; i < length; i++) {
      *(newBase + i) = *(base + i);
    }
    delete[] base;
    base = newBase;
    capacity = newCapacity;
  }

  const int factor = 2;
  size_t capacity;
  size_t length;
  T *base;
};

int main(int argc, char *argv[]) {
  Vector<int> vec{};
  vec.push_back(1);
  cout << vec.size() << endl;
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }

  return 0;
}
