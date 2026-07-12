class Solution {
public:
    struct Task{
        int count;
        int lastUsed;
    };
    struct Cmp {
        bool operator()(Task* a, Task* b) const { return a->count < b->count; }
    };
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<Task*, vector<Task*>, Cmp> pq;
        unordered_map<char, int> counter;
        for(char c: tasks) counter[c]++;

        for(auto p:counter) {
            pq.push(new Task{p.second, -1});
        }

        int i = 1;

        while(!pq.empty()) {
            queue<Task*> temp;
            while(!pq.empty()) {
                Task* t = pq.top();
                pq.pop();
                if (t->lastUsed == -1 || i - t->lastUsed > n) {
                    t->lastUsed = i;
                    t->count--;
                    if(t->count == 0) {
                        delete t;
                    }
                    else {
                        temp.push(t);
                    }
                    break;
                }
                else {
                    temp.push(t);
                }
            }
            while(!temp.empty()) {
                pq.push(temp.front());
                temp.pop();
            }
            ++i;
        }
        return i-1;
    }
};
