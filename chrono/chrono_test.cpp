#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

void normal_clock() {
    // There are three kinds of clocks
    // system_clock: from system-wide realtime clock
    // steady_clock: monotonic clock will never be adjusted
    // high_resolution_clock: click with shortest tick
    // https://en.cppreference.com/w/cpp/chrono/system_clock
    using SystemClock = std::chrono::system_clock;
    using TimePoint = std::chrono::time_point<SystemClock, SystemClock::duration>;
    using TP = std::chrono::system_clock::time_point;
    TimePoint start = std::chrono::system_clock::now();
    std::vector<int> vec(32);
    // std::fill(vec.begin(), vec.end(), 1);
    std::iota(vec.begin(), vec.end(), 1);
    std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    TP end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << std::endl;
    std::time_t end_time_t = std::chrono::system_clock::to_time_t(end);
    std::cout << std::ctime(&end_time_t) << std::endl;
    std::cout << end.time_since_epoch().count() << std::endl;
}

void duration() {
    // https://en.cppreference.com/w/cpp/chrono/duration
    // template<class Rep, class Period = std::ratio<1>> class duration
    // Rep represents that type used to represent tick number
    // Period: tick period, std::ratio<1, 100> means 1/100 seconds per tick

    // common time
    // std::chrono::nanoseconds, microseconds, seconds, minutes, hours
    constexpr auto year = 31556952ll; // seconds in average Gregorian year

    using shakes = std::chrono::duration<int, std::ratio<1, 100000000>>;
    using jiffies = std::chrono::duration<int, std::centi>;
    using microfortnights = std::chrono::duration<float, std::ratio<14*24*60*60, 1000000>>;
    using nanocenturies = std::chrono::duration<float, std::ratio<100*year, 1000000000>>;

    std::chrono::seconds sec(1);

    std::cout << "1 second is:\n";

    // integer scale conversion with no precision loss: no cast
    std::cout << std::chrono::microseconds(sec).count() << " microseconds\n"
              << shakes(sec).count() << " shakes\n"
              << jiffies(sec).count() << " jiffies\n";

    // integer scale conversion with precision loss: requires a cast
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(sec).count()
              << " minutes\n";

    // floating-point scale conversion: no cast
    std::cout << microfortnights(sec).count() << " microfortnights\n"
              << nanocenturies(sec).count() << " nanocenturies\n";
}

int main() {

    normal_clock();
    duration();

    return 0;
}
