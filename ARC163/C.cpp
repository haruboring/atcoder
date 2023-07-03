#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    rep(_, T) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << "Yes" << endl;
            cout << 1 << endl;
            continue;
        }
        if (N == 2) {
            cout << "No" << endl;
            continue;
        }

        vector<int> A(N);
        set<int> s;
        rep(i, N - 1) {
            A[i] = (i + 1) * (i + 2);
            s.insert(A[i]);
        }
        if (!s.count(N)) {
            cout << "Yes" << endl;
            A[N - 1] = N;
            rep(i, N) {
                cout << A[i] << " ";
            }
            cout << endl;
            continue;
        }
        vector<int> B(N);
        B[0] = 2;
        rep(i, N - 2) {
            B[i + 1] = 2 * (i + 1) * (i + 2);
        }
        B[N - 1] = 2 * (N - 1);
        cout << "Yes" << endl;
        rep(i, N) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
}