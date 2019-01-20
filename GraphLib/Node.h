#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>


// forward-deklaration
class Edge;


class Node
{
public:


	Node();

	Node(std::string id) : m_id(id) { s_numInstances++; }
	
	virtual ~Node() { }
	
	std::string getID() const { return m_id; }

    std::list<Edge*>& getOutEdges() { return m_outgoingEdges; }
    std::list<Edge*>& getInEdges()  { return m_incomingEdges; }

	void addOutEdge(Edge* e) { m_outgoingEdges.push_back(e); }
	void addInEdge(Edge* e) { m_incomingEdges.push_back(e); }

	void delOutEdge(Edge* e) { m_outgoingEdges.remove(e); }
	void delInEdge(Edge* e) { m_incomingEdges.remove(e); }


private:

	std::string m_id;

    std::list<Edge*> m_outgoingEdges;
    std::list<Edge*> m_incomingEdges;

	static int s_numInstances;

};


#endif
