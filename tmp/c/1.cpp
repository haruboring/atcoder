#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, L;
    cin >> N >> M >> L;
    vector<pair<int, int>> A(N), B(M), oA, oB;
    rep(i, N) {
        cin >> A[i].first;
        A[i].second = i;
    }
    rep(i, M) {
        cin >> B[i].first;
        B[i].second = i;
    }
    oA = A, oB = B;
    vector<int> C(L), D(L);
    rep(i, L) cin >> C[i] >> D[i];

    set<tuple<int, int, int>> s;
    sort(all(A));
    sort(all(B));
    reverse(all(A));
    reverse(all(B));
    s.insert({A[0].first + B[0].first, A[0].second, B[0].second});
    int size = s.size();
    int ai = 0, bi = 0;
    while (size < L + 1) {
        if (ai >= N - 1) {
            bi++;
        } else if (bi >= M - 1) {
            ai++;
            bi = 0;

        } else if (A[ai + 1].first + B[bi].first < A[ai].first + B[bi + 1].first) {
            bi++;
        } else {
            ai++;
            bi = 0;
        }
        s.insert({A[ai].first + B[bi].first, A[ai].second, B[bi].second});
        size++;
    }

    rep(i, L) {
        if (s.count({oA[C[i] - 1].first + oB[D[i] - 1].first, C[i] - 1, D[i] - 1})) s.erase({oA[C[i] - 1].first + oB[D[i] - 1].first, C[i] - 1, D[i] - 1});
    }

    auto [ans, _, __] = *s.rbegin();
    cout << ans << endl;
}