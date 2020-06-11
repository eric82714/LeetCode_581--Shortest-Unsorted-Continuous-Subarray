class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int right = nums.size()-1, left = 0;
        bool isRright = false, isLeft = false;
        for(int i = 0; i < nums.size(); i++) {
            if(isRright && isLeft) break;
            if(copy[i] != nums[i] && !isLeft) { 
                left = i;
                isLeft = true;           
            }
            if(copy[nums.size()-1-i] != nums[nums.size()-1-i] && !isRright) { 
                right = nums.size()-1-i;
                isRright = true;
            }
        }
        if(!isRright && !isLeft && (right - left == nums.size()-1)) return 0;
        
        return right - left + 1;
    }
};
