#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> kx(M, vector<int>(0));
    rep(i, M){
        int ki;
        cin >> ki;
        kx[i].push_back(ki);
        rep(j, ki){
            int xi;
            cin >> xi;
            kx[i].push_back(xi);
        }
    }
    set<pair<int, int>> S;
    rep(i, M){
        rep(j, kx[i].size() - 2){
            rep(k, kx[i].size() - 2 - j){
                pair<int, int> p = make_pair(kx[i][j + 1], kx[i][j + k + 2]);
                S.insert(p);
            }
        }
    }
    if(int(S.size()) == N*(N-1)/2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}