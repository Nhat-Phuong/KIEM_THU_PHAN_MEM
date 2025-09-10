#include <bits/stdc++.h>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) {
        return -1; // vô số nghiệm
    }
    if (a == 0 && b == 0) {
        return 0; // vô nghiệm
    }
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2 * a);
    double y2 = (-b - sqrt(delta)) / (2 * a);
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

static const double EPS = 1e-9;

bool almost_equal(double a, double b) {
    return fabs(a - b) < EPS;
}

void normalize(vector<double>& v) {
    for (auto &x : v) if (fabs(x) < EPS) x = 0.0;
    sort(v.begin(), v.end());
}

struct TestCase {
    double a, b, c;
    int expected_n;
    vector<double> expected_roots;
    string desc;
};

int main() {
    vector<TestCase> tests = {
        {0,0,0, -1, {}, "a=b=c=0 → vô số nghiệm"},
        {0,0,5, 0, {}, "a=b=0,c≠0 → vô nghiệm"},
        {0,1,-4, 2, {2,-2}, "a=0,b=1,c=-4 → x=±2"},
        {1,0,1, 0, {}, "x^4+1=0 → vô nghiệm thực"},
        {1,-5,4, 4, {2,-2,1,-1}, "x^4 - 5x^2 + 4=0 → (x=±1,±2)"},
        {1,0,0, 2, {0,0}, "x^4=0 → nghiệm kép x=0"},
    };

    int passed=0, failed=0;

    for (auto &tc : tests) {
        double out[4] = {NAN,NAN,NAN,NAN};
        int n = solveQuartic(tc.a, tc.b, tc.c, out);

        vector<double> got;
        if (n > 0) got.assign(out, out+n);

        vector<double> exp = tc.expected_roots;
        normalize(got);
        normalize(exp);

        bool ok = (n == tc.expected_n);
        if (ok && n > 0) {
            for (int i = 0; i < n; i++) {
                if (!almost_equal(got[i], exp[i])) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            cout << "[PASS] " << tc.desc << "\n";
            passed++;
        } else {
            cout << "[FAIL] " << tc.desc << "\n";
            cout << "  Input: a=" << tc.a << " b=" << tc.b << " c=" << tc.c << "\n";
            cout << "  Expected n=" << tc.expected_n << " roots=";
            for (auto v : exp) cout << v << " ";
            cout << "\n  Got n=" << n << " roots=";
            for (auto v : got) cout << v << " ";
            cout << "\n";
            failed++;
        }
    }

    cout << "\nSummary: " << passed << " passed, " << failed << " failed.\n";
    return failed == 0 ? 0 : 1;
}