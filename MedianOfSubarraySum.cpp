// Description

// Given an array of N integers A. The score of a subarray is the sum of all integers in the subarray. Mr.X calculated the score of all N*(N+1))/2 subarray. Mr.X wants you to find the median of the array containing the score of all the subarray.

 

// Note: The median of a sequence is the value that is in the middle when the sequence is sorted. If the length of the sequence is even, there are two values in the middle and the median is the smaller of these values (or either when they are equal).


// Input Format

// The first line contains an integer T, the number of test cases (1<=T<=10000).

// The first line of each test case contains an integer N where (1<=N<=10^5).

// Next line contains N space-separated integers (0<=Ai<=1e9).

// Sum of N across all test cases ≤ 10^6.


// Output Format

// For each test case output the median of the array containing the score of all the subarray in a new line.


// Sample Input 1

// 5
// 3
// 1 2 3
// 1
// 5
// 2
// 1 5
// 10
// 1 2 2 3 3 4 5 4 6 7
// 15
// 100 222 333 511 555 232 444 555 777 888 999 1000 1112 12345 123456

// Sample Output 1

// 3
// 5
// 5
// 13
// 3629
 


// Note

// 1st test case:
// Subarray and score:
// 1 -> 1
// 1,2 -> 3
// 1,2,3 -> 6
// 2 -> 2
// 2,3 -> 5
// 3 -> 3
// New array = {1,2,3,3,5,6}, median = 3

// 2nd test case:
// Subarray and Score:
// 5 -> 5
// New array = {5}, median = 5

// 3rd test case:
// Subarray and score
// 1 -> 1
// 1,5 -> 5
// 5 -> 5
// New array = {1,5,5}, median = 5.



// If X is a possible value of the median of the new array, then it should exist in the array and it should have (M+1)/2 elements lesser than or equal to X in the array. Here, M is the size of the new array, i.e. M = N*(N+1)/2.


// If we get the number of elements lesser than or equal to X as ≥ (M+1)/2. The possible value of median could X or any value lesser than X. Otherwise, it would be greater than X. This is a monotonic function and hence we can use binary search in this problem. Here M = N*(N+1)/2.


// We would be doing binary search on the possible values of the median. Here, we would be using the array which has the subarray sums of the original array. We take the left pointer as L = 0 or L = minimum value present in the new array and we take the right pointer as R = sum of all the numbers in the original array. We take mid = (L+R)/2. We need to find the number of values ≤ mid.

// It would not be possible to create the new array since N ≤ 105 and the new array would be of size N*(N+1)/2. To avoid making the new array, we will use two pointers to calculate the subarray sums. If a sum from i to j is ≤ mid, that means all sums from i to (values than j) is ≤ mid.

// If the number of values ≤ mid is greater than or equal to (M + 1)/2, that means mid can be a possible value of the median or it would be lesser than mid, so we continue binary search on L to R = mid - 1. Otherwise, the value of median would be > mid and so we continue binary search on L = mid+1 to R. Here, M = N*(N+1)/2.

// Time Complexity per test case: O(N * log2(ΣAi))


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[100001];
ll func(ll x){ // count number of subarray with sum<=x
   ll cnt = 0;
   ll currSum = 0;
   ll start = 0;
   ll current = 0;
   while(current<n){
       currSum+=arr[current];
       while(start<=current and currSum>x){
           currSum-=arr[start];
           start++;
       }
       cnt+=(current-start+1);
       current++;
   }
   return cnt;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int testcases;
   cin>>testcases;
   while(testcases--){
       cin>>n;
       ll low = 0,high = 0;
       for(ll i=0;i<n;i++){
           cin>>arr[i];
           high+=arr[i];
       }
       ll ans = -1;
       ll total = (n*(n+1))/2;
       ll median = (total+1)/2;
       while(low<=high){
           ll mid = (low+high)/2;
           ll cntSub = func(mid);
           if(cntSub>=median)
               high = mid-1,ans = mid;
           else
               low = mid+1;
       }
       cout<<ans<<"\n";
   }
}