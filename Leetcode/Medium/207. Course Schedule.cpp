
/*

//Solutions 1) DFS

bool DFS(vector<vector<int>>& AdjList, int node, vector<bool>& Processing, vector<bool>& Done){
    if(Processing[node]) return false;

    if(Done[node]) return true;

    Processing[node] = Done[node] = true;

    for(int i = 0; i<AdjList[node].size(); i++){
        if(!DFS(AdjList, AdjList[node][i], Processing, Done)) return false;
    }

    Processing[node] = false;

    return true;
}


class Solution {
public:

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> AdjList(numCourses);
    vector<bool> Processing (numCourses, false);
    vector<bool> Done (numCourses, false);

    bool flag = 0;

    for(int i = 0; i<prerequisites.size(); i++){
        AdjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i = 0; i<numCourses; i++){
        flag = DFS(AdjList, i, Processing, Done);

        if(!flag) return false;
    }

    return true;

}

};

*/
