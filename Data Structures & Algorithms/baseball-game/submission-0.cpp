class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int sum = 0;
        for(string operation: operations) {
            if(operation == "+") {
                int temp = s.top();
                int newScore = temp;
                s.pop();
                newScore += s.top();
                s.push(temp);
                s.push(newScore);
                sum += newScore;
            }
            else if(operation == "D") {
                int temp = s.top();
                sum += 2 * temp;
                s.push(2 * temp);
            }
            else if(operation == "C") {
                sum -= s.top();
                s.pop();
            }
            else {
                int num = stoi(operation);
                sum += num;
                s.push(num);
            }
        }
        return sum;
    }
};