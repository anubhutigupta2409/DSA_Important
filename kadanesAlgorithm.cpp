#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSubarraySum(int arr[], int n){
        int currSum = 0, maxSum = INT_MIN;//INT_MIN is for all negative numbers
        for(int i = 0; i < n; i++)
        {
            currSum += arr[i];
            if(currSum > maxSum)
                maxSum = currSum;
            if(currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
};
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}