#include <cstdlib>
#include <iostream>
#include <new>
#include <vector>

using namespace std;


template <class T>
struct Mallocator {
    typedef T value_type;

    Mallocator() = default;

    template <class U>
    Mallocator(const Mallocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout<< "User defined::allocate" << std::endl;
        if(n > std::size_t(-1) / sizeof(T)) throw std::bad_alloc();
        if(auto p = static_cast<T*>(std::malloc(n*sizeof(T)))) return p;
        throw std::bad_alloc();
    }
    void deallocate(T* p, std::size_t) noexcept {
        std::cout<< "User defined::deallocate" << std::endl;
        std::free(p); }
};
template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) { return true; }
template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) { return false; }

int main(int argc, char* argv[]) {

    vector<int, Mallocator<int> > array(3, 4);
    array.clear();


    return 0;
}
