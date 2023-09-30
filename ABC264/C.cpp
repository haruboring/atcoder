#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H1, W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(i, H1) rep(j, W1) cin >> A[i][j];
    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(i, H2) rep(j, W2) cin >> B[i][j];

    vector<vector<int>> select_H(0), select_W(0);

    rep(i, (1LL << H1)) {
        bitset<10> bs(i);
        vector<int> tmp;
        rep(j, H1) {
            if (bs[j]) tmp.push_back(j);
        }
        if (tmp.size() == H2) select_H.push_back(tmp);
    }

    rep(i, (1LL << W1)) {
        bitset<10> bs(i);
        vector<int> tmp;
        rep(j, W1) {
            if (bs[j]) tmp.push_back(j);
        }
        if (tmp.size() == W2) select_W.push_back(tmp);
    }

    rep(i, select_H.size()) {
        sort(all(select_H[i]));
        rep(j, select_W.size()) {
            sort(all(select_W[j]));

            vector<vector<int>> C(H2, vector<int>(W2));
            rep(k, H2) rep(l, W2) {
                C[k][l] = A[select_H[i][k]][select_W[j][l]];
            }

            if (C == B) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}