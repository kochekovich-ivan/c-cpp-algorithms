#include <iostream>
using namespace std;
template<typename T>
class SmartPointer {
public:
    explicit SmartPointer(T* ptr = nullptr) : ptr(ptr) {}

    // Delete copy constructor and copy assignment
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer& operator=(const SmartPointer&) = delete;

    // Move constructor
    SmartPointer(SmartPointer&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment
    SmartPointer& operator=(SmartPointer&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~SmartPointer() {
        delete ptr;
    }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

private:
    T* ptr;
};

struct MyClass {
    void hello() { cout << "Hello!\n"; }
};

int main() {
    SmartPointer<MyClass> sp(new MyClass());
    sp->hello();
}
