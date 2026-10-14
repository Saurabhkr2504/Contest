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
	int n ; cin >> n ;
		int x ;
	int sum = 0 ;
	for(int i=0;i<n;i++){
		cin >> x ;
		if(i>=n/2) sum+= x;
	}
	cout << sum << endl;
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