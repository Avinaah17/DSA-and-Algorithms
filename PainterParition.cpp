// Description

// We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of the board. The problem is to find the minimum time to get
// this job done under the constraints that any painter will only paint continuous sections of boards.

// Note:

// 2 painters cannot share a board to paint. A board cannot be painted partially by one painter, and partially by another.
// A painter will only paint contiguous boards. If a painter paints board 1 and 3 but not 2 is invalid.

// Input Format

// The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.

// The first line of each test case contains 2 space-separated integers N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and the number of painters.

// The second line of each test case contains N space-separated integers (0 ≤ xi ≤ 10^9) - the length of the boards.

// Sum of N across all test cases ≤ 10^6.


// Output Format

// For each test case print the minimum time required to complete the painting in a new line.


// Sample Output 1

// 5
// 5 2
// 1 2 3 4 5
// 5 3
// 2 5 7 2 5
// 5 1
// 1 2 3 4 5
// 5 5
// 1 2 3 4 5
// 5 4
// 1 7 2 3 5

// Sample Input 2

// 9
// 7
// 15
// 5
// 7    


// If K painters are able to paint the boards in time X, then they can paint the boards in time less than X as well. That means this is a monotonic function. You can use this to apply binary search.


// We would be doing binary search on the minimum time to paint all the boards by the K painters. We take the left pointer as L = max(Xi) (because 2 painters cannot share a board to paint) and R = Σ(Xi). We take mid = (L+R)/2. Find the number of painters it takes to paint all the boards in time ‘mid’. This can be done by assigning the boards to the painters in contiguous order and at the same time ensuring that the painters are painting the boards in continuous order.

// If the number of painters is ≤ K, that means this is a possible answer and we can minimize the time taken to paint the boards, we continue binary search on L to R = mid-1. Otherwise, we need to increase the time to ensure that only K painters are doing the job, so we continue the binary search on L = mid+1 to R.

// Time Complexity: O(N * log2(ΣXi))


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;
lli arr[100100];
int n,k;
double long PI = acos(-1);

void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}

bool check(lli x) {

	int curr_time = 0;
    int need = 0 ,last = 0;
	for(int i =0 ; i<n; i++) {
       
       if(last >= arr[i]) {

       	   last -= arr[i];
       }
       else {

       	   last = x-arr[i];
       	   need++;
       }

       //if(need > k) break;
      
	}

	return need  <= k;
}

void solve() {

	cin >> n >> k;

	for(int i=0; i<n; i++) cin >> arr[i];

	//sort(arr,arr+n);
	lli maxVal = arr[0];
    lli s = arr[0];
    for(int i=1; i<n; i++) {

    	maxVal = max(maxVal,arr[i]);
    	s += arr[i];

    }

    lli l = maxVal , r = s , ans = s;

    while(l<=r) {

    	lli mid = (l+r)/2;
    	if(check(mid)) {

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