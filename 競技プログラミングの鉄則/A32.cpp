#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<bool> can_First_win(N+1, true);
    int get_min = min(A,B), get_max = max(A,B);
    repp(i,1,N+1){
        if(i <= get_min){
            can_First_win[i] = false;
        }
        else if(i>get_min && i <= get_max){
            can_First_win[i] = true;
        }
        
    }
}