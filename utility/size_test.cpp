#include <iostream>
#include <type_traits>

using namespace std;


template<int n>
class Pointer {
public:
    typedef int Type;
};

template<>
class Pointer<8> {
public:
    typedef long Type;
};

template<>
class Pointer<4> {
public:
    typedef int Type;
};


int main() {
    int* a;
    cout << sizeof(Pointer<sizeof(a)>::Type) << endl;
}

