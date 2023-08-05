#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    vector<int> NG(3);
    cin >> N >> NG[0] >> NG[1] >> NG[2];
    set<int> ng = {NG[0], NG[1], NG[2]};
    int loc = N, cnt = 0;
    if (ng.count(N)) {
        cout << "NO" << endl;
        return 0;
    }
    while (loc > 0) {
        if (cnt > 99) {
            cout << "NO" << endl;
            return 0;
        }
        if (ng.count(loc - 3)) {
            if (ng.count(loc - 2)) {
                if (ng.count(loc - 1)) {
                    cout << "NO" << endl;
                    return 0;
                } else {
                    loc -= 1;
                    cnt++;
                }
            } else {
                loc -= 2;
                cnt++;
            }
        } else {
            loc -= 3;
            cnt++;
        }
    }
    cout << "YES" << endl;
}