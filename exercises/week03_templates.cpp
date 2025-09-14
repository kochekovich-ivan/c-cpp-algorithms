#include <iostream>

using namespace std;

template <typename T1, typename T2> 
void Sum(T1 a, T2 b) {
    cout << a << endl;
    cout << b << endl; 
}

template <typename C>
class box {
private:
    C value;
public:
    box(C val) : value(val) {}
    C get() {
        return value;
    }
};

int main() {
    Sum(10, 2.3);
    box<int> b1(20);
    cout << b1.get() << endl;
    return 0;
}
