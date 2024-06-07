class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        starting_index = 0
        while(starting_index < len(nums)):
            for i in range(starting_index+1,len(nums)):
                if(nums[starting_index] + nums[i]) == target:
                    return [starting_index, i]
            starting_index += 1
        
                