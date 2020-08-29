#include "HuffmanTree.h"

void HuffmanTree::copy(const Node * root, Node * otherRoot)
{
	if (!root) {
		return;
	}

	otherRoot = new Node(root->data, root->leftNode, root->rightNode);

	this->copy(root->leftNode, otherRoot->leftNode);
	this->copy(root->rightNode, otherRoot->rightNode);

}

void HuffmanTree::destroy(Node *& root)
{
	if (!root) {
		return;
	}

	this->destroy(root->leftNode);
	this->destroy(root->rightNode);
	delete root;

	root = nullptr;
}

bool HuffmanTree::getElement(std::ifstream &file, Pair<char, std::size_t>& pair, bool & isPair)
{
	bool isNode = false;
	char symbol = file.peek();

	//end of file
	if (file.eof()) {
		return isNode;
	}

	//skip spaces char(247)?
	while ((symbol = file.get()) == ' ') {
		if (file.eof()) {
			return isNode;
		}
	}

	std::size_t number = 0;

	if (symbol != ' ') {
		pair.firstArgument = symbol;

		std::string str = "";
		//while ((str=file.get())==std::to_string(char(247))){}
		while ((symbol = file.get()) != char(247)) {
			str += symbol;
		}

		//Parses str interpreting its content as an integral number of the specified base,
		//which is returned as an int value.
		//If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.

		pair.secondArgument = std::stoi(str);

		isPair = true;
		isNode = true;
	}
	else {
		file.ignore();
	}
	return isNode;

}

void HuffmanTree::loadTreeFromFile(Node *& root, std::ifstream &file)
{
	Pair<char, std::size_t> pair;
	bool isPair = false;

	if (this->getElement(file, pair, isPair)) {
		root = new Node(pair, nullptr, nullptr);

		this->loadTreeFromFile(root->leftNode, file);
		this->loadTreeFromFile(root->rightNode, file);
	}
	else {
		return;
	}
}

HuffmanTree::HuffmanTree()
{
	this->root = nullptr;
}

HuffmanTree::HuffmanTree(Node *& src)
{
	this->copy(src, this->root);
}

HuffmanTree::HuffmanTree(const HuffmanTree & src)
{
	this->copy(src.root, this->root);
}

HuffmanTree::~HuffmanTree()
{
	this->destroy(this->root);
}

HuffmanTree & HuffmanTree::operator=(const HuffmanTree & src)
{
	// TODO: operator =

	if (this != &src) {
		this->destroy(this->root);

		this->copy(src.root, this->root);
	}
	return *this;
}

bool HuffmanTree::isLeaf(const Node * node) const
{
	if (node->leftNode == nullptr && node->rightNode == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

Node * HuffmanTree::getRoot() const
{
	return this->root;
}

bool HuffmanTree::containSymbol(const Node * root, const char & symbol) const
{
	if (!root) {
		return false;
	}
	if (isLeaf(root) && (root->data.firstArgument == symbol)) {
		return true;
	}
	else {
		if (this->containSymbol(root->leftNode, symbol)) {
			return true;
		}
		else {
			return this->containSymbol(root->rightNode, symbol);
		}
	}
}

void HuffmanTree::print(const Node * node, const std::size_t & layer)
{
	if (node) {
		if (node->rightNode) {
			print(node->rightNode, layer + 4);
		}
		if (layer) {
			std::cout << std::setw(layer) << ' ';
			//Sets the field width to be used on output operations.
			//Behaves as if member width were called with n as argument on the stream on which it is inserted / extracted as a manipulator
			//(it can be inserted / extracted on input streams or output streams).
			//This manipulator is declared in header <iomanip>.

		}

		if (node->rightNode) {
			std::cout << "/\n" << std::setw(layer) << ' ';
		}
		std::cout << node->data << std::endl;

		if (node->leftNode) {
			std::cout << std::setw(layer) << ' ' << "\\\n";
			print(node->leftNode, layer + 4);
		}
	}
}

void HuffmanTree::seveInFile(Node * root, std::ostream & outputFile)
{
	if (!root) {
		outputFile << char(248) << char(247);
	}
	else {
		outputFile << root->data << char(247);

		this->seveInFile(root->leftNode, outputFile);
		this->seveInFile(root->rightNode, outputFile);
	}
}

void HuffmanTree::loadFromFile(std::ifstream & inputFile)
{
	this->loadTreeFromFile(this->root, inputFile);
}

std::ostream & operator<<(std::ostream & out, const HuffmanTree & src)
{
	// TODO: operator << for HuffmanTree

	out << *(src.root);
	return out;
}
