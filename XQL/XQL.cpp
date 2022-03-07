/*
The MIT License

Copyright (c) 2019 PyXLL Ltd. https://www.pyxll.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include <string>
#include <vector>
#include <iostream>
#include "xlfparser.h"

using namespace xlfparser;

std::ostream& operator<<(std::ostream& os, Token::Type t)
{
    switch (t)
    {
    case Token::Type::Operand:
        os << "Operand";
        break;
    case Token::Type::Function:
        os << "Function";
        break;
    case Token::Type::Array:
        os << "Array";
        break;
    case Token::Type::ArrayRow:
        os << "ArrayRow";
        break;
    case Token::Type::Subexpression:
        os << "Subexpression";
        break;
    case Token::Type::Argument:
        os << "Argument";
        break;
    case Token::Type::OperatorPrefix:
        os << "OperatorPrefix";
        break;
    case Token::Type::OperatorInfix:
        os << "OperatorInfix";
        break;
    case Token::Type::OperatorPostfix:
        os << "OperatorPostfix";
        break;
    case Token::Type::Whitespace:
        os << "Whitespace";
        break;
    case Token::Type::Unknown:
    default:
        os << "Unknown";
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, Token::Subtype t)
{
    switch (t)
    {
    case Token::Subtype::None:
        os << "None";
        break;
    case Token::Subtype::Start:
        os << "Start";
        break;
    case Token::Subtype::Stop:
        os << "Stop";
        break;
    case Token::Subtype::Text:
        os << "Text";
        break;
    case Token::Subtype::Number:
        os << "Number";
        break;
    case Token::Subtype::Logical:
        os << "Logical";
        break;
    case Token::Subtype::Error:
        os << "Error";
        break;
    case Token::Subtype::Range:
        os << "Range";
        break;
    case Token::Subtype::Math:
        os << "Math";
        break;
    case Token::Subtype::Concatenation:
        os << "Concatenation";
        break;
    case Token::Subtype::Intersection:
        os << "Intersection";
        break;
    case Token::Subtype::Union:
        os << "Union";
        break;
    default:
        os << "Unknown";
        break;
    }

    return os;
}

int main()
{
    const int e1 = 12;
    int result = NULL;
    std::vector<std::string>inputs{
        "=E1+2-3+$+MATH()"
    };
    
    for (const auto& input : inputs)
    {
        
        
        auto tokens = xlfparser::tokenize(input);
        
        for (const auto& token : tokens) {
            std::cout << '\t' << token.value(input) << '\t' << token.type() << '\t' << token.subtype() << std::endl;
        }
        std::cout << std::endl;
        
        
    }
    

    return 0;
}
