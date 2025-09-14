#include <iostream> 

using namespace std;
int min_num(int a) {
    int n{1};
    int del;
    int del_counter{0};
start:
    for(del = 1; del <= n; del++) {
        if(n%del==0) {
            del_counter++;
        }
    }
    if(del_counter == a) {
        return n;
    }
    else {
        n++;
        del_counter = 0;
        goto start;
    }
}


int main() {
    int k;
    cin >> k;
    cout << min_num(k) << endl;
    return 0;
}
