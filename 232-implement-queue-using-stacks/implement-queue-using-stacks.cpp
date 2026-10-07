class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> inputStack;
    stack<int> outputStack;
 
    void shiftStacks() {
        if (!outputStack.empty()) {
            return;
        }

        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }
    void push(int x) {
                inputStack.push(x);

    }
    
    int pop() {
                shiftStacks();
                if (outputStack.empty()) {
            return -1;
        }
 
        int frontValue = outputStack.top();
        outputStack.pop();
        return frontValue;

    }
    
    int peek() {
         shiftStacks();
 
        if (outputStack.empty()) {
            return -1;
        }
 
        return outputStack.top();
        
    }
    
    bool empty() {
          return inputStack.empty() && outputStack.empty();
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