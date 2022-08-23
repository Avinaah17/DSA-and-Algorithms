// Description

// You are given N balls and an integer K. The color of each ball is given in an array A. A basket is filled if it contains at least K balls of different colors. Find the maximum number of filled baskets you can get if you optimally put the balls in the baskets.


// Input Format

// The first line contains T, the number of test cases (1<=T<=100000).

// The first line contains three space-separated integers N, K where 1<=N<=10^5, 1<=K<=N.

// Next line contains N space-separated integers (0<=Ai<=1e9).

// Sum of N across all test cases <=10^6.


// Output Format

// For each test case output the maximum number of filled baskets in a new line. 


// Sample Input 1

// 3
// 5 5
// 1 2 3 4 5
// 5 2
// 1 2 3 4 5
// 6 3
// 1 2 2 1 3 3

// Sample Output 1

// 1
// 2
// 2

// Note

// 1st test case:
// 1st basket -> {1,2,3,4,5}

// 2nd test case:
// 1st basket -> {1,2,3}
// 2nd basket -> {4,5}

// 3rd test case:
// 1st basket -> {1,2,3}
// 2nd basket -> {1,2,3}

 // If we can fill X number of baskets with at least K balls of different colors, then the maximum possible baskets would be ≥ X. Otherwise, possible baskets would be < X. This is a monotonic function and hence we can use binary search in this problem.
// We would be doing binary search on the possible number of baskets. We take the left pointer as L = 0 and the right pointer as R = N/K (since each basket should have at least K balls). We take mid = (L+R)/2. We then check if it is possible to have mid number of baskets. To check this, we precalculate a frequency hashmap, which stores the frequency of the colors of the balls. For each ball of color, we cannot take balls more than the value of mid, since we want distinct balls in the baskets. If mid number of baskets is possible, then values ≥ mid can be a possible answer as well, so we continue binary search on L = mid+1 to R. Otherwise, the maximum number of baskets possible would be < mid and so we continue binary search on L to R = mid-1.

// Calculate the sum of min(freq[color],mid). If the sum ≥ mid * K then there exists a way to fill “mid” baskets.

// Imagine a 2-d grid of size mid * K. Each row corresponds to the basket. Start filling the first column continuously with the same color ball. As at max “mid” same color ball is present, we won't have two same color balls in the same basket. Now pick another color start filling column-wise, first column done then start filling the 2nd column. In this way, no basket have same color balls and all the basket have at least K distinct color balls.

// Time Complexity per test case: O(N * log2N)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);
int arr[100100];
int n, k;
map<ll, ll> mp;
void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
bool check(lli x) {
     
     lli need = 0;
     for(auto it : mp)
     	need += min(it.second , x);
     return need >= x*k;
}

void solve() {
    
    cin >> n >> k;
    for(int i=0 ; i<n; i++) {
    	cin >> arr[i];
    	mp[arr[i]]++;
    }
    lli l = 0 , r = n , ans = 0;

    while(l<=r) {
        
        lli mid = l+(r-l)/2;
    	if(check(mid)) {
    		ans = mid;
    		l = mid+1;
    	}
    	else r = mid-1;
    }
    cout << ans <<  endl;
    mp.clear();
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t; cin >> t;
   while(t--)
    solve();
    //mp.clear();
}