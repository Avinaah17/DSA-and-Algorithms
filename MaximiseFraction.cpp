// Given two arrays A and B of size N and an integer K. You have to select K indexes i1,i2,i3....iK such that 

// (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) is maximum.


// Input Format

// The first line contains T, the number of test cases (1<=T<=10000).

// The first line contains an integer N, K where 1<=N<=10^4, 1<=K<=N.

// Next line contains N space-separated integers (1<=Ai<=1e4).

// Next line contains N space-separated integers (1<=Bi<=1e4).

// Sum of N across all test cases<=10^5.


// Output Format

// For each test case print the maximum possible value of (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]). You have to print the result round off to 6 decimal places.


// Sample Input 1

// 3
// 3 2
// 10 9 7
// 3 5 4
// 8 3
// 4 4 2 1 5 3 2 5
// 2 2 2 5 3 5 2 3
// 1 1
// 1 
// 1

// Sample Output 1

// 2.428571
// 1.857143
// 1.000000   
// Note

// 1st test case:
// Select index → [1,3], result = 17/7.

// Equate (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) to X. If the value of X is possible, then the maximum value would be ≥ X. Otherwise it would be < X. This is a monotonic function and hence we can use binary search in this problem.


// (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]) = X

// (A[i1]+A[i2]+A[i3]+……+A[iK]) - X*(B[i1]+B[i2]+B[i3]+……+B[iK]) = 0

// (A[i1] - XB[i1]) + (A[i2] - XB[i2]) + …… + (A[iK] - X*B[iK]) = 0

// So, we need to select K indices such that the above condition must be satisfied.


// We would be doing binary search on the maximum possible value of (A[i1]+A[i2]+A[i3]+……+A[iK]) / (B[i1]+B[i2]+B[i3]+……+B[iK]). Let’s

// We take the left pointer as L = 0 and the right pointer as R = 108. We take mid = (L+R)/2. We then check if it is possible to have mid as a possible value of the given function. To do this, we take the maximum K values of (A[i] - mid*B[i]) by using a priority queue. If the sum of these values is ≥ 0, then it might be possible to equate the sum to 0. If mid is a possible value, the maximum possible value can be ≥ mid and we continue binary search on L = mid to R. Otherwise, the maximum possible value would be < mid, so we continue binary search on L to R = mid.

// Time Complexity per test case: O(N * log2(ΣAi) * log2K)
#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using lli = long long int;

double long PI = acos(-1);
const int N = 1e5+10;
int arr[N], brr[N];
int n,k;
long double EPS = 1e-9;
void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
bool check(long double x) {

	priority_queue<long double, vector<long double> , greater<long double> > pq;

	for(int i=0; i<n; i++) {

		pq.push(arr[i]-x*brr[i]);

		if(pq.size() > k) {
			pq.pop();
		}
	}
	long double sum = 0;
	while(pq.size() > 0) {
        sum += pq.top();
		pq.pop();
	}

	return sum >= 0.0;
}

void solve() {
    
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> brr[i];

    long double lo = 0.0 ,hi = 1e9 , ans = 0.0;

    while(abs(hi-lo) >= EPS) {

    	long double mid = (hi+lo)/2;

    	if(check(mid)) {

    		ans = mid;
    		lo = mid;
    	}
    	else {
    		hi = mid;
    	}
    }
    cout << fixed << setprecision(6) << ans << endl;
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t; cin >> t;
   while(t--)
    solve();
}