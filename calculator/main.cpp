// Add item to stack
//(1 + 3) * 2

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

bool evaluate(const char *expression, int &result)
{
    // Loop through char array
    int arrSize = sizeof(expression) / sizeof(*expression);

    result = arrSize;
    return true;
}



int main()
{
    string expression = "Hello";
    int result = 0;
    const char *charArr = expression.c_str();
    bool isSuccess = evaluate(charArr, result);
    
    cout << isSuccess << endl;
    cout << result << endl;
    
    return 0;
}