#include "atcoder/all"
#include "bits/stdc++.h"
#define int long long
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;

using SS = int;
SS op(SS a, SS b) {
    return SS(a * b);
}
SS e() {
    return SS(1);
}
using FF = int;
SS mapping(FF f, SS x) {
    return SS(f * x);
}
FF composition(FF f, FF g) {
    return FF(f * g);
}
FF id() {
    return FF(1);
}

signed main() {
    string S;
    cin >> S;

    vector<int> tmp;
    map<int, int> rl, lr;
    rep(i, S.size()) {
        if (S[i] == ')' || S[i] == '(') {
            tmp.push_back(0);
        } else if (islower(S[i])) {
            tmp.push_back(-1);
        } else {
            tmp.push_back(1);
        }
    }
    atcoder::lazy_segtree<SS, op, e, FF, mapping, composition, id> seg(tmp);

    stack<int> st;
    vector<pair<int, int>> v;
    vector<int> cnt(S.size(), 0);
    rep(i, S.size()) {
        if (S[i] == '(') {
            st.push(i);
        } else if (S[i] == ')') {
            v.push_back({st.top(), i});
            lr[st.top()] = i;
            rl[i] = st.top();
            cout << st.top() << " " << i << endl;
            st.pop();
        }
        cnt[i] = st.size();
    }

    int v_size = v.size();
    rep(_, v_size) {
        int l = v.back().first;
        int r = v.back().second;
        v.pop_back();
        seg.apply(l, r + 1, -1);
    }

    int i = 0;
    bool forward = true;
    vector<char> ans;
    int max_i = 0;
    rep(cnt, S.size()) {
        if (S[i] == '(' || S[i] == ')') {
            if (S[i] == '(' && forward) {
                i = lr[i];
                forward = false;
            } else if (S[i] == '(' && !forward) {
                i = lr[i];
                forward = true;
            } else if (S[i] == ')' && forward) {
                i = rl[i];
                forward = false;
            } else if (S[i] == ')') {
                i = rl[i];
                forward = true;
            }
        } else {
            char c = S[i];
            if (seg.get(i) == 1 && islower(c)) {
                c -= 32;
            } else if (seg.get(i) == -1 && isupper(c)) {
                c += 32;
            }
            cout << c;
        }

        if (forward) {
            i++;
        } else {
            i--;
        }
    }
    cout << endl;
}
