#include<bits/stdc++.h>

using namespace std;

class Quadruple {
public:
    std::string op;
    std::string arg1;
    std::string arg2;
    std::string result;

    Quadruple(std::string op, std::string arg1, std::string arg2, std::string result)
        : op(op), arg1(arg1), arg2(arg2), result(result) {}
};

class QuadrupleGenerator {
private:
    std::vector<Quadruple> quadruples;
    int tempCounter;

    std::string getNextTemp() {
        return "t" + std::to_string(++tempCounter);
    }

public:
    QuadrupleGenerator() : tempCounter(0) {}

    void generateQuadruples(const std::string& postfix) {
        std::stack<std::string> operandStack;

        for (char c : postfix) {
            if (std::isalnum(c)) {
                operandStack.push(std::string(1, c));
            } else {
                std::string arg2 = operandStack.top(); operandStack.pop();
                std::string arg1 = operandStack.top(); operandStack.pop();
                std::string result = getNextTemp();
                quadruples.emplace_back(std::string(1, c), arg1, arg2, result);
                operandStack.push(result);
            }
        }
    }

    void printQuadruples() {
        std::cout << "\nQuadruple Table:\n";
        std::cout << "------------------------------\n";
        std::cout << "Op\tArg1\tArg2\tResult\n";
        std::cout << "------------------------------\n";
        for (const auto& q : quadruples) {
            std::cout << q.op << "\t" << q.arg1 << "\t" << q.arg2 << "\t" << q.result << "\n";
        }
        std::cout << "------------------------------\n";
    }
};

class InfixToPostfixConverter
{
private:
    unordered_map<char, int> precedence;

    bool isOperator(char c)
    {
        return precedence.find(c) != precedence.end();
    }

    bool hasHigherPrecedence(char op1, char op2)
    {
        return precedence[op1] >= precedence[op2];
    }

public:
    InfixToPostfixConverter()
    {
        precedence['+'] = 1;
        precedence['-'] = 1;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['%'] = 2;
        precedence['^'] = 3;
        precedence['='] = 0;
    }

    string convert(const string &infix)
    {
        string postfix;
        stack<char> operatorStack;

        for (char c : infix)
        {
            if (isalnum(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                operatorStack.push(c);
            }
            else if (c == ')')
            {
                while (!operatorStack.empty() && operatorStack.top() != '(')
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(')
                {
                    operatorStack.pop();
                }
            }
            else if (isOperator(c))
            {
                while (!operatorStack.empty() && operatorStack.top() != '(' &&
                       hasHigherPrecedence(operatorStack.top(), c))
                {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            }
        }

        while (!operatorStack.empty())
        {
            postfix += operatorStack.top();
            operatorStack.pop();
        }

        return postfix;
    }
};

void runTests(InfixToPostfixConverter &converter)
{
    vector<pair<string, string>> testCases = {
        {"a+b*c", "abc*+"},
        {"(a+b)*c", "ab+c*"},
        {"a+b*(c^d-e)^(f+g*h)-i", "abcd^e-fgh*+^*+i-"},
        {"k+l-m*n+(o^p)*w/u/v*t+q", "kl+mn*-op^w*u/v/t*+q+"},
        {"a+b*(c^d-e)^(f+g*h)-i", "abcd^e-fgh*+^*+i-"},
        {"A+B*C-D/E^F*G", "ABC*+DEF^/G*-"},
        {"(a+b*c-d)/(e-f)", "abc*+d-ef-/"},
        {"x^y/(5*z)+2", "xy^5z*/2+"},
        {"a%b+c-d*e/f^g", "ab%c+de*fg^/-"},
        {"(A+B)*(C-D)/(E+F)^G", "AB+CD-*EF+G^/"},
        {"a=b+c*d-e/f^g%h", "abcd*+efg^/h%-="},
        {"(2+3)*4^(5-1)%3", "23+451-^*3%"},
        {"a*(b+c*d)^(e-f*g)/h", "abcd*+efg*-^*h/"}};

    for (pair<string, string> &test : testCases)
    {
        string result = converter.convert(test.first);
        if (result == test.second)
        {
            cout << "PASS: " << test.first << " -> " << result << endl;
        }
        else
        {
            cout << "FAIL: " << test.first << endl;
            cout << "  Expected: " << test.second << endl;
            cout << "  Got:      " << result << endl;
        }
    }
}

int main()
{
    InfixToPostfixConverter converter;
    QuadrupleGenerator generator;

    // cout << "Running tests...\n"
    //      << endl;
    // runTests(converter);


    string infix = "a%b+c-d*e/f^g";

    string postfix = converter.convert(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;

    generator.generateQuadruples(postfix);
    generator.printQuadruples();
    return 0;
}

// for interactive mode
// int main() {
//     InfixToPostfixConverter converter;
//     string infix;

//     cout << "Enter an infix expression: ";
//     getline(cin, infix);

//     string postfix = converter.convert(infix);
//     cout << "Postfix expression: " << postfix << endl;

//     return 0;
// }


