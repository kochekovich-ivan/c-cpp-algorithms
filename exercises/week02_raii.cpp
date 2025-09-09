#include <iostream>
using namespace std;

class RAII_Example
{
private:
    int* data;
public:

    RAII_Example()
    {
        data = new int[10];
    }
    
    ~RAII_Example()
    {
        delete[] data;
    }
    
    int& operator[](size_t idx)
    {
        return data[idx];
    }
    
    const int& operator[](size_t idx) const
    {
        return data[idx];
    }
};

int main()
{
    RAII_Example test;
    test[0] = 10;
    test[5] = 12;
    cout << test[0] << " " << test[5] << endl;
   
    return 0;
}
