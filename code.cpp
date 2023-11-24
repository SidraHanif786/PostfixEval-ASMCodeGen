// Sample arguments to test
//  23+4*      res 20
//  572+*8-    res 37
//  92/34*+    res 16
//  63/5*2+    res 12
//  921+/4*    res 12

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//============= Evaluating Postfix Expressions =========
void PostfixEval(string exp)
{
    string token = "Token ";
    string push = "Push ";
    string pop = "Pop  ";
    string blank = "      ";

    //============== Start of the operations =========
    stack<int> store;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        //===== pushing the operands
        if (isdigit(c))
        {
            int integer = c - '0'; // THIS LINE GOT ME STUCK FOR 3 HOURS :(
            store.push(integer);
            cout << token << exp[i] << blank << push << exp[i] << endl;
        }
        else
        {
            //====== handling expressions that are not well formed.
            if (store.size() < 2)
            {
                cout << "Error: Not enough operands for operator " << endl;
                break;
            }
            //=========pop first number
            int first = store.top();
            store.pop();
            //=========pop second number
            int second = store.top();
            store.pop();
            int res;

            if (exp[i] == '*')
            {
                res = first * second;
            }
            if (exp[i] == '/')
            {
                if (second > first)
                {
                    res = second / first;
                }
                else
                {
                    res = first / second;
                }
            }
            if (exp[i] == '+')
            {
                res = first + second;
            }
            if (exp[i] == '-')
            {
                if (second > first)
                {
                    res = second - first;
                }
                else
                {
                    res = first - second;
                }
            }
            store.push(res);
            cout << token << exp[i] << blank << pop << first << blank << pop << second << blank << push << res << endl;
        }
    }
    if (!store.empty())
    {
        cout << endl;
        cout << token << "END" << blank << pop << store.top() << endl;
    }
    //====== handling expressions that are not well formed.
    else
    {
        cout << "Error: No result available" << endl;
    }
}

//======= Generating Assembly Language Code ==========
void ASMCodeGen(string exp)
{
    string load = "LOAD  ";
    string store = "STORE ";
    string add = "ADD   ";
    string sub = "SUB   ";
    string mlt = "MLT   ";
    string div = "DIV   ";

    stack<int> asmStore;
    int arr[10];

    //============== Start of the operations =========
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        //===== pushing the operands
        if (isdigit(c))
        {
            int integer = c - '0';
            asmStore.push(integer);
        }
        else
        {
            //====== handling expressions that are not well formed.
            if (asmStore.size() < 2)
            {
                cout << "Error: Not enough operands for operator " << endl;
                break;
            }

            //=========pop first number
            int first = asmStore.top();
            asmStore.pop();

            //=========pop second number
            int second = asmStore.top();
            asmStore.pop();
            cout << load << second << endl;
            int res;

            if (exp[i] == '*')
            {
                res = first * second;
                cout << mlt << first << endl;
            }
            if (exp[i] == '/')
            {
                if (second > first)
                {
                    res = second / first;
                }
                else
                {
                    res = first / second;
                }
                cout << div << first << endl;
            }
            if (exp[i] == '+')
            {
                res = first + second;
                cout << add << first << endl;
            }
            if (exp[i] == '-')
            {
                if (second > first)
                {
                    res = second - first;
                }
                else
                {
                    res = first - second;
                }
                cout << sub << first << endl;
            }
            asmStore.push(res);
            cout << store << res << endl;
        }
    }
    if (!asmStore.empty())
    {
        cout << endl
             << "END OF CODE" << endl;
    }
    //====== handling expressions that are not well formed.
    else
    {
        cout << "Error: No result available" << endl;
    }
}

//========= MAIN ===========
int main(int argc, char *argv[])
{
    string exp;
    if (argc < 2)
    {
        cout << "Provide a postfix expression like this, 921+/4* " << endl;
        return 1;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            exp += argv[i];
        }
    }
    if (exp.length() < 3)
    {
        cout << "ERROR: Invalid postfix expression. Enter valid exp like this, 921+/4* " << endl;
        return 1;
    }
    //===================================
    //==== calling the function =========
    cout << "@@@@@@@@@@ Evaluating Postfix Expressions @@@@@@@@@" << endl;
    PostfixEval(exp);
    cout << endl
         << endl;
    cout << "@@@@@@@@@ Generating Assembly Language Code @@@@@@@@ " << endl
         << endl;
    ASMCodeGen(exp);

    return 0;
}
