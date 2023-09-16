#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    int cnt = 0;
    rep(i, N) {
        string number = to_string(i + 1);
        int sum = 0;
        rep(j, number.size()) {
            sum += (number[j] - '0');
        }
        if (A <= sum && sum <= B) {
            cnt += i + 1;
        }
    }
    cout << cnt << endl;
}