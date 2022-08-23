// Description

// Vivek has built a new classroom with N seats. The seats are located along a straight line at positions x1,x2…..xN.
// Vivek has to assign seats to K students such that a seat can be assigned to at most 1 student and the minimum distance between any two students is as large as possible. Find the largest minimum distance possible.


// Input Format

// The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.

// The first line of each test case contains 2 space-separated integers N, K (2 ≤ N ≤ 100000, 2 ≤ K ≤ N) - the number of seats and the number of students.

// The second line of each test case contains N space-separated integers (0 ≤ xi ≤ 10^9) - the position of the seats. All the given positions are distinct.

// Sum of N across all test cases ≤ 10^6.


// Output Format

// For each test case print the largest minimum distance possible in a new line.


// Sample Input 1

// 14
// 13 3
// 6048 2794 6123 1643 6907 6993 2382 6961 1094 488 7424 6469 6009 
// 10 6
// 469 706 278 545 711 386 298 242 385 316 
// 18 17
// 1042 271 839 45 1253 1060 428 676 418 1298 1230 668 665 158 916 659 458 202
// 11 10
// 16073873 456996657 980038523 123316193 427829862 54109396 319462445 181390046 543060523 490620628 938036110
// 6 2
// 274592090 858952753 241301573 721888021 806214246 383142174
// 12 5
// 5940 28062 23820 1965 3005 18306 23749 18322 17322 15504 14570 4481
// 17 13
// 1905 1798 5250 986 1239 3311 3519 5262 2444 151 5580 5008 1914 2366 5285 1528 331 
// 4 3
// 792050646 886157889 58701906 576742651
// 9 6
// 3584 5153 5516 6249 2453 3992 6179 1646 4810
// 7 6
// 149042184 953621985 987837168 343845676 726735692 6723177 435784762 
// 4 3
// 149479138 621021707 506424026 519149062 
// 2 2
// 1557 4228 
// 5 2
// 4150 9442 5146 9633 3537
// 6 4
// 160913372 862781533 10044128 722271773 201193061 944524755 

// Sample Output 1

// 2306
// 70
// 8
// 38035523
// 617651180
// 3975
// 116
// 309415238
// 706
// 91939086
// 114597681
// 2671
// 6096
// 191148933  


// If minimum distance, X is possible by assigning seats to K students, then it is possible to have a minimum distance lesser than X as well. That means this is a monotonic function. You can use this to apply binary search.


// We would be doing binary search on the largest minimum adjacent distance possible. First, we will sort the seat positions given to us. We take the left pointer as L = 1(since it is given that a seat can be assigned to at most 1 student) and R = X[N-1] - X[0]. We take mid = (L+R)/2. Find the number of students that can be seated if the minimum separation should be mid. This can be done by assigning the first seat to student 1 and then assigning seats such that they have separation of at least mid.

// If this number is ≥ K, that means this can be a possible answer and so we continue binary search on L = mid+1 to R. Otherwise, we need to decrease the value of minimum distance to allow more number of students to be seated so we continue binary search on L to R = mid-1.

// Time Complexity per test case: O(N * log2(X[N-1] - X[0]))  


#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, k;
       cin >> n >> k;
       int x[n];
       for (int i = 0; i < n; ++i) {
           cin >> x[i];
       }
       sort(x, x+n);
       int l = 1, r = x[n-1]-x[0];
       int ans = 1;
       while(l <= r) {
           int mid = (l+r)/2;
           int cnt = 1;
           int prev = x[0];
           for (int i = 1; i < n; ++i) {
               if(x[i] >= prev + mid) {
                   cnt++;
                   prev = x[i];
               }
           }
           if(cnt >= k) {
               ans = mid;
               l = mid + 1;
           }
           else {
               r = mid - 1;
           }
       }
       cout << ans << "\n";
   }
   return 0;
}