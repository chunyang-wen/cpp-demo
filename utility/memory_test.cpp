#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char* argv[]) {

    weak_ptr<int> wp;
    {
        shared_ptr<int> sp = make_shared<int>(3);
        wp = sp;
        cout << std::boolalpha << wp.expired() << endl;
        cout << "value: " << *wp.lock() << endl;
    }
    cout << std::boolalpha << wp.expired() << endl;
    return 0;
}
