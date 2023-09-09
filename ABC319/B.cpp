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

    string s = "";

    for (int i = 0; i <= N; ++i) {
        bool found = false;

        for (int j = 1; j <= 9; ++j) {
            if (N % j == 0 && i % (N / j) == 0) {
                s += to_string(j);
                found = true;
                break;
            }
        }

        if (!found) {
            s += "-";
        }
    }

    cout << s << endl;

    return 0;
}