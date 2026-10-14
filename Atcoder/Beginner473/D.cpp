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

void f(int idx , int n , int k , vector<int>&v){
	if(idx == n-1){
		if(k%(idx+1) == 0){
			for(auto &x:v) cout << x << " " ;
			cout << k/(idx+1) <<  endl;
		}
		return ;
	}
	for(int i=0;i<=k;i++){
		if(k-(idx+1)*i >= 0){
			v.push_back(i) ;
			f(idx+1,n,k-(idx+1)*i,v);
			v.pop_back() ;
		}
	}

}

void solve(){
	int n , k ; cin >> n >> k ;
	vector<int> v ;
	f(0 , n ,k, v);
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