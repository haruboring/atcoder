#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string X;
    cin >> X;

    reverse(all(X));

    vector<int> A(0);
    rep(i, X.size()) {
        A.push_back(X[i] - '0');
    }

    int sum = accumulate(all(A), 0LL);
    int cre = 0;
    vector<int> ans(0);
    rep(i, A.size()) {
        int tmp = sum + cre;

        ans.push_back(tmp % 10);
        cre = tmp / 10;
        sum -= A[i];
    }
    if (cre > 0) ans.push_back(cre);

    reverse(all(ans));
    for (int a : ans) cout << a;

    cout << endl;
}
