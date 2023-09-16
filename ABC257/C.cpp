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
    string S;
    cin >> S;
    vector<int> W(N), ad(0), ch(0);
    rep(i, N) {
        cin >> W[i];
        if (S[i] == '0') {
            ch.push_back(W[i]);
        } else {
            ad.push_back(W[i]);
        }
    }
    sort(all(W));
    sort(all(ch));
    sort(all(ad));
    int correct = ad.size();
    int max_correct = correct;
    int index_ch = 0, index_ad = 0;
    rep(i, N) {
        if (int(ch.size()) > index_ch && ch[index_ch] < W[i] + 1) {
            correct++;
            index_ch++;
        }
        if (int(ad.size()) > index_ad && ad[index_ad] < W[i] + 1) {
            correct--;
            index_ad++;
        }
        max_correct = max(max_correct, correct);
    }
    cout << max_correct << endl;
}