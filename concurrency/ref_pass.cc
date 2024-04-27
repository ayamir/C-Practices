#include <functional>
#include <iostream>
#include <memory>
#include <thread>

class X {
   public:
    void do_lengthy_work();
};

void increament(int &n) { n++; }

void process_big_object(std::unique_ptr<X>);

int main(int argc, char *argv[]) {
    int n = 0;
    std::thread t1(increament, std::ref(n));
    if (t1.joinable()) {
        t1.join();
    }
    std::cout << "n = " << n << std::endl;
    X my_x;
    std::thread t2(&X::do_lengthy_work, &my_x);
    auto p = std::make_unique<X>();
    std::thread t3(process_big_object, std::move(p));
    return 0;
}
