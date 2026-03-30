class Solution {
public:
    bool isSign(string s){
        return (s=="+" || s=="-" || s=="*" || s=="/");
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string& str: tokens){
            if(isSign(str)){
                int one = s.top(); s.pop();
                int two = s.top(); s.pop();

                if(str == "+") s.push(two + one);
                else if(str == "-") s.push(two - one);
                else if(str == "*") s.push(two * one);
                else if(str == "/") s.push(two / one);
            } else {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};