// Description

// You are given two integers N and S. Find the number of positive integers X less than equal to N, such that the difference between X and the sum of its digits (in decimal representation) is not less than S.


// Input Format

// The first line of input contains one integer T (1 ≤ T ≤ 104) — the number of test cases. Then T test cases follow.

// The first line of each test case contains two space-separated integer N, S where 1<=N<=10^18, 0<=S<=10^18.


// Output Format

// For each test case print the number of positive integers X in a new line.


// Sample Input 1

// 10
// 5 4
// 100 5
// 20 3
// 40 19
// 32 15
// 69 12
// 1000000000000000 0
// 1000000000000000000 10000000
// 9999999999999 9999999999882
// 13465751690089037 981448507916936

// Sample Output 1

// 0
// 91
// 11
// 11
// 13
// 50
// 1000000000000000
// 999999999989999991
// 10
// 12484303182172038    


// If for a number X, the difference between X and the sum of its digits is not less than S, then for X+1 also difference will not be less than S. Can you prove it?
// If this claim is true then use this monotone property.


// Prove: Let F(X) represents the sum of digits of X.

// Since F(X+1) is not greater than F(X)+1, 
// F(X+1) ≤ F(X)+1
// X + F(X+1) ≤ F(X) + 1 + X , adding X both side
// X - F(X) ≤ X + 1 - F(X+1)

// then X + 1 - F(X+1) ≥ X - F(X). 

// and if X - F(X) ≥ S, 

// then X + 1 - F(X+1) ≥ S.


// This observation allows us to use binary search to find the minimum number X, such that the difference between X and the sum of its digits is not less than S. It follows the monotone property that initially all numbers less than X have difference less than equal to S. So “NO”  instance holds for numbers less than X. Then for all numbers ≥X “YES” instance hold. Using binary search we can find the smallest value X such that the “YES” instance holds. And if X ≤ N, then all numbers in the segment [X, N] have difference not less than S.


#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

lli N, S;

double long PI = acos(-1);

void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
bool check(lli x) {

	lli temp = x;

	lli sum = 0;

	while(temp > 0) {

		sum += temp%10;
		temp /= 10;
	}

	lli diff = x - sum;
	return diff >= S;
}
void solve() {

   cin >> N >> S;

   lli l = 1 , r = N , ans = N+1;

   while(l <= r) {

   	  lli mid = l+(r-l)/2;

   	  if(check(mid)) {

   	  	 ans = mid;
   	  	// cout << ans << endl;
   	  	 r = mid-1;
   	  }
   	  else {
   	  	l = mid+1;
   	  	//ans = mid;
   	  	//cout << mid << endl;
   	  }
   }
   cout << N-ans+1<<endl;
    
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int t; cin >> t;
   while(t--)
    solve();
}