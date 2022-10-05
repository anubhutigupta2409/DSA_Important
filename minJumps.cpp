#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int minJumps(int arr[], int n){
        int jumps = 0, maxRange = 0, steps = 0, curr = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j <= i + arr[i]; j++)
            {
                maxRange = max(arr[i] + arr[j], maxRange);
            }
            curr += maxRange; 
            jumps++;
            if(maxRange >= n)
                break;
        }
        return jumps;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}