#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    vector<string> hitigosan = {"7", "5", "3"};
    repp(keta, 1, 9 + 1) {
        rep(i, pow(3, keta)) {
            string s = "";
            int copy_i = i;
            set<int> appear;
            rep(_, keta) {
                s += hitigosan[copy_i % 3];
                appear.insert(copy_i % 3);
                copy_i /= 3;
            }
            if (stoll(s) <= N && appear.size() == 3) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}