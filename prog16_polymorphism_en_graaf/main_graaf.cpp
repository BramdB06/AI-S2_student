//
// Created by disaa on 12/05/2025.
//

#include <iostream>
#include <string>
#include <vector>
struct Node;

struct Edge {
    float cost;
    Node* destination;
    Node* origin;
};

struct Node {
    std::string name;
    std::vector<Edge*> edges;
    void printNeighbours() {
        std::cout << "Neighbours of " << name << " are: " << std::endl;
        for (auto e : edges) {
            std::cout << e->destination->name << std::endl;
        }
    }
};


int main() {
    Node* A = new Node{"A"};
    Node* B = new Node{"B"};
    Node* C = new Node{"C"};

    Edge* edgeAB = new Edge{1.5f, B, A};
    Edge* edgeAC = new Edge{2.0f, C, A};
    Edge* edgeBC = new Edge{2.5f, C, B};

    A->edges.push_back(edgeAB);
    A->edges.push_back(edgeAC);
    B->edges.push_back(edgeBC);

    A->printNeighbours();
    B->printNeighbours();
    C->printNeighbours();
    return 0;
}