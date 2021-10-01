class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1001][1001];
    int knapSack(int w, int wt[], int val[], int n)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0; //Initialising the dp matrix
            }
        }
        //Breaking the larger problem into smaller sub problems using iteration
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (wt[i - 1] <= j) //i instead of n
                {
                    int val1 = val[i - 1] + dp[i - 1][j - wt[i - 1]]; //j instead of W
                    int val2 = dp[i - 1][j];                          //i instead of n

                    dp[i][j] = max(val1, val2);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][w]; //The bottom right cell gives the maximum profit
    }
};