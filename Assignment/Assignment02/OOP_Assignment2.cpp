#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Input : ";
    getline(cin, input); // 공백이 있는 문자열 읽기

    bool cap_bool = true;

    for (char& ch : input) { // input을 직접 &ch를 통해 변화시킬것.
        // 공백 확인
        if (ch == ' ') {
            cap_bool = true; // 공백  다음 글자는 대문자
        }
        else {
            // 다음 글자는 대문자
            if (cap_bool) {
                if (ch >= 'a' && ch <= 'z') {
                    ch = ch - ('a' - 'A'); // 소문자를 대문자로 변환
                }
                cap_bool = false; // 대문자 다음 소문자
            }
            // 다음 글자는 소문자
            else {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + ('a' - 'A'); // 대문자를 소문자로 변환
                }
            }
        }
    }

    cout << "Output : " << input << endl;
    return 0;
}