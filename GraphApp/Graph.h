#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <Map>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;

class Triplet {
public:
	Triplet(string f, string s, int t) {
		first = f;
		second = s;
		third = t;
	}
	bool operator<(const Triplet& other) const {
		return std::tie(first, second, third) < std::tie(other.first, other.second, other.third);
	}

	string first;
	string second;
	int third;

};

class Graph {
public:
	Graph(bool w, bool o) {
		Weighted = w;
		Oriented = o;
		v = map<string, set<pair<string, int>>>();
	}

	Graph() {
		Weighted = false;
		Oriented = false;
	}

	Graph(string name) {
		in.open(name);
		string versh;
		string strMain;
		getline(in, strMain);
		Weighted = stoi(strMain.substr(2, 1));
		Oriented = stoi(strMain.substr(0, 1));
		while (getline(in, strMain)) {

			int i = 0;
			string strDop;
			string strDopWeight;

			while (strMain[i] != ':') {
				strDop += strMain[i];
				i++;
			}
			i += 2;
			versh = strDop;
			this->NodeAdd(versh);
			while (i < strMain.size()) {
				strDop = "";
				strDopWeight = "";
				while (strMain[i] != '_') {
					strDop += strMain[i];
					i++;
				}
				i++;
				while (strMain[i] != ' ') {
					strDopWeight += strMain[i];
					i++;
				}
				this->NodeAdd(strDop);
				this->NodeConnect(versh, strDop, stoi(strDopWeight));
				i++;
			}
		}
		in.close();
		cout << "Загружен граф из файла!" << endl;
	}

	Graph(const Graph& g)
	{
		Weighted = g.Weighted;
		Oriented = g.Oriented;
		v = g.v;
	}

	bool isWeighted() {
		return Weighted;
	}

	bool isOriented() {
		return Oriented;
	}

	map<string, set<pair<string, int>>> getList() {
		return v;
	}

	bool Remove() {
		string option;
		cout << "Вы действительно хотите удалить весь граф? (y - Да, n - Нет): ";
		cin >> option;
		if (option == "y") {
			v.clear();
		}
		else {
			cout << "Удаление отменено." << endl;
		}
		return true;
	}
	bool NodeDel(string node) {
		if (v.find(node) != v.end()) {
			v.erase(node);
			for (auto& element : v) {
				for (auto it = element.second.begin(); it != element.second.end(); it++) {
					if (it->first == node) {
						element.second.erase(it);
						break;
					}
				}
				//element.second.erase(find(element.second.begin(), element.second.end(), NodeName(node));
			}
			return true;
		}
		else {
			cout << "NODE NOT FOUND" << endl;
			return false;
		}
	}
	bool NodeAdd(string node) {
		v.insert(make_pair(node, set<pair<string, int>>()));
		return true;
	}
	bool NodeConnect(string node1, string node2, int w) {
		if (v.find(node1) != v.end() && v.find(node2) != v.end()) {
			/*if (findInCertainNode(node1,node2)) {
				cout << "NODE IS ALREADY CONNECTED IN LIST" << endl;
				return false;
			}*/
			if (!Oriented) {
				if (!Weighted) {
					v[node1].insert(make_pair(node2, 0));
					v[node2].insert(make_pair(node1, 0));
					return true;
				}
				else {
					/*cout << node1 << "-" << node2 << " Type Weight: ";
					int w;
					cin >> w;*/
					v[node1].insert(make_pair(node2, w));
					v[node2].insert(make_pair(node1, w));
					return true;
				}
			}
			else {
				if (!Weighted) {
					v[node1].insert(make_pair(node2, 0));
					return true;
				}
				else {
					/*cout << node1 << "-" << node2 << " Type Weight: ";
					int w;
					cin >> w;*/
					v[node1].insert(make_pair(node2, w));
					return true;
				}
			}
		}
		else {
			cout << "One or both of nodes NOT FOUND" << endl;
			return false;
		}

	}

