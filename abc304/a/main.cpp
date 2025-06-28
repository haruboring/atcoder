#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> S[i] >> A[i];

    vector<pair<int, int>> V(N);
    rep(i, N) V[i] = {A[i], i};
    sort(V.begin(), V.end());

    for (int i = V[0].second; i < V[0].second + N; i++) cout << S[i % N] << endl;
}
