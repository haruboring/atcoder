#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    set<int> A;
    rep(i, M) {
        int a;
        cin >> a;
        A.insert(a);
    }
    vector<int> V = {};
    repp(i, 1, N + 1) {
        V.push_back(i);
        if (A.count(i) == false) {
            sort(all(V));
            reverse(all(V));
            rep(i, V.size()) {
                cout << V[i] << " ";
            }
            V = {};
        }
        if (i == N) {
            sort(all(V));
            reverse(all(V));
            rep(i, V.size()) {
                cout << V[i] << " ";
            }
            V = {};
        }
    }
    cout << endl;
}