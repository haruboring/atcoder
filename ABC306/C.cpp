#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(3 * N);
    rep(i, 3 * N) cin >> A[i];

    set<int> s;
    vector<pair<int, int>> ans(0);

    vector<int> a(0);
    rep(i, 3 * N) {
        if (s.count(A[i]) == 1) {
            a.push_back(A[i]);
            s.erase(A[i]);
        } else {
            s.insert(A[i]);
        }
    }
    rep(i, N) {
        cout << a[i] << " ";
    }
    cout << endl;
}