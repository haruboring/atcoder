#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> UV(200010, vector<int>(0));
vector<bool> visited(200010);
deque<int> path;
bool reach_goal = false;

void dfs(int position, int goal) {
    visited[position] = true;
    if(reach_goal == false){
        path.push_back(position);
    }
    if (position == goal) {
        reach_goal = true;
        return;
    }

    int dead_end = 0;
    rep(i, UV[position].size()) {
        if (visited[UV[position][i]] == false) {
            dfs(UV[position][i], goal);
            dead_end++;
        }
    }
    if (reach_goal == false) {
        path.pop_back();
    }
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    rep(i, N - 1) {
        int U, V;
        cin >> U >> V;
        UV[U].push_back(V);
        UV[V].push_back(U);
    }
    repp(i, 1, N + 1) {
        visited[i] = false;
    }
    dfs(X, Y);
    int path_size = path.size();
    rep(i, path_size) {
        cout << path.front() << " ";
        path.pop_front();
    }
    cout << endl;
}