	bool NodeDisconnect(string node1, string node2) {
		if (v.find(node1) != v.end() && v.find(node2) != v.end()) {
			if (!Oriented) {
				for (auto it = v[node1].begin(); it != v[node1].end(); it++) {
					if (it->first == node2) {
						v[node1].erase(it);
						break;
					}
				}
				for (auto it = v[node2].begin(); it != v[node2].end(); it++) {
					if (it->first == node1) {
						v[node2].erase(it);
						break;
					}
				}
				return true;
			}
			else {
				int f = 0;
				auto it = v[node1].begin();
				for (; it != v[node1].end(); it++) {
					if (it->first == node2) {
						v[node1].erase(it);
						f = 1;
						break;
					}
				}
				if (f) {
					return true;
				}
				else {
					cout << "There was NO WAY from Node 1 to Node 2" << endl;
					return false;
				}
			}
		}
		else {
			cout << "One or both of nodes NOT FOUND";
			return false;
		}

	}

	bool findInNodeList(string nodeToFind) {
		for (auto element : v) {
			if (findInCertainNode(element.first, nodeToFind)) {
				return true;
			}
		}
		return false;
	}

	bool findInCertainNode(string nodeMain, string nodeToFind) {
		set<pair<string, int>> v2 = v[nodeMain];
		for (auto it = v2.begin(); it != v2.end(); it++) {
			if (it->first == nodeToFind) {
				return true;
			}
		}
		return false;
	}

	int degreeIncome(string node) {
		int count = 0;
		for (auto element : v) {
			if (findInCertainNode(element.first, node)) {
				count++;
			}
		}
		return count;
	}

	int degreeOutcome(string node) {
		return v[node].size();
	}

	string task1() {
		string bigString = "";
		for (auto element : v) {
			if (degreeOutcome(element.first) > degreeIncome(element.first)) {
				bigString += element.first + " ";
			}
		}
		return bigString;
	}

	string task2(string node) {
		set <string> bigString;
		string s = "";
		for (auto element : v) {
			if (findInCertainNode(element.first, node)) {
				bigString.insert(element.first);
			}
		}

		for (auto it = v[node].begin(); it != v[node].end(); it++) {
			bigString.insert(it->first);
		}

		for (string sNode : bigString) {
			s += sNode + " ";
		}

		return s;
	}


	set<string> findWay(string node, string nodeTo, set<string> visited) {
		set<string> waypoints;
		waypoints.insert(node);
		if (visited.count(node) == 1) {
			return waypoints;
		}
		visited.insert(node);
		if (findInCertainNode(node, nodeTo)) {
			waypoints.insert(node);
			waypoints.insert(nodeTo);
		}
		for (auto it = v[node].begin(); it != v[node].end(); it++) {
			if (findWay(it->first, nodeTo, visited).size() > 1) {
				set<string> next = findWay(it->first, nodeTo, visited);

				waypoints.insert(node);
				waypoints.insert(next.begin(), next.end());
			}
		}
		return waypoints;
	}

	set<string> mergeComponents(set<string> comp1, set<string> comp2) {
		for (string const& waypoint1 : comp1)
		{
			for (string const& waypoint2 : comp2)
			{
				if (waypoint1 == waypoint2) {
					comp1.insert(comp2.begin(), comp2.end());
					return comp1;
				}
			}
		}
		return comp1;
	}

	bool hasIntersection(set<string> comp1, set<string> comp2) {
		for (const string& waypoint : comp1) {
			if (comp2.count(waypoint) > 0) {
				return true;
			}
		}
		return false;
	}
	set<set<string>> compareAllComponents(set<set<string>> setOfComp) {

		set<set<string>> largestComponents;
		set<set<string>> toDel;
		set<string> temp;
		for (set<string> comp : setOfComp) {
			bool isUnique = true;
			bool reWrite = false;
			temp.clear();
			toDel.clear();
			for (set<string> existingComp : largestComponents) {
				if (hasIntersection(comp, existingComp)) {
					if (comp.size() > existingComp.size() && comp.size() > temp.size()) {
						temp = comp;
						toDel.insert(existingComp);
						reWrite = true;
					}
					isUnique = false;
				}
			}
			if (isUnique) {
				largestComponents.insert(comp);
			}
			else {
				if (reWrite) {
					largestComponents.insert(temp);
					for (set<string> elem : toDel) {
						largestComponents.erase(elem);
					}
				}
			}
		}
		return largestComponents;
	}

