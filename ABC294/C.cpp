#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C(N + M);
    rep(i, N) {
        cin >> A[i];
        C[i] = A[i];
    }
    rep(i, M) {
        cin >> B[i];
        C[N + i] = B[i];
    }
    sort(all(C));
    map<int, int> m;
    rep(i, N + M) {
        m[C[i]] = i + 1;
    }
    rep(i, N) {
        cout << m[A[i]] << " ";
    }
    cout << endl;
    rep(i, M) {
        cout << m[B[i]] << " ";
    }
}