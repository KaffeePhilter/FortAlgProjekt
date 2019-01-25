#include "Graph.h"
#include <list>
#include <fstream>
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <iostream>


typedef std::list<Node*>::iterator nIt;
typedef std::list<Edge*>::iterator eIt;
//---------------------------------------------------------------------------------------------------------------------

Node* Graph::findNode(const std::string& id)
{
	// - soll einen Node mit der gegebenen id in m_nodes suchen
	// - gibt den Pointer auf den Node zurück, wenn er gefunden wurde.
	// - gibt NULL zurück, falls kein Node mit der id gefunden wurde.

	for (Node* n : m_nodes)
	{
		if (n->getID().compare(id) == 0)
		{
			return n;
		}
	}
	return NULL;
}


//---------------------------------------------------------------------------------------------------------------------

Node& Graph::addNode(Node* pNewNode)
{
	// Überprüfen Sie, ob schon ein Node mit der gegeben id im Graph vorhanden ist!
	// Falls ja:
	//  - Exception werfen
	// Falls nein:
	//  - den neuen Node 'pNewNode' in m_nodes einfügen
	//  - Referenz auf den neuen Node zurück geben

	nIt it = std::find(m_nodes.begin(), m_nodes.end(), pNewNode);

	if (it != m_nodes.end())
		throw "node already in the graph";
	else
	{
		m_nodes.push_back(pNewNode);
		return *pNewNode;
	}
}


//---------------------------------------------------------------------------------------------------------------------

Edge& Graph::addEdge(Edge* pNewEdge)
{
	// - die neue Edge 'pNewEdge' in m_edges einfügen
	// - Referenz auf die neue Edge zurück geben

	// - Testen Sie ob der Source- und Destination-Node von 'pNewEdge' schon im Graph vorhanden ist.
	// -> fügen Sie diese Nodes hinzu, falls nicht (nutzen Sie dafür Graph::addNode)

	nIt nit1 = std::find(m_nodes.begin(), m_nodes.end(), &pNewEdge->getSrcNode());
	nIt nit2 = std::find(m_nodes.begin(), m_nodes.end(), &pNewEdge->getDstNode());

	if (nit1 == m_nodes.end())
	{
		addNode(&pNewEdge->getSrcNode());
	}
	if (nit2 == m_nodes.end())
	{
		addNode(&pNewEdge->getDstNode());
	}
	m_edges.push_back(pNewEdge);
	return *pNewEdge;
}


//---------------------------------------------------------------------------------------------------------------------

