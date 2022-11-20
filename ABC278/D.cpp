#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int Q;
    cin >> Q;
    vector<vector<ll>> qu(Q, vector<ll>(0));
    rep(i, Q) {
        ll st;
        cin >> st;
        qu[i].push_back(st);
        ll in, x;
        if (st == 2) {
            cin >> in >> x;
            qu[i].push_back(in);
            qu[i].push_back(x);
        } else {
            cin >> x;
            qu[i].push_back(x);
        }
    }
    ll add = 0;
    vector<map<ll, ll>> as(Q);
    ll cnt = 0;
    rep(i, Q) {
        if (qu[i][0] == 1) {
            cnt++;
            add = qu[i][1];
        } else if (qu[i][0] == 2) {
            if (as[cnt][qu[i][1]] == 0) {
                as[cnt][qu[i][1]] = 0;
            }
            as[cnt][qu[i][1]] += qu[i][2];
        } else {
            if (cnt == 0) {
                cout << A[qu[i][1]-1] + as[cnt][qu[i][1]] << endl;
            } else {
                cout << as[cnt][qu[i][1]] + add << endl;
            }
        }
    }
}