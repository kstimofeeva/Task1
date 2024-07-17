#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> gr(n + 1);
    int u, v, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> c;
        gr[u].push_back({ v, c });
        gr[v].push_back({ u, c });
    }
    vector<bool> visit(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> v;
        visit[v] = true;
    }
    int s, d;
    cin >> s >> d;
    queue<int> q;
    vector<int> dist(n + 1, 1000000000);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto i : gr[v]) {
            if (dist[i.first] == 1000000000) {
                dist[i.first] = dist[v] + i.second;
                q.push(i.first);
            }
        }
    }
    vector<int> vc;
    for (int i = 1; i <= n; i++)
        if (visit[i] == false)
            vc.push_back(dist[i]);
    sort(vc.begin(), vc.end());
    cout << vc[d - 1];
    return 0;
}
