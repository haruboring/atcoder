#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> XY(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        XY[i] = make_pair(x, y);
    }
    vector<pair<int, int>> L(N, make_pair(10000, 10000));
    L[0] = make_pair(0, 0);
    vector<int> Ly(N);
    rep(i,N){
        Ly[i]=L[i].second;
    }

    vector<int> dp(100000+100);
    int max_len = -1;
    sort(all(XY));
    rep(i, N) {
        int pos_x = lower_bound(L.begin(), L.end(), XY[i]) - L.begin();
        int pos = lower_bound(Ly.begin()+pos_x, Ly.end(), XY[i].second) - Ly.begin();
        dp[i] = pos;
        L[dp[i]] 
    }
    cout << max_len << endl;
}