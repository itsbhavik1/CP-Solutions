#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<bool> vis(n + 1, false);

    int total = 0;
    long long ans = 0;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    for (auto x : adj[1]) {
        pq.push({x.second, x.first});
    }

    vis[1] = true;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int neigh = top.second;

        if (vis[neigh]) continue;

        vis[neigh] = true;
        total++;
        ans += cost;

        for (auto x : adj[neigh]) {
            if (!vis[x.first]) {
                pq.push({x.second, x.first});
            }
        }
    }

if (total == n - 1)
    cout << ans;
else
    cout << "IMPOSSIBLE";

    return 0;
}