#include <iostream>
#include <string>

using namespace std;

int main() {
    const string hexdigits = "0123456789ABCDEF";
    string input;

    cout << "Hexadecimal Input : ";
    cin >> input;

    // 대문자만 입력 가능하다
    for (char ch : input) {
        // input의 모든 글자를 확인하여 소문자를 걸러낸다
        if (ch >= 'a' && ch <= 'z') {
            cout << "Error : Please enter the correct Hexadecimal digits" << endl;
            return 0;
        }
    }

    // 입력이 16진수 범위 내의 값인지 확인
    for (char ch : input) {
        bool hexbool = false;
        // 모든 글자를 hexdigits의 모든 글자와 비교해서 하나라도 같은게 있는지 확인
        for (char hexChar : hexdigits) {
            if (ch == hexChar) {
                hexbool = true;
                break;
            }
        }
        // 한 글자라도 hexdigit 이 아니면 오류
        if (!hexbool) {
            cout << "Error : Please enter the correct Hexadecimal digits" << endl;
            return 0;
        }
    }

    // 8자리가 넘는지 확인
    if (input.size() > 8) {
        cout << "Error : Please enter within 8 hexadecimal digits" << endl;
        return 0;
    }

    // 10진수로 변환
    unsigned int result = 0;

    // size()는 size_t를 반환
    for (size_t i = 0; i < input.size(); ++i) { 
        result *= 16; // 자릿수 올리기
        for (size_t j = 0; j < hexdigits.size(); ++j) {

            // 현재 문자에 해당하는 값을 찾는다
            if (input[i] == hexdigits[j]) { 
                result += j;
                break;
            }
        }
    }

    cout << "Decimal Output : " << result << endl;
    return 0;
}