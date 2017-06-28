#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

// 1 + 3 * 2
// ->
//stack<char> mystack;

int isOperator(char c)
{
    if (c == '-')
    {
        return 1;
    }
    else if (c == '+')
    {
        return 2;
    }
    else if (c == '/')
    {
        return 3;
    }
    else if (c == '*')
    {
        return 4;
    }

    return 0;
}

bool balanceCheck(string expression)
{
    stack<char> mystack;
    for (string::iterator it = expression.begin(); it != expression.end(); ++it)
    {
        if (*it == ')')
        {
            if (mystack.empty())
            {
                return false;
            }
            char c = mystack.top();
            if (c != '(')
            {
                return false;
            }
            mystack.pop();
        }
        else if (*it == '(')
        {
            mystack.push('(');
        }
    }

    if (!mystack.empty())
    {
        return false;
    }
    return true;
}

string convertToPostFix(string strExpression)
{
    string postfixExpression;
    stack<char> mystack;
    for (string::iterator it = strExpression.begin(); it != strExpression.end(); ++it)
    {
        if (*it == '(')
        {
            mystack.push('(');
        }
        else if (*it == ')')
        {
            char c = mystack.top();
            while (c != '(')
            {
                postfixExpression.push_back(c);
                mystack.pop();
                c = mystack.top();
            }
            mystack.pop(); // pop '('
        }
        else if (isOperator(*it) == 0)
        {
            postfixExpression.push_back(*it);
        }
        else if (isOperator(*it) > 0)
        {
            if (mystack.empty())
            {
                mystack.push(*it);
            }
            else
            {
                int opval = isOperator(*it);
                while (!mystack.empty() && opval < isOperator(mystack.top()))
                {
                    postfixExpression.push_back(mystack.top());
                    mystack.pop();
                }
                mystack.push(*it);
            }
        }
    }

    while (!mystack.empty())
    {
        postfixExpression.push_back(mystack.top());
        mystack.pop();
    }

    return postfixExpression;
}

int arithmatic(int num1, int num2, char oper)
{
    if (oper == '*')
    {
        return num1 * num2;
    }
    else if (oper == '/')
    {
        return num1 / num2;
    }
    else if (oper == '+')
    {
        return num1 + num2;
    }

    return num1 - num2;
}

int evaluatePostfix(string expression)
{
    stack<char> mystack;
    int value = 0;
    for (string::iterator it = expression.begin(); it != expression.end(); ++it)
    {
        if (!isOperator(*it))
        {
            mystack.push(*it);
        }
        else
        {
            int num2 = mystack.top() - '0';
            mystack.pop();
            int num1 = mystack.top() - '0';
            mystack.pop();
            value = arithmatic(num1, num2, *it);
            mystack.push(value + '0');
        }
    }

    return mystack.top() - '0';
}

bool evaluate(const char *expression, int &result)
{
    string strExpression = expression;
    stack<char> mystack;
    bool isBalanced = balanceCheck(strExpression);
    if (!isBalanced)
    {
        return false;
    }
    string postfixExpression = convertToPostFix(strExpression);
    result = evaluatePostfix(postfixExpression);

    return true;
}

int main()
{
    string expression = "(1+3)*2";
    int result = 0;
    const char *charArr = expression.c_str();
    bool isSuccess = evaluate(charArr, result);

    cout << isSuccess << endl;
    cout << result << endl;

    return 0;
}