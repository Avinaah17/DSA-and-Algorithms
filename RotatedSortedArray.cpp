// Description

// Given a rotated sorted array. Find the index of the minimum element in the array.

// All the elements are distinct.

 


// Input Format

// The first line contains T, the number of test cases (1<=T<=10000).

// The first line contains an integer N where 1<=N<=10^5.

// The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

// Sum of N over all test cases ≤10^6.


// Output Format

// For each test case print the index of the minimum element in the array.

// 0-indexed.


// Sample Input 1

// 5
// 5
// 3 4 5 1 2
// 5
// 4 5 1 2 3
// 5
// 5 1 2 3 4
// 5
// 1 2 3 4 5
// 5
// 2 3 4 5 1

// Sample Output 1

// 3
// 2
// 1
// 0
// 4


// The array was sorted in ascending order originally. When it is rotated, there would be a point in the array where the element is smaller than the element before it, i.e. A[i-1] > A[i]. You need to find this point.


// You can use the fact that all numbers to the left of the inflection point (where the element is smaller than the element before it) are greater than the first number and all numbers to the right of the inflection point are smaller than the first number.


// We will use binary search on the given array in a different way since the array is not sorted. We take the left pointer as L = 0 and the right pointer as R = N-1. If at any point, we get A[L] ≤ A[R], that means the array from L to R is sorted and the smallest number would be A[L]. We take mid = (L+R)/2.

// If A[L] ≤ A[mid], that means the array is sorted from L to mid, mid+1 could be a possible answer and then we continue binary search from L = mid+1 to R. Otherwise, A[L] > A[mid], that means the minimum number would be somewhere between L to mid, because if the array is not increasing in this range there will be an inflection point where the element is smaller than the element before it, so we continue binary search from L to R = mid.

// Time Complexity per test case: O(N + log2N) (since we are performing binary search on the length of the given array)


#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

bool check(int i){
   if(arr[i]<arr[0])return 1;
   else return 0;
}

void solve(){
   cin>>n;
   arr.resize(n);
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   int lo = 1;
   int hi = n-1;
   int ans = 0;
   while(lo<=hi){
       int mid = (lo+hi)/2;
       if(check(mid)){
           ans = mid;
           hi = mid - 1;
       }else{
           lo = mid + 1;
       }
   }
   cout<<ans<<endl;
}  

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int _t;cin>>_t;while(_t--)
   solve();
}