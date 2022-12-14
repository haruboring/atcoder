#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    int cnt = 0;
    rep(i, N - 1) {
        repp(j, i + 1, N) {
            int unslv = 0;
            rep(k, M) {
                if (S[i][k] == S[j][k] && S[j][k] == 'x') {
                    unslv++;
                }
            }
            if (unslv == 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}