#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    if (N <= 19) {
        vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99};
        debug(A.size());
        cout << A[N - 1] << endl;
        return 0;
    }
    N -= 20;
    int t = 10;
    while (N - 2 * (10 * t - t) >= 0) {
        N -= 2 * (10 * t - t);
        t *= 10;
    }

    if (N <= 10 * t - t) {
        string s = to_string(t + N);
        cout << s;
        reverse(all(s));
        cout << s.substr(1, s.size());
        cout << endl;
    } else {
        string s = to_string(t + N - (10 * t - t));
        cout << s;
        reverse(all(s));
        cout << s;
        cout << endl;
    }
}
