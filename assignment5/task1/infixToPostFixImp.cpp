//
//
//  InfixPostfix
//
//  Created by Antoun, Sherine on 11/11/21.
//  Copyright © 2021 Antoun, Sherine. All rights reserved.
//  Implementation File
 
#include <iostream>
#include <string>
#include <stack>
// #include "myStack.h"
#include "infixToPostfix.h"
  
using namespace std; 
 

string infixToPostfix::getInfx()
{
    return this->infx;
}
string infixToPostfix::getPfx()
{
    return this->pfx;
}

void infixToPostfix::convertToPostfix()
{
    stack<char> stackGuy;
    int i;
    char stackOpr;

    i = 0;
    pfx = "";

    int len = infx.length();

    for (i = 0; i < len; i++)
        if (infx[i] >= 'A' && infx[i] <= 'Z')
            pfx = pfx + infx[i];
        else
        {
            switch (infx[i])
            {
            case '(':  
                stackGuy.push(infx[i]);
                break;
            case ')':   
                stackOpr = stackGuy.top();
                stackGuy.pop();

                while (stackOpr != '(')
                {
                    pfx = pfx + stackOpr;

                    if (!stackGuy.empty())
                    {
                        stackOpr = stackGuy.top();
                        stackGuy.pop();
                    }
                    else
                        break;
                }
                break;
			case ';': 
			case ' ':  
                break;
			   
			default:
                if (stackGuy.empty())
                    stackGuy.push(infx[i]);
                else
                {
                    stackOpr = stackGuy.top();
                    stackGuy.pop();

                    while (precedence(stackOpr,infx[i]))
                    {
                        pfx = pfx + stackOpr;
                        if (!stackGuy.empty())
                        {
                            stackOpr = stackGuy.top();
                            stackGuy.pop();
                        }
                        else
                            break;
                    }

                    if (!precedence(stackOpr,infx[i]))
                        stackGuy.push(stackOpr);

                    stackGuy.push(infx[i]);
                }
										
            }//end switch
        }//end else

    while (!stackGuy.empty())
    {
        pfx += stackGuy.top();
        stackGuy.pop();
    }
}//end convertToPostfix


bool infixToPostfix::precedence(char opr1, char opr2)
{
    int prec1, prec2;

    if (opr1 == '*' || opr1 =='/')
        prec1 = 2;
	else if (opr1 == '+' || opr1 == '-')
        prec1 = 1;
    else if (opr1 == '(')
        prec1 = 0;

    if (opr2 == '*' || opr2 == '/')
        prec2 = 2;
    else if (opr2 =='+' || opr2 == '-')
        prec2 = 1;

	return (prec1 >= prec2);
}//end precedence

void infixToPostfix::getInfix(string data)
{
    infx = data;
    convertToPostfix();
}

void infixToPostfix::showInfix()
{
    cout << "Infix Expression: " << infx << endl;
}

void infixToPostfix::showPostfix()
{
    cout << "Postfix Expression: " << pfx << endl;
}

infixToPostfix::infixToPostfix(string ifx)
{
    infx = ifx;
    convertToPostfix();
}
