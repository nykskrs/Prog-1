#include <iostream>

// 1.
class B1
{
public:
    virtual void vf() { std::cout << "B1::vf()\n"; }
    void f() { std::cout << "B1::f()\n"; }
};

// 2.
class D1 : B1
{
public:
    void vf() override { std::cout << "D1::vf()\n"; }
    void f() { std::cout << "D1::f()\n"; }
};

int main()
{
    // // 1.
    // B1 b;
    // b.vf();
    // b.f();

    // // 2.
    // D1 d;
    // d.vf();
    // d.f(); // inaccessible

    // // 3.
    // B1 &ref = d; // conversion to inaccessible base class is not allowed
    // ref.vf();
    // ref.f();

    // // 4.

    return 0;
}