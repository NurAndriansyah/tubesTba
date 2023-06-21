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
std::string top(std::string stack[]) {
    return stack[stackIndex];
}
void show(std::string stack[]) {
    for (int i = 0; i <= stackIndex; ++i) {
        std::cout << stack[i] << " ";
    }
}


int main()
{
    std::map<std::string, std::map<std::string, std::string>> parseTable[5];

    std::string inputString;
    std::getline(std::cin, inputString);
    inputString = "while (true) do a = a + a endwhile";

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
            }
            else if (signature == "b") {
                scannedString[scannedPointer] = "b";
            }
            else if (signature == "c") {
                scannedString[scannedPointer] = "c";
            }
            else if (signature == "d") {
                scannedString[scannedPointer] = "d";
            }
            else if (signature == "while") {
                scannedString[scannedPointer] = "while";
            }
            else if (signature == "do") {
                scannedString[scannedPointer] = "do";
            }
            else if (signature == "endwhile") {
                scannedString[scannedPointer] = "endwhile";
            }
            else if (signature == "true") {
                scannedString[scannedPointer] = "true";
            }
            else if (signature == "false") {
                scannedString[scannedPointer] = "false";
            }
            else break;
        }
        else if (inputString[inputPointer] == '>') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = ">=";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = ">";
            }
        }
        else if (inputString[inputPointer] == '<') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "<=";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "<";
            }
        }
        else if (inputString[inputPointer] == '=') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "==";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "=";
            }
        }
        else if (inputString[inputPointer] == '!') {
            ++inputPointer;
            if (inputString[inputPointer] == '=') {
                scannedString[scannedPointer] = "!=";
                ++inputPointer;
            }
            else {
                scannedString[scannedPointer] = "!";
            }
        }
        else if (inputString[inputPointer] == '(') {
            scannedString[scannedPointer] = "(";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == ')') {
            scannedString[scannedPointer] = ")";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '+') {
            scannedString[scannedPointer] = "+";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '-') {
            scannedString[scannedPointer] = "-";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '*') {
          scannedString[scannedPointer] = "*";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '/') {
            scannedString[scannedPointer] = "/";
            ++inputPointer;
        }
        else if (inputString[inputPointer] == '%') {
            scannedString[scannedPointer] = "%";
            ++inputPointer;
        }
        else {

            break;
        }

        ++scannedPointer;
    }

    std::string column[] = { "a", "b", "c", "d", ">", "<", ">=", "<=", "==", "!=", "&&", "||", "(", ")", "!", "=", "+", "-", "*", "/", "%", "while", "do", "endwhile", "true", "false", "eos" };
    std::string row[] = { "S", "<condition>", "<comparison>", "<logicalOperator>", "<vacriable>", "<comparisonOperator", "<boolean>", "<action>", "<operation>", "<arithmeticOperator>", "<calculatio>"};
    int numColumn = sizeof(column) / sizeof(column[0]);
    int numRow = sizeof(row) / sizeof(row[0]);

    for (int i = 0; i < numColumn; ++i) {
        for (int j = 0; j < numRow; ++j) {
            parseTable[0][row[j]][column[i]] = "error";
        }
    }

    parseTable[0]["S"]["while"] = "while";
    parseTable[1]["S"]["while"] = "<condition>";
    parseTable[2]["S"]["while"] = "do";
    parseTable[3]["S"]["while"] = "<action>";
    parseTable[4]["S"]["while"] = "endwhile";

    parseTable[0]["<condition>"]["a"] = "<comparison>";
    parseTable[0]["<condition>"]["b"] = "<comparison>";
    parseTable[0]["<condition>"]["c"] = "<comparison>";
    parseTable[0]["<condition>"]["d"] = "<comparison>";
    parseTable[0]["<condition>"]["("] = "(";
    parseTable[1]["<condition>"]["("] = "<condition>";
    parseTable[2]["<condition>"]["("] = ")";
    parseTable[0]["<condition>"]["!"] = "!";
    parseTable[1]["<condition>"]["!"] = "<condition>";
    parseTable[0]["<condition>"]["true"] = "<boolean>";
    parseTable[0]["<condition>"]["false"] = "<boolean>";

    parseTable[0]["<comparison>"]["a"] = "<comparison>";
    parseTable[0]["<comparison>"]["b"] = "<comparison>";
    parseTable[0]["<comparison>"]["c"] = "<comparison>";
    parseTable[0]["<comparison>"]["d"] = "<comparison>";

    parseTable[0]["<logicalOperator>"]["&&"] = "&&";
    parseTable[0]["<logicalOperator>"]["||"] = "||";

    parseTable[0]["<variable>"]["a"] = "a";
    parseTable[0]["<variable>"]["b"] = "b";
    parseTable[0]["<variable>"]["c"] = "c";
    parseTable[0]["<variable>"]["d"] = "d";

    parseTable[0]["<comparisonOperator>"][">"] = ">";
    parseTable[0]["<comparisonOperator>"]["<"] = "<";
    parseTable[0]["<comparisonOperator>"][">="] = ">=";
    parseTable[0]["<comparisonOperator>"]["<="] = "<=";
    parseTable[0]["<comparisonOperator>"]["=="] = "==";
    parseTable[0]["<comparisonOperator>"]["!="] = "!=";

    parseTable[0]["<boolean>"]["true"] = "true";
    parseTable[0]["<boolean>"]["false"] = "false";

    parseTable[0]["<action>"]["a"] = "<variable>";
    parseTable[1]["<action>"]["a"] = "=";
    parseTable[2]["<action>"]["a"] = "<operation>";
    parseTable[0]["<action>"]["b"] = "<variable>";
    parseTable[1]["<action>"]["b"] = "=";
    parseTable[2]["<action>"]["b"] = "<operation>";
    parseTable[0]["<action>"]["c"] = "<variable>";
    parseTable[1]["<action>"]["c"] = "=";
    parseTable[2]["<action>"]["c"] = "<operation>";
    parseTable[0]["<action>"]["d"] = "<variable>";
    parseTable[1]["<action>"]["d"] = "=";
    parseTable[2]["<action>"]["d"] = "<operation>";
    parseTable[0]["<action>"]["while"] = "S";

    parseTable[0]["<operation>"]["a"] = "<variable>";
    parseTable[1]["<operation>"]["a"] = "<arithmeticOperator>";
    parseTable[2]["<operation>"]["a"] = "<variable>";
    parseTable[0]["<operation>"]["b"] = "<variable>";
    parseTable[1]["<operation>"]["b"] = "<arithmeticOperator>";
    parseTable[2]["<operation>"]["b"] = "<variable>";
    parseTable[0]["<operation>"]["c"] = "<variable>";
    parseTable[1]["<operation>"]["c"] = "<arithmeticOperator>";
    parseTable[2]["<operation>"]["c"] = "<variable>";
    parseTable[0]["<operation>"]["d"] = "<variable>";
    parseTable[1]["<operation>"]["d"] = "<arithmeticOperator>";
    parseTable[2]["<operation>"]["d"] = "<variable>";
    parseTable[0]["<operation>"]["("] = "(";
    parseTable[1]["<operation>"]["("] = "<operation>";
    parseTable[2]["<operation>"]["("] = ")";

    parseTable[0]["<arithmeticOperator>"]["+"] = "+";
    parseTable[0]["<arithmeticOperator>"]["-"] = "-";
    parseTable[0]["<arithmeticOperator>"]["*"] = "*";
    parseTable[0]["<arithmeticOperator>"]["/"] = "/";
    parseTable[0]["<arithmeticOperator>"]["%"] = "%";

    parseTable[0]["<calculation>"]["a"] = "<variable>";
    parseTable[0]["<calculation>"]["b"] = "<variable>";
    parseTable[0]["<calculation>"]["c"] = "<variable>";
    parseTable[0]["<calculation>"]["d"] = "<variable>";
    parseTable[0]["<calculation>"]["("] = "(";
    parseTable[1]["<calculation>"]["("] = "<calculation>";
    parseTable[2]["<calculation>"]["("] = ")";

    //for (int i = 0; i < scannedPointer; ++i) {                    // untuk debugging scanned input
    //    std::cout << scannedString[i] << " ";
    //}
    //std::cout << "\n";

    int scannedCursor = 0;
    push(stack, "#");
    push(stack, "S");

    while (top(stack) != "#" && top(stack) != "error") {

        //std::cout << "stack   : ";                                // Untuk debugging stack
        //show(stack);
        //std::cout << "\n";

        //std::cout << "scanned : ";                                // Untuk debugging scanned input
        //for (int i = scannedCursor; i < scannedPointer; ++i) {
        //    std::cout << scannedString[i] << " ";
        //}
        //std::cout << "\n\n";

        bool topIsColumn = false;

        for (int i = 0; i < numColumn; ++i) {
            if (top(stack) == column[i]) {
                topIsColumn = true;
                break;
            }
        }

        if (topIsColumn) {  // jika top stack adalah terminal
            if (top(stack) == scannedString[scannedCursor]) {
                pop(stack);
                ++scannedCursor;
            }
            else {
                break;
            }
        }
        else { // jika top stack adalah non terminal
            int leftIndex = 0;
            for (int i = 4; i >= 0; --i) {
                if (parseTable[i][top(stack)][scannedString[scannedCursor]] != "") {
                    leftIndex = i;
                    //std::cout << "i : " << i << "\n";
                    break;
                }
            }
            //std::cout << "left index : " << leftIndex << "\n";
            std::string poppedColumn = pop(stack);
            for (int i = leftIndex; i >= 0; --i) {
                push(stack, parseTable[i][poppedColumn][scannedString[scannedCursor]]);
                //std::cout << "i : " << i << " top(stack) : " << top(stack) << " scannedString : " << scannedString[scannedCursor] << " scannedCursor : " << scannedCursor << "\n";
            }
        }
    }

    std::cout << "Hasil akhir stack: \n";
    show(stack);
    std::cout << "Hasil akhir input: \n";
    for (int i = 0; i < scannedPointer; ++i) {
        std::cout << scannedString[i] << " ";
    }
    std::cout << "\n";

    if (scannedString[scannedCursor] == "")     std::cout << "VALID";
    else                                        std::cout << "Error";
}
