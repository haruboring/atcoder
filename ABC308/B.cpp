#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> C(N);
    rep(i, N) cin >> C[i];
    vector<string> D(M);
    rep(i, M) cin >> D[i];
    vector<int> P(M + 1);
    rep(i, M + 1) cin >> P[i];

    set<string> dish;
    map<string, int> pay;
    rep(i, M) dish.insert(D[i]);
    rep(i, M) pay[D[i]] = P[i + 1];

    ll sum = 0;
    rep(i, N) {
        if (dish.count(C[i])) {
            sum += pay[C[i]];
        } else {
            sum += P[0];
        }
    }
    cout << sum << endl;
}