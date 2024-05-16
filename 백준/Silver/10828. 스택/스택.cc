#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string order;
        cin >> order;

        if (order == "push")
        {
            int number;
            cin >> number;

            stack.push(number);
        }
        else if (order == "top")
        {
            if (stack.empty()) cout << -1 << endl;
            else cout << stack.top() << endl;
        }
        else if (order == "size")
        {
            cout << stack.size() << endl;
        }
        else if (order == "empty")
        {
            if (stack.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (order == "pop")
        {
            if (stack.empty()) cout << -1 << endl;
            else
            {
                cout << stack.top() << endl;
                stack.pop();
            }
        }

    }
}