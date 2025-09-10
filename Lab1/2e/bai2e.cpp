#include <iostream>
using namespace std;

// Hàm tìm số lớn nhất trong 3 số
// Lỗi: không xử lý đúng khi có 2 số bằng nhau
int findMax(int num1, int num2, int num3) {
    int max = 0; // lỗi: gán sẵn 0
    if ((num1 > num2) && (num1 > num3)) max = num1;
    if ((num2 > num1) && (num2 > num3)) max = num2;
    if ((num3 > num1) && (num3 > num2)) max = num3;
    return max;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;  // nhập 3 số
    cout << findMax(a, b, c) << endl;
    return 0;
}