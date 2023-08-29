#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    vector<ll> T(Q), X(Q);
    rep(i, Q) cin >> T[i] >> X[i];

    vector<ll> up(0), low(0);
    rep(i,Q){
        int t = T[i];
        int x = X[i];

        if(t==1){
            up.push_back(x);
        }
        else if(t==2){
            low.push_back(x);
        }
        else{
            int up_size = up.size();
            int low_size = low.size();
            if(x<=up_size){
                cout << up[up_size-x] << endl;
            }
            else{
                cout << low[x-up_size-1] << endl;
            }
        }
    }
}
