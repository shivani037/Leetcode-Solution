class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // Copy elements of nums2 into the end of nums1
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        
        // Sort the merged array using the merge sort algorithm
        
        // Initialize gap size to be half the size of the merged array, rounded up
        int gap = ceil((n+m)/2); 
        
        // Continue sorting as long as gap size is greater than or equal to 1
        while(gap>=1) 
        {
            int s=0; // Initialize starting index of subarrays
            int e=s+gap; // Initialize ending index of subarrays
            
            // Continue merging subarrays as long as the ending index is within the merged array
            while(e<(m+n)) 
            {
                // Compare the first elements of each subarray and swap them if necessary
                if(nums1[s]>nums1[e])
                {
                    swap(nums1[s],nums1[e]);
                }
                s++; // Move to next element in the subarrays
                e++;
            }
            
            // Update the gap size for the next iteration of sorting
            if(gap==1) // If gap is already 1, exit loop
            {
                break;
            }
            if(gap%2) // If gap size is odd, round up
            {
                gap=gap/2+1;
            }
            else // If gap size is even, divide by 2
            {
                gap = gap/2;
            }
        }
    }
};
