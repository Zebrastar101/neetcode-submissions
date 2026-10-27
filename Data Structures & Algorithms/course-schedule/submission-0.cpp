class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for( int c=0; c<numCourses;c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int i){
        if(visited.count(i)){
            return false;
        }
        if(preMap[i].empty()){
            return true;
        }
        visited.insert(i);
        for( auto& pre: preMap[i]){
            if(!dfs(pre)){
                return false;
            }
        }
        visited.erase(i);
        preMap[i].clear();
        return true;
    }
};
