#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int T;
    cin >> T;
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int M;
    cin >> M;
    vector<int> B(M);
    rep(i, M) {
        cin >> B[i];
    }
    int A_index = 0, cnt = 0;
    rep(i, M) {
        while (A_index < N) {
            if (B[i] - A[A_index] >=0 && B[i] - A[A_index] <= T) {
                cnt++;
                A_index++;
                break;
            }
            A_index++;
        }
    }
    if (cnt == M) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}