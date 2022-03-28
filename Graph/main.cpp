#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> gewichtetListeToMatrix(map<int, vector<pair<int, int>>> adjazenzListe) {//gewichtet
    /*vector<vector<int>> AdjazenzMatrix;
    AdjazenzMatrix.resize(adjazenzListe.size());

    for (int i = 0; i < adjazenzListe.size(); i++) {
        AdjazenzMatrix[i] = vector<int>(adjazenzListe.size(), -1);
        vector<pair<int, int>> knotenListe = adjazenzListe[i];
        for (int j = 0; j < knotenListe.size(); j++) {
            AdjazenzMatrix[i][knotenListe[j].first] = knotenListe[j].second;
        }
    }
    return AdjazenzMatrix;*/
    vector<vector<int>> adjmat;
    adjmat.resize(adjazenzListe.size());
    for (int i = 0; i < adjazenzListe.size(); i++) {
        adjmat[i] = vector<int>(adjazenzListe.size(), 0);
        vector<pair<int, int>> knotenliste = adjazenzListe[i];
        for (int j = 0; j < adjazenzListe.size(); j++) {
            adjmat[i][knotenliste[j].first] = knotenliste[j].second;
        }
    }
    return adjmat;
}

vector<vector<int>> ungewichtetListeToMatrix(map<int, vector<int>> adjazenzListe) {//gewichtet
    /*vector<vector<int>> AdjazenzMatrix;
    AdjazenzMatrix.resize(adjazenzListe.size());

    for (int i = 0; i < adjazenzListe.size(); i++) {
        AdjazenzMatrix[i] = vector<int>(adjazenzListe.size(), -1);
        vector<int> knotenListe = adjazenzListe[i];
        for (int j = 0; j < knotenListe.size(); j++) {
            AdjazenzMatrix[i][knotenListe[j]] = 1;
        }
    }
    return AdjazenzMatrix;*/
    vector<vector<int>> adjmat;
    adjmat.resize(adjazenzListe.size());
    for (int i = 0; i < adjazenzListe.size(); i++) {
        adjmat[i] = vector<int>(adjazenzListe.size(), 0);
        vector<int> knotenliste = adjazenzListe[i];
        for (int j = 0; j < adjazenzListe.size(); j++) {
            adjmat[i][knotenliste[j]] = 1;
        }
    }
    return adjmat;
}


map<int, vector<pair<int, int>>> gewichtetMatrixToListe(vector<vector<int>> adjazenzMatrix) {
    /*map<int, vector<pair<int, int>>> adjlist;
    for (int i = 0; i < adjazenzMatrix.size(); i++) {
        vector<pair<int, int>>vector;
        for (int j = 0; j < adjazenzMatrix.size(); j++) {
            if (adjazenzMatrix[i][j] != 0) {
                pair<int, int> vec = { j,adjazenzMatrix[i][j] };
                vector.emplace_back(vec);
            }
        }
        adjlist.insert({ i,vector });
    }
    return adjlist;*/
    map<int, vector<pair<int, int>>> adjlist;
    for (int i = 0; i < adjazenzMatrix.size(); i++) {
        vector<pair<int, int>> vec;
        for (int j = 0; j < adjazenzMatrix.size(); j++) {
            if (adjazenzMatrix[i][j] != 0) {
                pair<int, int> pair = { j,adjazenzMatrix[i][j] };
                vec.emplace_back(pair);
            }
        }
        adjlist.insert({ i,vec });
    }
}

map<int, vector<int>> ungewichtetMatrixToListe(vector<vector<int>> adjazenzMatrix) {
    /*map<int, vector<int>> adjazenzListe;

    for (int i = 0; i < adjazenzMatrix.size(); i++) {
        vector<int> vektor;
        for (int j = 0; j < adjazenzMatrix.size(); j++) {
            if (adjazenzMatrix[i][j] != -1) {
                vektor.emplace_back(j);
            }
        }
        adjazenzListe.insert({ i,vektor });
    }
    return adjazenzListe;*/
    map<int, vector<int>> adjlist;
    for (int i = 0; i < adjazenzMatrix.size(); i++) {
        vector<int> vektor;
        for (int j = 0; j < adjazenzMatrix.size(); j++) {
            if (adjazenzMatrix[i][j] != 0) {
                vektor.emplace_back(j);
            }
        }
        adjlist.insert({ i,vektor });
    }
    return adjlist;
}

