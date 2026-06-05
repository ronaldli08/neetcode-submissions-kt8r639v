class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        int pos = 0;

        vector<int> lastPush(n, -1);

        for(int i = 0; i < n; ++i) q.push(i);

        while(1) { // add condition
            int front = q.front();
            q.pop();
            if(students[front] == sandwiches[pos]) {
                ++pos;
                if(pos == n) return 0;
            }
            else {
                q.push(front);
                if(lastPush[front] == q.size() + 1) {
                    break;
                }
                else {
                    lastPush[front] = q.size() + 1;
                }
            }
        }
        return q.size();
    }
};