	set<set<string>> mergeAllComponents(set<set<string>> setOfComp) {
		set<set<string>> newSetOfComp;
		for (auto it = setOfComp.begin(); it != setOfComp.end(); it++) {
			for (auto it2 = setOfComp.begin(); it2 != setOfComp.end(); it2++) {
				newSetOfComp.insert(mergeComponents(*it, *it2));
			}
		}
		return newSetOfComp;
	}

	string showComponents() {
		set <set<string>> control;

		for (auto element : v) {
			control.insert(findWay(element.first, element.first, set<string>()));
		}
		while (control.size() != mergeAllComponents(control).size()) {
			control = mergeAllComponents(control);
		}

		control = compareAllComponents(control);

		string bigString = "";
		for (auto it = control.begin(); it != control.end(); it++) {
			bigString += "component: ";
			for (string const& waypoint : *it) {
				bigString += waypoint + " ";
			}
			bigString += "\n";
		}
		return bigString;
	}

	set <string> showComponentContain(string node) {
		set <set<string>> control;
		set<string> result;
		for (auto element : v) {
			control.insert(findWay(element.first, element.first, set<string>()));
		}
		while (control.size() != mergeAllComponents(control).size()) {
			control = mergeAllComponents(control);
		}

		control = compareAllComponents(control);

		for (auto it = control.begin(); it != control.end(); it++) {
			for (string const& waypoint : *it) {
				if (waypoint == node) {
					result = *it;
					return result;
				}
			}
		}
		return result;
	}

	string findWayLength(string node, int lim) {
		map<string, int> d;
		queue <string> q;
		for (auto& el : v) {
			d.insert(make_pair(el.first, INT_MAX));
		}

		d[node] = 0;
		q.push(node);

		while (!q.empty())
		{
			string vertice = q.front();
			q.pop();

			for (auto& el : v[vertice]) {
				if (d[el.first] > d[vertice] + 1) {
					d[el.first] = d[vertice] + 1;
					q.push(el.first);
				}
			}
		}

		string bigString = "";
		for (auto& waypoint : d) {
			if (waypoint.second <= lim) bigString += waypoint.first + " ";
		}
		return bigString;
	}

	Triplet NodesMinWeight(map<string, set<pair<string, int>>> newV) {
		string node1, node2;
		int minWeight = 2147483647;
		for (auto const& element : newV) {
			for (auto it = element.second.begin(); it != element.second.end(); it++) {
				if (it->second < minWeight) {
					minWeight = it->second;
					node1 = element.first;
					node2 = it->first;
				}
			}
		}

		return Triplet(node1, node2, minWeight);
	}

	bool allNodesConnected(Graph gr) {
		set<string> nodes;
		string nodeF;
		for (auto const& element : v) {
			nodeF = element.first;
			nodes.insert(element.first);
		}

		if (gr.showComponentContain(nodeF) == nodes) return true;
		else return false;

	}

	Graph ostovKraskal() {
		if (Oriented || !Weighted || v.empty()) {
			cout << "Попытка ввести пустой или ориентированный или невзвешенный граф, будет возвращен пустой" << endl;
			return Graph(1, 0);
		}

		Graph newG(1, 0);
		map<string, set<pair<string, int>>> newV = v;

		for (auto const& element : v) {
			newG.NodeAdd(element.first);
		}

		while (!allNodesConnected(newG)) {
			Triplet way = NodesMinWeight(newV);

			if (newG.showComponentContain(way.first) == newG.showComponentContain(way.second)) {
				//ничего не делаем и просто удаляем ребро
			}
			else {
				newG.NodeConnect(way.first, way.second, way.third);
			}

			for (auto it = newV[way.first].begin(); it != newV[way.first].end(); it++) {
				if (it->first == way.second) {
					newV[way.first].erase(it);
					break;
				}
			}
			for (auto it = newV[way.second].begin(); it != newV[way.second].end(); it++) {
				if (it->first == way.first) {
					newV[way.second].erase(it);
					break;
				}
			}
		}

		return newG;
	}

