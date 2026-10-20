class MinStack {
private:
    long min;
    std::stack<long> stk;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            min=val;
        }
        else{
        stk.push(val-min);
        if(min>val){min=val;}}
    }
    
    void pop() {
        if(stk.empty()){return;}
        long p= stk.top();
        stk.pop();
        if(p<0){ min=min-p;}

    }
    int top() {
        long t= stk.top();
        if(t<=0){
            return (int)min;
        }
        return (int)(stk.top()+min);
    }
    
    int getMin() {
        return (int)min;
    }
};
