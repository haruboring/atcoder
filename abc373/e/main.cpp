#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int rest = K - accumulate(all(A), 0LL);
    sort(all(A));

    vector<int> nes(N);  // 1e18までに必要な個数
    rep(i, N) {
        nes[i] = 1e18 - A[i];
        if (i > 0) nes[i] += nes[i - 1];
    }

    vector<int> ans(N);
    int already_lose = 0;
    int up_lose = 0;
    rep(i, N) {
        int st = A[i] + 1;
        int cnt = 0;
        repp(j, i+1, N){
            if (cnt + st - A[j] > rest) break;
            cnt += st - A[j];
            up_lose++;
        }
    }
}
