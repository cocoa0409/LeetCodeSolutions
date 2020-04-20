// A simple calculator using stack containers
#include <cmath>                                          // For pow() function
#include <iostream>                                       // For standard streams
#include <stack>                                          // For stack<T> container
#include <algorithm>                                      // For remove()
#include <stdexcept>                                      // For runtime_error exception
#include <string>                                         // For string class
using std::string;

// Returns value for operator precedence
inline size_t precedence(const char op)
{
    if (op == '(' )
        return 0;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;

    throw std::runtime_error {string {"invalid operator in precedence() function: "} + op};
}

// Execute an operation
double execute(std::stack<char>& ops, std::stack<double>& operands)
{
    double result {};
    double rhs {operands.top()};                            // Get rhs...
    operands.pop();                                         // ...and delete from stack
    double lhs {operands.top()};                            // Get lhs...
    operands.pop();                                         // ...and delete from stack

    switch (ops.top())                                      // Execute current op
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
        case '^':
            result = std::pow(lhs, rhs);
            break;
        default:
            throw std::runtime_error {string{"invalid operator: "} + ops.top()};
    }
    ops.pop();                                              // Delete op just executed
    operands.push(result);
    return result;
}

void RecINPUT(string & exp){
    std::cout << "Enter an arithmetic expression and press Enter - enter an empty line to end:" << std::endl;
    std::getline(std::cin, exp, '\n');
    // Remove spaces
    exp.erase(std::remove(std::begin(exp), std::end(exp), ' '), std::end(exp));
    return;
}

void RecNUMs(std::stack<double> & operands,string exp,size_t &index){
    size_t i {};
    operands.push(std::stod(exp.substr(index), &i));  // Push rhs operand
    index += i;
}

void RecOPs(std::stack<char> & operators,std::stack<double> & operands,string exp,size_t &index){
    while (!operators.empty() && precedence(exp[index]) <= precedence(operators.top()))
        execute(operators, operands);                   //  Execute previous op.
    operators.push(exp[index++]);
}

void RecleftPARENTHESES(std::stack<char> & operators,string exp,size_t &index){
    while(exp[index]=='(')
    {
        operators.push(exp[index++]);
    }
}

void RecrightPARENTHESES(std::stack<char> & operators,std::stack<double> & operands,string exp,size_t &index){
    while(exp[index]==')')
    {
        while(operators.top()!='('){
            execute(operators, operands);
        }
        operators.pop();            // pop '('
        index++;
    }
}


bool DectEND(std::stack<char> & operators,std::stack<double> & operands,string exp,size_t &index){
    if (index == exp.length())                        // If we are at end of exp...
    {
        while (!operators.empty())                      // ...execute outstanding ops
            execute(operators, operands);
        return true;
    }
    return false;
}

int main()
{
    std::stack<double> operands;                            // Push-down stack of operands
    std::stack<char> operators;                             // Push-down stack of operators
    string exp;                                             // Expression to be evaluated
    std::cout << "An arithmetic expression can include the operators +, -, *, /, and ^ for exponentiation." << std::endl;
    try
    {
        while (true)
        {
            RecINPUT(exp);
            if (exp.empty()) break;
            size_t index=0;
            while (true)
            {
                RecleftPARENTHESES(operators, exp, index);              // Receive left parenthesis
                RecNUMs(operands, exp, index);  // Receive float numbers by std::stod(exp.substr(index), &i)
                if(DectEND(operators, operands, exp, index))     // 1 of 2 end condition: receive numbers
                    break;
                RecrightPARENTHESES(operators, operands, exp, index); // Receive right parenthesis
                if(DectEND(operators, operands, exp, index))     // 1 of 2 end condition: receive right parenthesis
                    break;
                RecOPs(operators , operands, exp, index); // Receive operator and judge "execute() computation"?
            }
            std::cout << "result = " << operands.top() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Calculator ending..." << std::endl;
}

