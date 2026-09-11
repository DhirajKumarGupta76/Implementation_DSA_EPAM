#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long minOdd = LLONG_MAX;
        long long maxEven = LLONG_MIN;

        for (int i = 1; i <= n; ++i) {
            long long w;
            cin >> w;   

            if (i % 2 == 1) minOdd = min(minOdd, w);
            else maxEven = max(maxEven, w);
        }

        if (n % 2 == 0 && minOdd - maxEven >= 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}