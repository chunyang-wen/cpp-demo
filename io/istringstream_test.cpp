#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(int argc, char* argv[]) {

    string a = "a b c";
    istringstream is(a);
    string in;
    while (true) {
        if (!(is >> in)){
            break;
        }
        cout << in << endl;
    }
    return 0;

}
