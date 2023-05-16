#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> G(100000 + 10, vector<int>(0));
vector<int> depths(100000 + 10, 0);
vector<int> reefs(0);
vector<int> supers(100000 + 10);

// 葉と、それぞれの頂点の深さを求める
void dfs(int pos, int depth) {
    depths[pos] = depth;
    for (auto next_pos : G[pos]) {
        if (depths[next_pos] == 0) {
            supers[next_pos] = pos;
            dfs(next_pos, depth + 1);
        }
    }
    if (G[pos].size() == 1 && pos != 1) {
        reefs.push_back(pos);
    }
}

// 葉から遡って根まで上がりながらSetを埋めていく（大きい数から最大21個まで）
void insert_set(set<pair<int, int>> &S, pair<int, int> value) {
    pair<int, int> mini = *begin(S);
    if (value.first > mini.first) {
        S.insert(value);
    }
    if (S.size() > 21) {
        S.erase(mini);
    }
}
vector<set<pair<int, int>>> set_of_top20_values(100000 + 10, {make_pair(-1, -1)});
vector<int> X(100000 + 10);
void get_set(int pos, int child_pos = 0) {
    int depth = depths[pos];
    for (auto value : set_of_top20_values[child_pos]) {
        insert_set(set_of_top20_values[pos], value);
    }
    insert_set(set_of_top20_values[pos], make_pair(X[pos], pos));

    if (pos != 1) {
        get_set(supers[pos], pos);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    rep(i, N) {
        cin >> X[i + 1];
    }
    rep(i, N - 1) {
        int A, B;
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    vector<int> V(Q), K(Q);
    rep(i, Q) {
        cin >> V[i] >> K[i];
    }

    dfs(1, 1);

    for (auto reef : reefs) {
        get_set(reef);
    }

    rep(i, Q) {
        int cnt = 0;
        for (auto value : set_of_top20_values[V[i]]) {
            if (cnt == int(set_of_top20_values[V[i]].size()) - K[i]) {
                cout << value.first << endl;
                break;
            }
            cnt++;
        }
    }
}