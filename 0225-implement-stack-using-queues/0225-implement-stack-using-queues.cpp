
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);

        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;

        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


//TC = O(N) ...for push operation
//TC = O(1) ...for all other operation except push
//SC = O(N)  