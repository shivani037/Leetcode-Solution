class Solution {
private: 
    // merge function to merge two sorted subarrays and count reverse pairs
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        // count the number of reverse pairs using two pointers
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        // merge the two sorted subarrays
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    // merge sort function to divide the array into smaller subarrays and call merge
    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1; // find the mid-point of the array
        mergeSort(nums, low, mid, reversePairsCount); // recursively sort the left subarray
        mergeSort(nums, mid+1, high, reversePairsCount); // recursively sort the right subarray
        merge(nums, low, mid, high, reversePairsCount); // merge the two sorted subarrays and count reverse pairs
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount); // sort the entire array and count reverse pairs
        return reversePairsCount; // return the count of reverse pairs
    }
};
