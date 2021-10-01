class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n == 0) //Base case when allowed weight = 0 or number of items = 0
        {
            return 0;
        }
        if (wt[n - 1] <= W)
        {
            //Condition in which the weight is less than allowed weight but we have a choice to add it to the knapsack or not
            return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else
        {
            return knapSack(W, wt, val, n - 1); //Condition in which the weight is greater than allowed weight
        }
    }
};