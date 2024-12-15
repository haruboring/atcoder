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

    vector<int> v;
    repp(i, 1, 10) {
        rep(j, 10) {
            int x = i;
            rep(k, j) {
                x *= 10;
                x += i;
            }
            v.push_back(x);
        }
    }

    sort(all(v));

    cout << v[N - 1] << endl;
}
