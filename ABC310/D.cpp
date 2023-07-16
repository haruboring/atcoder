
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int N, T, M;
vector<int> A(50), B(50);
vector<set<int>> S(10);
vector<set<int>> G(10);
int sized = 0;
int ans = 0;

void dfs(int p) {
    if (p == N) {
        if (sized == T) ans++;
        return;
    }
    rep(i, sized) {
        bool b = true;
        for (auto p_Gi : G[i]) {
            if (S[p_Gi].count(p)) {
                b = false;
            }
        }
        if (b) {
            G[i].insert(p);
            dfs(p + 1);
            G[i].erase(p);
        }
    }
    if (sized >= T) return;
    G[sized].insert(p);
    sized++;
    dfs(p + 1);
    sized--;
    G[sized].erase(p);
}

int main() {
    cin >> N >> T >> M;
    rep(i, M) cin >> A[i] >> B[i];

    rep(i, M) {
        S[A[i] - 1].insert(B[i] - 1);
        S[B[i] - 1].insert(A[i] - 1);
    }

    dfs(0);
    cout << ans << endl;
}