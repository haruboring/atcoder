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

struct ZikuSolver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    ZikuSolver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    int high = 1000;
    vector<vector<int>> create_temperature() {
        vector<vector<bool>> visited(L, vector<bool>(L, false));
        queue<Pos> q;
        vector<vector<int>> temperature(L, vector<int>(L, 0));
        // (0. 0)が500度
        temperature[0][0] = high;  // cost: 500*500*4 = 1^6
        visited[0][0] = true;
        q.push({0, 0});

        int base = 0;
        vector<vector<int>> dydx = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            Pos now = q.front();
            q.pop();
            for (auto d : dydx) {
                Pos next = {(now.y + d[0] + L) % L, (now.x + d[1] + L) % L};
                if (visited[next.y][next.x]) continue;
                temperature[next.y][next.x] = int(0.35 * (temperature[now.y][now.x] + base));
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);

        set<int> rest;
        for (int i = 0; i < N; i++) rest.insert(i);

        int st = 850;
        for (int i_in = 0; i_in < N; i_in++) {
            map<int, Pos> mp;
            int max_temperature = 0;
            for (int i = 0; i < N; i++) {
                if (rest.count(i) == 0) continue;

                int y = landing_pos[i].y;
                int x = landing_pos[i].x;
                int dy, dx;

                dy = -y;
                dx = -x;

                int temperature = judge.measure(i_in, dy, dx);
                mp[temperature] = Pos{y, x};
                max_temperature = max(max_temperature, temperature);
                if (temperature > st) break;
            }

            Pos pos = mp[max_temperature];
            for (int i = 0; i < N; i++) {
                if (landing_pos[i].y == pos.y && landing_pos[i].x == pos.x) {
                    estimate[i_in] = i;
                    rest.erase(i);
                    break;
                }
            }
        }
        return estimate;
    }
};

struct BigSolver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    BigSolver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    int high = 1000;
    vector<vector<int>> create_temperature() {
        vector<vector<bool>> visited(L, vector<bool>(L, false));
        queue<Pos> q;
        vector<vector<int>> temperature(L, vector<int>(L, 0));
        // (0. 0)が500度
        temperature[0][0] = high;  // cost: 500*500*4 = 1^6
        visited[0][0] = true;
        q.push({0, 0});

        int base = 0;
        vector<vector<int>> dydx = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            Pos now = q.front();
            q.pop();
            for (auto d : dydx) {
                Pos next = {(now.y + d[0] + L) % L, (now.x + d[1] + L) % L};
                if (visited[next.y][next.x]) continue;
                temperature[next.y][next.x] = int(0.15 * (temperature[now.y][now.x] + base));
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);

        set<int> rest;
        for (int i = 0; i < N; i++) rest.insert(i);

        int cnt = 0;
        int tarinai = max(0, N * N - 10000);
        int st = 750 * 2;
        for (int i_in = 0; i_in < N; i_in++) {
            map<int, Pos> mp;
            int max_temperature = 0;
            for (int i = 0; i < N; i++) {
                if (rest.count(i) == 0) continue;

                if (cnt >= 10000) {
                    cnt = 11111;
                    break;
                }

                int y = landing_pos[i].y;
                int x = landing_pos[i].x;
                int dy, dx;

                dy = -y;
                dx = -x;

                int temperature = judge.measure(i_in, dy, dx);
                cnt++;

                if (cnt >= 10000) {
                    cnt = 11111;
                    break;
                }

                temperature += judge.measure(i_in, dy, dx);

                mp[temperature] = Pos{y, x};
                max_temperature = max(max_temperature, temperature);

                if (temperature > st) break;
            }

            if (cnt == 11111) {
                estimate[i_in] = *rest.begin();
                rest.erase(*rest.begin());
                continue;
            }
            Pos pos = mp[max_temperature];
            for (int i = 0; i < N; i++) {
                if (landing_pos[i].y == pos.y && landing_pos[i].x == pos.x) {
                    estimate[i_in] = i;
                    rest.erase(i);
                    break;
                }
            }
        }
        return estimate;
    }
};

