#include "trie.h"
#include <iostream>
using namespace std;

void Trie::resetIndegrees() {
	for (size_t i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->indegree = 0;

	}
	//como fazer recursivo
	for (size_t i = 0; i < vertexSet.size(); i++) {
		for (size_t j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
	//como fazer recursivo

}
vector<Vertex*> Trie::getSources() const {
	vector<Vertex *> resp;
	 vector<Vertex*>::const_iterator it = vertexSet.begin();
	 vector<Vertex*>::const_iterator ite = vertexSet.end();

	for (; it != ite; it++) {
		if ((*it)->indegree == 0) {
			resp.push_back(*it);
		}

	}

	return resp;
}
//não devia bastar fazer false a tudo e depois devia ver se algumas das
int Trie::getNumVertex() const {
	return vertexSet.size();
}
vector<Vertex *> Trie::getVertexSet() const {
	return vertexSet;
}

bool Trie::addVertex(const char &in) {
	 vector<Vertex*>::iterator it = vertexSet.begin();
	 vector<Vertex*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex *v1 = new Vertex(in);
	vertexSet.push_back(v1);
	return true;
}

bool Trie::removeVertex(const char &in) {
	 vector<Vertex*>::iterator it = vertexSet.begin();
	 vector<Vertex*>::iterator ite = vertexSet.end();

	for (; it != ite; it++) {
		if ((*it)->info == in) {
			Vertex * v = *it;
			vertexSet.erase(it);
			 vector<Vertex*>::iterator it1 = vertexSet.begin();
			 vector<Vertex*>::iterator it1e = vertexSet.end();
			//check this part
			for (size_t i = 0; i < v->adj.size(); i++) {
				v->adj[i].dest->indegree--;
			}

			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}
			delete v;
			return true;
		}
	}
	return false;
}

bool Trie::addEdge(const char &sourc, const char &dest, double w) {
	 vector<Vertex*>::iterator it = vertexSet.begin();
	 vector<Vertex*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vS->addEdge(vD, w);
	return true;
}

bool Trie::removeEdge(const char &sourc, const char &dest) {
	 vector<Vertex*>::iterator it = vertexSet.begin();
	 vector<Vertex*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	return vS->removeEdgeTo(vD);
}

vector<char> Trie::dfs() const {
	 vector<Vertex*>::const_iterator it = vertexSet.begin();
	 vector<Vertex*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	vector<char> res;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfs(*it, res);
	return res;
}

void Trie::dfs(Vertex *v, vector<char> &res) const {
	v->visited = true;
	res.push_back(v->info);
	 vector<Edge >::iterator it = (v->adj).begin();
	 vector<Edge >::iterator ite = (v->adj).end();
	for (; it != ite; it++)
		if (it->dest->visited == false)
			dfs(it->dest, res);
}

vector<char> Trie::bfs(Vertex *v) const {
	vector<char> res;
	queue<Vertex *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		 vector<Edge >::iterator it = v1->adj.begin();
		 vector<Edge >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}

