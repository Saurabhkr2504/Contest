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

constexpr int MOD = 998244353 ;

void solve(){
	int n ; cin >> n  ;
	vector<int> v(n) ;
	for(int i=0;i<n;i++) cin >> v[i] ;
	int cnt = 1 ;
	stack<int> st ;
	vector<int> prev(n) ;
	 
	for(int i=1;i<n;i++){
		while(!st.empty() && v[st.top()] < v[i]) st.pop() ;
		if(st.empty()) prev[i] = 0 ;
		else prev[i] = st.top() ;
		st.push(i) ;		
		cnt = (cnt*(i-prev[i]))%MOD ;
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