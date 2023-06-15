
/*

//Solutions 1) Depth First Search

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


/*
Solution 2) Breadth First Search

bool BreadthFirstSearch(vector<vector<int>>& DirectedGraph, int numCourses, vector<int> dependency) {
    for (int i = 0; i < numCourses; i++) {
        int CourseIndex = 0;
        for (; CourseIndex < numCourses; CourseIndex++) {
            if (!dependency[CourseIndex]) break;
        }

        if (CourseIndex == numCourses) return false;

        dependency[CourseIndex]--;

        for (auto dependent : DirectedGraph[CourseIndex]) {
            dependency[dependent]--;
        }

    }

    return true;

}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    vector<vector<int>> DirectedGraph(numCourses);
    vector<int> dependency(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
        DirectedGraph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        dependency[prerequisites[i][0]]++;
    }

    return BreadthFirstSearch(DirectedGraph, numCourses, dependency);

}

*/

//Solution 3) Topological Sort + Breadth First Search

class Solution {
public:

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> AdjList(numCourses);
    vector<int> Dependency(numCourses);

    queue<int> Independent;

    int CourseIndex;

    for (auto prerequisite : prerequisites) {
        AdjList[prerequisite[1]].push_back(prerequisite[0]);
        Dependency[prerequisite[0]]++;
    }

    for (int j = 0; j < numCourses; j++)
        if (Dependency[j] == 0) Independent.push(j);

    for (int i = 0; i < numCourses; i++) {

        if (Independent.empty()) return false;

        CourseIndex = Independent.front();
        Independent.pop();
        Dependency[CourseIndex]--;

        for (auto dependent : AdjList[CourseIndex]) {
            Dependency[dependent]--;

            if (!Dependency[dependent]) Independent.push(dependent);
        }
    }
    
    return true;

}

};


