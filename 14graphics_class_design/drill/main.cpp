#include <iostream>

// 1.
class B1
{
public:
    virtual void vf() { std::cout << "B1::vf()\n"; }
    void f() { std::cout << "B1::f()\n"; }
    virtual void pvf() = 0;
};

// 2.
class D1 : public B1
{
public:
    void vf() override { std::cout << "D1::vf()\n"; }
    void f() { std::cout << "D1::f()\n"; }
};

// 6
class D2 : public D1
{
public:
    void pvf() { std::cout << "D2::pvf()\n"; }
};

// 7
class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    std::string str = "something";
    void pvf() { std::cout << str << std::endl; }
};

class D22 : public B2
{
public:
    int num = 0;
    void pvf() { std::cout << num << std::endl; }
};

void f(B2 &b) { b.pvf(); }

int main()
{
    /*
    // 1.
    std::cout << "1" << std::endl;
    B1 b;
    b.vf();
    b.f();

    // 2.
    std::cout << "2" << std::endl;
    D1 d;
    d.vf();
    d.f();

    // 3.
    std::cout << "3" << std::endl;
    B1 &ref = d;
    ref.vf();
    ref.f();

    // 4.
    std::cout << "4" << std::endl;
    B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1 &ref1 = d1;
    ref1.vf();
    ref1.f();

    // 5
    // object of abstract class is not allowed
    */

    // 6
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();

    // 7
    D21 d21;
    D22 d22;

    f(d21);
    f(d22);

    return 0;
}
