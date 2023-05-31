class Solution {
    public:
        int uniquePaths(int m, int n) {

        // declare a 2D array of size m x n to store the results
        int dp[m][n];

        // loop through each element of the 2D array
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // if it is the first row or first column, there is only one way to reach that element
                if(i==0||j==0)
                dp[i][j]=1;
                // for all other elements, the number of ways to reach that element is the sum of the ways to reach the element above it and the element to the left of it
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        // the result is the value at the bottom-right corner of the 2D array
        return dp[m-1][n-1];
    }
};
