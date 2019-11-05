#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>


int main(int argc, char* argv[]) {

    std::ofstream ofs("out.txt");
    int a = 3;
    double b = 4;
    ofs << a << "\n" << b << "\n";
    int d = 4;
    ofs.write(reinterpret_cast<char*>(&d), sizeof(d));
    char c = '\n';
    ofs.write(&c, sizeof(char));
    ofs.put('X');
    ofs.flush();
    ofs.close();

    std::ifstream ifs("out.txt");
    int e; double f;
    ifs >> e >> f;
    ifs.get();
    int g;
    ifs.read(reinterpret_cast<char*>(&g), sizeof(g));
    std::cout << e << " " << f << " " << e << std::endl;
    std::cout << std::boolalpha << ifs.eof() << std::endl;

    std::ofstream ofss("out.txt");
    std::vector<std::string> result {"Hello", "The", "World"};
    std::copy(result.begin(), result.end(), std::ostream_iterator<std::string>(ofss, "\n"));
    std::vector<int> result1 {1, 3, 5};
    std::copy(result1.begin(), result1.end(), std::ostream_iterator<int>(ofs, "\n"));

    return 0;
}
