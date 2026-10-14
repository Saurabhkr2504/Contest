#include<bits/stdc++.h>
using namespace std;

#define itn int
#define int long long int
#define F first
#define S second
#define all(p) p.begin(),p.end()
#define allr(p) p.rbegin(),p.rend()
#define endl "\n"
#define pb push_back
#define sz(x) ((int)(x).size())

constexpr int MOD = 1000000007 ;

vector<vector<pair<int,int>>> adj , revadj ;
vector<int> topo , vis , vis2 ;

void dfs1(int nn){
	vis[nn] = 1 ;
	for(auto [tt,cc]:adj[nn]){
		if(!vis[cc]){
			dfs1(cc);
		}
	}
	topo.push_back(nn) ;
}

void dfs2(int nn , int a){
	vis2[nn] = a ;
	for(auto [tt,cc]:revadj[nn]){
		if(!vis2[cc]){
			dfs2(cc,a) ;
		}
	}
}

void solve(){
	int n , q ; cin >> n >> q ;
	vector<pair<int,int>> edge ;
	adj.resize(n+1) ;
	revadj.resize(n+1);
	vis.resize(n+1) ;
	vis2.resize(n+1);
	int t,u,v ;
	for(int i=0;i<q;i++){
		cin >> t >> u >> v ;
		adj[u].push_back({t,v});
		revadj[v].push_back({t,u}) ;
		if(t == 1) edge.push_back({u,v}) ;
	}

	// Write a algorithm to detect an SCC with an edge t = 1 ,
	// if it is present , then return 'NO' else 
	// find the toplogocal sort and give assign them the numbers ,
	// if SCC members equal weight 

	// Task 1-> find all the SCC , if t = 1 exist in cyle , answer NO 
	// Task 2-> find the topological sort of the graph . 
	// Task 2-> give the SCC equal value 
	// Task 3-> assign number as per topological sort 


	for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i) ;
	reverse(all(topo)) ;
	int a = 1 ;
	for(int i=0;i<n;i++){
		if(!vis2[topo[i]]){
			dfs2(topo[i], a++) ;
		}
	}

	for(auto [x,y]:edge){
		if(vis2[x] == vis2[y]){
			cout << "No\n" ;
			return ;
		}
	}
	cout << "Yes\n" ;

	for(int i=1;i<=n;i++){
		cout << vis2[i] << " " ;
	}

	









}

int32_t main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
	int t=1;//cin>>t;
	while(t--) solve();
	
}