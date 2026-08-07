class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> coursesLeft(numCourses, 0);

        map<int, vector<int>> m;

        for (int i = 0; i < prerequisites.size(); i++) {
            coursesLeft[prerequisites[i][0]]++;
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        int remaining = numCourses;

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if(coursesLeft[i] == 0) {
                q.push(i);
                remaining--;
            }
        }
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            for(int course:m[front]) {
                coursesLeft[course]--;
                if(coursesLeft[course] == 0) {
                    remaining--;
                    q.push(course);
                }
            }
        }
        if(remaining == 0) {
            return true;
        }
        else {
            return false;
        }
    }
};
