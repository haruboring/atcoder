#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    set<string> s = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    if (s.count(S))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}