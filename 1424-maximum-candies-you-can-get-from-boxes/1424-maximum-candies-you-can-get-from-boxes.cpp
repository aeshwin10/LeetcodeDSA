class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        unordered_set<int> seen;
        vector<bool> canOpen(status.begin(), status.end());
        vector<bool> visited(1001, false);
        int ans = 0;

        for(int box : initialBoxes){
            seen.insert(box);
            if(canOpen[box]) q.push(box);
        }

        while(!q.empty()){
            int curNode = q.front(); q.pop();
            if(visited[curNode]) continue;
            visited[curNode] = true;
            ans+=candies[curNode];

            for(int key: keys[curNode]){
                if(!canOpen[key]){
                    canOpen[key] = true;
                    if(seen.count(key)) q.push(key);
                }
            }

            for(int contained : containedBoxes[curNode]){
                seen.insert(contained);
                if(canOpen[contained]) q.push(contained);
            }
        }
        return ans;
    }
};