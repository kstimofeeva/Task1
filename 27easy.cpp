#include <iostream>
#include <vector>
#include <queue>
using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> gr(n+1);
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
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
        for (int i : gr[v]) {
            if (dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                q.push(i);
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
