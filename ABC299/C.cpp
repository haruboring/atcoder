#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = -1;
    int cnt = 0;
    rep(i, N) {
        if (S[i] == 'o') {
            cnt++;
        } else {
            if(cnt == 0){
                cnt--;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cnt = 0;
    reverse(all(S));
    rep(i, N) {
        if (S[i] == 'o') {
            cnt++;
        } else {
            if(cnt == 0){
                cnt--;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;
}