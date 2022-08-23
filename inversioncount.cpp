    
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = long long int;

double long PI = acos(-1);

void init_code() {

	#ifndef ONLINE_JUDGE
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	#endif
}
int mergeInversion(int * a , int p , int r , int q) {
      int n1 = r-p+1 , n2 = q-r ; int cnt  =0;
	  int a1[n1],a2[n2];

	  for(int i=0; i<n1; i++) a1[i] = a[p+i];
	  for(int i=0; i<n2; i++) a2[i] = a[r+1+i];

	  int i =0 , j =0 , k = p;

	  while(i<n1 && j <n2) {

	  	if(a1[i] <= a2[j]) {
	  		a[k++] = a1[i++];
	  	}
	  	else {

             cnt += r+1-(p);
             a[k++] = a2[j++];
	  	}
	  } 

	  while(i < n1) a[k++] = a1[i++];
	  while(j < n2) a[k++] = a2[j++];

	  return cnt;
}
int mergeSortInversionCount(int* a, int l , int r) {

	if(l >= r) return 0;

	int inversionCount = 0;

	int mid = (l+r)/2;

	inversionCount += mergeSortInversionCount(a,l,mid);
    inversionCount += mergeSortInversionCount(a,mid+1,r);
    inversionCount += mergeInversion(a,l,mid,r);

    return inversionCount;
}

signed main() {

   init_code();
   ios_base::sync_with_stdio(0); 
   cin.tie(0); cout.tie(0);
   
   int n; cin >> n;
   int a[n];
   for(int i=0; i<n; i++) cin >> a[i];

   int inversionCount = mergeSortInversionCount(a,0,n-1);
   cout << inversionCount << endl;
}