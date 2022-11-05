#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    int cnt = 0;
    repp(i, 1, N + 1) {
        repp(j, 1, N + 1) {
            if (0 < (K - (i + j)) && (K - (i + j)) < N + 1) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}