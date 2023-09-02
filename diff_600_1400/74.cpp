#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int tmp = 0;
    multiset<int> cnts1;
    rep(i, N) {
        if (A[i] == 1)
            tmp++;
        else
            tmp--;
        cnts1.insert(tmp);
    }
    int seq1 = *rbegin(cnts1);
    tmp = 0;
    rep(i, N) {
        int cnt1 = *rbegin(cnts1);
        if (A[i] == 1)
            tmp++;
        else
            tmp--;
        seq1 = max(seq1, cnt1 - tmp);
        cnts1.erase(cnts1.find(tmp));
    }

    tmp = 0;
    multiset<int> cnts0;
    rep(i, N) {
        if (A[i] == 0)
            tmp++;
        else
            tmp--;
        cnts0.insert(tmp);
    }
    int seq0 = *rbegin(cnts0);
    tmp = 0;
    rep(i, N) {
        int cnt0 = *rbegin(cnts0);
        if (A[i] == 0)
            tmp++;
        else
            tmp--;
        seq0 = max(seq0, cnt0 - tmp);
        cnts0.erase(cnts0.find(tmp));
    }

    debug(seq0);
    debug(seq1);

    cout << seq0 + seq1 + 1 << endl;
}