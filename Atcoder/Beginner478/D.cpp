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

void solve(){
	int n , q ; cin >> n >> q ;
	vector<vector<pair<int,int>>> v(q+1); 
	vector<int> pref(n+1,0) ;
	int t = q ;
	while(q--){
		int l , r, x ;
		cin >> l >> r >> x ;
		v[x].push_back({l,r});
	}
	for(int i=1;i<=t;i++){
		sort(v[i].begin(),v[i].end()) ;
	}
	for(int i=1;i<=t;i++){
		int mini = INT_MAX ;
		int maxi = INT_MIN ;
		if(v[i].size() > 0){
			mini = v[i][0].F ;
			maxi = v[i][0].S ;
		}		
		for(int j=1;j<v[i].size();j++){
			if(v[i][j].S > maxi && v[i][j].F <= maxi) maxi = v[i][j].S ;
			else if(v[i][j].F > maxi){
				pref[mini]++;
				if(maxi + 1 <= n) pref[maxi+1]-- ;
				mini = v[i][j].F ;
				maxi = v[i][j].S ;
			}
		}
		if(mini != INT_MAX) {pref[mini]++;
									if(maxi+1<=n) pref[maxi+1]--;}
	}

	for(int i=1;i<=n;i++) {pref[i]+=pref[i-1] ; cout << pref[i] << " " ;}


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