#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(K + 1);
    rep(i, K + 1) {
        cout << "? ";
        rep(j, K) cout << (i + j) % (K + 1) + 1 << " ";
        cout << endl;

        int res;
        cin >> res;
        if (res == -1) return 0;

        A[i] = res;
    }

    vector<int> ans(N);

    int sum = 0;
    rep(i, K + 1) sum += A[i];
    rep(i, K + 1) {
        ans[i] = (sum - A[(i + 1) % (K + 1)]) % 2;
    }

    sum = 0;

    repp(i, K + 1, N) {
        int sum = 0;

        cout << "? ";
        repp(j, i + 1 - K, i + 1) {
            cout << j + 1 << " ";
            sum += ans[j];
        }
        cout << endl;

        int res;
        cin >> res;
        if (res == -1) return 0;

        ans[i] = (res != sum % 2);
    }

    cout << "! ";
    rep(i, N) cout << ans[i] << " ";
    cout << endl;
}