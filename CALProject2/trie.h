/*
 * Trie.h
 */
#ifndef TRIE_H_
#define TRIE_H_

#include <vector>
#include <queue>

using namespace std;
class Trie;
class Vertex;

class Edge {
	Vertex  * dest;
	double weight;
public:
	Edge(Vertex  *d, double w);
	friend class Trie;
	friend class Vertex;

	Vertex * getDest()
	{
		return dest;
	}
	double getWeight()
	{
		return weight;
	}
};

Edge::Edge(Vertex  *d, double w) :
dest(d), weight(w) {
}


class Vertex {
	char info;
	vector<Edge  > adj;
	bool visited;
	int indegree;
	
public:
	Vertex()
	{
		visited = false;
		info = ' ';


	}
	Vertex(char in);
	friend class Trie  ;
	int getIndegree();
	void addEdge(Vertex  *dest, double w);
	bool removeEdgeTo(Vertex  *d);
	char getInfo() const;
};

int Vertex ::getIndegree() {
	return indegree;
}
bool Vertex ::removeEdgeTo(Vertex  *d) {

	  vector<Edge>::iterator it = adj.begin();
	  vector<Edge>::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {

			it->dest->indegree--;
			adj.erase(it);
			return true;
		}
		else
			it++;
	}
	return false;
}

Vertex ::Vertex(char in) :
info(in), visited(false), indegree(0) {
}

char Vertex ::getInfo() const {
	return info;
}

void Vertex ::addEdge(Vertex *dest, double w) {
	Edge  edgeD(dest, w);
	adj.push_back(edgeD);
	dest->indegree++;

}


class Trie {
private:
	Vertex* root;
	vector<Vertex  *> vertexSet;

public:
 
	Trie(Vertex* v)
	{
		root = v;
	}
	Trie()
	{
		root = new Vertex();
	}
	bool addVertex(const char &in);
	bool addEdge(const char &sourc, const char &dest, double w);
	bool removeVertex(const char &in);
	bool removeEdge(const char &sourc, const char &dest);
	vector<char> dfs() const;
	vector<char> bfs(Vertex  *v) const;//em principio é o que queremoss
	void dfs(Vertex  *v, vector<char> &res) const;
	vector<Vertex  *> getVertexSet() const;
	int getNumVertex() const;
	vector<Vertex *> getSources() const;
	void resetIndegrees();

};



#endif /* GRAPH_H_ */
