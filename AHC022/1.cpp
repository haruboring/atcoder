#include "bits/stdc++.h"
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, m, n) for (int i = m; i < (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << endl
using namespace std;
using ll = long long;

struct Pos {
    int y, x;
};

struct Judge {
    void set_temperature(const vector<vector<int>>& temperature) {
        for (const vector<int>& row : temperature) {
            for (int i = 0; i < row.size(); i++) {
                cout << row[i] << (i == row.size() - 1 ? "\n" : " ");
            }
        }
        cout.flush();
    }

    int measure(int i, int y, int x) {
        cout << i << " " << y << " " << x << endl;  // endl does flush
        int v;
        cin >> v;
        if (v == -1) {
            cerr << "something went wrong. i=" << i << " y=" << y << " x=" << x << endl;
            exit(1);
        }
        return v;
    }

    void answer(const vector<int>& estimate) {
        cout << "-1 -1 -1" << endl;
        for (int e : estimate) {
            cout << e << endl;
        }
    }
};

struct Solver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    Solver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    int d = 2;

    vector<vector<int>> create_temperature() {
        vector<vector<int>> temperature(L, vector<int>(L, -1));
        vector<vector<bool>> visited(L, vector<bool>(L, false));
        queue<Pos> q;

        // set the temperature to i * 10 for i-th position
        for (int i = 0; i < N; i++) {
            // 1000まで。Nは60 ~ 100
            if (i > 1000 / d) break;
            temperature[landing_pos[i].y][landing_pos[i].x] = (i * d);
            visited[landing_pos[i].y][landing_pos[i].x] = true;
            q.push(landing_pos[i]);
        }

        int base = min(N, 1000 / d) * d / 2;
        vector<vector<int>> dydx = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            Pos now = q.front();
            q.pop();
            for (auto d : dydx) {
                Pos next = {(now.y + d[0] + L) % L, (now.x + d[1] + L) % L};
                if (visited[next.y][next.x]) continue;
                temperature[next.y][next.x] = (temperature[now.y][now.x] + base) / 2;
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                if (temperature[i][j] == -1) {
                    temperature[i][j] = base;
                }
            }
        }
        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);
        for (int i_in = 0; i_in < N; i_in++) {
            if (i_in > 1000 / d) {
                estimate[i_in] = N - 1;
                continue;
            }
            // you can output comment
            cout << "# measure i=" << i_in << " y=0 x=0" << endl;

            // if (4 * dis > d) {
            //     measured_value += judge.measure(i_in, 0, 0);
            //     measured_value += judge.measure(i_in, 0, 0);
            //     measured_value /= 3;
            // }
            int max_rep = 6;
            int sum_measured_value = 0;
            int ave = 0;
            for (int i = 0; i < max_rep; i++) {
                sum_measured_value += judge.measure(i_in, 0, 0);
                ave = sum_measured_value / (i + 1);
                if (i >= 4 && ave % d == 0) break;
            }

            int it = (ave + d / 2) / d;
            estimate[i_in] = min(max(it, 0), N - 1);
        }
        return estimate;
    }
};

int main() {
    int L, N, S;
    cin >> L >> N >> S;
    vector<Pos> landing_pos(N);
    for (int i = 0; i < N; i++) {
        cin >> landing_pos[i].y >> landing_pos[i].x;
    }

    Solver solver(L, N, S, landing_pos);
    solver.solve();
}

/*
# MEMO

標準偏差について考える必要性がある
g++-13 -std=c++17 -I.. 1.cpp -o tools/a.out && cd tools && cargo run --release --bin tester ./a.out < in/0011.txt > out.txt && cd ..
幅大きめ→誤差を無視できるようにした、でもその文差がデカくなって配置コスト大
配置コストを削減してみる。間を埋めるように配置する→これだと評価下がった→配置コストを下げれば良さそ



*/
