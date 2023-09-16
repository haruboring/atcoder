#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H), T(H);
    rep(i, H) {
        cin >> S[i];
    }
    rep(i, H) {
        cin >> T[i];
    }

    vector<string> St(0), Tt(0);
    rep(i,W){
        string s = "";
        rep(j,H){
            s+=S[j][i];
        }
        St.push_back(s);
    }
    rep(i,W){
        string s = "";
        rep(j,H){
            s+=T[j][i];
        }
        Tt.push_back(s);
    }
    bool b = true;
    sort(all(Tt));sort(all(St));
    rep(i,W){
        if(Tt[i]!=St[i]){
            b=false;
        }
    }
    if(b){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}