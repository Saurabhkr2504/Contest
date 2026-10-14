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

static bool cmp( pair<int,int>&a , pair<int,int>&b){
	return (a.F)*(b.S) > (a.S)*(b.F) ;
}

void solve(){
	int n , v ; cin >> n >> v ;
	vector<int> h(n) ;
	for(int i=0;i<n;i++) cin >> h[i] ;
	int maxi = 0 ;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(i+j+k+3 <= v){
					maxi = max(maxi , h[i]+h[j]+h[k]) ;
				}
			}
		}
	}
	cout << maxi << endl;
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