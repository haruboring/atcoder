#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    vector<int> score(3), save_score(3);
    rep(i, 3) {
        cin >> score[i];
        save_score[i] = score[i];
    }
    sort(all(score));
    reverse(all(score));
    rep(i, 3) {
        rep(j, 3) {
            if (score[j] == save_score[i]) {
                cout << j + 1 << endl;
            }
        }
    }
}