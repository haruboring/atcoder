#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<int> v = {A, B};

    rep(i, K) {
        if (v[i % 2] % 2 == 1) {
            v[i % 2]--;
        }

        v[i % 2] /= 2;
        v[(i + 1) % 2] += v[i % 2];
    }

    cout << v[0] << " " << v[1] << endl;
}
