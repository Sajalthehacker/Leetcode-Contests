// https://leetcode.com/problems/zero-array-transformation-iii/description/

/*
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length
*/

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // Priority queues to manage query processing
        priority_queue<int> availableEndIndices; // Max-heap for candidate queries' end indices
        priority_queue<int, vector<int>, greater<>> activeEndIndices; // Min-heap for active queries' end indices

        // Sort queries by their starting indices
        sort(queries.begin(), queries.end());

        int successfulQueries = 0; // Count of queries successfully used
        int queryPointer = 0;      // Tracks the current query being processed

        // Process each position in nums
        // = (3 * q * log2(q)) + n
        for (int index = 0; index < nums.size(); ++index) {
            // Add all queries starting at the current index to the available queue
            while (queryPointer < queries.size() && queries[queryPointer][0] == index) {
                availableEndIndices.push(queries[queryPointer][1]);
                ++queryPointer;
            }

            // Adjust the current number by subtracting the count of active queries
            nums[index] -= activeEndIndices.size();

            // Use candidate queries to fulfill the current position's requirement
            while (nums[index] > 0 && !availableEndIndices.empty() && availableEndIndices.top() >= index) {
                ++successfulQueries;
                activeEndIndices.push(availableEndIndices.top()); // Move query from available to active
                availableEndIndices.pop();
                --nums[index];
            }

            // If the current position cannot be zeroed out, return -1
            if (nums[index] > 0)
                return -1;

            // Remove expired queries from the active queue
            while (!activeEndIndices.empty() && activeEndIndices.top() == index)
                activeEndIndices.pop();
        }

        // Return the number of queries that can be removed
        return queries.size() - successfulQueries;
    }
};

// tc - O(qlogq + n)
// sc - O(q)