#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    vector<vector<int>> frnd(N + 1, vector<int>(0));
    rep(i, M) {
        cin >> A[i] >> B[i];
        frnd[A[i]].push_back(B[i]);
        frnd[B[i]].push_back(A[i]);
    }
    repp(i, 1, N + 1) {
        int cnt = 0;
        set<int> me_or_friend = {i};
        rep(j, frnd[i].size()) {
            me_or_friend.insert(frnd[i][j]);
        }
        rep(j, frnd[i].size()) {
            rep(k, frnd[frnd[i][j]].size()){
                if(me_or_friend.count(frnd[frnd[i][j]][k]) == false){
                    cnt++;
                    me_or_friend.insert(frnd[frnd[i][j]][k]);
                }
            }
        }
        cout << cnt << endl;
    }
}