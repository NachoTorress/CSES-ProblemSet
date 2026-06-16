#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> grid(n);
    for (auto &i:grid)cin >> i;
    string res;
    res+=grid[0][0];
    vector<pair<int,int>>cur, nxt;
    cur.push_back({0,0});
    vector<vector<int>> mark(n, vector<int>(n, -1));
    int timer = 0;
    for (int step = 1; step <= 2*n-2; step++) {
        char best = 'Z';
        for (auto pos:cur) {
            int x=pos.first;
            int y=pos.second;
            if (x+1<n)
                best = min(best, grid[x+1][y]);
            if (y + 1 < n)
                best = min(best, grid[x][y+1]);
        }
        res+=best;
        nxt.clear();
        timer++;
        for (auto pos : cur) {
            int x = pos.first;
            int y = pos.second;
            if (x + 1 < n && grid[x+1][y]==best && mark[x+1][y] != timer) {
                mark[x+1][y] = timer;
                nxt.push_back({x+1, y});
            }
            if (y+1<n && grid[x][y+1]==best && mark[x][y+1] != timer) {
                mark[x][y+1] = timer;
                nxt.push_back({x, y+1});
            }
        }
        cur.swap(nxt);
    }
    cout << res;
}
