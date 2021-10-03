#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[],int n,int sum)
{
   int dp[n+1][sum+1];

   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)
       {
           if(i==0) dp[i][j] = false;
           if(j==0) dp[i][j] = true;
       }
   }
   
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
              if(arr[i-1] <= sum)
              {
                  dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }
              else
              {
                  dp[i][j] = dp[i-1][j];
              }
       }
   }
     return dp[n][sum];
}




int main()
{
     int n;
     cout<<"Enter number of elements: "<<endl;
     cin>>n;

     int arr[n];
     cout<<"Enter elements: "<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     int sum;
     cout<<"enter sum:"
     cin>>sum; 

     bool isPresent = subsetSum(arr,n,sum);

     if(isPresent) cout<<"There is subset available in the given array";
     else cout<<"No such subset present";



}

