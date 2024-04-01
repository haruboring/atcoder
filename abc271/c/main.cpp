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
    vector<int> a(N);
    set<int> set_a;
    rep(i, N) {
        cin >> a[i];
        set_a.insert(a[i]);
    }
    sort(all(a));
    int cnt_sold_books = 0, cnt_bought_books = 0, cnt_read = 0;
    while (1) {
        if (N + cnt_bought_books - (cnt_sold_books + cnt_read) <= 0) {
            break;
        } else if (set_a.count(cnt_read + 1)) {
            cnt_read++;
        } else if (N + cnt_bought_books - (cnt_sold_books + cnt_read) > 2) {
            cnt_sold_books += 2;
            cnt_bought_books++;
            cnt_read++;
        } else if (N + cnt_bought_books - (cnt_sold_books + cnt_read) == 2) {
            cnt_read++;
            break;
        } else {
            break;
        }
    }
    cout << cnt_read << endl;
}