#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Expression Input : ";
    getline(cin, input);

    int parentheses_cnt = 0; // 소괄호 개수
    int brackets_cnt = 0;    // 대괄호 개수
    int open_parentheses = 0;  // '(' 개수
    int open_brackets = 0;     // '[' 개수
    bool brackets_error = false; // 대괄호 에러
    bool parentheses_error = false; // 소괄호 에러

    for (char ch : input) {
        // 소괄호 처리
        if (ch == '(') {
            open_parentheses++; 
        }
        else if (ch == ')') {
            if (open_parentheses > 0) {
                // 현재 열려있는 소괄호가 1개이상이면 ')'는 유효하다
                open_parentheses--;
                // 문제 없이 소괄호가 닫혔으면 소괄호 갯수증가
                parentheses_cnt++; 
            }    
            else { // 열려있는 괄호도 없는데 닫을경우 에러
                parentheses_error = true;
            }
        }
        // 대괄호 처리
        else if (ch == '[') {
            open_brackets++;
        }
        else if (ch == ']') {
            if (open_brackets > 0) {
                // 현재 열려있는 대괄호가 1개이상이면 ']'는 유효하다
                open_brackets--;
                // 문제 없이 대괄호가 닫혔으면 대괄호 갯수증가
                brackets_cnt++;
            }
            else { // 열려있는 괄호도 없는데 닫을경우 에러
                brackets_error = true;
            }
        }
    }

    // 에러여부 점검
    // 이미 에러가 발생했거나 문장이 끝났을때, 아직 열려있는 괄호가 있으면 에러
    if (open_parentheses > 0 || open_brackets > 0 || parentheses_error || brackets_error) {
        if (open_parentheses > 0 || parentheses_error) {
            cout << "Error : Parenthesis Missing" << endl;
        }
        if (open_brackets > 0 || brackets_error) {
            cout << "Error : Bracket Missing" << endl;
        }
    }
    // 에러가 없으면 출력
    else {
        cout << "Parentheses : " << parentheses_cnt;
        cout << "  Brackets : " << brackets_cnt << endl;
    }
    return 0;
}