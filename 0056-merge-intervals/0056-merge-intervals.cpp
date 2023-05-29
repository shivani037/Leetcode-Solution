class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        // Create an empty vector to store the merged intervals
        vector<vector<int>> output;
        
        // Loop through each interval
        for(auto interval : intervals){
            
            // If the output vector is empty or the end of the last interval in the output vector
            // is less than the start of the current interval, add the current interval to the output vector
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                // Otherwise, merge the current interval with the last interval in the output vector
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        
        // Return the merged intervals
        return output;
    }
};
