#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// �˿��ƻ�ɫ
const string suits[] = {"��Ƭ", "÷��", "����", "����"};

// �˿��Ƶ���
const string ranks[] = {
    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

int main() {
    // ��ʼ�������������
    srand(time(0));
    
    // ���ѡ��ɫ��0-3��
    int suitIndex = rand() % 4;
    
    // ���ѡ�������0-12��
    int rankIndex = rand() % 13;
    
    // ��ȡ��Ӧ�Ļ�ɫ�͵���
    string suit = suits[suitIndex];
    string rank = ranks[rankIndex];
    
    // ������
    cout << "���ѡ����˿�����: " << suit << rank << endl;
    
    return 0;
}
