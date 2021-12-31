class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        visited[node] = 1;
        
        for(int j=0; j<graph[node].size();j++){
            if(visited[graph[node][j]]==1)
                return false;
            
            if(visited[graph[node][j]]==0){
                if(!dfs(graph[node][j],graph,visited))
                    return false;
            }
        }
        
        visited[node] = 2;
        
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        
        vector<int>visited(numCourses,0);
        
        for(int i=0; i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses; i++){
            if(visited[i]==0){
                if(!dfs(i,graph,visited)){
                    return false;
                }
            }
        }
        
        return true;
    }
};