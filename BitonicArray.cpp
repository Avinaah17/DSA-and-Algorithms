// Description

// Given a bitonic array A consisting of N integers and an integer Q. In each query, you will be given an integer K, find the positions of K in A. Integer K exists in A.

// Bitonic array - A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N. 


// Input Format

// The first line contains T, the number of test cases (1<=T<=10000).

// The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.

// The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

// Next Q lines contains an integer K, -1e9<=K<=1e9.

// Sum of N, Q across all test case ≤10^6


// Output Format

// For each test case print the positions of K in A in sorted order in a new line.

// Positions are 1-indexed.


// Sample Input 1

// 1
// 6 4
// 1 2 5 3 2 1
// 1
// 2
// 5
// 3

// Sample Output 1

// 1 6
// 2 5
// 3
// 4

// The given array can be seen as two different arrays which are merged together, one is in increasing order and the other in decreasing order.


// First, find the peak of the given array using binary search and since both the parts of the array are sorted, we can use binary search on both of them to find the given query number.


// We will use binary search on the given array in a different way since the array is not sorted. First we need to find the peak of the array. This would be done by binary search, since the peak point would be the only point that is greater than elements to both sides, its left and right. We take the left pointer L = 1, the right pointer R = N (since the array is 1-indexed) and mid = (L+R)/2. If we get A[mid-1] < A[mid], that means mid could be a possible peak, since the peak cannot exist at any point lower than mid, so we continue binary search on L = mid+1 to R. Otherwise, A[mid-1] > A[mid], the peak would be lower than mid, so we continue binary search on L to R = mid-1. If peak is the index of the given query number, that would be the answer.

// After finding the peak, we apply binary search on both sides of the peak, i.e. from L = 1 to R = peak -1 and L = peak + 1 to R = N, separately. Note that it is possible that an element can exist in the left part as well as the right part of the peak of the array.

// Time Complexity per test case: O(log2N) (since we are performing binary search on the length of the given array)


#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<int> arr;

bool check(int i){
   if(arr[i]>arr[i-1])return 1;
   else return 0;
}

void solve(){
   cin>>n>>q;
   arr.resize(n);
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }

   int lo = 1;
   int hi = n-1;
   int peak = 0;
   while(lo<=hi){
       int mid = (lo+hi)/2;
       if(check(mid)){
           peak = mid;
           lo = mid + 1;
       }else{
           hi = mid - 1;
       }
   }

   while(q--){
       int k;
       cin>>k;

       vector<int> final;
       lo = 0;
       hi = peak-1;
       while(lo<=hi){
           int mid = (lo+hi)/2;
           if(arr[mid]==k){
               final.push_back(mid+1);
               break;
           }else if(arr[mid]>k){
               hi=mid-1;
           }else{
               lo=mid+1;
           }
       }

       lo = peak;
       hi = n-1;
       while(lo<=hi){
           int mid = (lo+hi)/2;
           if(arr[mid]==k){
               final.push_back(mid+1);
               break;
           }else if(arr[mid]>k){
               lo=mid+1;
           }else{
               hi=mid-1;
           }
       }

       for(auto v:final){
           cout<<v<<" ";
       }  
       cout<<endl;
   }
}

signed main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   int _t;cin>>_t;while(_t--)
   solve();
}