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

    if (N == 1) {
        cout << "Not Prime" << endl;
        return 0;
    }

    int cnt = 0;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) cnt++;
    }
    if (cnt == 0) {
        cout << "Prime" << endl;
        return 0;
    }

    string S = to_string(N);
    int s = 0;
    rep(i, S.size()) s += S[i] - '0';
    if (N % 2 != 0 && N % 5 != 0 && s % 3 != 0) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }
}
