#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

const char alphabet[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0',
'1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '='}; //������� base64

//���������� ������������ ����������
int decision = 0; //����������, ����������� ���, ��� �� ����� ������ � ������
//���������� ��� �����������
char c1; char c2; char c3; //���������� ��������
int asciic1; int asciic2; int asciic3; int asciic3dub; //������� � ASCII ���������
int res; //��������� ��������� 1 �������
int res11; int res12; int res1; //���������� ��������� 1 � 2 �������
int res22; int res23; int res2; //���������� ��������� 2 � 3 ��������
int res3; //��������� ��������� 3 
//���������� ��� �������������


int main() {
	cout << "Hello there! To encode a file type 0. To decode a file type 1.\n";
	cin >> decision;
	if (decision == 0) {
		ifstream fin("Code.txt");
		int charCount = 0; //������� ���������� �������� � �����
		char c;
		while (!fin.eof()) {
			c = fin.get();
			cout << c; //������� ���������� �����
			charCount++;
		}
		fin.close();
		double count = charCount - 1;
		cout << "\nNumber of characters in a string: " << count << endl; //������� ���������� �������� � �����
		cout << "Your string in base64 will be: ";
		ifstream fin1("Code.txt");
		for (int i = 0; i < ceil(count / 3); i++) {
			//��������� ������ ��������
			c1 = fin1.get(); //��������� ������ ������
			c2 = fin1.get(); //��������� ������ ������
			c3 = fin1.get(); //��������� ������ ������
			//cout << "\n" << c1 << " " << c2 << " " << c3 << endl;
			asciic1 = static_cast<int>(c1); //��������� � ����� ��� ���������� ��������� ��������
			asciic2 = static_cast<int>(c2);
			asciic3 = static_cast<int>(c3);
			asciic3dub = asciic3; //��������� �������� �������� ����� �� ������, ����� ��������� �������� = � base64
			//cout << asciic1 << " " << asciic2 << " " << asciic3 << endl;
			if ((count == 4 || count == 5) && asciic2 == -1) { asciic2 = 0; }
			if (count == 5 && asciic3 == -1) { asciic3 = 0; }
			//cout << asciic1 << endl; //�������� �������� � ASCII
			//cout << asciic2 << endl;
			//cout << asciic3 << endl;
			//��� 1 ��������� STEP 1
			res = asciic1 >> 2; //������ ��������� ����� ������ �� 2
			//��� 2 ��������� STEP 2
			res11 = asciic1 << 4; //������ ��������� ����� ����� �� 4
			res12 = asciic2 >> 4; //������ ��������� ����� ������ �� 4
			res1 = res11 | res12; //������ ��������� ���
			res1 = res1 & 63; //������ ��������� � ��� ���������� �� 2 ������� ��������
			//��� 3 ��������� STEP 3
			res22 = asciic2 << 2; //������ ��������� ����� ����� �� 2
			res23 = asciic3 >> 6; //������ ��������� ����� ������ �� 6
			res2 = res22 | res23;
			res2 = res2 & 63;
			//��� 4 ��������� STEP 4
			res3 = asciic3dub & 63;
			//������� ������� �� base64 � �������� ����������
			cout << alphabet[res];
			cout << alphabet[res1];
			cout << alphabet[res2];
			cout << alphabet[res3];
		}
		fin1.close();
	}
	else if(decision == 1) {
		cout << "Jenya's code here\n";
	}
	else {
		cout << "Oops! It seems you typed the wrong number! Close the console and try again ;-)";
	}
	return 0;
}