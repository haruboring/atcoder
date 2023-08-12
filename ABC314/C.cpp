#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> C(N);
    rep(i, N) cin >> C[i];

    map<int, vector<int>> same_color;
    rep(i, N) {
        same_color[C[i] - 1].push_back(i);
    }

    vector<int> ind(M, 0);
    vector<char> ans(N);
    rep(i, N) {
        int c = C[i] - 1;
        ind[c]++;
        ans[same_color[c][ind[c] % same_color[c].size()]] = S[i];
    }
    rep(i, N) {
        cout << ans[i];
    }
    cout << endl;
}