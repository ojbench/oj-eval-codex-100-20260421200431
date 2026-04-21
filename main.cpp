#include <bits/stdc++.h>
using namespace std;

static inline unsigned long long sum_proper_divisors(unsigned long long n) {
    if (n <= 1) return 0ULL; // proper divisors of 1 is empty
    unsigned long long sum = 1ULL; // 1 is always a proper divisor for n>1
    unsigned long long r = sqrtl((long double)n);
    for (unsigned long long i = 2; i <= r; ++i) {
        if (n % i == 0) {
            unsigned long long j = n / i;
            if (i == j) {
                sum += i;
            } else {
                sum += i + j;
            }
            if (sum > n) return sum; // early exit for abundant numbers
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;
    for (int k = 0; k < m; ++k) {
        unsigned long long n;
        cin >> n;
        unsigned long long s = sum_proper_divisors(n);
        cout << (s == n ? 1 : 0) << '\n';
    }
    return 0;
}

