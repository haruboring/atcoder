#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int dist(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    // get input
    int N, M, T, L_A, L_B;
    cin >> N >> M >> T >> L_A >> L_B;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> t(T);
    for (int i = 0; i < T; i++) {
        cin >> t[i];
    }

    vector<Point> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i].x >> P[i].y;
    }

    // construct and output the array A
    vector<int> A(L_A, 0);
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }
    for (int i = 0; i < L_A; i++) {
        cout << A[i];
        if (i < L_A - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }

    int pos_from = 0;

    for (int i = 0; i < T; i++) {
        int pos_to = t[i];

        // determine the path by DFS
        vector<int> path;
        vector<bool> visited(N, false);
        auto dfs = [&](auto &&self, int cur, int prev) -> bool {
            if (visited[cur]) {
                return false;
            }
            if (cur != pos_from) {
                path.push_back(cur);
            }
            visited[cur] = true;
            if (cur == pos_to) {
                return true;
            }
            // visit next city in ascending order of Euclidean distance to the target city
            vector<int> search_order = G[cur];
            sort(search_order.begin(), search_order.end(),
                 [&](const int &a, const int &b) {
                     return dist(P[a], P[pos_to]) < dist(P[b], P[pos_to]);
                 });
            for (int v : search_order) {
                if (v == prev) {
                    continue;
                }
                if (self(self, v, cur)) {
                    return true;
                }
            }
            path.pop_back();
            return false;
        };
        dfs(dfs, pos_from, -1);

        // for every step in the path, control the signal and move
        for (int u : path) {
            cout << 's' << ' ' << 1 << ' ' << u << ' ' << 0 << endl;
            cout << 'm' << ' ' << u << endl;
        }
        pos_from = pos_to;
    }
}
