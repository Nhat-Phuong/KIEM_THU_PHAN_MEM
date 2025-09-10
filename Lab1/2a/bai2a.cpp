#include <iostream>
using namespace std;

// Hàm f1 theo đề
int f1(int x) {
    if (x > 10)
        return 2 * x;    // Nếu x > 10 thì nhân đôi
    else
        return -x;       // Nếu x <= 10 thì lấy số đối
}

int main() {
    int x;
    cin >> x;             // Đọc 1 số nguyên từ stdin
    cout << f1(x) << endl; // In kết quả
    return 0;
}