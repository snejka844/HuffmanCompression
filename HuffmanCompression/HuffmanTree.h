#pragma once
#include <iomanip>
#include <fstream>
#include<string>
#include"Node.h"
#include "DynamicTable.hpp"

class HuffmanTree {
private:

	Node *root;

	void copy(const Node *root, Node *otherRoot);
	void destroy(Node *&root);

	bool getElement(std::ifstream &file, Pair<char, std::size_t> &pair, bool &isPair);
	void loadTreeFromFile(Node *&root, std::ifstream &file);
	

public:

	HuffmanTree();
	HuffmanTree(Node *&src);
	HuffmanTree(const HuffmanTree &src);
	~HuffmanTree();

	HuffmanTree &operator=(const HuffmanTree &src);

	bool isLeaf(const Node *node)const;
	Node *getRoot() const;

	bool containSymbol(const Node *root, const char &symbol)const;

	friend std::ostream &operator<<(std::ostream &out, const HuffmanTree &src);

	void print(const Node *node, const std::size_t &layer);

	void seveInFile(Node *root, std::ostream &outputFile);
	void loadFromFile(std::ifstream &inputFile);

};