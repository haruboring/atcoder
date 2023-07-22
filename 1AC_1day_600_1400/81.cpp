#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    A[1] = 1;
    repp(i, 1, N) {
        for (int j = 2; i * j <= N; j++) {
            A[i * j] = A[i] + 1;
        }
    }
    repp(i, 1, N + 1) {
        cout << A[i] << " " << endl;
    }
}