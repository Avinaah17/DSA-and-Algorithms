// Description

// Given two arrays A of size N and B of size M and an integer K. Create a new array C of size N*M consisting of A[i]+B[j] for 1≤i≤N, 1≤j≤M. Find the Kth smallest element in the array C.


// Input Format

// The first line contains T, the number of test cases (1<=T<=10000).

// The first line contains 3 space-separated integer N, M, K where 1<=N<=10^6, 1<=M<=10^6, 1<=K<=N*M.

// Next line contains N space-separated integers (0<=Ai<=1e4).

// Next line contains M space-separated integers (0<=Bi<=1e4).

// Sum of min(N, M) across all test cases<=10^5.


// Output Format

// For each test case print the Kth smallest element in the array C.


// Sample Input 1

// 1
// 3 3 6
// 1 2 3
// 4 5 6

// Sample Output 1

// 7

// Note

// Array C -> [1+4,1+5,1+6,2+4,2+5,2+6,3+4,3+5,3+6] -> [5,6,7,6,7,8,7,8,9]
// Array C after sorting - [5,6,6,7,7,7,8,8,9]
// 6th element is 7. 


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);
const int N = 1e6 + 10;
int a[N], b[N];
lli n,m,k;
void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
bool check(lli x) {

	lli cnt = 0;
   for(int i=0; i<n; i++) {

      cnt += upper_bound(b,b+m,x-a[i])-b;

   }
   return cnt >= k;
}
void solve() {

    //int n,m,k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0;i<m; i++) cin >> b[i];

    if(n > m ) {

      swap(n,m);
      swap(a,b);
    }
    sort(a,a+n);
    sort(b,b+n);



    lli l = a[0] + b[0] , r = a[n-1]+b[m-1] ,ans = a[n-1]+b[m-1];

    while(l<=r) {

    	lli mid = (l+r)/2;
    	if(check(mid)) {
    		ans = mid;
    		r = mid-1;
    	}
    	else l = mid+1;
    }
    cout << ans << endl;
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t; cin >> t;
   while(t--)
    solve();
}