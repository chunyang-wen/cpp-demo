#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

void old_way() {
    std::srand(std::time(nullptr));
    std::cout << rand() << std::endl;
    std::cout << RAND_MAX << std::endl;
}

void new_way() {

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dis(1, 6);
    for (int i = 0; i < 10; ++i) {
        std::cout << dis(engine) << std::endl;
    }
    std::normal_distribution<> dis1(1, 6);
    for (int i = 0; i < 10; ++i) {
        std::cout << dis1(engine) << std::endl;
    }

    std::vector<int> vec{1,3,5};
    std::shuffle(std::begin(vec), std::end(vec), engine);
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, ","));
    std::cout << "\n";

}

int main() {

    old_way();
    new_way();
    return 0;
}
