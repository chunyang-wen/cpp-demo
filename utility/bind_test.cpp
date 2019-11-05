#include <random>
#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void f(int n1, int n2, int n3, const int& n4, int n5) {
    cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}


struct Hello {
    void print_sum(int a, int b) {
        cout << a << " " << b << "\n";
    }
    bool operator()(const int& lhs, const int& rhs) {
        return lhs < rhs;
    }
};


int main()
{
    using namespace std::placeholders;  // for _1, _2, _3...
    int n = 7;
    auto f1 = bind(f, std::placeholders::_2, std::placeholders::_1, 42, cref(n), ref(n));
    n = 10;
    f1(1, 2, 1003);
    auto f2 = std::bind(less<int>(), std::placeholders::_1, 3);
    auto f3 = std::bind(less<int>(), _1, _2);
    cout << boolalpha << f2(5) << "\n";
    cout << boolalpha << f3(5, 6) << "\n";

    Hello hello;
    auto f4 = mem_fn(&Hello::print_sum);
    f4(hello, 4, 5);
    auto f5 = bind(&Hello::print_sum, hello, _1, 3);
    f5(1);


    std::vector<int> a {1,5,9};
    auto ff = std::bind(Hello(), _1, 3);
    std::replace_if(a.begin(), a.end(), ff, 0);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
}
