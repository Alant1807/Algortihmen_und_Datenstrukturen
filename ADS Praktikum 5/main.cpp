#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"

using namespace std;

/*
Bearbeitet von Alan Tofeq
*/

void ausgabeAdjazenzen(EdgeWeightedGraph G) {
	for (int v = 0; v < G.getV(); v++) {
		cout << v;
		for (auto w : G.getAdj(v)) {     // gehe über alle Adjazenzkanten zu dem Knoten v
			int adj_node = w.other(v);   // AdjazenzKnoten zu i bestimmen
			cout << " -> " << adj_node << " [" << w.weight() << "]";
		}
		cout << endl;
	}
}

void ausgabePrimMst(PrimMST Prim, vector<Edge> mst_kanten) {
	cout << "\nMinimaler Spannbaum (MST) nach Prim: \n"
		<< "Gewicht: " << Prim.weight() << endl << "Adjazenzliste: \n";
	mst_kanten = Prim.edges();
	int highest_node = 0;
	int i = 0;
	bool output = false;
	while (i < mst_kanten.size()) {        // geht alle Knoten durch 
		Edge node = mst_kanten[i];
		if (highest_node < node.either()) {
			highest_node = node.either();        // speichere den höchsten Knoten
		}
		i++;
	}
	for (int x = 0; x <= highest_node; x++) {
		for (int w = 0; w < mst_kanten.size(); w++) {
			if (mst_kanten[w].either() == x) {       // Wenn die Kante, die untersucht wird gleich x ist
				if (!output) {
					output = true;
					std::cout << std::endl << x;
				}
				std::cout << " -> " << mst_kanten[w].other(x) << "[" << mst_kanten[w].weight() << "]";       // gebe alle Adjazenzknoten aus
			}
		}
		output = false;
	}
	std::cout << "\n";
}

void ausgabeKruskal(KruskalMST Kruskal) {
	cout << "\nMinimaler Spannbaum nach Kruskal: \n"
		<< "Gewicht: " << Kruskal.weight() << endl
		<< "Adjazenzliste: \n";
	vector<Edge> mst_kanten = Kruskal.edges();
	int highest_node = 0;
	int i = 0;
	bool output = false;
	while (i < mst_kanten.size()) {        // geht alle Knoten durch 
		Edge node = mst_kanten[i];
		if (highest_node < node.either()) {
			highest_node = node.either();        // speichere den höchsten Knoten
		}
		i++;
	}
	for (int x = 0; x <= highest_node; x++) {
		for (int w = 0; w < mst_kanten.size(); w++) {
			if (mst_kanten[w].either() == x) {      // Wenn die Kante, die untersucht wird gleich x ist
				if (!output) {
					output = true;
					std::cout << std::endl << x;
				}
				std::cout << " -> " << mst_kanten[w].other(x) << "[" << mst_kanten[w].weight() << "]";       // gebe alle Adjazenzknoten aus 
			}
		}
		output = false;
	}
	std::cout << "\n";
}

void ausgabeDijkstra(DijkstraSP Dijkstra, EdgeWeightedDigraph Graph, int start, int zielknoten) {
	cout << "Gewichtete Kanten des Graphen\n";
	// Gebe den gerichteten Graph aus
	for (int v = 0; v < Graph.getV(); v++) {      
		cout << v;
		for (auto w : Graph.getAdj(v)) {   
			cout << " -> " << w.to() << " [" << w.weight() << "] ";
		}
		cout << endl;
	}

	int cost = 0;
	vector<DirectedEdge> path = Dijkstra.pathTo(zielknoten);
	cout << "\n\n";
	cout << "Kurzester Weg (Dijkstra):\n";
	cout << "Start: " << start << endl;
	cout << "Ziel: " << zielknoten << endl;
	cout << "Pfad: " << path[0].from();

	for (int node_edge = 0; node_edge < path.size(); node_edge++) {
		DirectedEdge w = path[node_edge];
		cost += w.weight();
		cout << " [" << w.weight() << "] " << "-> " << w.to();
	}
	cout << endl;
	cout << "Kosten: " << cost << endl;
}

