#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while (st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st1.pop();
        while (st2.empty()) {
            st1.push(st1.top());
            st2.pop();
        }

    }
    
    int peek() {
        while (st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st1.pop();
        while (st2.empty()) {
            st1.push(st1.top());
            st2.pop();
        }
    }

    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    cout<<q.empty();
    return 0;
}
