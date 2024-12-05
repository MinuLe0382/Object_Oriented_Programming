#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Input Sentence : ";
    getline(cin, input); // �����ִ� �����Է�

    int char_cnt = 0;      // ���� ��
    int word_cnt = 0;      // �ܾ� ��
    int punc_cnt = 0; // ������ ��
    int space_cnt = 0;  // ���� ��

    string punc_list = ".?!,��:;/\"'(){}[]";
    bool in_word = false; // �ܾ� �ȿ� �ִ��� Ȯ��

    for (char ch : input) {
        char_cnt++;
        bool is_blank = false;
        // ���� ���� Ȯ��
        if (ch == ' ') {
            space_cnt++;
            is_blank = true;
            in_word = false; // �����̸� �ܾ�� ����
        }
        // ������ �ƴϸ�, �������� Ȯ��
        else {
            is_blank = false;
            for (char p : punc_list) { // ������ ����� ��� ���ڿ� ��
                if (ch == p) {
                    punc_cnt++;
                    break;
                }
            }
            // �������� ù��° ���ڰ� �����ߴٸ� ���ο� �ܾ��� ��
            // �̷��� �ؾ� ���ӵ� ������ ���� ����� �ܾ ����
            if (!is_blank && !in_word) {
                word_cnt++;
                in_word = true;
            }
        }
    }

    // ���� ��� ���
    cout << "Character(s) " << char_cnt << endl;
    cout << "Word(s) " << word_cnt << endl;
    cout << "Punctuation(s) " << punc_cnt << endl;
    cout << "Whitespace(s) " << space_cnt << endl;

    return 0;
}