struct MedSolver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    MedSolver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    int high = 1000;
    vector<vector<int>> create_temperature() {
        vector<vector<bool>> visited(L, vector<bool>(L, false));
        queue<Pos> q;
        vector<vector<int>> temperature(L, vector<int>(L, 0));
        // (0. 0)が500度
        temperature[0][0] = high;  // cost: 500*500*4 = 1^6
        visited[0][0] = true;
        q.push({0, 0});

        int base = 0;
        vector<vector<int>> dydx = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            Pos now = q.front();
            q.pop();
            for (auto d : dydx) {
                Pos next = {(now.y + d[0] + L) % L, (now.x + d[1] + L) % L};
                if (visited[next.y][next.x]) continue;
                temperature[next.y][next.x] = int(0.15 * (temperature[now.y][now.x] + base));
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);

        set<int> rest;
        for (int i = 0; i < N; i++) rest.insert(i);

        int cnt = 0;
        int tarinai = max(0, N * N - 10000);
        int st = 750 * 2;
        for (int i_in = 0; i_in < N; i_in++) {
            map<int, Pos> mp;
            int max_temperature = 0;
            for (int i = 0; i < N; i++) {
                if (rest.count(i) == 0) continue;

                if (cnt >= 10000) {
                    cnt = 11111;
                    break;
                }

                int y = landing_pos[i].y;
                int x = landing_pos[i].x;
                int dy, dx;

                dy = -y;
                dx = -x;

                int temperature = judge.measure(i_in, dy, dx);
                cnt++;

                if (cnt >= 10000) {
                    cnt = 11111;
                    break;
                }

                if (temperature < 270) continue;

                temperature += judge.measure(i_in, dy, dx);
                cnt++;

                mp[temperature] = Pos{y, x};
                max_temperature = max(max_temperature, temperature);

                if (temperature > st) break;
            }

            if (cnt == 11111) {
                estimate[i_in] = *rest.begin();
                rest.erase(*rest.begin());
                continue;
            }
            Pos pos = mp[max_temperature];
            for (int i = 0; i < N; i++) {
                if (landing_pos[i].y == pos.y && landing_pos[i].x == pos.x) {
                    estimate[i_in] = i;
                    rest.erase(i);
                    break;
                }
            }
        }
        return estimate;
    }
};

struct ExBigSolver {
    const int L;
    const int N;
    const int S;
    const vector<Pos> landing_pos;
    Judge judge;

    ExBigSolver(int L, int N, int S, const vector<Pos>& landing_pos) : L(L), N(N), S(S), landing_pos(landing_pos), judge() {
    }

    void solve() {
        const vector<vector<int>> temperature = create_temperature();
        judge.set_temperature(temperature);
        const vector<int> estimate = predict(temperature);
        judge.answer(estimate);
    }

    vector<vector<int>> create_temperature() {
        vector<vector<int>> temperature(L, vector<int>(L, 0));

        return temperature;
    }

    vector<int> predict(const vector<vector<int>>& temperature) {
        vector<int> estimate(N);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, N - 1);

        for (int i = 0; i < N; i++) {
            estimate[i] = dis(gen);
        }

        return estimate;
    }
};

int main() {
    int L, N, S;
    cin >> L >> N >> S;

    // 10 <= L <= 50, 2.5*10^3
    // Nは60 ~ 100
    // Sは標準偏差で、1から900まで

    vector<Pos> landing_pos(N);
    for (int i = 0; i < N; i++) {
        cin >> landing_pos[i].y >> landing_pos[i].x;
    }

    if (S > 800) {
        ExBigSolver solver(L, N, S, landing_pos);
        solver.solve();
    } else if (S > 350) {
        BigSolver solver(L, N, S, landing_pos);
        solver.solve();
    } else if (S > 200) {
        MedSolver solver(L, N, S, landing_pos);
        solver.solve();
    } else if (S > 3) {
        ZikuSolver solver(L, N, S, landing_pos);
        solver.solve();
    } else {
        Solver solver(L, N, S, landing_pos);
        solver.solve();
    }
}

/*
# MEMO

標準偏差について考える必要性がある
g++-13 -std=c++17 -I.. 1.cpp -o tools/a.out && cd tools && cargo run --release --bin tester ./a.out < in/0011.txt > out.txt && cd ..
幅大きめ→誤差を無視できるようにした、でもその文差がデカくなって配置コスト大
配置コストを削減してみる。間を埋めるように配置する→これだと評価下がった→配置コストを下げれば良さそ

Result:
123456789
884962963
2481

357533215

4,194,836,125
*/