/*
* Loeschen einer Kante aus einer Adjazenzliste
*/
void delete_Adjazenzliste(map<int, vector<int>>& list, int x, int y) {
    //Loeschen der Kanten von x nach y und
    //Loeschen der Kanten von y nach x
    for (auto iterator = list.begin(); iterator != list.end(); iterator++) {
        //Traveriserung durch die Map
        for (auto it = (*iterator).second.begin(); it != (*iterator).second.end(); it++) {
            if ((*iterator).first == x)
                if ((*it) == y) {
                    (*iterator).second.erase(it);
                    break;
                }
        }
        for (auto it = (*iterator).second.begin(); it != (*iterator).second.end(); it++) {
            if ((*iterator).first == y)
                if ((*it) == x) {
                    (*iterator).second.erase(it);
                    break;
                }
        }
    }
}

//Loeschen von Kanten aus Kantenliste
void delete_Kantenliste(vector<int>& list, int x, int y) {

    for (int i = 2; i < list.size(); i++) {
        if (i % 2 == 0) {
            if (list[i] == x && list[i + 1] == y) {
                list.erase(list.begin() + i + 1);
                list.erase(list.begin() + i);
            }
            if (list[i] == y && list[i + 1] == x) {
                list.erase(list.begin() + i + 1);
                list.erase(list.begin() + i);
            }
        }
    }

}

void printkantenlist(vector<int> list) {
    cout << "{ ";
    for (auto it = list.begin(); it != list.end(); it++) {
        cout << *it;
        if (it != list.end() - 1) {
            cout << ", ";
        }
    }
    cout << " }" << endl << endl;
}

void insertNode(map<int, vector<int>>& adj, int key, vector<int> edges) {
    if (adj.find(key) == adj.end())
        adj[key];
    adj[key].insert(adj[key].end(), edges.begin(), edges.end());
    set<int> s(adj[key].begin(), adj[key].end());
    adj[key].assign(s.begin(), s.end());
}

bool del_vertex(map<int, vector<int>>& adj, int node) {
    if (adj.find(node) == adj.end())
        return false;
    adj.erase(node);
    for (auto it = adj.begin(); it != adj.end(); it++) {
        auto itr = remove(it->second.begin(), it->second.end(), node);
        if (itr != it->second.end())
            it->second.erase(itr);
    }
}

void print_map(map<int, vector<int>> m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << (*it).first << " -> { ";
        for (auto itr = it->second.begin(); itr != it->second.end(); itr++) {
            cout << *itr << " ";
        }
        cout << "}" << endl;

    }
}


int main() {
    //map<int, vector<pair<int, int>>> gewichtetAdjazenzListe = {//{from,{to,weight}}
    //                                                        {0,{{1,1}}},
    //                                                        {1,{{0,1},{2,1}}},
    //                                                        {2,{{1,1},{3,1}}},
    //                                                        {3,{{2,1},{4,1}}},
    //                                                        {4,{{3,1}}}
    //};
    //map<int, vector<int>> ungewichtetAdjazenzListe = {//{from,{to}}
    //                                                        {0,{1}},
    //                                                        {1,{0,2}},
    //                                                        {2,{1,3}},
    //                                                        {3,{2,4}},
    //                                                        {4,{3}}
    //};

    //vector<vector<int>> gewichtetAdjazenzMatrix = gewichtetListeToMatrix(gewichtetAdjazenzListe);
    //map<int, vector<pair<int, int>>> gewichtetzweiteListe = gewichtetMatrixToListe(gewichtetAdjazenzMatrix);

    //vector<vector<int>> ungewichtetAdjazenzMatrix = ungewichtetListeToMatrix(ungewichtetAdjazenzListe);
    //map<int, vector<int>> ungewichtetzweiteListe = ungewichtetMatrixToListe(ungewichtetAdjazenzMatrix);

    map<int, vector<int>>m;
    m.insert({ 0, {1,2} });
    m.insert({ 1, {0,2} });
    m.insert({ 2, {0,1,3,4} });
    m.insert({ 3, {2,1} });
    m.insert({ 4, {2} });
    m.insert({ 5, {6,7,8} });
    m.insert({ 6, {5,8} });
    m.insert({ 7, {5,8} });
    m.insert({ 8, {6,7,8} });
    m.insert({ 9, {10,11} });
    m.insert({ 10, {9,11} });
    m.insert({ 11, {9,10} });


    print_map(m);
    delete_Adjazenzliste(m, 2, 4);
    cout << endl;
    print_map(m);
    /*cout << "delete 8" << endl;
    del_vertex(m, 8);
    cout << endl;
    print_map(m);*/

    /*vector<int> list = { 6,11,1,2,1,3,3,1,4,1,3,4,3,6,5,3,5,5,6,5,6,2,6,4 };
    printkantenlist(list);
    delete_Kantenliste(list, 6, 4);
    printkantenlist(list);*/

    system("PAUSE");
    return 0;
}