	bool allNodesIsSet(set<string> d) {
		set<string> nodes;

		for (auto const& element : v) {
			nodes.insert(element.first);
		}

		if (d == nodes) return true;
		else return false;

	}

	pair<string, int> getPairWithName(string inList, string node) {
		for (auto const& element : v[inList]) {
			if (element.first == node) return element;
		}
		return make_pair(node, INT_MAX);
	}

	pair<string, int> getPairWithName(string inList, string node, map<string, set<pair<string, int>>> list) {
		for (auto const& element : list[inList]) {
			if (element.first == node) return element;
		}
		if (inList == node) return make_pair(node, 0);
		return make_pair(node, INT_MAX);
	}

	map<string, string> dekstra(string node) {
		map<string, int> d;
		map<string, string> dWay;
		map<string, int> dFin;
		map<string, string> dFinWay;
		set<string> s;
		string curNode = node;
		int minW;

		for (auto const& element : v) {
			if (element.first == node) d.insert(make_pair(element.first, 0));
			else d.insert(make_pair(element.first, INT_MAX));
		}

		for (auto const& element : v) {
			dWay.insert(make_pair(element.first, ""));
		}

		dFin.insert(make_pair(curNode, 0));
		dFinWay.insert(make_pair(curNode, node));
		dWay[curNode] = node;
		s.insert(curNode);
		d.erase(curNode);

		while (!allNodesIsSet(s)) {
			for (auto& element : d) {
				if (getPairWithName(curNode, element.first).second == INT_MAX) minW = INT_MAX;
				else minW = dFin[curNode] + getPairWithName(curNode, element.first).second;

				if (element.second > minW) {
					element.second = minW;
					dWay[element.first] = dFinWay[curNode] + " " + element.first;
				}
			}
			minW = INT_MAX;
			for (auto& element : d) {
				if (element.second <= minW) {
					minW = element.second;
					curNode = element.first;
				}
			}
			dFinWay[curNode] = dWay[curNode];
			dFin.insert(make_pair(curNode, minW));
			s.insert(curNode);
			d.erase(curNode);
			dWay.erase(curNode);
		}
		return dFinWay;
	}

	string dekstraTask(string u1, string u2, string v) {
		return u1 + ": " + dekstra(u1)[v] + "\n" + u2 + ": " + dekstra(u2)[v];
	}

	void floydTask(string u1, string u2, int l) {
		map<string, set<pair<string, int>>> newV = v;
		for (auto& element : newV) {
			for (auto& it : newV) {
				if (!findInCertainNode(element.first, it.first)) {
					newV[element.first].insert(make_pair(it.first, INT_MAX));
				}
			}
		}
		map<string, set<pair<string, int>>> newVprev = newV;
		map<string, set<pair<string, int>>> newVnext = newV;



		string bigString;
		string name;
		int weight;
		for (auto& k : v) {
			for (auto& i : newVprev) {
				for (auto j = i.second.begin(); j != i.second.end(); j++) {
					name = j->first;
					weight = j->second;
					newVnext[i.first].erase(make_pair(name, weight));

					if (getPairWithName(i.first, k.first, newVprev).second == INT_MAX
						|| getPairWithName(k.first, j->first, newVprev).second == INT_MAX) weight = INT_MAX;
					else weight = getPairWithName(i.first, k.first, newVprev).second
						+ getPairWithName(k.first, j->first, newVprev).second;

					newVnext[i.first].insert(make_pair(name, min(getPairWithName(i.first, j->first, newVprev).second, weight)));
				}
			}
			newVprev = newVnext;

		}

		if (getPairWithName(u1, u2, newVnext).second != INT_MAX && getPairWithName(u1, u2, newVnext).second <= l) cout << u1 << " -> " << u2 << ": существует" << endl;
		else cout << u1 << " -> " << u2 << ": не существует" << endl;
		if (getPairWithName(u2, u1, newVnext).second != INT_MAX && getPairWithName(u2, u1, newVnext).second <= l) cout << u2 << " -> " << u1 << ": существует" << endl;
		else cout << u2 << " -> " << u1 << ": не существует" << endl;
	}

