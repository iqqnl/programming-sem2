#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    Stack<int> stack;
    int num;

    while (cin >> num && num != 0)
    {
        stack.push(num);
    }
    
    while (stack.count() > 0)
    {
        int elem = stack.pop();
        if (elem > 0)
        {
            cout << elem << " ";
        }
    }
    
    return 0;
}