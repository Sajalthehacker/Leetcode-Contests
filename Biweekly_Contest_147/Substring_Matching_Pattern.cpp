// https://leetcode.com/problems/substring-matching-pattern/description/

/*
You are given a string s and a pattern string p, where p contains exactly one '*' character.

The '*' in p can be replaced with any sequence of zero or more characters.

Return true if p can be made a substring of s, and false otherwise.

A substring is a contiguous non-empty sequence of characters within a string.

 

Example 1:

Input: s = "leetcode", p = "ee*e"

Output: true

Explanation:

By replacing the '*' with "tcod", the substring "eetcode" matches the pattern.

Example 2:

Input: s = "car", p = "c*v"

Output: false

Explanation:

There is no substring matching the pattern.

Example 3:

Input: s = "luck", p = "u*"

Output: true

Explanation:

The substrings "u", "uc", and "uck" match the pattern.

 

Constraints:

1 <= s.length <= 50
1 <= p.length <= 50 
s contains only lowercase English letters.
p contains only lowercase English letters and exactly one '*'
*/

class Solution {
public:
    bool hasMatch(string s, string p) {
        int index = p.find('*');

        string subStrBefore = p.substr(0, index);
        string subStrAfter = p.substr(index + 1);

        int n = s.size();
        int len = subStrBefore.size() + subStrAfter.size();

        for(int i = 0; i <= (n - len); i++){
            if(s.substr(i, subStrBefore.size()) == subStrBefore){
                for(int j = i + subStrBefore.size(); j <= (n - subStrAfter.size()); j++){
                    if(s.substr(j, subStrAfter.size()) == subStrAfter){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};