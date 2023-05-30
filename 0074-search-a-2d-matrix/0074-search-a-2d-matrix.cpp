class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;
   
        // Loop until we've either found the target or checked every element in the matrix
        while (row < rows && col > -1) {

            // Get the value at the current row and column
            int cur = matrix[row][col];

            // If we've found the target, return true
            if (cur == target) return true;

            // If the target is greater than the current value, move down to the next row
            if (target > cur) row++;

            // If the target is less than the current value, move left to the previous column
            else col--;
        }
        
        // If we've checked every element and haven't found the target, return false
        return false;
    }
};
