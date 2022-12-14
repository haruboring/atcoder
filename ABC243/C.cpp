#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> YXi(N);

    rep(i, N) {
        int x, y;
        cin >> x >> y;
        YXi[i] = make_tuple(y, x, i);
    }
    string S;
    cin >> S;
    sort(all(YXi));
    bool r = false;
    rep(i, N - 1) {
        if (get<0>(YXi[i]) == get<0>(YXi[i + 1])) {
            int index = get<2>(YXi[i]);
            if (r == false) {
                if (S[index] == 'R') {
                    r = true;
                }
            } else {
                if (S[index] == 'L') {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            index = get<2>(YXi[i + 1]);
            if (r == false) {
                if (S[index] == 'R') {
                    r = true;
                }
            } else {
                if (S[index] == 'L') {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        } else {
            r = false;
        }
    }
    cout << "No" << endl;
}