#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>
#include <queue>
#include <algorithm>

/*
Bearbeitet von Alan Tofeq
*/

namespace Graphsearch {

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen G,
		* ab dem Knoten v aus und markiert alle besuchten
		* Knoten in marked.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]	 G			Graph
		* \param[in]	 v			Startknoten
		* \param[in/out] marked		Bereits besuchte Knoten
		* \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
		*/
	void DFS_recursive(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		marked[v] = true; // marked auf true setzen Knoten ist besucht
		for (auto w : G.getAdj(v)) {      // gehe über alle Adjazenzenknoten zu v
			int adj_node = w.other(v);    // gebe adjazenzen Knoten zu v zurück
			if (!marked[adj_node]) {
				std::cout << " -> " << adj_node;
				edgeTo[v] = adj_node;     // speichert zu knoten v den adjazenzen_knoten adj_node
				DFS_recursive(G, adj_node, marked, edgeTo);
			}
		}
	}

	/**
		* Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		* Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
		*
		* \param[in]  G			Graph
		* \param[out] marked	Bereits besuchte Knoten
		* \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
		* \param[in]  v			Startknoten
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/

	bool DFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		marked.clear(); edgeTo.clear();
		marked.assign(G.getV(), false); edgeTo.assign(G.getV(), -1);
		std::cout << "\nTiefensuche(Depth - First - Search(DFS)) - Startknoten: " << v << std::endl 
			<< "Besuchsreihenfolge: \n" << v;
		DFS_recursive(G, v, marked, edgeTo);
		for (int i = 0; i < G.getV(); i++) {
			if (!marked[i]) {
				return false;
			}
		}
		return true;
	}

	/**
		* Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
		* Alle besuchten Knoten werden ausgegeben.
		*
		* \param[in]  G			Graph
		* \param[in]  v			Startknoten
		* \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
		* \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
		* \return	  true		Graph ist zusammenhaengend
		*			  false		Graph ist nicht zusammenhaengend
		*/
	bool BFS(const EdgeWeightedGraph& G, int v, std::vector<bool>& marked, std::vector<int>& edgeTo) {
		marked.clear(); edgeTo.clear();
		marked.assign(G.getV(), false); edgeTo.assign(G.getV(), -1);
		std::cout << "\nBreitensuche (Breadth-First-Search (BFS)) - Startknoten: " << v << std::endl
			<< "Besuchsreihenfolge: \n" << v;
		std::queue<int> q;
		q.push(v);
		while (!q.empty()) {
			v = q.front();
			q.pop();
			marked[v] = true;
			for (auto w : G.getAdj(v)) {
				int adj_node = w.other(v);
				if (!marked[adj_node]) {
					if (edgeTo[adj_node] == -1) {
						std::cout << " -> " << adj_node;
						edgeTo[adj_node] = v;
						q.push(adj_node);
					}
				}
			}
		}
		for (int i = 0; i < G.getV(); i++) {
			if (!marked[i]) {
				return false;
			}
		}
		return true;
	}
}
