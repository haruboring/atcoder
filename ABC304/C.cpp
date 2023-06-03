#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];

    vector<bool> ans(N, false);
    queue<int> q;
    q.push(0);
    ans[0] = true;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        rep(i, N) {
            if (ans[i]) continue;
            if (pow(X[i] - X[now], 2) + pow(Y[i] - Y[now], 2) <= pow(D, 2)) {
                if (ans[i] == false) q.push(i);
                ans[i] = true;
            }
        }
    }

    rep(i, N) {
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}