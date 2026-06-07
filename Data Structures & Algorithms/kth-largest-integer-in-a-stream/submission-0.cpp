class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num:nums) pq.push(num);
    }
    
    int add(int val) {
        pq.push(val);
        queue<int> q;
        for(int i = 0; i < k - 1; ++i) {
            q.push(pq.top());
            pq.pop();
        }
        int ans = pq.top();
        while(!q.empty()) {
            pq.push(q.front());
            q.pop();
        }
        return ans;
    }
};
