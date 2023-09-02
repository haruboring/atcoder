#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, size;
    cin >> N;
    vector<int> A(N), cnt(N);
    vector<vector<int> > b(N);
    int ans = N;
    rep(i, N) {
        cin >> A[i];
        A[i]--;
        cnt[A[i]]++;
    }
    rep(i, N) {
        if (cnt[i] == 0) {
            ans--;
            b[0].push_back(i);
        }
    }
    rep(i, N - 1) {
        size = b[i].size();
        if (size == 0) break;
        rep(j, size) {
            cnt[A[b[i][j]]]--;
            if (cnt[A[b[i][j]]] == 0) {
                ans--;
                b[i + 1].push_back(A[b[i][j]]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}