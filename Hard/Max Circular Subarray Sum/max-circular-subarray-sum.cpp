//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num)
    {
        if(num==1)
        return arr[0];
        int cs1=0,cs2=0,mins=0,maxs=0,sum=0;
        int maxelement = *max_element(arr, arr+num);
        int minelement=*min_element(arr, arr+num);
        for(int i=0;i<num;i++)
        {
            sum+=arr[i];
            cs1+=arr[i];
            cs2+=arr[i];
            mins=min(cs2,mins);
            maxs=max(cs1,maxs);
            if(cs1<0)
            cs1=0;
            if(cs2>0)
            cs2=0;
        }
        if(maxelement<0)
        maxs=maxelement;
        if(minelement>0)
        mins=minelement;
        if(mins>0)
        return maxs;
        if(maxs<0)
        return maxs;
        return max(maxs,sum-mins);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends