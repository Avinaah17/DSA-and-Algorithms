//  Description

// You are given N distinct points on the number line in a sorted array A. You can place at most K more points on the Line (Integer coordinates only). You have to make the maximum separation between any two consecutive points in the final configuration as minimum as possible. Output this minimal value.  

// Note - You can place the points anywhere you like, but you cannot place more than one point at the same position on the line. 


// Input Format

// The first line contains an integer T, the number of test cases (1<=T<=10000).

// The first line of each test case contains two space-separated integers N, K, 2<=N<=10^5, 0<=K<=10^9.

// Next line contains N space-separated distinct integers (0<=Ai<=1e9).

// Sum of N across all test cases <= 10^6.


// Output Format

// For each test case output the minimum maximum separation between any two consecutive points possible in a new line.


// Sample Input 1

// 5
// 5 5
// 1 2 3 4 5
// 5 0
// 2 5 7 8 10
// 3 2
// 100 200 230
// 6 5
// 1 3 5 7 9 11
// 6 4
// 1 4 8 13 19 26

// Sample Output 1

// 1
// 3
// 34
// 1
// 4
 

// Note

// For the first test case - do not place any additional points or place points at 6,7.

// For the third test case - place the points at 133, 166. So final configuration = [100, 133, 166, 200, 230] and maximum difference between two consecutive numbers = 34.

// For fourth test case - place the points at 2, 4, 6, 8, 10. So final configuration = [1,2,3,4,5,6,7,8,9,10,11] and maximum difference between two consecutive numbers = 1.   
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);

int arr[100100];
int n, k;

void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
int check(int x) {
    int need = 0;
	for(int i=1; i<n; i++) {

		int d = arr[i] - arr[i-1];
		need += (d+x-1)/x-1;
	}

	return need <= k;
}
void solve() {

    //int n;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];

    int l = 1 , r = 1e9;
    int ans = r;
    while(l<=r) {

    	int mid = (l+r)/2;

    	if(check(mid)){

    		ans = mid;
    		r = mid-1;
    	}
    	else {
    		l = mid+1;
    	}
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