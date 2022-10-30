#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<pair<int, int>> A(N), B(N), AB(N);
    rep(i, N) {
        cin >> A[i].first;
        A[i].second = 10000 - i;
    }
    rep(i, N) {
        cin >> B[i].first;
        B[i].second = 10000 - i;
        AB[i].first = A[i].first + B[i].first;
        AB[i].second = 10000 - i;
    }
    set<int> pass;
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    sort(all(AB));
    reverse(all(AB));
    rep(i, X) {
        pass.insert(A[i].second);
    }
    int pass_Y_cnt = 0;
    rep(i, N) {
        if (pass_Y_cnt == Y) {
            break;
        }
        if (pass.count(B[i].second) == false) {
            pass_Y_cnt++;
            pass.insert(B[i].second);
        }
    }
    int pass_Z_cnt = 0;
    rep(i, N) {
        if (pass_Z_cnt == Z) {
            break;
        }
        if (pass.count(AB[i].second) == false) {
            pass_Z_cnt++;
            pass.insert(AB[i].second);
        }
    }

    while (pass.size()) {
        cout << (-1) * (*rbegin(pass) - 10000) + 1 << endl;
        pass.erase(*rbegin(pass));
    }
}