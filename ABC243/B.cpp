#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        cin >> B[i];
    }
    int cnt = 0;
    rep(i, N) {
        if (A[i] == B[i]) {
            cnt++;
        }
    }
    int cntk = 0;
    rep(i, N) {
        rep(j, N) {
            if (A[i] == B[j]) {
                cntk++;
            }
        }
    }
    cout << cnt << " " << cntk - cnt << endl;
}