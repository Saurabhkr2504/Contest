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

const int N = 2000200 ;
vector<pair<int,int>> tree(N) ;

void build(int node , int left , int right , string &s){
	if(left == right){
		tree[node].F = (s[left] == 'A' ? 1:-1);
		tree[node].S = (s[left] == 'A' ? 1 : -1);
		return ;
	}
	int mid = (left + right)/2 ;
	build(2*node , left , mid , s);
	build(2*node +1, mid+1 , right , s);
	tree[node].F = tree[2*node].F + tree[2*node+1].F ;
	tree[node].S = min(tree[2*node].S , tree[2*node].F + tree[2*node+1].S) ;
}

void update(int node , int left , int right , int idx , char val){
	if(left == right){
		tree[node].F = (val == 'A'?1:-1);
		tree[node].S = (val == 'A'?1:-1);
		return ;
	}
	int mid = (left + right)/2 ;
	if(idx <= mid) update(2*node , left , mid , idx , val);
	else update(2*node+1 , mid+1 , right , idx , val) ;
	tree[node].F = tree[2*node].F + tree[2*node+1].F ;
	tree[node].S = min(tree[2*node].S , tree[2*node].F + tree[2*node+1].S);
}

pair<int,int> query(int node , int left , int right , int l , int r){
	if(l <= left && right <=r){
		return tree[node] ;
	}
	int mid = (left + right)/2 ;
	if(r <= mid) return query(2*node , left , mid , l , r);
	if(l>mid) return query(2*node+1 , mid+1,right , l ,r);
	pair<int,int> lnode = query(2*node , left , mid , l , r);
	pair<int,int> rnode = query(2*node+1 , mid+1, right , l , r);
	pair<int,int> res ;
	res.F = lnode.F + rnode.F ;
	res.S = min(lnode.S , lnode.F + rnode.S) ;
	return res ;
}

void solve(){
	int n ; cin >> n ;
	string s ; cin >> s ;
	build(1,0,n-1,s);
	int q ; cin >> q;
	int t, l , r ;
	char c ;
	while(q--){
		cin >> t ;
		if(t == 1){
			cin >> l >> c ;
			s[l-1] = c ;
			update(1,0,n-1,l-1,c) ;
		}
		else{
			cin >> l >> r ;
			pair<int,int> res = query(1,0,n-1,l-1,r-1) ;
			if(res.S >= 0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
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


