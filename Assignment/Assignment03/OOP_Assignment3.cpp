#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Input Sentence : ";
    getline(cin, input); // 공백있는 문장입력

    int char_cnt = 0;      // 문자 수
    int word_cnt = 0;      // 단어 수
    int punc_cnt = 0; // 구두점 수
    int space_cnt = 0;  // 공백 수

    string punc_list = ".?!,·:;/\"'(){}[]";
    bool in_word = false; // 단어 안에 있는지 확인

    for (char ch : input) {
        char_cnt++;
        bool is_blank = false;
        // 공백 문자 확인
        if (ch == ' ') {
            space_cnt++;
            is_blank = true;
            in_word = false; // 공백이면 단어는 종료
        }
        // 공백이 아니면, 구두점을 확인
        else {
            is_blank = false;
            for (char p : punc_list) { // 구두점 목록의 모든 글자와 비교
                if (ch == p) {
                    punc_cnt++;
                    break;
                }
            }
            // 공백이후 첫번째 문자가 등장했다면 새로운 단어라는 뜻
            // 이렇게 해야 연속된 공백이 들어가도 제대로 단어를 감지
            if (!is_blank && !in_word) {
                word_cnt++;
                in_word = true;
            }
        }
    }

    // 최종 결과 출력
    cout << "Character(s) " << char_cnt << endl;
    cout << "Word(s) " << word_cnt << endl;
    cout << "Punctuation(s) " << punc_cnt << endl;
    cout << "Whitespace(s) " << space_cnt << endl;

    return 0;
}