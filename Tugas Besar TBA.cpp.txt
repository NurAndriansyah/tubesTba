#include <iostream>
#include <string>
#include <map>

int stackIndex = -1;
std::string stack[300];
void push(std::string stack[], std::string input) {
    ++stackIndex;
    stack[stackIndex] = input;
}
std::string pop(std::string stack[]) {
    --stackIndex;
    return stack[stackIndex + 1];
}

int main()
{
    std::map<std::string, std::map<std::string, std::string>> parseTable[5];

    std::string inputString;
    //std::getline(std::cin, inputString);
    inputString = "while >= do ( endwhile )   a b >> >= <> do () -= false==true truetrue";
    std::string scannedString[300];

    int inputPointer = 0;
    int scannedPointer = 0;
    
    while (inputString[inputPointer] != '\0') {

        while (inputString[inputPointer] == ' ') {
            ++inputPointer;
        }
        
        if (isalpha(inputString[inputPointer])) {
            std::string signature = "";
            while (isalpha(inputString[inputPointer])) { //membaca seluruh string sebelum 'space' atau 'akhir kata' ditemukan
                signature.insert(signature.length(), 1, inputString[inputPointer]);
                ++inputPointer;
            }
            if (signature == "a") {
                scannedString[scannedPointer] = "a";
                std::cout << "a" << "\n";
            }
            else if (signature == "b") {
                scannedString[scannedPointer] = "b";
                std::cout << "b" << "\n";
            }
            else if (signature == "c") {
                scannedString[scannedPointer] = "c";
                std::cout << "c" << "\n";
            }
            else if (signature == "d") {
                scannedString[scannedPointer] = "d";
                std::cout << "d" << "\n";
            }
            else if (signature == "while") {
                scannedString[scannedPointer] = "while";
                std::cout << "while" << "\n";
            }
            else if (signature == "do") {
                scannedString[scannedPointer] = "do";
                std::cout << "do" << "\n";
            }
            else if (signature == "endwhile") {
                scannedString[scannedPointer] = "endwhile";
                std::cout << "endwhile" << "\n";
            }
            else if (signature == "true") {
                scannedString[scannedPointer] = "true";
                std::cout << "true" << "\n";
            }
            else if (signature == "false") {
                scannedString[scannedPointer] = "false";
                std::cout << "false" << "\n";
            }
            else break;
        }
        else if (inputString[inputPointer] == '>') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = ">=";
                std::cout << ">=" << "\n";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = ">";
                std::cout << ">" << "\n";
            }
        }
        else if (inputString[inputPointer] == '<') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "<=";
                std::cout << "<=" << "\n";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "<";
                std::cout << "<" << "\n";
            }
        }
        else if (inputString[inputPointer] == '=') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "==";
                std::cout << "==" << "\n";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "=";
                std::cout << "=" << "\n";
            }
        }
        else if (inputString[inputPointer] == '!') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "!=";
                std::cout << "!=" << "\n";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "!";
                std::cout << "!" << "\n";
            }
        }
        else if (inputString[inputPointer] == '(') {
            scannedString[scannedPointer] = "(";
            std::cout << "(" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == ')') {
            scannedString[scannedPointer] = ")";
            std::cout << ")" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '+') {
            scannedString[scannedPointer] = "+";
            std::cout << "+" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '-') {
            scannedString[scannedPointer] = "-";
            std::cout << "-" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '*') {
          scannedString[scannedPointer] = "*";
            std::cout << "*" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '/') {
            scannedString[scannedPointer] = "/";
            std::cout << "/" << "\n";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '%') {
            scannedString[scannedPointer] = "%";
            std::cout << "%" << "\n";
            ++inputPointer;
        }
        else {

            break;
        }

        ++scannedPointer;
    }

    parseTable[0]["S"]["a"] = "error";
    parseTable[0]["S"]["b"] = "error";
    parseTable[0]["S"]["c"] = "error";
    parseTable[0]["S"]["d"] = "error";
    parseTable[0]["S"][">"] = "error";
    parseTable[0]["S"]["<"] = "error";
    parseTable[0]["S"][">="] = "error";
    parseTable[0]["S"]["<="] = "error";
    parseTable[0]["S"]["=="] = "error";
    parseTable[0]["S"]["!="] = "error";
    parseTable[0]["S"]["&&"] = "error";
    parseTable[0]["S"]["||"] = "error";
    parseTable[0]["S"]["("] = "error";
    parseTable[0]["S"][")"] = "error";
    parseTable[0]["S"]["!"] = "error";
    parseTable[0]["S"]["="] = "error";
    parseTable[0]["S"]["+"] = "error";
    parseTable[0]["S"]["-"] = "error";
    parseTable[0]["S"]["*"] = "error";
    parseTable[0]["S"]["/"] = "error";
    parseTable[0]["S"]["%"] = "error";
    parseTable[0]["S"]["while"] = "error";
    parseTable[0]["S"]["do"] = "error";
    parseTable[0]["S"]["endwhile"] = "error";
    parseTable[0]["S"]["true"] = "error";
    parseTable[0]["S"]["false"] = "error";
    parseTable[0]["S"]["eos"] = "error";
}