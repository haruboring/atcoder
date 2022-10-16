#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> not_duplicated_A(0);
    rep(i, N) {
        cin >> A[i];
    }
    A[N] = 1000000001;
    sort(all(A));
    vector<int> ans(0);
    int cnt = 1, not_duplicated_cnt = 0;
    rep(i, N) {
        if (A[i] != A[i + 1]) {
            ans.push_back(cnt);
            cnt = 1;
            not_duplicated_cnt++;
            not_duplicated_A.push_back(A[i]);
        } else {
            cnt++;
        }
    }
    rep(i, not_duplicated_cnt) {
        cout << ans[not_duplicated_cnt - i - 1] << endl;
    }
    rep(i, N - not_duplicated_cnt) {
        cout << 0 << endl;
    }
}