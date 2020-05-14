class Solution {
public:
    vector<vector<int>> Adj;
    
    bool DFS_VISIT(int Node,vector<int> & u_color){
        u_color[Node]=1;
        for(auto it=Adj[Node].begin();it!=Adj[Node].end();it++){
            if(u_color[*it]==1)
                return true;
            else if(u_color[*it]==0){
                if(DFS_VISIT(*it, u_color)==true)
                    return true;
            }
        }
        u_color[Node]=-1;
        return false;
    }
    
    bool DFS(int NodeNum){
        vector<int> u_color(NodeNum,0);
        for(int i=0;i<NodeNum;i++){
            if(u_color[i]==0){
                if(DFS_VISIT(i, u_color)==true)
                    return true;
            }
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto it=prerequisites.begin();it!=prerequisites.end();it++){
            adj[it->front()].push_back(it->back());
        }
        Adj=adj;
        return !DFS(numCourses);
    }
};
