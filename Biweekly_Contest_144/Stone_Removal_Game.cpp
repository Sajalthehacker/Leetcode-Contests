// https://leetcode.com/problems/stone-removal-game/description/

/*
Alice and Bob are playing a game where they take turns removing stones from a pile, with Alice going first.

Alice starts by removing exactly 10 stones on her first turn.
For each subsequent turn, each player removes exactly 1 fewer stone than the previous opponent.
The player who cannot make a move loses the game.

Given a positive integer n, return true if Alice wins the game and false otherwise.

 

Example 1:

Input: n = 12

Output: true

Explanation:

Alice removes 10 stones on her first turn, leaving 2 stones for Bob.
Bob cannot remove 9 stones, so Alice wins.
Example 2:

Input: n = 1

Output: false

Explanation:

Alice cannot remove 10 stones, so Alice loses.
 

Constraints:

1 <= n <= 50
*/

class Solution {
public:
    bool canAliceWin(int n) {
        int player = 1, pick = 10;

        while(n >= pick){
            n = n - pick;
            player = 3 - player;
            pick--;
        }

        if(n == 0 && player == 2){
            return true;
        }

        return (player == 1) ? false : true;
    }
};