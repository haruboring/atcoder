#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
    int i = -1, j = 0;
    ll cnt = 0;
    while (1) {
        i++;
        if (i == N - 1) {
            break;
        }
        cnt += max((j - i - 1), 0);
        while (1) {
            j = max(j, i + 1);
            if (j == N) {
                break;
            }
            if (A[j] - A[i] <= K) {
                j++;
                cnt++;
            } else {
                break;
            }
        }
    }
    cout << cnt << endl;
}