#include<bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {

	if(a.size() > b.size())
	{
		return median(b, a);
	}

	int n1 = a.size() , n2 = b.size();

	int n = n1+n2;

	int requiredPartitionSize = n/2;

	int mid1,mid2;

	int lo = 0,hi = n1;

	while(lo <= hi){

		mid1 = lo + (hi-lo)/2;

		mid2 = requiredPartitionSize - mid1;

		int r1 = INT_MAX;
		int r2 = INT_MAX;
		int l1 = INT_MIN;
		int l2 = INT_MIN;


		if(mid1 < n1){
			r1 = a[mid1];
		}

		if(mid2 < n2){
			r2 = b[mid2];
		}

		if(mid1 > 0){
			l1 = a[mid1-1];
		}

		if(mid2 > 0){
			l2 = b[mid2-1];
		}

		if(l1 <= r2 && l2 <= r1){
			// cout << "l1: " <<l1 << " l2: " << l2 << " r2: " << r2 << " r1: " << r1 << endl; 

			if(n % 2 == 0){
				// cout << "max: " << max(l1,l2) << " min: " << min(r1 , r2) << endl;
				return ((double)(max(l1,l2)+ min(r1,r2)))/2.0;
			} 
			else {
				return min(r1,r2);
			}
		}

		if(l1 >= r2){
			hi = mid1 -1;
		} else {
			lo = mid1+1;
		}

	}

int main()
{
 
    
    cout << endl;
    return 0;
}