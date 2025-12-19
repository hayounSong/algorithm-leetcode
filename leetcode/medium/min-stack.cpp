class MinStack {
public:
    int v[30001]={0};
    int mins[30001]={0};
    int index=0;
    MinStack() {   
    }
    void push(int val) {
        v[index]=val;
        if(index>0){
            mins[index]=min(val,mins[index-1]);
        }
        else{
            mins[index]=val;
        }
        index++;
    }
    
    void pop() {
        
        index--;
    }
    
    int top() {
        return v[index-1];
    }
    
    int getMin() {
    
        return mins[index-1];
    }
};
