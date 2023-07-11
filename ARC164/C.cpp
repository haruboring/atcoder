#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    multiset<pair<int, int>> cards;
    rep(i, N) {
        cards.insert({A[i] - B[i], A[i]});
    }

    ll ans = 0;
    while (!cards.empty()) {
        auto [d1, a1] = *cards.rbegin();
        int b1 = a1 - d1;
        cards.erase(cards.find({d1, a1}));
        cards.insert({-d1, b1});

        auto [d2, a2] = *cards.rbegin();
        cards.erase(cards.find({d2, a2}));
        ans += a2;
    }

    cout << ans << endl;
}