#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <Map>
#include <queue>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	vector<Graph> GraphM;
	GraphM.push_back(Graph());
	int now = 0;

	bool w, o;
	int option;
	int optInt;
	int weight;
	int num1, num2;
	string name;
	string name1;
	string name2;
	string opt;


	while (true) {
		cout << endl << "0 - ������� ���� " << endl
			<< "1 - ������� ������ ��������� ����� " << endl
			<< "2 - �������� ������� " << endl
			<< "3 - ������� ������� " << endl
			<< "4 - �������� ����� " << endl
			<< "5 - ������� ����� " << endl
			<< "6 - ������� ������ ��������� ����� � ���� " << endl
			<< "7 - �������� ���� (������� ���������) " << endl
			<< "8 - ����� " << endl
			<< "9 - ������� ���� " << endl
			<< "10 - ���� ����������� ������� " << endl << endl;
		cout << "������� ����� ��������, ������� �� ������ �������: ";
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "�� ������ ��������� ���� �� �����? (y - ��, n - ���): ";
			cin >> opt;
			if (opt == "y") {
				cout << "������� ��� �����: ";
				cin >> name;
				GraphM.push_back(Graph(name));
				now = GraphM.size() - 1;
			}
			else {
				cout << "������� ��������� ����� (������������, �����������������): ";
				cin >> w >> o;
				/*cout << "������� ��� �����: ";
				cin >> name;*/
				GraphM.push_back(Graph(w, o));
				now = GraphM.size() - 1;
			}
			break;
		case 1:
			GraphM[now].Print();
			break;
		case 2:
			cout << "������� ��� ������� ������� ������ ��������: ";
			cin >> name;
			GraphM[now].NodeAdd(name);
			break;
		case 3:
			cout << "������� ��� ������� ������� ������ �������: ";
			cin >> name;
			GraphM[now].NodeDel(name);
			break;
		case 4:
			cout << "������� ����� ������ ������� ������ ��������� (���� ������ �� � ������� 1 -> 2): " << endl;
			cout << "��� ������ �������: ";
			cin >> name1;
			cout << "��� ������ �������: ";
			cin >> name2;
			if (GraphM[now].isWeighted()) {
				cout << "��� �����: ";
				cin >> weight;
				GraphM[now].NodeConnect(name1, name2, weight);
			}
			else {
				GraphM[now].NodeConnect(name1, name2, 0);
			}
			break;
		case 5:
			cout << "������� ����� ������ ������� ������ ����������� (���� ������ �� � ������� 1 -> 2): " << endl;
			cout << "��� ������ �������: ";
			cin >> name1;
			cout << "��� ������ �������: ";
			cin >> name2;
			GraphM[now].NodeDisconnect(name1, name2);
			break;
		case 6:
			cout << "������� ��� �����: ";
			cin >> name;
			GraphM[now].Writefile(name);
			break;
		case 7:
			GraphM[now].Remove();
			break;
		case 8:
			cout << "�� ������������� ������ �����? (y - ��, n - ���): ";
			cin >> opt;
			if (opt == "y") {
				exit(0);
			}
			else {
				cout << "����� �������." << endl;
			}
			break;
		case 9:
			cout << "������� ����� ���������� ����� (�� 0 �� "<< GraphM.size() - 1 << ") : ";
			cin >> optInt;
			now = optInt;
			break;
		case 10:
			cout << endl << "���� ����������� �������: " << endl << "1 - ������� �� �������, � ������� ����������� ������ ������ ����������� ������. " << endl
				<< "2 - ������� ��� ������� �������, ������� � ������. " << endl
				<< "3 - ����� ������� ������ ������� " << endl
				<< "4 - ����� ������� ������ ������� " << endl
				<< "5 - ��������� ����, ���������� ������������ ���� ��������. " << endl
				<< "6 - ����� ������ ������� ���������� �������. " << endl
				<< "7 - ������� ��� �������, � ������� ���� ���� ������ �� ����� k ��� �� �������� ������� u. " << endl
				<< "8 - ����� � ����� ������ ������������ ����, ��������� �������� �������� " << endl
				<< "9 - ������� ���������� ���� �� ������ u1 � u2 �� v. (��������) " << endl
				<< "10 - ����������, ���������� �� ���� ������ �� ����� L ����� ����� ��������� ��������� �����. (�����) " << endl
				<< "11 - ����� �������, ����� ���� ���������� ����� �� ������� �� ��������� ������ ����������. (�������-����) " << endl
				<< "12 - ����� ������������ ����� " << endl
				<< "13 - NOFUNCTION " << endl
				<< "14 - NOFUNCTION " << endl
				<< "15 - ����� �� ���� " << endl;
			cout << "������� ����� ��������, ������� �� ������ �������: ";
			cin >> optInt;
			switch (optInt) {
			case 1:
				cout << "�������, � ������� ����������� ������ ������ ����������� ������: " << GraphM[now].task1();
				break;
			case 2:
				cout << "������� ��� �������, � ������� ������ ����� �������: ";
				cin >> name;
				cout << "������� ������� " << name << ": " << GraphM[now].task2(name);
				break;
			case 3:
				cout << "������� ��� ������� ������� ������ ������� ������ �����: ";
				cin >> name;
				cout << "������� ������: " << GraphM[now].degreeIncome(name);
				break;
			case 4:
				cout << "������� ��� ������� ������� ������ ������� ������ �����: ";
				cin >> name;
				cout << "������� ������: " << GraphM[now].degreeOutcome(name);
				break;
			case 5:
				cout << "������� ������ ������ ������� ������ ���������� : " << endl;
				cout << "����� ������� �����: ";
				cin >> num1;
				cout << "����� ������� �����: ";
				cin >> num2;
				GraphM.push_back(unite(GraphM[num1], GraphM[num2]));
				now = GraphM.size() - 1;
				cout << "�������� ����� ����" << endl;
				break;
			case 6:
				cout << GraphM[now].showComponents();
				break;
			case 7:
				cout << "k: ";
				cin >> num1;
				cout << "u: ";
				cin >> name2;
				cout << GraphM[now].findWayLength(name2,num1);
				break;
			case 8:
				GraphM.push_back(GraphM[now].ostovKraskal());
				now = GraphM.size() - 1;
				cout << "�������� ����� ����" << endl;
				break;
			case 9:
				cout << "u1: ";
				cin >> name1;
				cout << "u2: ";
				cin >> name2;
				cout << "v: ";
				cin >> name;
				cout << GraphM[now].dekstraTask(name1, name2, name);
				break;
			case 10:
				cout << "u1: ";
				cin >> name1;
				cout << "u2: ";
				cin >> name2;
				cout << "L: ";
				cin >> num1;
				GraphM[now].floydTask(name1,name2,num1);
				break;
			case 11:
				cout << GraphM[now].bellFordTask();
				break;
			case 12:
				cout << "IN: ";
				cin >> name1;
				cout << "OUT: ";
				cin >> name2;
				cout << GraphM[now].potok(name1, name2);
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}