#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;

    rep(i, T) {
        int size;
        cin >> size;
        string s;
        cin >> s;

        vector<string> ans(0);
        string rest = "";
        while (s.size() > 0) {
            string st = s.substr(0, 1);
            string anst = s.substr(1, s.size() - 1);
            while (anst.size() > 0) {
                if (rest < st && st < anst) {
                    if (i == 3) {
                        debug(st);
                    }
                    break;
                }
                st += anst.substr(0, 1);
                anst = anst.substr(1, anst.size() - 1);
            }
            ans.push_back(st);
            rest = st;
            s = s.substr(st.size(), s.size() - st.size());
        }
        if (ans.size() < 2) {
            cout << "No" << endl;
        } else {
            bool b = true;
            rep(i, ans.size() - 1) {
                if (ans[i] >= ans[i + 1]) {
                    cout << "No" << endl;
                    b = false;
                    break;
                }
            }
            if (b) {
                cout << "Yes" << endl;
            }
        }
    }
}