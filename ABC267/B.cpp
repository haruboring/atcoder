#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    vector<vector<int>> pin_arrangement = {{7}, {4}, {2, 8}, {1, 5}, {3, 9}, {6}, {10}};
    bool left = false, right = false, space = false;
    if (S[0] == '1') {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 7) {
        int cnt = 0;
        rep(j, pin_arrangement[i].size()) {
            if (S[pin_arrangement[i][j] - 1] == '1') {
                left = true;
                cnt++;
            }
            if (space && S[pin_arrangement[i][j] - 1] == '1') {
                right = true;
            }
        }
        if (left && cnt == 0) {
            space = true;
        }
    }
    if (left && space && right) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}