Graph::~Graph()
{
	// - soll alle Edges im Graph löschen (delete)
	// - soll alle Nodes im Graph löschen (delete)

	for (Edge* e : m_edges)
		delete e;

	for (Node* n : m_nodes)
		delete n;
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Node& rNode)
{
	// - alle Edges, die mit rNode verbunden sind, müssen entfernt werden!
	// - finden sie den Pointer mit der Adresse von 'rNode' in m_nodes.
	// 		- der Pointer auf rNode soll aus m_nodes entfernt werden!
	// 		- der Pointer auf rNode muss mit 'delete' freigegeben werden!

	for (Edge* e : m_edges)
	{
		if (e->isConnectedTo(rNode))
		{
			m_edges.remove(e);
			delete e;
			break;
		}
	}

	for (Node* n : m_nodes)
	{
		if (n == &rNode)
		{
			m_nodes.remove(&rNode);
			delete n;
			break;
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------

void Graph::remove(Edge& rEdge)
{
	// - der Pointer auf rEdge muss aus m_edges entfernt werden!
	// - der Pointer auf rEdge muss mit 'delete' freigegeben werden!

	for (Edge* e : m_edges)
	{
		if (e == &rEdge)
		{
			m_edges.remove(e);
			delete e;
			break;
		}
	}
}


//---------------------------------------------------------------------------------------------------------------------

std::vector<Edge*> Graph::findEdges(const Node& rSrc, const Node& rDst)
{
	std::vector<Edge*> ret;

	// - findet alle edges, mit rSrc als Source-Node und rDst als Destination-Node.
	// - füge die Zeiger der Edges in den vector 'ret' ein.

	for (Edge* e : m_edges)
	{
		if (e->isConnectedTo(rSrc) && e->isConnectedTo(rDst))
		{
			ret.push_back(e);
		}
	}

	return ret;

	// FUNCTIONAL
}

//---------------------------------------------------------------------------------------------------------------------

void Graph::findShortestPathDijkstra(std::deque<Edge*>& rPath, const Node& rSrcNode, const Node& rDstNode)
{
	using namespace std;


	/*
	Ein häufiges Anwendungsproblem für Graphen-Anwendungen besteht darin,
	den Pfad zwischen verschiedenen Nodes zu finden, die direkt oder indirekt über Edges miteinander verbunden sind.
	Um den optimalsten Pfad(den mit den geringsten Kantengewichten) zu finden, gibt es den Dijkstra-Algorithmus!
	Pseudocode (Quelle: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
	>>>
	function Dijkstra(Graph, source):

		  create vertex set Q

		  for each vertex v in Graph:             // Initialization
			  dist[v] ← INFINITY                  // Unknown distance from source to element in m_nodes
			  prev[v] ← UNDEFINED                 // Previous node in optimal path from source
			  add v to Q                          // All nodes initially in Q (unvisited nodes)

		  dist[source] ← 0                        // Distance from source to source

		  while Q is not empty:
			  u ← vertex in Q with min dist[u]    // Source node will be selected first
			  remove u from Q

			  for each neighbor v of u:           // where v is still in Q.
				  alt ← dist[u] + length(u, v)
				  if alt < dist[v]:               // A shorter path to v has been found
					  dist[v] ← alt
					  prev[v] ← u

		  return dist[], prev[]
	<<<

	Betrachten Sie den Pseudocode und setzen Sie ihn in C++ um.
	Sortieren Sie am Ende das Ergebnis in die richtige Reihenfolge um
	und geben sie die kürzeste Route zwischen rSrcNode und rDstNode als Liste von Edges zurück.

	TEST:
	Testen Sie diese Funktion, indem Sie einen Graph in main.cpp erstellen
	und sich die kürzesteste Route zwischen 2 Nodes zurückgeben lassen.
	*/

	//-----------------------------
	/*
	Notation:
	v == proofNode
	u == examineNode
	q == queque
	*/
	//-----------------------------
	map<Node*, double> distance;
	map<const Node*, Node*> previous;
	vector<Edge*> route;
	set<Node*> queque;

	double newDistance;


	//iteriert durch liste m_nodes und fügt Nodes hinzu
	for (Node* proofNode : m_nodes)
	{
		previous[proofNode] = NULL;
		queque.insert(proofNode);

		if (proofNode == &rSrcNode)
		{
			distance[proofNode] = 0;
		}
		else
		{
			distance[proofNode] = numeric_limits<double>::max();
		}
	}

	while (!queque.empty())
	{

		//vergleicht Distanzen
		Node* examineNode = *queque.begin();
		for (Node* proofNode : queque)
		{
			if (distance.find(proofNode)->second < distance.find(examineNode)->second) // distance[proofNode]
			{
				examineNode = proofNode;
			}
		}

		//entfernt examninNode aus queque und als erforscht
		queque.erase(examineNode);

		// für jede Nachbar Node von examineNode zu proofNode
		for (Edge* nieghbour : m_edges)
		{

			Node* proofNode = &nieghbour->getDstNode();
			if (&nieghbour->getSrcNode() == examineNode)
			{
				newDistance = distance.find(examineNode)->second + nieghbour->getWeight();

				if (newDistance < distance.find(proofNode)->second)
				{
					distance.find(proofNode)->second = newDistance;
					previous.find(proofNode)->second = examineNode;
				}
			}
		}
	}

	//Sortierung des Pfades
	//sucht nach Zielnode

	const Node* way = &rDstNode;

	while (way != &rSrcNode)
	{
		list<Edge*> inEdges = previous.find(way)->second->getOutEdges();

		for (Edge* sortIn : inEdges)
		{

			if (&sortIn->getDstNode() == way)
			{
				rPath.push_front(sortIn);
				break;
			}
		}
		way = previous.find(way)->second;
	}
}
//---------------------------------------------------------------------------------------------------------------------