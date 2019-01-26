/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#include "Edge.h"


//---------------------------------------------------------------------------------------------------------------------

Edge::Edge(Node& rSrc, Node& rDst) : m_rSrc(rSrc), m_rDst(rDst)
{
	// fügt die Edge (this) in m_outgoingEdges des Source-Node ein.
	// fügt die Edge (this) in m_incomingEdges des Destination-Node ein.

	// Hinweis: die Funktionen Node::getOutEdges() und Node::getInEdges() verwenden!
	rSrc.addOutEdge(this);

	rDst.addInEdge(this);
}


//---------------------------------------------------------------------------------------------------------------------

Edge::Edge(const Edge& rOther) : m_rSrc(rOther.m_rSrc), m_rDst(rOther.m_rDst)
{
	// macht das Selbe wie 'Edge(Node& rSrc, Node& rDst)'

	rOther.m_rSrc.addOutEdge(this);

	rOther.m_rDst.addInEdge(this);
}


//---------------------------------------------------------------------------------------------------------------------

Edge::~Edge()
{
	// - entfernt die Edge (this) aus m_outgoingEdges im Source-Node
	// - entfernt die Edge (this) aus m_incomingEdges im Destination-Node

	m_rSrc.delOutEdge(this);

	m_rDst.delInEdge(this);

	// Hinweis: arbeiten Sie mit 'new' und 'delete'!
}


//---------------------------------------------------------------------------------------------------------------------

bool Edge::isConnectedTo(const Node& rNode) const
{
	// - gibt true zurück, wenn rNode entweder m_rSrc und m_rDst ist.
	// Hinweis: Adressen vergleichen, um zu gucken, ob es wirklich das selbe Objekt ist!
	if (&rNode == &m_rSrc || &rNode == &m_rDst)
		return true;
	return false;
}


//---------------------------------------------------------------------------------------------------------------------

std::string Edge::toString() const
{
	std::string result;
	result = m_rSrc.getID() + " -> " + m_rDst.getID();
	return result;
}


//---------------------------------------------------------------------------------------------------------------------
