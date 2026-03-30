class MinStack {
public:
    stack<int> s;
    stack<int> minstack;
    MinStack() {
        while(!s.empty()){
            s.pop();
        }
        while(!minstack.empty()){
            minstack.pop();
        }
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minstack.push(val);
        }else{
            if(!minstack.empty() && minstack.top()<val){
                // minstack.push(val);
                 s.push(val);
            }else{
                 minstack.push(val);
                 s.push(val);
            }
           
        }
    }
    
    void pop() {
        int v = s.top();
        s.pop();
        if(v==minstack.top()){
            minstack.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
