#include <iostream>
using namespace std;

// Hàm f2 như đề
int f2(int x) { 
    if (x < 10)
        return 2 * x; 
    else if (x < 2) // Dead code, không bao giờ chạy
        return -x; 
    else
        return 2 * x;
}

int main() {
    int x;
    cin >> x;             // đọc 1 số nguyên
    cout << f2(x) << endl;
    return 0;
}
