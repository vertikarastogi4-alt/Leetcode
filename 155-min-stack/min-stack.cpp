class MinStack {
    stack<long long> st;
    long long minVal;

public:
    MinStack() {
       
    }
    
    void push(int value) {
       if (st.empty()) {
            st.push(value);
            minVal = value;
        }
        else if (value >= minVal) {
            st.push(value);
        }
        else {
            st.push(2LL * value - minVal);
            minVal = value;
        }
    }
    
    void pop() {
        if (st.top() < minVal) {
            minVal = 2LL * minVal - st.top();
        }
        st.pop();   
    }
    
    int top() {
        if (st.top() < minVal) {
            return minVal;
        }
        return st.top();
    }
    
    int getMin() {
        return minVal;
    }
};

