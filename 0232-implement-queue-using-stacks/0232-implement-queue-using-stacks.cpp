class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
        //return s1.size() == 0;
    }
};

//TC = O(2N) ...for push operation
//TC = O(1)  ...for all other operation except push
//SC = O(2n)

//This will be expensive if i have lot of push operations in my problem statement. bcoz here push is taking lot of time to push. thus for bunch of push operations this might be expensive.

// thus depending upon problem statement if our PS have very limited push operation then we can use it. but if we have significantly higher push operations than the top & pop then we are going for approch 2 where push is gonna take lesser time and top & pop are gonna take more time.

//thus 2nd approch going to focus on optimizing the push oprations assuming that we are doing lot of push operations & we are making top & pop operations expensive

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */