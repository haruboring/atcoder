#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    reverse(all(A));

    rep(i, min(K, N)) {
        A.pop_back();
    }

    reverse(all(A));
    rep(i,min(K,N)){
        A.push_back(0);
    }
    rep(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
}