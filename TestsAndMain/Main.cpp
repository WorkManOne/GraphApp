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
		cout << endl << "0 - Создать граф " << endl
			<< "1 - Вывести список смежности графа " << endl
			<< "2 - Добавить вершину " << endl
			<< "3 - Удалить вершину " << endl
			<< "4 - Добавить ребро " << endl
			<< "5 - Удалить ребро " << endl
			<< "6 - Вывести список смежности графа В ФАЙЛ " << endl
			<< "7 - Очистить граф (Удалить полностью) " << endl
			<< "8 - Выход " << endl
			<< "9 - Выбрать Граф " << endl
			<< "10 - Меню специальных заданий " << endl << endl;
		cout << "Введите номер действия, которое вы хотите сделать: ";
		cin >> option;
		switch (option)
		{
		case 0:
			cout << "Вы хотите загрузить граф из файла? (y - Да, n - Нет): ";
			cin >> opt;
			if (opt == "y") {
				cout << "Введите имя файла: ";
				cin >> name;
				GraphM.push_back(Graph(name));
				now = GraphM.size() - 1;
			}
			else {
				cout << "Введите параметры графа (взвешенность, ориентированность): ";
				cin >> w >> o;
				/*cout << "Введите имя графа: ";
				cin >> name;*/
				GraphM.push_back(Graph(w, o));
				now = GraphM.size() - 1;
			}
			break;
		case 1:
			GraphM[now].Print();
			break;
		case 2:
			cout << "Введите имя вершины которую хотите добавить: ";
			cin >> name;
			GraphM[now].NodeAdd(name);
			break;
		case 3:
			cout << "Введите имя вершины которую хотите удалить: ";
			cin >> name;
			GraphM[now].NodeDel(name);
			break;
		case 4:
			cout << "Введите имена вершин которые хотите соединить (если орграф то в порядке 1 -> 2): " << endl;
			cout << "Имя первой вершины: ";
			cin >> name1;
			cout << "Имя второй вершины: ";
			cin >> name2;
			if (GraphM[now].isWeighted()) {
				cout << "Вес ребра: ";
				cin >> weight;
				GraphM[now].NodeConnect(name1, name2, weight);
			}
			else {
				GraphM[now].NodeConnect(name1, name2, 0);
			}
			break;
		case 5:
			cout << "Введите имена вершин которые хотите разъединить (если орграф то в порядке 1 -> 2): " << endl;
			cout << "Имя первой вершины: ";
			cin >> name1;
			cout << "Имя второй вершины: ";
			cin >> name2;
			GraphM[now].NodeDisconnect(name1, name2);
			break;
		case 6:
			cout << "Введите имя файла: ";
			cin >> name;
			GraphM[now].Writefile(name);
			break;
		case 7:
			GraphM[now].Remove();
			break;
		case 8:
			cout << "Вы действительно хотите выйти? (y - Да, n - Нет): ";
			cin >> opt;
			if (opt == "y") {
				exit(0);
			}
			else {
				cout << "Выход отменен." << endl;
			}
			break;
		case 9:
			cout << "Введите номер выбранного графа (от 0 до "<< GraphM.size() - 1 << ") : ";
			cin >> optInt;
			now = optInt;
			break;
		case 10:
			cout << endl << "МЕНЮ СПЕЦИАЛЬНЫХ ЗАДАНИЙ: " << endl << "1 - Вывести те вершины, у которых полустепень исхода больше полустепени захода. " << endl
				<< "2 - Вывести все вершины орграфа, смежные с данной. " << endl
				<< "3 - Найти степень ЗАХОДА вершины " << endl
				<< "4 - Найти степень ИСХОДА вершины " << endl
				<< "5 - Построить граф, являющийся объединением двух заданных. " << endl
				<< "6 - Найти сильно связные компоненты орграфа. " << endl
				<< "7 - Вывести все вершины, в которые есть путь длиной не более k дуг из заданной вершины u. " << endl
				<< "8 - Найти в графе каркас минимального веса, используя алгоритм Краскала " << endl
				<< "9 - Вывести кратчайшие пути из вершин u1 и u2 до v. (Дейкстра) " << endl
				<< "10 - Определить, существует ли путь длиной не более L между двумя заданными вершинами графа. (Флойд) " << endl
				<< "11 - Найти вершину, сумма длин кратчайших путей от которой до остальных вершин минимальна. (Беллман-Форд) " << endl
				<< "12 - Найти максимальный поток " << endl
				<< "13 - NOFUNCTION " << endl
				<< "14 - NOFUNCTION " << endl
				<< "15 - Выйти из меню " << endl;
			cout << "Введите номер действия, которое вы хотите сделать: ";
			cin >> optInt;
			switch (optInt) {
			case 1:
				cout << "Вершины, у которых полустепень исхода больше полустепени захода: " << GraphM[now].task1();
				break;
			case 2:
				cout << "Введите имя вершины, у которой хотите найти смежные: ";
				cin >> name;
				cout << "Смежные вершины " << name << ": " << GraphM[now].task2(name);
				break;
			case 3:
				cout << "Введите имя вершины степень захода которой хотите найти: ";
				cin >> name;
				cout << "Степень захода: " << GraphM[now].degreeIncome(name);
				break;
			case 4:
				cout << "Введите имя вершины степень исхода которой хотите найти: ";
				cin >> name;
				cout << "Степень исхода: " << GraphM[now].degreeOutcome(name);
				break;
			case 5:
				cout << "Введите номера графов которые хотите объединить : " << endl;
				cout << "Номер первого графа: ";
				cin >> num1;
				cout << "Номер второго графа: ";
				cin >> num2;
				GraphM.push_back(unite(GraphM[num1], GraphM[num2]));
				now = GraphM.size() - 1;
				cout << "Добавлен новый граф" << endl;
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
				cout << "Добавлен новый граф" << endl;
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