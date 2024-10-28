class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        int idx = 0;
        while(cnt < size){
            if(nums[idx] == 0){
                nums.erase(nums.begin()+idx);
                nums.push_back(0);
            }
            else{
                idx++;
            }
            cnt++;
        }
        
    }
};