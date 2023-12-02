#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    vector<ll> dist(n, 1e18);
    dist[a] = 0;
    set<pair<ll, ll>> s1;
    s1.insert({0, a});
    while (!s1.empty()) {
        ll u = s1.begin()->second;
        s1.erase(s1.begin());
        for (auto elem : g[u]) {
            if (dist[elem.first] > dist[u] + elem.second) {
                s1.erase({dist[elem.first], elem.first});
                dist[elem.first] = dist[u] + elem.second;
                s1.insert({dist[elem.first], elem.first});
            }
        }
    }
    if (dist[b] == 1e18)
      cout << -1;
    else
      cout << dist[b] << endl;
    return 0;
}
