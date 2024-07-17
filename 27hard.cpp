#include <iostream>
#include <vector>
#include <set>
using namespace std;

signed main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<vector<pair<int,int>>> gr(n+1);
    int u, v, c;
    for (int i = 0; i < m; i++) {
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
    set<pair<int, int>> q;
    vector<int> dist(n + 1, 1000000000);
    dist[s] = 0;
    q.insert({ 0, s });
    while (!q.empty()) {
        v = q.begin()->second;
        q.erase(q.begin());
        for (auto i : gr[v]) {
            if (dist[i.first] > dist[v] + i.second) {
                q.erase({ dist[i.first], i.first });
                dist[i.first] = dist[v] + i.second;
                q.insert({ dist[i.first], i.first });
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (visit[i] == false && dist[i] == d) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
