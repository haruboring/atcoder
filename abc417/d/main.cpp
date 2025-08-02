#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

int N;
vector<int> P(10000 + 10), A(10000 + 10), B(10000 + 10);
vector<vector<int>> V(10000 + 10, vector<int>(500 + 10, 0));

signed main() {
    cin >> N;
    rep(i, N) cin >> P[i] >> A[i] >> B[i];
    int Q;
    cin >> Q;
    vector<int> X(Q);
    rep(i, Q) cin >> X[i];

    vector<int> t;
    int b = 0;
    rep(i, N) {
        b += B[i];
        t.push_back(b);
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int ten = 0; ten <= 500; ten++) {
            if (P[i] >= ten) {
                if (ten + A[i] <= 500) {
                    V[i][ten] = V[i + 1][ten + A[i]] + A[i];
                } else {
                    int idx = lower_bound(all(t), ten + A[i] - 500 + t[i]) - t.begin();
                    if (idx == N) {
                        V[i][ten] = A[i] - (t[N - 1] - t[i]);
                    } else {
                        V[i][ten] = V[idx + 1][ten + A[i] - (t[idx] - t[i])] + A[i] - (t[idx] - t[i]);
                    }
                }
            } else {
                V[i][ten] = V[i + 1][ten - min(B[i], ten)] - min(B[i], ten);
            }
        }
    }

    rep(i, Q) {
        if (X[i] > 500) {
            int idx = lower_bound(all(t), X[i] - 500) - t.begin();
            if (idx == N) {
                cout << X[i] - b << endl;
            } else {
                cout << V[idx + 1][X[i] - t[idx]] + X[i] - t[idx] << endl;
            }
        } else {
            cout << V[0][X[i]] + X[i] << endl;
        }
    }
}