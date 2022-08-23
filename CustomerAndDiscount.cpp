    
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;
const int N = 1e5+10;
double long PI = acos(-1);
int arr[N];
int cost[N];
lli n,m,d;

void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}

bool check(lli x) {

	for(int i=0; i<x;i++) {
    //    cout << d << endl;
		d -= max(0,cost[i]-arr[n-x+i]);
		if(d < 0) return false;
	}
	return true;
}

void solve() {
    
    cin >> n >> m >> d;
    lli dis = d;

    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<m; i++) cin >> cost[i];

    sort(arr,arr+n);
    sort(cost,cost+m);

    lli lo = 0 , hi = min(n,m) ,ans = 0;
    lli sum = 0;
    while(lo <= hi) {

    	lli mid = (lo+hi)/2;
    	if(check(mid)){

    		ans  = mid;
    		lo = mid+1;
    	}
    	else hi = mid-1;
    }

    cout << ans << " ";
    for(int i=0; i<ans; i++) {
    	sum += cost[i];
    }
   // cout << sum << endl;
    //cout << d << endl;
    sum = max(0ll, sum-dis);
    cout << sum << endl;

}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   //int t; cin >> t;
   //while(t--)
    solve();
}