#include <iostream>
#include <string.h>
//#include <string>
using namespace std;


char* deleteSubstring(char* inputString, const char* substring) {
    size_t inputLen = strlen(inputString);
    size_t subLen = strlen(substring);

    if (subLen == 0) {
        cout << "Підрядок порожній!" << endl;
        return inputString;
    }


    if (strstr(inputString, substring) == NULL) {
        cout << "В строчці " << inputString << " немає підрядка  " << substring << " " << endl;
        return inputString;
    }


    char* result = new char[256];
    int resIndex = 0;

    for (int i = 0; i < inputLen;) {
        if (strstr(&inputString[i], substring) == &inputString[i]) {

            i += subLen;
        } else {
            result[resIndex++] = inputString[i++];
        }
    }

    result[resIndex] = '\0'; 

    return result;
}

// З використанням стандартних функцій

// string deleteSubstring(const string& inputString, const string& substring) {
//     if (substring.empty()) {
//         cout << "Підрядок порожній!" << endl;
//         return inputString;
//     }

//     string result = inputString;
//     size_t pos;

//     // Шукаємо і видаляємо всі входження підрядка
//     while ((pos = result.find(substring)) != string::npos) {
//         result.erase(pos, substring.length());
//     }

//     return result;
// }

// int main() {
//     string input;
//     cout << "Введіть рядок: ";
//     getline(cin, input);

//     string sub;
//     cout << "Введіть підрядок: ";
//     getline(cin, sub);

//     string result = deleteSubstring(input, sub);
//     cout << "Результат: " << result << endl;

//     return 0;
// }


int main() {
    char input[256];
    cout << "Введіть рядок: ";
    cin.getline(input, 256);

    char sub[256];
    cout << "Введіть підрядок: ";
    cin.getline(sub, 256);

    char* result = deleteSubstring(input, sub);
    cout << "Результат: " << result << endl;

    delete[] result; 

    return 0;
}
