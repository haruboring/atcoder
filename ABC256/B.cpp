#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int cnt = 0, ans = N;
    reverse(all(A));
    rep(i, N) {
        if (cnt >= 4) {
            ans++;
            break;
        }
        cnt += A[i];
        ans--;
    }
    cout << ans << endl;
}