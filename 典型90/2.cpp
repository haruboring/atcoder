#include "atcoder/all"
#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    queue<string> que, copy_que;
    que.push("");
    rep(i, N) {
        copy_que = que;
        while (!copy_que.empty()) {
            string s = copy_que.front();
            copy_que.pop();
            int left = 0, right = 0;
            for (char c : s) {
                if (c == '(')
                    left++;
                else
                    right++;
            }
            if (left < N / 2) {
                que.push(s + "(");
            }
            if (left > right) {
                que.push(s + ")");
            }
            que.pop();
        }
    }

    while (!que.empty()) {
        cout << que.front() << endl;
        que.pop();
    }
}