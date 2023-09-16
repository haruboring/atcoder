#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;cin>>N;
    vector<int> P(N);
    rep(i,N){
        cin>>P[i];
    }
    int cnt = 0;
    rep(i,N-1){
        if(P[i]==i+1 && P[i+1]==i+2){
            int c = P[i];
            P[i] = P[i+1];
            P[i+1] = c;
            cnt++;
        }
    }
    rep(i,N){
        if(P[i]==i+1){
            cnt++;
        }
    }
    cout << cnt << endl;
}