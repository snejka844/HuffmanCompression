/*#pragma once
#include "HuffmanTree.h"
#include "MinHeap.hpp"


void mainProgram();
void startArchive(const std::string &src); //archive file

//Create
void makeTable(std::string src, DynamicTable<char, std::size_t> &table); //create frequancy table;
void makeMinHeap(MinHeap<Node *> &heap, DynamicTable<char, std::size_t> table); //create minimum heap
void makeHuffmanTree(MinHeap<Node *> heap, HuffmanTree &tree); //create huffman tree
/*do I need & for heap???*/

#pragma once
#include "HuffmanTree.h"
#include "MinHeap.hpp"

void mainCases();
void mainProgram();
void startArchive(const std::string &src); // archive file

void makeTable(std::string src, DynamicTable<char, std::size_t> &table); // create frequancy table
void makeMinimumHeap(MinHeap<Node *> &heap, DynamicTable<char, std::size_t> table); // create minimum heap
void makeHuffmanTree(MinHeap<Node *> heap, HuffmanTree &tree); // create huffman tree

// ENCODING FUNCTION
void encodeSymbols(Node *node, DynamicTable<char, std::string> &table, std::string code); // encode symbols
int binToDec(std::string str);
void readFileInputData( std::string fileName, std::string &str); // read data (text) from file

// WRITE ENCODED DATA TO FILE
void archive(const std::size_t &lastNumberSize, std::string decStr, std::string &fileName);

// DECODING FUNCTIONS
std::string decToBin(int number);
void transferBitsToDec(std::string code, std::string &res, std::size_t &lastSizeNumber);
void decodeSymbols(std::string code, const Node *node, std::string &res, const Node *startNode);
void decodeSymbolsFromFile(const std::string &fileName, std::string &res); // from file with dec code convert to bin code


