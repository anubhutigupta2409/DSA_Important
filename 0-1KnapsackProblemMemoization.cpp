class Solution
{
public:
    int knapSackUtil(int W, int wt[], int val[], int n, int *dp[1002][1002])
    {
        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }
        if (wt[n - 1] <= W)
        {
            //Condition in which the weight is less than allowed weight but we have a choice to add it to the knapsack or not
            return dp[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1, dp), knapSack(W, wt, val, n - 1, dp));
        }
        else
        {
            return dp[n][W] = knapSack(W, wt, val, n - 1, dp); //Condition in which the weight is greater than allowed weight
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        int maxProfit = 0;
        if (W == 0 || n == 0)
        {
            return maxProfit;
        }
        int dp[1002][1002];
        memset(dp, -1, sizeof(dp)); //Setting the matrix to -1
        maxProfit = knapSackUtil(W, wt, val, n, dp);
        return maxProfit;
    }
};