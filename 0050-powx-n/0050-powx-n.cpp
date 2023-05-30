class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;        long long nn = n;
        
        // If n is negative, convert it to a positive value
        if (nn < 0) nn = -1 * nn;
        
        // Loop while nn is not zero
        while (nn) {
            // If nn is odd, multiply ans by x and decrement nn by 1
            if (nn % 2) 
		{
                ans = ans * x;
                nn = nn - 1;
            } 
		else {
                // If nn is even, square x and divide nn by 2
                x = x * x;
                nn = nn / 2;
            }
        }
        
        // If n is negative, take the reciprocal of ans
        if (n < 0) ans = (double)(1.0) / (double)(ans);

        return ans;
    }
};
