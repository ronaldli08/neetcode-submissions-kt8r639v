class MedianFinder {
public:

    priority_queue<int> minHeap;
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    int size = 0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(num);
        ++size;
    }
    
    double findMedian() {
        priority_queue<int> tempMin = minHeap;
        priority_queue<int, vector<int>, greater<int>> tempMax = maxHeap;

        for(int i = 0; i < size / 2; ++i) {
            tempMin.pop();
            tempMax.pop();
        }
        return (tempMin.top() + tempMax.top()) / 2.0;
    }
};
