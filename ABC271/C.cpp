#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    set<ll> set_a;
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