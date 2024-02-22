#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> G(200000 + 100, vector<int>(0));
vector<int> depths(200000 + 100, 0);
vector<int> not_2_tops(0);
map<int, vector<int>> even_odd;
map<int, int> top_to_2_tops;
int number_of_2_tops = 0;
int cnt_invalid_tops = 0;
void dfs(int top, int ex_top = 0) {
    depths[top] = depths[ex_top] + 1;
    top_to_2_tops[top] = number_of_2_tops;
    if (depths[top] % 2 == 1) {
        even_odd[number_of_2_tops][1]++;
    } else {
        even_odd[number_of_2_tops][0]++;
    }
    for (auto next_top : G[top]) {
        if (depths[next_top] == 0) {
            dfs(next_top, top);
        } else {
            if (depths[top] % 2 == depths[next_top] % 2) {
                not_2_tops.push_back(top);
            }
        }
    }
}

void not_2(int top) {
    depths[top] = -2;
    cnt_invalid_tops++;

    for (auto next_top : G[top]) {
        if (depths[next_top] != -2) {
            not_2(next_top);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll ans = 0;
    repp(i, 1, N + 1) {
        if (depths[i] == 0) {
            number_of_2_tops++;
            even_odd[number_of_2_tops].push_back(0);
            even_odd[number_of_2_tops].push_back(0);
            dfs(i);
        }
    }
    for (auto not_2_top : not_2_tops) {
        if (depths[not_2_top] != -2) {
            not_2(not_2_top);
        }
    }

    int cnt_valid_tops = N - cnt_invalid_tops;
    repp(i, 1, N + 1) {
        if (depths[i] == -2) {
            cout << 0 << endl;
            return 0;
        }
        if (depths[i] % 2 == 1) {
            ans += (even_odd[top_to_2_tops[i]][0] - G[i].size());
            ans += (cnt_valid_tops - (even_odd[top_to_2_tops[i]][0] + even_odd[top_to_2_tops[i]][1]));
        } else {
            ans += (even_odd[top_to_2_tops[i]][1] - G[i].size());
            ans += (cnt_valid_tops - (even_odd[top_to_2_tops[i]][0] + even_odd[top_to_2_tops[i]][1]));
        }
    }
    cout << ans / 2 << endl;
}