class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_0 = 0;
        int num_1 = 0;
        int num_2 = 0;
        for (auto iter : nums)
        {
            if (iter == 0)
            {
                num_0 += 1;
            } else if (iter == 1)
            {
                num_1 += 1;
            } else {
                num_2 += 1;
            }
        }
        
        nums.clear();
        nums.insert(nums.begin(), num_0, 0);
        nums.insert(nums.begin() + num_0, num_1, 1);
        nums.insert(nums.begin() + num_0 + num_1, num_2, 2);
    }
};
