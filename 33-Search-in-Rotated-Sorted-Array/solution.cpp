class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){ 
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[r]){// two situation
                if(target > nums[mid] || target <= nums[r]) l = mid + 1;   
                // condition for pick right side
                else r = mid - 1;    // else, pick left side
            }else{
                if(target <= nums[r] && target > nums[mid]) l = mid + 1;  
                // condition for pick right side
                else r = mid - 1;     // else, pick left side
            } 
        }
        
        return -1;
    }
};
//because rotated, nums[mid] > nums[r]   1 2 4 5 6 7 9 might become 4 5 6 7 9 1 2