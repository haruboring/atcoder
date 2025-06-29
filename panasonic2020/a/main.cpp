#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int K;
    cin >> K;

    string S = "1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51";
    vector<int> A(0);
    string t = "";
    rep(i, S.size()) {
        if (S[i] == ',') {
            i++;
            A.push_back(stoi(t));
            t = "";
            continue;
        }
        t += S[i];
    }
    A.push_back(stoi(t));

    cout << A[K - 1] << endl;
}
