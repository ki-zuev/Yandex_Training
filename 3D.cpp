using namespace std;
#include<tuple>
#include<vector>
#include<iostream>
vector<vector<tuple<int,int,int>>> graph;
vector<bool> used;
vector<int> d;
const int INF=1e9;
int n,m;
void dijkstra(int s)
{
	d[s]=0;
	for(int i=0; i<n; i++)
	{
		int min=-1;
		for(int j=0; j<n; j++)
		{
			if (!used[j] && (min==-1 || d[j]<d[min]))
			{min=j;}
		}
		if (d[min]==INF)
		{break;}
		used[min]=true;
		for (auto u : graph[min])
		{
			if (get<1>(u) >= d[min] && get<2>(u) < d[get<0>(u)])
			{d[get<0>(u)]=get<2>(u);}
		}
	}
}

int main()
{
	cin >> n;
	int s,f; cin >> s >> f; s--; f--;
	graph.resize(n);
	used.resize(n);
	d.resize(n,INF);
	int R; cin >> R;
	while(R--)
	{
		int a,t1,b,t2; cin >> a >> t1 >> b >> t2; a--; b--;
		graph[a].emplace_back(make_tuple(b,t1,t2));
	}
	dijkstra(s);
	cout << (d[f] == INF ? -1 : d[f]) << "\n";
}
