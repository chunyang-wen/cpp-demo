#include <array>
#include <fstream>
#include <iostream>
#include <string>

/* We assume there are 3 lines in test.txt
 * 1.3
 * 4
 * hello
 */

int main(int argc, char* argv[]) {

    std::string path = "data/test.txt";
    std::ifstream input(path, std::ios_base::in);
    double d1; input >> d1;
    input.get(); /* skip \n */
    char d2;
    char d3[2];
    input.get(d3, 2); // read count - 1 character */
    std::cout << "get(& char) d2: " << d3 << "\n";
    d2 = d3[0];
    input.putback(d2);
    input.get(d2);
    std::cout << "get(*ptr, count) d2: " << d2 << "\n";
    input.unget();
    input.read(reinterpret_cast<char*>(&d2), sizeof(d2));
    std::cout << "read(char*, count) d2: " << d2 << " gcount() = " << input.gcount() << "\n";


    input.get(); /* skip \n */
    std::array<char, 10> arr;
    input.getline(&arr[0], 10); /* default delimit: \n */
    std::cout << d1 << " " << d2 << " " << &arr[0] << std::endl;
    std::cout << std::boolalpha << "good = " << input.good() << " eof = " << input.eof() << std::endl;
    std::cout << "last: " << input.get() << std::endl;
    std::cout << std::boolalpha << "good = " << input.good() << " eof = " << input.eof() << std::endl;

    input.clear(); /* you should clear first, otherwise following code will fail */
    input.seekg(0, std::ios_base::seekdir::beg);
    std::cout << std::boolalpha << "good = " << input.good() << " eof = " << input.eof() << std::endl;
    std::string x;
    input >> d1 >> d2;
    input.get();
    // std::cout << "good: " << input.good() << " eof: " << input.eof() << " " << int(input.get()) << "\n";
    std::getline(input, x);
    std::cout.setf(std::ios_base::showbase, std::ios::hex);
    std::cout.setf(std::ios::hex, std::ios::showbase);
    std::cout << std::hex<<std::showbase<<"d1: " << d1 << " d2: " << d2 << " x: " << x << std::endl;
    std::cout << std::hex << std::showbase << 30 << "\n";
}