	set<string> dfs(string node, set<string> used) {
		set<string> waypoints;
		set<string> temp;
		if (used.count(node) == 1) return waypoints;

		waypoints.insert(node);
		used.insert(node);
		for (auto& element : v[node]) {
			temp = dfs(element.first, used);
			waypoints.insert(temp.begin(), temp.end());
		}

		return waypoints;

	}

	map<string, int> bellFord(string node) {
		map<string, int> d;
		int sum = 0;
		set<string> temp;
		set<string> badVertex;
		set<string> badAssVertex;

		for (auto const& element : v) {
			if (element.first == node) d.insert(make_pair(element.first, 0));
			else d.insert(make_pair(element.first, INT_MAX));
		}

		int weight;
		for (int k = 0; k < v.size(); k++) {
			for (auto& i : v) {
				for (auto j = i.second.begin(); j != i.second.end(); j++) {
					if (d[i.first] == INT_MAX || getPairWithName(i.first, j->first).second == INT_MAX)
						weight = INT_MAX;
					else
						weight = d[i.first] + getPairWithName(i.first, j->first).second;

					if (d[j->first] > weight) {
						if (k == v.size() - 1) {
							badVertex.insert(j->first);
						}
						else {
							d[j->first] = weight;
						}
					}

				}
			}
		}

		for (auto& element : badVertex) {
			temp = dfs(element, set<string>());
			badAssVertex.insert(temp.begin(), temp.end());
		}

		for (auto& element : badAssVertex) {
			d[element] = INT_MAX;
		}
		d.erase(node);
		return d;
	}

	string bellFordTask() {
		int sum;
		int min = INT_MAX;
		string name = "NOT FOUND";
		for (auto& const element : v) {
			sum = INT_MAX;
			for (auto& const it : bellFord(element.first)) {
				if (it.second != INT_MAX) {
					if (sum == INT_MAX) sum = 0;
					sum += it.second;
				}
			}
			if (sum < min) {
				min = sum;
				name = element.first;
			}
		}
		return name + ": " + to_string(min);
	}

	int findOverallWeight(set<Triplet> trip) {
		int minWeight = INT_MAX;
		for (auto& elem : trip) {
			minWeight = min(minWeight, elem.third);
		}
		if (minWeight == INT_MAX) return 0;
		else return minWeight;
	}

	map<string, set<pair<string, int>>> decreaseRoads(map<string, set<pair<string, int>>> newV, set<Triplet> roads, int dec) {
		for (auto& elem : roads) {
			newV[elem.first].erase(make_pair(elem.second, elem.third));
			newV[elem.first].insert(make_pair(elem.second, elem.third - dec));
		}
		return newV;
	}

	set<Triplet> buildPairs(string nodeFrom, string nodeTo, set<string> visited, map<string, set<pair<string, int>>> tempV) {
		set<Triplet> primaryPairs;
		set<Triplet> secondaryPairs;
		set<Triplet> tempPairs;

		if (visited.count(nodeFrom) == 1) {
			return set<Triplet>();
		}

		visited.insert(nodeFrom);
		if (findInCertainNode(nodeFrom, nodeTo)) {
			pair <string, int> finPair = getPairWithName(nodeFrom, nodeTo, tempV);
			Triplet finTriplet = Triplet(nodeFrom, finPair.first, finPair.second);
			primaryPairs.insert(finTriplet);
		}
		for (auto it = tempV[nodeFrom].begin(); it != tempV[nodeFrom].end(); it++) {
			tempPairs.clear();
			pair <string, int> finPair = getPairWithName(nodeFrom, it->first, tempV);
			Triplet finTriplet = Triplet(nodeFrom, finPair.first, finPair.second);
			tempPairs.insert(finTriplet);

			set<Triplet> next = buildPairs(it->first, nodeTo, visited, tempV);
			if (next.size() > 0) {
				tempPairs.insert(next.begin(), next.end());

				if (findOverallWeight(secondaryPairs) < findOverallWeight(tempPairs)) {
					secondaryPairs = tempPairs;
				}

			}
		}

		if (findOverallWeight(primaryPairs) >= findOverallWeight(secondaryPairs)) {
			return primaryPairs;
		}
		else {
			return secondaryPairs;
		}

	}

