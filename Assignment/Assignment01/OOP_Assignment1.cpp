#include <iostream>
#include <string>

using namespace std;

int main() {
    const string hexdigits = "0123456789ABCDEF";
    string input;

    cout << "Hexadecimal Input : ";
    cin >> input;

    // �빮�ڸ� �Է� �����ϴ�
    for (char ch : input) {
        // input�� ��� ���ڸ� Ȯ���Ͽ� �ҹ��ڸ� �ɷ�����
        if (ch >= 'a' && ch <= 'z') {
            cout << "Error : Please enter the correct Hexadecimal digits" << endl;
            return 0;
        }
    }

    // �Է��� 16���� ���� ���� ������ Ȯ��
    for (char ch : input) {
        bool hexbool = false;
        // ��� ���ڸ� hexdigits�� ��� ���ڿ� ���ؼ� �ϳ��� ������ �ִ��� Ȯ��
        for (char hexChar : hexdigits) {
            if (ch == hexChar) {
                hexbool = true;
                break;
            }
        }
        // �� ���ڶ� hexdigit �� �ƴϸ� ����
        if (!hexbool) {
            cout << "Error : Please enter the correct Hexadecimal digits" << endl;
            return 0;
        }
    }

    // 8�ڸ��� �Ѵ��� Ȯ��
    if (input.size() > 8) {
        cout << "Error : Please enter within 8 hexadecimal digits" << endl;
        return 0;
    }

    // 10������ ��ȯ
    unsigned int result = 0;

    // size()�� size_t�� ��ȯ
    for (size_t i = 0; i < input.size(); ++i) { 
        result *= 16; // �ڸ��� �ø���
        for (size_t j = 0; j < hexdigits.size(); ++j) {

            // ���� ���ڿ� �ش��ϴ� ���� ã�´�
            if (input[i] == hexdigits[j]) { 
                result += j;
                break;
            }
        }
    }

    cout << "Decimal Output : " << result << endl;
    return 0;
}