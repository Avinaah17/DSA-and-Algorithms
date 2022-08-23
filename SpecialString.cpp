    
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);
lli arr[100100];
lli brr[100100];
int n;
void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
pair<lli,lii> countInversion( int p , int r, int q) {

	int n1 = r-p+1;
	int n2 = q-r;
    lli cnt = 0;
	int arr1[n1],arr2[n2];

	for(int i =0 ; i<n1; i++) arr1[i] = arr[p+i];
	for(int i=0; i<n2; i++) arr2[i] = arr[r+1+i];

	int i = 0 , j = 0 , k = p;
    
    while(i < n1 && j < n2) {

    	if(arr1[i] <= arr2[j]) {

    		arr[k++] = arr[i++];
    	}
    	else {
    		arr[k++] = arr[j++];
    		cnt += r+1-(p+i);
    	}
    }
    while(i<n1) arr[k++] = arr1[i++];
    while(j < n2) arr[k++] = arr2[j++];
    return cnt;
}
pair<lli,lli> findInversioncount(int si , int ei) {

      if(si >= ei) {
      	pair<lli,lli> ans;
      	ans.first = 0;
      	ans.second = -1;
      	return ans;
      }
      lli cnt = 0;

      int mid = (si+ei)/2;
      cnt += findInversioncount(si,mid);
      cnt += findInversioncount(mid+1,ei); 
      cnt += countInversion(si,mid,ei);
      return cnt;
}
bool check(lli st, lli mid) {
    
    //int cnt = 1;
     //lli cnt = 0;
     lli cnt = findInversioncount(st,mid);
     cout <<arr[st] << cnt << endl;
     return cnt+1 <= brr[st];
}
void solve() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> brr[i];

    for(int st = 0; st < n ; st++) {

    	lli lo = st , hi = n, ans = -1;

    	while(lo <= hi) {

    		lli mid = (lo+hi)/2;
    		if(check(st,mid)) {
    			ans = mid;
    			hi = mid-1;
    		}
    		else lo = mid+1;
    	}
    //	if(ans == -1) cout << -1 << endl;
    //	cout << ans-(st-1) << endl;
    }
 //   for(auto it : v) cout << it <<" ";

}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   //int t; cin >> t;
   //while(t--)
    solve();
}