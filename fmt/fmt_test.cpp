#include <iostream>

#include "fmt/format.h"

int main() {
    std::string s = fmt::format("Hello, {}!", "world");
    std::cout << s << std::endl;
    return 0;
}
