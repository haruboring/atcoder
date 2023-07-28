#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> TS(N);
    rep(i, N) {
        string name;
        int height;
        cin >> name >> height;
        TS[i] = make_pair(height, name);
    }
    sort(all(TS));
    reverse(all(TS));

    cout << TS[1].second << endl;
}