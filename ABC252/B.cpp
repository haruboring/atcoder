#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> A_i(N);
    rep(i, N) {
        cin >> A_i[i].first;
        A_i[i].second = i + 1;
    }
    vector<int> B(K);
    rep(i, K) {
        cin >> B[i];
    }
    sort(all(A_i));
    reverse(all(A_i));
    rep(i, N) {
        if (A_i[i].first == A_i[0].first) {
            rep(j, K) {
                if (A_i[i].second == B[j]) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}