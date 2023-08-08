#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

vector<int> par(200000 + 100);

void init(int n) {
    rep(i, n) par[i] = i;
}

int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

int unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
        return 0;
    } else {
        return par[rx] = ry;
    }
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    rep(i, N) cin >> S[i] >> T[i];

    map<string, int> mp;
    rep(i, N) mp[S[i]] = i;

    init(N);
    rep(i, N) {
        if (mp.count(T[i])) {
            if (root(i) != root(mp[T[i]])) {
                unite(i, mp[T[i]]);
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}