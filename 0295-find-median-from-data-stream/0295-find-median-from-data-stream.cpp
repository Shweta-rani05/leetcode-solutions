class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {}

    void addNum(int num) {
        if (maxheap.empty() && minheap.empty()) {
            maxheap.push(num);
        } else {
            if (maxheap.top() < num) {
                minheap.push(num);
            } else {
                maxheap.push(num);
            }
        }
        // Balance the heaps here
        if (maxheap.size() - minheap.size() == 2) {
            int element = maxheap.top();
            maxheap.pop();
            minheap.push(element);
        } else if (minheap.size() - maxheap.size() == 2) {
            int element = minheap.top();
            minheap.pop();
            maxheap.push(element);
        }
    }

    double findMedian() {
        int n = maxheap.size();
        int m = minheap.size();

        if ((n + m) % 2 == 0) {
            return ((double)maxheap.top() + (double)minheap.top()) / 2.0;
        }
        if (n > m) {
            return maxheap.top();
        } else {
            return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */