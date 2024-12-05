#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Expression Input : ";
    getline(cin, input);

    int parentheses_cnt = 0; // �Ұ�ȣ ����
    int brackets_cnt = 0;    // ���ȣ ����
    int open_parentheses = 0;  // '(' ����
    int open_brackets = 0;     // '[' ����
    bool brackets_error = false; // ���ȣ ����
    bool parentheses_error = false; // �Ұ�ȣ ����

    for (char ch : input) {
        // �Ұ�ȣ ó��
        if (ch == '(') {
            open_parentheses++; 
        }
        else if (ch == ')') {
            if (open_parentheses > 0) {
                // ���� �����ִ� �Ұ�ȣ�� 1���̻��̸� ')'�� ��ȿ�ϴ�
                open_parentheses--;
                // ���� ���� �Ұ�ȣ�� �������� �Ұ�ȣ ��������
                parentheses_cnt++; 
            }    
            else { // �����ִ� ��ȣ�� ���µ� ������� ����
                parentheses_error = true;
            }
        }
        // ���ȣ ó��
        else if (ch == '[') {
            open_brackets++;
        }
        else if (ch == ']') {
            if (open_brackets > 0) {
                // ���� �����ִ� ���ȣ�� 1���̻��̸� ']'�� ��ȿ�ϴ�
                open_brackets--;
                // ���� ���� ���ȣ�� �������� ���ȣ ��������
                brackets_cnt++;
            }
            else { // �����ִ� ��ȣ�� ���µ� ������� ����
                brackets_error = true;
            }
        }
    }

    // �������� ����
    // �̹� ������ �߻��߰ų� ������ ��������, ���� �����ִ� ��ȣ�� ������ ����
    if (open_parentheses > 0 || open_brackets > 0 || parentheses_error || brackets_error) {
        if (open_parentheses > 0 || parentheses_error) {
            cout << "Error : Parenthesis Missing" << endl;
        }
        if (open_brackets > 0 || brackets_error) {
            cout << "Error : Bracket Missing" << endl;
        }
    }
    // ������ ������ ���
    else {
        cout << "Parentheses : " << parentheses_cnt;
        cout << "  Brackets : " << brackets_cnt << endl;
    }
    return 0;
}