	int potok(string nodeFrom, string nodeTo) {
		bool hasWays = false;
		int sum = 0;
		set<Triplet> wayToFin;
		int weightToFin;
		map<string, set<pair<string, int>>> tempV = v;

		while (true) {
			wayToFin = buildPairs(nodeFrom, nodeTo, set<string>(), tempV);
			if (wayToFin.size() <= 0) break;
			weightToFin = findOverallWeight(wayToFin);
			sum += weightToFin;
			tempV = decreaseRoads(tempV, wayToFin, weightToFin);
		}

		return sum;

	}

	void Print() {
		cout << "==================PRINT==================" << endl;
		cout << "Граф: ";
		if (Oriented) cout << "Ориентированный, ";
		else cout << "Неориентированный, ";
		if (Weighted) cout << "Взвешенный" << endl;
		else cout << "Невзвешенный" << endl;
		if (!v.empty()) {
			for (auto element : v) {
				cout << element.first << ": ";
				for (auto it = element.second.begin(); it != element.second.end(); it++) {
					cout << it->first << "_" << it->second << " ";
				}
				cout << endl;
			}
		}
		cout << "==================PRINT==================" << endl;
	}

	void Readfile(string name) {
		cout << "Текущий граф будет УДАЛЕН" << endl;
		this->Remove();
		in.open(name);
		string versh;
		string strMain;
		getline(in, strMain);
		Weighted = stoi(strMain.substr(2, 1));
		Oriented = stoi(strMain.substr(0, 1));
		while (getline(in, strMain)) {

			int i = 0;
			string strDop;
			string strDopWeight;

			while (strMain[i] != ':') {
				strDop += strMain[i];
				i++;
			}
			i += 2;
			versh = strDop;
			this->NodeAdd(versh);
			while (i < strMain.size()) {
				strDop = "";
				strDopWeight = "";
				while (strMain[i] != '_') {
					strDop += strMain[i];
					i++;
				}
				i++;
				while (strMain[i] != ' ') {
					strDopWeight += strMain[i];
					i++;
				}
				this->NodeAdd(strDop);
				this->NodeConnect(versh, strDop, stoi(strDopWeight));
				i++;
			}
		}
		in.close();
		cout << "Загружен граф из файла!" << endl;
	}
	void Writefile(string name) {
		out.open(name);
		out << Oriented << " " << Weighted << endl;
		for (auto element : v) {
			out << element.first << ": ";
			for (auto it = element.second.begin(); it != element.second.end(); it++) {
				out << it->first << "_" << it->second << " ";
			}
			out << endl;
		}
		out.close();
	}
private:
	map<string, set<pair<string, int>>> v;
	bool Weighted;
	bool Oriented;

};

Graph unite(Graph g1, Graph g2) {
	if (g1.isWeighted() || g1.isOriented() || g2.isWeighted() || g2.isOriented()) {
		cout << "Попытка ввести взвешенный или ориентированный граф, будет возвращаен пустой!" << endl;
		return Graph(0, 0);
	}
	Graph united(0, 0);
	map<string, set<pair<string, int>>> v1, v2;
	v1 = g1.getList();
	v2 = g2.getList();
	for (auto& element : v1) {
		united.NodeAdd(element.first);
	}
	for (auto& element : v2) {
		united.NodeAdd(element.first);
	}
	for (auto& element : v1) {
		for (auto it = element.second.begin(); it != element.second.end(); it++) {
			united.NodeConnect(element.first, it->first, it->second);
		}
	}
	for (auto& element : v2) {
		for (auto it = element.second.begin(); it != element.second.end(); it++) {
			united.NodeConnect(element.first, it->first, it->second);
		}
	}
	return united;
}