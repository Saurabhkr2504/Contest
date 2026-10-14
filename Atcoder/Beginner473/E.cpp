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
	int n ,k; cin >> n >>k;
	vector<int> v(n) ; 
	for(int i=0;i<n;i++) cin >> v[i] ;
	int sum = 0 ;
	int cnt = 0 ;
	map<int,int> mpp ;
	mpp[0] = -1 ;
	int maxi = 0 ;
	int prev = -1 ;
	for(int i=0;i<n;i++){
		sum = (sum+ v[i])%k ;
		if(mpp.find(sum%k) != mpp.end()){

			if(prev <= mpp[sum%k] || prev == -1){ cnt++ ;prev = i ;}

		}
		mpp[sum%k] = i ;
	}
	cout << cnt << endl;
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