class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int N = players.size(), M = trainers.size();

        int j = 0, ans = 0, maxIndex = 0;

        for(int i = 0; i < N && j < M; i++) {
            int need = players[i];
			
			// When the jth trainer ability is less, move to next trainer
            while(trainers[j] < need) {
                j++;
                if(j == M) return ans; // If we move next to last trainer, return the answer.
            }
			
			// We got out right trainer for ith player, increment the answer and move to next trainer
            if(trainers[j] >= need) {
                ans++;
                j++;
            }
        }

        return ans;
    }
};