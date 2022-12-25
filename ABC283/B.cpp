#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    rep(i, N) {
        cin >> A[i + 1];
    }
    int Q;
    cin >> Q;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int k, x;
            cin >> k >> x;
            A[k] = x;
        } else {
            int k;
            cin >> k;
            cout << A[k] << endl;
        }
    }
}