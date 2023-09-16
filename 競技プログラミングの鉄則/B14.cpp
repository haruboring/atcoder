#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    int hlf = N / 2;
    vector<int> first_hlf(0), second_hlf(0);
    rep(i, 1 << hlf) {
        bitset<16> S(i);
        int sum = 0;
        rep(j, hlf) {
            if (S.test(j)) {
                sum += A[j];
            }
        }
        first_hlf.push_back(sum);
    }
    rep(i, 1 << (N - hlf)) {
        bitset<16> S(i);
        int sum = 0;
        rep(j, N - hlf) {
            if (S.test(j)) {
                sum += A[hlf + j];
            }
        }
        second_hlf.push_back(sum);
    }
    sort(all(second_hlf));
    rep(i, first_hlf.size()) {
        if (binary_search(second_hlf.begin(), second_hlf.end(), K - first_hlf[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}