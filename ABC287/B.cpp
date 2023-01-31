#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    rep(i, N) {
        cin >> S[i];
    }
    rep(i, M) {
        cin >> T[i];
    }
    int cnt = 0;
    rep(i, N) {
        rep(j, M) {
            if (S[i][3] == T[j][0] && S[i][4] == T[j][1] && S[i][5] == T[j][2]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}