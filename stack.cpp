/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 2 : Stack:
                        1.Implementation of Stack
                        2.Implementation of Matching Parenthesis
                        3.Conversion of Infix to Postfix
                        4.Evaluation of Postfix.
*/

#include <bits/stdc++.h>
using namespace std;

//Function declarations 
bool isFull(int n, int top);
bool isEmpty(int top);
void intPush(int stack[], int &top, int n);
void intPop(int stack[], int &top);
void intDisplay(int stack[], int &top);
void simple_stack(int stack[], int &top, int n);
void balanced_check();
bool isOperator(char ch);
void inToPost();
void solvePostfix();

//check if stack is full
bool isFull(int top, int n)
{
    if (top == n - 1)
        return true;
    return false;
}

//check if stack is empty
bool isEmpty(int top)
{
    if (top == -1)
        return true;
    else
        return false;
}

//push inteeger into stack
void intPush(int stack[], int &top, int n)
{
    if (isFull(top, n))          //can't push if stack is full
    {
        cout << "Stack is full!!!\n";
        return;
    }
    cout << "Enter element to push: \n";
    int ele;
    cin >> ele;
    stack[++top] = ele;         //push the element and increment the top
    cout << stack[top] << " entered in the stack." << endl;
}

void intPop(int stack[], int &top)
{
    if (isEmpty(top))          //can't pop if stack is already epmty
    {
        cout << "Stack is empty!!!\n";
        return;
    }
    else
    {
        cout << "Poped element: " << stack[top--] << endl;    //pop the top and decrement the top
    }

    if (top != -1)
    {
        cout << "Element at top: " << stack[top] << endl;     //print if top element is present
    }
    else
        cout << "Stack is empty now!!!\n";                    //else print stack is empty
}

void intDisplay(int stack[], int &top)
{
    int temp = top;                                            //store top in temporory variable so that "top" should not change
    if (temp == -1)
    {
        cout << "STACK IS EMPTY!!!\n";
        return;
    }
    cout << "Stack: ";
    while (temp != -1)
    {
        cout << stack[temp--] << " ";
    }
    cout << endl;
}

void simple_stack(int stack[], int &top, int n)
{
    cout << "\n\nChoose the operation: \n";
    cout << " 1.Push\n 2.Pop.\n 3.Display.\n 4.Back to menu.\n\n";
    int operation;
    cin >> operation;
    switch (operation)
    {
    case 1:
    {
        intPush(stack, top, n);
        simple_stack(stack, top, n);
        break;
    }

    case 2:
    {
        intPop(stack, top);
        simple_stack(stack, top, n);
        break;
    }

    case 3:
    {
        intDisplay(stack, top);
        simple_stack(stack, top, n);
        break;
    }

    case 4:
    {
        return;
        break;
    }

    default:
    {
        cout << "Invalid choice!!!";
        simple_stack(stack, top, n);
    }
    }
}

// void charDisplay(char stack[], int &top)
// {
//     int temp = top;
//     if (temp == -1)
//     {
//         cout << "STACK IS EMPTY!!!\n";
//         return;
//     }
//     cout << "Stack: ";
//     while (temp != -1)
//     {
//         cout << stack[temp--] << " ";
//     }
//     cout << endl;
// }

void balanced_check()
{
    cout << "Enter the string of paranthesis\n";
    string s;
    cin >> s;
    int n = s.length();
    // cout << n << endl;
    char stack[n];
    int i = 0, top = -1;

    while (i < n)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')             //push if opening bracket
        {
            stack[++top] = s[i];
        }
        else
        {
            string temp;
            temp = temp + stack[top] + s[i];

            if (temp == "{}" || temp == "[]" || temp == "()")      //pop if opening baracket at top of stack matchs closing bracket in string
            {
                top--;
            }
            else
            {
                cout << "\nNOT BALANCED\n";                        //if not matching, not balanced
                return;
            }
        }
        i++;
        // charDisplay(stack, top);
    }

    if (isEmpty(top))
    {
        cout << "\nBALANCED\n";                     //balanced only if stack is empty
        return;
    }
    else
    {
        cout << "\nNOT BALANCED\n";
        return;
    }
}

bool isOperator(char ch)
{
    return (!isalpha(ch) && !isdigit(ch));              // returns true if char is any of +,-,*,/,^  ****NOTE*** (paranthesis are handled in conditional statements)
}

int opPrec(char ch)
{
    if (ch == '-' || ch == '+')                         // +,- have low precedence
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')                    // *, /have higher precedence than +, -
    {
        return 2;
    }
    else if (ch == '^')                                 // ^ operator have highest priority
    {
        return 3;
    }
    return 0;
}

void inToPost()
{
    cout << "\nEnter the expression : ";
    string s;
    cin >> s;
    int n = s.length();
    cout << n << endl;
    char stack[n];
    int i = 0, top = -1;
    string postfix = "";
    while (i < n)
    {
        if (s[i] == '(')
        {
            stack[++top] = '(';
        }
        else if (s[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix += stack[top--];
            }
            top--;
        }
        else if (isalpha(s[i]) || isdigit(s[i]))
        {
            postfix += s[i];
            cout << postfix << endl;
        }
        else if (isOperator(s[i]))
        {
            if (isEmpty(top))
            {
                stack[++top] = s[i];
            }
            else
            {
                while (opPrec(s[i]) <= opPrec(stack[top]) && !isEmpty(top))
                {
                    postfix += stack[top--];
                }
                stack[++top] = s[i];
            }
        }
        i++;
    }
    while (!isEmpty(top))
    {
        postfix += stack[top--];
    }

    cout << postfix << endl;
}

void solvePostfix()
{
    cout << "\nEnter the expression: ";
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, top = -1;
    int stack[n];
    int a, b;

    while (i < n)                               //iterate over string
    {
        // if(s[i]==' '){
        //     continue;
        // }
        if (isdigit(s[i]))
        {
            // int num = 0;

            // while(isdigit(s[i])){
            //     num = num * 10 + (s[i]-'0');
            //     i++;
            // }
            // i--;
            // stack[++top] = num;
            stack[++top] = s[i] - '0';                  //convert character to integer and push into stack
        }
        else
        {
            a = stack[top--];                           // top value
            b = stack[top--];                           // top-1 value
            switch (s[i])
            {
            case '+':                                   //add
                stack[++top] = (b + a);                 
                break;
            case '-':                                   //sub
                stack[++top] = (b - a);
                break;
            case '*':                                   //mult
                stack[++top] = (b * a);
                break;
            case '/':                                   //div
                stack[++top] = (b / a);
                break;
            case '^':                                   //pow
                stack[++top] = pow(b, a);
                break;
            }
        }
        i++;
    }
    cout << "Solution of expression: " << stack[top] << endl;
}

void ops()
{
    cout << "\n===============================================\n";
    cout << "\nEnter your choice: \n";
    cout << " 1.Simple stack operations.\n 2.Balanced parenthesis check.\n 3.Infix to postix.\n 4.Solve postfix expression.\n 5.Exit\n\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Enter the size of stack: \n";
        int n;
        cin >> n;
        int stack[n];
        int top = -1;
        simple_stack(stack, top, n);
        ops();
        break;
    }

    case 2:
    {
        balanced_check();
        ops();
        break;
    }

    case 3:
    {
        inToPost();
        ops();
        break;
    }

    case 4:
    {
        solvePostfix();
        ops();
        break;
    }

    case 5:
    {
        return;
        break;
    }

    default:
    {
        cout << "Invalid choice\n";
        ops();
    }
    }
}

int main()
{
    ops();
    return 0;
}