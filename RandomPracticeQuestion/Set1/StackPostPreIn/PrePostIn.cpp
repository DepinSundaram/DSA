#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int getPriority (char c) {
    if (c == '^') {
        return 3;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}
/*
void infixToPostfix(string InfixEx) {

    stack<char> st;
    string res;

    for (int i = 0; i < InfixEx.length(); i++) {
        char c = InfixEx[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            res += c;
        } else if (c == '('){
            st.push(c);
        } else if( c == ')') {
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                res +=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (st.size()) {
        res += st.top();
        st.pop();
    }

    std::cout << res;
}

*/
bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = infix.size();
  stack < char > char_stack;
  string output;

  for (int i = 0; i < l; i++) {

    // If the scanned character is an
    // operand, add it to output.
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (infix[i] == '(')
      char_stack.push('(');

    // If the scanned character is an
    // ‘)’, pop and output from the stack
    // until an ‘(‘ is encountered.
    else if (infix[i] == ')') {
      while (char_stack.top() != '(') {
        output += char_stack.top();
        char_stack.pop();
      }

      // Remove '(' from the stack
      char_stack.pop();
    }

    // Operator found
    else {
      if (isOperator(char_stack.top())) {
        if (infix[i] == '^') {
          while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        } else {
          while (getPriority(infix[i]) < getPriority(char_stack.top())) {
            output += char_stack.top();
            char_stack.pop();
          }

        }

        // Push current Operator on stack
        char_stack.push(infix[i]);
      }
    }
  }
  while (!char_stack.empty()) {
    output += char_stack.top();
    char_stack.pop();
  }
  return output;
}

string InfixToPreFix(string infix) {
    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  std::cout << InfixToPreFix(exp);
  return 0;
}