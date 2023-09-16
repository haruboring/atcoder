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
    vector<int> A(N + 1), B(N + 1), ans(0), a(N + 1);
    rep(i, N - 1) {
        cin >> A[i + 2];
    }
    rep(i, N - 2) {
        cin >> B[i + 3];
    }
    a[2] = A[2];
    repp(i, 3, N + 1) {
        a[i] = min(a[i - 1] + A[i], a[i - 2] + B[i]);
    }
    int pos = N;
    while (1) {
        ans.push_back(pos);
        if (pos <= 1) {
            break;
        }
        if (a[pos] - a[pos - 1] == A[pos]) {
            pos--;
        } else {
            pos -= 2;
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}