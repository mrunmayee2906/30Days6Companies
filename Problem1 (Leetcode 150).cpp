int evalRPN(vector<string>& tokens) {
    stack<int> stack;

    for (string &s: tokens) {
        if((s.length() > 1) || isdigit(s[0])){
            // if the length is greater than 1 then it is a number
            // or if the string is a digit
            // push the number to the stack
            stack.push(stoi(s));                
        }
        else {
            // else if there are characters, then check which one is them
            // get the 2 operands from the top
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();

            // push the appropriate result back to the stack
            if (s == "+") {
                stack.push(op1 + op2);
            } else if (s == "-") {
                stack.push(op1 - op2);
            } else if (s == "*") {
                stack.push(op1 * op2);
            } else if (s == "/") {
                stack.push(op1 / op2);
            }
        }
    }

    return stack.top();
}
