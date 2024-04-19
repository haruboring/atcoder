#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    map<int, int> s2e;
    multiset<int> s;
    rep(i, N) {
        string ss = S[i].substr(0, 4);
        string es = S[i].substr(5, 4);

        int si = stoi(ss);
        si -= si % 5;
        if (si % 100 == 60) {
            si -= 60;
            si += 100;
        }

        int ei = stoi(es);
        ei += 4;
        ei -= ei % 5;
        if (ei % 100 == 60) {
            ei -= 60;
            ei += 100;
        }

        s.insert(si);
        s2e[si] = max(s2e[si], ei);
    }

    while (s.size() > 0) {
        int si = *s.begin();
        int ei = s2e[si];
        s.erase(s.find(si));
        while (s.size() > 0) {
            int another_si = *s.begin();
            if (another_si > ei) break;
            s.erase(s.find(another_si));
            ei = max(ei, s2e[another_si]);
        }
        cout << setfill('0') << setw(4) << si << "-" << setfill('0') << setw(4) << ei << endl;
    }
}
