#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main() {

    // auto fn = hash<str::string>()
    cout << hash<std::string>()("xxx") << endl;
    string a = "111";
    for (char c : a) {
        cout << c << endl;
    }

    return 0;
}
