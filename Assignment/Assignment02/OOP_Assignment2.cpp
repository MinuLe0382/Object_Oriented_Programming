#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Input : ";
    getline(cin, input); // ������ �ִ� ���ڿ� �б�

    bool cap_bool = true;

    for (char& ch : input) { // input�� ���� &ch�� ���� ��ȭ��ų��.
        // ���� Ȯ��
        if (ch == ' ') {
            cap_bool = true; // ����  ���� ���ڴ� �빮��
        }
        else {
            // ���� ���ڴ� �빮��
            if (cap_bool) {
                if (ch >= 'a' && ch <= 'z') {
                    ch = ch - ('a' - 'A'); // �ҹ��ڸ� �빮�ڷ� ��ȯ
                }
                cap_bool = false; // �빮�� ���� �ҹ���
            }
            // ���� ���ڴ� �ҹ���
            else {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + ('a' - 'A'); // �빮�ڸ� �ҹ��ڷ� ��ȯ
                }
            }
        }
    }

    cout << "Output : " << input << endl;
    return 0;
}