#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>


int main(int argc, char* argv[]) {

    std::ofstream ofs("out.txt");
    std::ios::fmtflags flags = ofs.flags();
    int a = 3;
    ofs << std::setw(8) << std::setfill('-') << std::left << std::showbase << std::hex << a << "\n";

    ofs.width(4);
    ofs.fill('+');
    ofs.setf(std::ios::right|std::ios::showbase);
    ofs << a << "\n";

    double c = 3.4;
    ofs << std::showpos << std::showpoint << c << "\n";

    double e = 3.141592653;
    ofs.unsetf(std::ios::showpos);
    ofs << std::setprecision(3) << e << "\n";

    // reset flags
    ofs.flags(flags);
    double d = 3.4;
    ofs << d << "\n";

    ofs.flush();
    ofs.close();

    return 0;
}
