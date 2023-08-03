//Postfix Calculator
 
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <stack>
#include <cmath>
/*
 The Australian philosopher and early computer scientist Charles L. Hamblin proposed a scheme in which the operators follow the operands (postfix operators), resulting in the Reverse Polish notation. This has the advantage that the operators appear in the order required for computation.For example, the expression a + b * c in a postfix expression is a b c * +.  Code up this process using STL!
 */
using namespace std; 

void evaluateExpression(ifstream& inpF, ofstream& outF, stack<double>& stackExp, char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stack<double>& stackExp, char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);
void printResult(ofstream& outF, stack<double>& stackExp, bool isExpOk);
void clearStack(stack<double>& stackExp);
//need to add conversion function that converts standard into reverse polish
void 


int main()
{
    bool expressionOk;
    char ch;
    stack<double> stackExp;
    ifstream infile;
    ofstream outfile;
 
    infile.open("RpnData2.txt");

    //opening input and creating a conversion file with all reverse polish expressions
    //close input and open conversion file instead and then continue on

    if (!infile)
    {
        cout << "Cannot open the input file. " << "Program terminates!" << endl;
        return 1;
    }

    outfile.open("RpnOutput.txt");
    outfile << fixed << showpoint;
    outfile << setprecision(2); 

    infile >> ch;
    while (infile)
    {
        clearStack(stackExp);
        expressionOk = true;
        outfile << ch;

        evaluateExpression(infile, outfile, stackExp, ch, expressionOk);
        printResult(outfile, stackExp, expressionOk);
        infile >> ch; //begin processing the next expression
    } //end while 

    infile.close();
    outfile.close();

    return 0;

} //end main

void evaluateExpression(ifstream& inpF, ofstream& outF, stack<double>& stackExp, char& ch, bool& isExpOk)
{
    double num;

    while (ch != '=')
    {
        switch (ch)
        {
        case '#': 
            inpF >> num;
            outF << num << " ";
            stackExp.push(num);
            break;
        default: 
            evaluateOpr(outF, stackExp, ch, isExpOk);
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch;
            outF << ch;

            if (ch != '#')
                outF << " ";
        }
        else
            discardExp(inpF, outF, ch);
    } //end while (!= '=')
}

void evaluateOpr(ofstream& out, stack<double>& stackExp, char& ch, bool& isExpOk)
{
    double op1, op2;

    if (stackExp.empty())
    {
        out << " (Not enough operands)";
        isExpOk = false;
    }
    else
    {
        op2 = stackExp.top();
        stackExp.pop();

        if (stackExp.empty())
        {
            out << " (Not enough operands)";
            isExpOk = false;
        }
        else
        {
            op1 = stackExp.top();
            stackExp.pop();

            switch (ch)
            {
            case '+': 
                stackExp.push(op1 + op2);
                break;
            case '-': 
                stackExp.push(op1 - op2);
                break;
            case '*': 
                stackExp.push(op1 * op2);
                break;
            case '/': 
                if (op2 != 0)
                    stackExp.push(op1 / op2);
                else
                {
                    out << " (Division by 0)";
                    isExpOk = false;
                }
                break;

            case '^': //including power operator
                stackExp.push(pow(op1, op2));
                break;
            default:  
                out << " (Illegal operator)";
                isExpOk = false;
            }//end switch
        } //end else
    } //end else
} //end evaluateOpr

void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=')
    {
        in.get(ch);
        out << ch;
    }
} //end discardExp

void printResult(ofstream& outF, stack<double>& stackExp,
                 bool isExpOk)
{
    double result;

    if (isExpOk) //if no error, print the result
    {
        if (!stackExp.empty())
        {
            result = stackExp.top();
            stackExp.pop();

            if (stackExp.empty())
                outF << result << endl;
            else
                outF << " (Error: Too many operands)" << endl;
        } //end if
        else
            outF << " (Error in the expression)" << endl;
    }
    else
        outF << " (Error in the expression)" << endl;

    outF << "_________________________________" 
         << endl << endl;
} //end printResult

void clearStack(stack<double>& stackExp)
{
	while (!stackExp.empty())
		stackExp.pop();
}
