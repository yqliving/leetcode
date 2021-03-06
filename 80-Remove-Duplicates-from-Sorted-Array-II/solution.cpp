class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
};

/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2)
        return nums.size();
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums.size();
}
};

