class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> valStack;
        for(int i = 0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                int val1= valStack.top();
                valStack.pop();
                int val2=valStack.top();
                valStack.pop();
                valStack.push(val1+val2);
            }
            else if(tokens[i]=="-"){
                int val1= valStack.top();
                valStack.pop();
                int val2=valStack.top();
                valStack.pop();
                valStack.push(val2-val1);
            }
            else if(tokens[i]=="*"){
                int val1= valStack.top();
                valStack.pop();
                int val2=valStack.top();
                valStack.pop();
                valStack.push(val2*val1);
            }
            else if(tokens[i]=="/"){
                int val1= valStack.top();
                valStack.pop();
                int val2=valStack.top();
                valStack.pop();
                valStack.push(val2/val1);
            }
            else{
                valStack.push(std::stoi(tokens[i]));
            }

        }
        int res=valStack.top();
        valStack.pop();
        return res;
    }
};
