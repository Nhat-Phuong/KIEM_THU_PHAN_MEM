#include <iostream>
#include <cmath>   // để dùng log và cos
using namespace std;

// Hàm f3 như đề
int f3(int x) {
    if (log(x * x * cos(x)) < 3 * x)
        return 2 * x;
    else
        return 2 * x;
}

int main() {
    int x;
    cin >> x;
    cout << f3(x) << endl;
    return 0;
}