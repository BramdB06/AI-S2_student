#include <iostream>
#include <vector>

class Base {
public:
    virtual void hello(){std::cout << "Hello from Base" <<std::endl;}
    virtual void bye(){std::cout << "Bye from Base" << std::endl;}
};

class Derived : public Base {
public:
    void hello() override{std::cout << "Hello from Derived" << std::endl;}
};

class D2 : public Base {
public:
    void bye() override{std::cout << "Bye from D2" << std::endl;}
};

int main() {
    Base* b     = new Base();
    Derived* d  = new Derived();
    Base* bd    = new Derived();
    Base* d2    = new D2();

    std::vector<Base*> v = {b, d, bd, d2};

    for (auto i : v) {
        i->hello();
        i->bye();
        std::cout << std::endl;
    }

}