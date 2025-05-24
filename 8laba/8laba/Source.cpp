#include <iostream>   
#include <cstring>     

// ��������� ������ ������� ������ ���������� ������� ��������, ������ �����
template <typename T>
int findLastIndex(const T arr[], int size, const T& key) {
    int lastIndex = -1;           // ���������� ������ ���������� ���������� �������� -1 (������ "�� ��������")
    for (int i = 0; i < size; ++i) {  // ���������� �� �������� ������ �� 0 �� size-1
        if (arr[i] == key) {          // ���� �������� ������� ������� ����� (��������� ���������� ==)
            lastIndex = i;            // �����'������� ������ ���������� ���������� ��������
        }
    }
    return lastIndex;             // ��������� ������ ���������� ���������� �������� ��� -1, ���� �� ��������
}

// ������������ ������� ��� ������ ����� (��� const char*)
template <>
int findLastIndex<const char*>(const char* const arr[], int size, const char* const& key) {
    int lastIndex = -1;           // ���������� ������ ���������� ���������� �������� -1
    for (int i = 0; i < size; ++i) {  // ���������� �� ����� � �����
        if (std::strcmp(arr[i], key) == 0) {  // ��������� ����� �� ��������� strcmp (������� 0, ���� ���)
            lastIndex = i;         // �����'������� ������ ���������� ���������� �����
        }
    }
    return lastIndex;             // ��������� ������ ��� -1, ���� �� ��������
}

int main() {
    int arrInt[] = { 1, 3, 5, 3, 7, 3 };  // ����� ����� �����
    int sizeInt = sizeof(arrInt) / sizeof(arrInt[0]);  // ���������� ����� ������ (������� ��������)
    int keyInt = 3;                     // ���� ��� ������
    // �������� ������ ���������� ��������� ����� � ����� ����� �����
    std::cout << "Last index of " << keyInt << " in arrInt: "
        << findLastIndex(arrInt, sizeInt, keyInt) << std::endl;

    const char* arrStr[] = { "apple", "banana", "orange", "banana", "kiwi" };  // ����� C-����� (����� ���������)
    int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);  // ���������� ����� ������ �����
    const char* keyStr = "banana";           // ���� (�����) ��� ������
    // �������� ������ ���������� ��������� ����� � ����� �����
    std::cout << "Last index of \"" << keyStr << "\" in arrStr: "
        << findLastIndex(arrStr, sizeStr, keyStr) << std::endl;

    return 0;
}
