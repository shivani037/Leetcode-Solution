class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Get the number of rows in the input matrix
        int n = matrix.size();
        // Get the number of columns in the input matrix
        int m = matrix[0].size();
        
        // Define a temporary matrix to store the transposed matrix
        vector<vector<int>> temp(n, vector<int>(m, 0));
        
        // Transpose the input matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row in the transposed matrix to rotate it by 90 degrees
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
