#include <iostream>
using namespace std;

// Hàm f1 bị sai logic
int f1(int x) { 
    if (x > 10) {
        return 2 * x; 
    } else if (x > 0) {
        return -x; 
    } else {
        return 2 * x; // BUG: lẽ ra phải là -x
    }
}

int main() {
    int x;
    cin >> x;              // đọc 1 số nguyên
    cout << f1(x) << endl; // in kết quả
    return 0;
}