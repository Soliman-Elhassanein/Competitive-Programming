class Solution {
public:

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> AdjList(numCourses);
    vector<int> Dependency(numCourses);

    queue<int> Independent;

    vector<int> CoursesOrder;

    int CourseIndex;

    for (auto prerequisite : prerequisites) {
        AdjList[prerequisite[1]].push_back(prerequisite[0]);
        Dependency[prerequisite[0]]++;
    }

    for (int j = 0; j < numCourses; j++)
        if (Dependency[j] == 0) Independent.push(j);

    for (int i = 0; i < numCourses; i++) {

        if (Independent.empty()) return {};

        CourseIndex = Independent.front();
        CoursesOrder.push_back(Independent.front());
        Independent.pop();
        Dependency[CourseIndex]--;

        for (auto dependent : AdjList[CourseIndex]) {
            Dependency[dependent]--;

            if (!Dependency[dependent]) Independent.push(dependent);
        }
    }
    
    return CoursesOrder;

}

};
