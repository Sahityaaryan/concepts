// https://www.youtube.com/watch?v=X6WF_RZyP44&t=1674s

// must check both the questions



#include<bits/stdc++.h>
using namespace std;

/**
 * question: 1
 * 
*/

bool canDistChoco(vector<int> &arr,int mid,int s)
{
    int n = arr.size();
    int studentReq = 1;

    int currSum = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid)
        {
            return false;
        }

        if(currSum + arr[i] > mid)
        {
            studentReq++;
            currSum = arr[i];

            if(studentReq > s) return false;
        } else {
            currSum += arr[i];
        }
    }

    return true;


}


int distChoco(vector<int> &arr, int s)
{
    int n = arr.size();
    int lo = arr[0];
    int hi = 0;

    for(int i = 0;i < n;i++)
    {
        hi += arr[i];
    }

    int ans = -1;

    while(lo <= hi)
    {
        int mid = lo + (hi-lo)/2;

        if(canDistChoco(arr,mid,s))
        {
            ans = mid;
            hi = mid-1;   
        }else {
            lo = mid + 1;
        }
    }

    return ans;
}

/**
 * question 1 with new approach
 * 
*/

int distChoco2(vector<int> &arr, int s)
{
       int n = arr.size();
    int lo = arr[0];
    int i = 1,count = 1,chocoAlreadyDistributed = 0, ans = INT_MAX,maxEle=0, hi;

    // creating Prefix sum

    while(i < n)
    {
        maxEle = max(arr[i],maxEle);
        arr[i] += arr[i-1];
        i++;
    }
       if(n==s) return maxEle;

    hi = arr[n-1];

    while(lo <= hi){

        int mid = lo+(hi-lo)/2;

        if(mid < maxEle) {
            lo = mid+1;
            continue;
        }


        i=0;
        count=1;
        chocoAlreadyDistributed=0;
        while(i < n){

            
            if(arr[i]-chocoAlreadyDistributed>mid){
                count++;
                if(i>0) chocoAlreadyDistributed = arr[i-1];
            } else  {i++;}
        }

        if (count==s) {
            cout <<"ans: "<< mid << endl;
            ans = min(mid,ans);
            hi = mid-1;
        } else if(count > s){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    return ans;
}
/**
 * question:2 
 * 
 * at 28:03
*/


    bool canPlaceStudents(vector<int> &pos,int s,int mid)
    {
        //as the first child will always be placed we are fetching the position for the second element
        int palcedChilds= 1;
        int size = pos.size();
        int i = 0,j = 0;

        while(j < size)
        {
            if(pos[j]-pos[i] >= mid)
            {
                palcedChilds++;
                i = j;
            }

            if(palcedChilds==s) return true;
            
            j++;
        }

        return false;
    }

    int race(vector<int> &pos,int s)
    {
        int n = pos.size();
        int lo = 1;
        int hi = pos[n-1]-pos[0];
        int ans = -1;

        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;

            if(canPlaceStudents(pos,s,mid))
            {
                ans = mid;
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }

        return ans;
    }


    /**
     *  Revision
     * time complexity: O()
     * 
     * 
    **/

// start = 10:58

int minPlaceStudent(vector<int> arr,int m){
	
	int i = 0,lo = 0, count = 1,n = arr.size(), hi = arr[n-1]-arr[0],ans = -1, lastSpot;

	while(lo <= hi){
		int mid = lo +(hi-lo)/2;

		lastSpot = arr[0];

		i = 0;
		count = 1;

		while(i < n){
			
			if(arr[i]-lastSpot > mid){
				count++;
				lastSpot = arr[i];
			}
			i++;
		}


		if(count==m){
			ans = mid;
			lo = mid+1;
		} else if (count < m){
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}

	return lo;

}




int main()
{

    vector<int> pos = {1,2,4,8,9};

    int s = 3;
        cout << "ans1: "<< minPlaceStudent(pos,s) << '\n';
    cout << "ans2: "<< race(pos,s);


    
    cout << endl;
    return 0;
}
