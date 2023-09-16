#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

signed main() {
    string S;
    cin >> S;

    deque<char> deq;
    bool is_forward = true;

    rep(i, S.size()) {
        if (S[i] == 'R') {
            is_forward = !is_forward;
        } else {
            if (is_forward) {
                if (deq.empty()) {
                    deq.push_back(S[i]);
                } else {
                    if (deq.back() == S[i]) {
                        deq.pop_back();
                    } else {
                        deq.push_back(S[i]);
                    }
                }
            } else {
                if (deq.empty()) {
                    deq.push_front(S[i]);
                } else {
                    if (deq.front() == S[i]) {
                        deq.pop_front();
                    } else {
                        deq.push_front(S[i]);
                    }
                }
            }
        }
    }

    if (!is_forward) {
        reverse(all(deq));
    }

    for (char c : deq) {
        cout << c;
    }
    cout << endl;
}