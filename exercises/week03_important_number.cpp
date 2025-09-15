#include <iostream>
using namespace std;

int important_num(int hmn, int hmsn, int* arrOfNums) {
    if (!(hmsn >= 2 && hmsn < hmn && hmn <= 1000000)) {
        cout << "invalid values" << endl;
        return -1;
    }

    for (int j = 0; j < hmn; j++) {
        if (arrOfNums[j] < 1 || arrOfNums[j] > 1000000000) {
            cout << "invalid values" << endl;
            return -1;
        }
    }

    int count = 1;
    for (int i = 1; i <= hmn; i++) {
        if (i < hmn && arrOfNums[i] == arrOfNums[i - 1]) {
            count++;
        }
        else {
            if (count != hmsn) {
                return arrOfNums[i - 1];
            }
            count = 1;
        }
    }
    return -1; 
}




int main() {
    int n;
    int k;
    cin >> n >> k;
    int* arr = new int[n];
    for (int i{ 0 }; i < n; i++) {
        cin >> arr[i];
    }
    cout << important_num(n, k, arr);
    return 0;
}
