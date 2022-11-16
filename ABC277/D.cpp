#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    map<ll, ll> m;
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        m[A[i]] += A[i];
        sum += A[i];
    }
    sort(all(A));
    A.erase(unique(A.begin(), A.end()), A.end());
    ll index = 1;
    ll summ = m[A[0]];
    ll mini = 10000000000;
    while (1) {
        // cout << mini << endl;
        mini = min((ll)max(sum - summ, (ll)0), mini);
        if (index == (ll)(A.size())) {
            break;
        }
        if (A[index % A.size()] % M == (A[(index - 1) % A.size()] + 1) % M) {
            summ += m[A[index]];
        } else {
            summ = m[A[index]];
        }
        index++;
    }
    cout << mini << endl;
}