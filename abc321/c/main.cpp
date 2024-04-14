#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

vector<int> like(0);

signed main() {
    int K;
    cin >> K;

    for (int i = 1; i <= 9; i++) {
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int x = q.front();
            string xs = to_string(x);
            like.push_back(x);
            q.pop();

            for (int j = 0; j < xs[xs.size() - 1] - '0'; j++) {
                q.push(x * 10 + j);
            }
        }
    }

    sort(all(like));

    cout << like[K - 1] << endl;
}