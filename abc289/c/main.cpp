#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> C(M);
    vector<vector<int>> A(M, vector<int>(0));
    rep(i, M) {
        cin >> C[i];
        rep(j, C[i]) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    int cnt = 0;
    for (int i = 0; i < (1 << M); i++) {
        bitset<10> s(i);
        set<int> st;
        rep(j, M) {
            if (s.test(j)) {
                for (auto a : A[j]) {
                    st.insert(a);
                }
            }
        }

        if (st.size() == N) cnt++;
    }

    cout << cnt << endl;
}
