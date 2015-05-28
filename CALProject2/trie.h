/*
 * Trie.h
 */
#ifndef TRIE_H_
#define TRIE_H_

#include <map>

#include<iostream>
using namespace std;

class Node
{
public:
	wchar_t  letra;
	map<wchar_t, Node*> nodes;
	bool end = false;
	Node(){
	}

	~Node()
	{
		cout << "dest" << endl;
		map<wchar_t, Node*>::iterator it = nodes.begin();
		map<wchar_t, Node*>::iterator ite = nodes.end();

		if (it == ite)
			return;

		for (; it != ite; it++)
		{
			(it->second)->~Node();
		}
	}
	Node(wchar_t letra)
	{
		this->letra = letra;
	}
	Node(wchar_t  letra, map<wchar_t, Node*> nodes)
	{
		this->letra = letra;
		this->nodes = nodes;
	}
	Node* insertNode(wchar_t c)
	{
		Node* n = nodes[c];
		if (n == NULL) {
			n = new Node(c);
			nodes[n->letra] = n;
		}

		return n;
	}
	wchar_t getLetra()
	{
		return letra;
	}
	map<wchar_t, Node*> getNodes()
	{
		return nodes;
	}
	Node* getNode(Node*  find)
	{
		return nodes[find->letra];
	}
	friend class Trie;
	void print()
	{
		map<wchar_t, Node*>::iterator it = nodes.begin();
		map<wchar_t, Node*>::iterator ite = nodes.end();

		if (it == ite)
			return;

		for (; it != ite; it++)
		{
			cout << (char)letra;
			it->second->print();
		}

		cout << endl;

	}
};

class Trie
{
private:
	Node* root;
public:

	void print()
	{
		root->print();
	}
	Trie()
	{
		root = new Node();
	}
	Node* getRoot()
	{
		return root;
	}
	void addWord(System::String^ s)
	{
		addWord(s, root, 0);
		//	cout << endl;
	}
	void addWord(System::String^ s, Node *n, int i)
	{
		if (i > s->Length - 1)
		{
			n->end = true;
			return;
		}
		//	cout << "inserting: " << (char)s[i] << endl;
		Node * newNode = n->insertNode(s[i]);
		addWord(s, newNode, i + 1);
	}
	void setRoot(Node * newRoot)
	{
		root = newRoot;
	}
};
#endif /* Trie */
