// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

/*
Given an integer array nums, return the number of 
subarrays
 of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

 

Example 1:

Input: nums = [1,2,1,4,1]

Output: 1

Explanation:

Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

Example 2:

Input: nums = [1,1,1]

Output: 0

Explanation:

[1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

 

Constraints:

3 <= nums.length <= 100
-100 <= nums[i] <= 100
*/


class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0];
        int second = nums[1];
        int third = nums[2];

        int count = 0;
        if(2 * (first + third) == second){
            count++;
        }

        for(int i = 3; i < n; i++){
            first = second;
            second = third;
            third = nums[i];

            if(2 * (first + third) == second){
                count++;
            }
        }

        return count;
    }
};