int main() {
	// Starte Unit-Tests
	Catch::Session().run();

	//------------------------------------------------------------------------
	// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
	//------------------------------------------------------------------------

	EdgeWeightedGraph Graph(0);
	EdgeWeightedGraph Graph1("graph1.txt");
	EdgeWeightedGraph Graph2("graph2.txt");
	EdgeWeightedGraph Graph3("graph3.txt");

	EdgeWeightedDigraph DiGraph(0);
	EdgeWeightedDigraph DiGraph1("graph1.txt");
	EdgeWeightedDigraph DiGraph2("graph2.txt");
	EdgeWeightedDigraph DiGraph3("graph3.txt");

	vector<bool> marked;
	vector<int> edgeTo;
	bool zsmhängend = false;
	int eingabe, graph, prim, dfs, bfs = 0;

	do {

		//------------------------------------------------------------------------
		// 5. Menü für Benutzereingaben
		//------------------------------------------------------------------------
		// Alle Funktionalitäten aus der Aufgabenstellung muessen umgesetzt werden

		cout << "\nPraktikum 5: Graphenalgorithmen:\n";
		cout << "1) Graph einlesen\n";
		cout << "2) Tiefensuche\n";
		cout << "3) Breitensuche\n";
		cout << "4) MST nach Prim\n";
		cout << "5) MST nach Kruskal\n";
		cout << "6) Kuerzeste Wege nach Dijkstra\n";
		cout << "7) Ausgabe der Adjazenzliste\n";
		cout << "8) Program beenden\n";
		cout << "\nWaehlen sie eine Eingabe ";

		do {
			while (!(cin >> eingabe)) {
				cout << "Falsche Eingabe.Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (eingabe < 1 || eingabe > 8) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
			}
		} while (eingabe < 1 || eingabe > 8);

		if (eingabe == 1) {
			cout << "\nWaehlen sie einen Graphen aus. Zur Verfuegung stehen die Graphen 1, 2 oder 3\n";
			do {
				while (!(cin >> graph)) {
					cout << "Falsche Eingabe. Bitte erneut eingeben ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (graph < 1 || graph > 3) {
					cout << "Falsche Eingabe. Bitte erneut eingeben ";
				}
			} while (graph < 1 || graph > 3);
			if (graph == 1) {
				Graph = Graph1;
				DiGraph = DiGraph1;
			}
			else if (graph == 2) {
				Graph = Graph2;
				DiGraph = DiGraph2;
			}
			else if (graph == 3) {
				Graph = Graph3;
				DiGraph = DiGraph3;
			}
		}

		//------------------------------------------------------------------------
		// 2. Suche in Graphen
		//------------------------------------------------------------------------
		// Verwenden Sie hierfür die Vorlagen in Graphsearch.h
		//
		// Beispielaufruf der Tiefensuche: 
		// std::vector<bool> marked;
		// std::vector<int>  edgeTo;
		// bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);

		if (eingabe == 2) {
			cout << "Waehlen sie ihren Startknoten ";
			while (!(cin >> dfs)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			zsmhängend = Graphsearch::DFS(Graph, dfs, marked, edgeTo);
			if (zsmhängend) {
				cout << "\nGraph ist zusammenhaengend\n";
			}
			else {
				cout << "\nGraph ist nicht zusammenhaengend\n";
			}
		}

		if (eingabe == 3) {
			cout << "Wählen sie ihren Startknoten ";
			while (!(cin >> bfs)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			zsmhängend = Graphsearch::BFS(Graph, bfs, marked, edgeTo);
			if (zsmhängend) {
				cout << "\nGraph ist zusammenhangend\n";
			}
			else {
				cout << "\nGraph ist nicht zusammenhangend\n";
			}
		}

		//------------------------------------------------------------------------
		// 3. Minimaler Spannbaum mit Prim und Kruskal
		//------------------------------------------------------------------------
		// Vorlage für Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
		// Vorlage für Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
		//
		// Beispielaufruf von Prim:
		// PrimMST prim(G, 0);

		if (eingabe == 4) {
			cout << "\nWählen sie Ihren Startknoten ? ";
			while (!(cin >> prim)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			PrimMST Prim(Graph, prim);
			ausgabePrimMst(Prim, Prim.edges());
		}

		if (eingabe == 5) {
			KruskalMST Kruskal(Graph);
			ausgabeKruskal(Kruskal);
		}

		if (eingabe == 6) {
			
			int start = 0;
			int zielknoten = 0;
			cout << "Wählen sie Ihren Startknoten ? ";
			while (!(cin >> start)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Wählen sie Ihren Zielknoten ? ";
			while (!(cin >> zielknoten)) {
				cout << "Falsche Eingabe. Bitte erneut eingeben ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			DijkstraSP Dijkstra(DiGraph, start);
			ausgabeDijkstra(Dijkstra, DiGraph, start, zielknoten);
		}

		if (eingabe == 7) {
			cout << "\n";
			ausgabeAdjazenzen(Graph);
		}

		if (eingabe == 8) {
			cout << "\nSie haben die Menueanwendung verlassen.\n\n";
			break;
		}

	} while (true);

	//------------------------------------------------------------------------
	// 4. Kuerzeste Wege mit Dijkstra
	//------------------------------------------------------------------------
	// Beispielaufruf von Dijkstra
	//
	// EdgeWeightedDigraph G1_directed("graph1.txt");
	// Dijkstra dijkstra(G1_directed, start);
	// path = dijkstra.pathTo(target);

	system("pause");
	return 0;
}