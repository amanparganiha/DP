class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int , int> pos;
    bool solve(vector<int> &stones , int idx , int jump){
        int n = stones.size();

        if(idx == n-1) return true;
        if(dp[idx][jump] != -1) return dp[idx][jump];

        for(int nextJump = jump -1 ; nextJump <= jump + 1 ; nextJump++){
            if(nextJump <= 0) continue;
            int nextStone = stones[idx] + nextJump;

            if(pos.count(nextStone)){
                if(solve(stones, pos[nextStone] , nextJump))
                return dp[idx][jump] = true;
            }
        }
        return dp[idx][jump] = false;
    }


    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        dp.assign(n , vector<int> (n+1 , -1));
        for(int i = 0 ; i < n ; i++){
            pos[stones[i]] = i;
        }
        return solve(stones ,  1 , 1);
    }
};