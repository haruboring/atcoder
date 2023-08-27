#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, L;
    cin >> N >> L;
    int K;
    cin >> K;
    vector<int> A(N+1);
    rep(i, N) cin >> A[i];
    A[N] = L;

    int left = 0, right = 1e9;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        int cnt = 0;
        int prev = 0;
        rep(i, N + 1) {
            if (A[i] - prev >= mid) {
                cnt++;
                prev = A[i];
            }
        }
        if (cnt >= K + 1) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;
}