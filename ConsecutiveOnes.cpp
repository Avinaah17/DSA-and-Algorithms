// Description

// Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only one.

// Find the maximum score possible if you can change at most K elements of the array.


// Input Format

// The first line contains an integer T, the number of test cases.
// The first line of each test case contains two space-separated integer N, K where 
// The next line contains N space-separated integers which are either 0 or 1.


// Output Format

// For each test case print the maximum score possible if you can change at most K elements of the array in a new line.


// Constraints

// 1 ≤ T ≤ 104
// 1 ≤ N ≤ 105
// 0 ≤ K ≤ N
// Sum of N across all test cases ≤ 106.


// Sample Input 1

// 5
// 10 2
// 1 0 1 1 0 1 1 0 0 1
// 10 1
// 1 1 0 1 0 0 0 1 0 0
// 10 3
// 1 0 0 1 1 0 1 1 0 1
// 10 3
// 1 1 1 0 0 0 1 1 1 1
// 10 3
// 1 1 0 0 1 1 0 0 1 1

// Sample Output 1

// 7
// 4
// 8
// 10
// 7  

// If maximum score X is possible, then scores below X are also possible. That means this is a monotonic function. You can use this to apply binary search.


// We would be doing binary search on the maximum score possible. We take the left pointer as L = 0 and the right pointer as R = N. We take mid = (L+R)/2. Find if it is possible to have mid number of consecutive ones, by changing at most K values in the array. This can be done by going through all the subarrays of size mid and counting the number of 0s in it. If any subarray has a count of 0s ≤ K, then mid is a possible answer.

// If it is possible, mid could be a possible answer and we continue binary search on L = mid+1 and R. Otherwise, any value above mid would also not be a possible answer(because if score mid is not possible, any score above mid would also not be possible), so we continue binary search on L and R = mid-1.

// Time Complexity per test case: O(N*log2N)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);
lli arr[100100],pf[100100];
lli n,k;

lli countZeroes(lli l , lli r) {

	  return (r-l +1 - (pf[r] - pf[l-1]));
}

lli check(lli st, lli x) {

    return countZeroes(st,x) <= k;
}
void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}

void solve() {

    cin >> n >> k;
    for(int i=0; i<n; i++) {

    	cin >> arr[i];
    }
    pf[0] = arr[0];
    for(int i=1; i<n; i++) pf[i] = pf[i-1]+arr[i];
    lli maxSub = 0;
    for(int st = 0; st<n; st++) {
   
       lli lo = st, hi = n-1 , ans = st-1;
       while(lo <= hi) {

       	   lli mid = (lo+hi)/2;
       	   if(check(st,mid)) {
       	   	  ans = mid;
       	   	  lo = mid+1;
       	   }
       	   else hi = mid-1;
       }

       maxSub =  max(maxSub, ans-(st-1));
    }
    cout << maxSub << endl;
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t; cin >> t;
   while(t--)
    solve();
}