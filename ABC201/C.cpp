#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    set<int> must, may, none;
    rep(i, 10) {
        if (S[i] == 'o')
            must.insert(i);
        else if (S[i] == 'x')
            none.insert(i);
        else
            may.insert(i);
    }
    int ans = 0;
    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                rep(l, 10) {
                    set<int> tmp = {i, j, k, l};
                    bool ok = true;
                    for (auto x : must) {
                        if (tmp.count(x) == 0) ok = false;
                    }
                    for (auto x : none) {
                        if (tmp.count(x) != 0) ok = false;
                    }
                    if (ok) ans++;
                }
            }
        }
    }
    cout << ans << endl;
}