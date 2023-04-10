#ifndef BIB_H
#define BIB_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>

#include "wordkey.h"

using namespace std; 

const int t = 6; 

//structs 

struct Word {
    int ID; 
    string palavra; 
    string classe;
    string genero;
    string numero;  
    string significado; 
    bool deleted; 
}; 


struct Key {
    int ID; 
    WordKey word;
    streampos address;       //endereço de uma struct dentro do arquivo //
};

//node declaration
struct Node {    
    Key keys[t];              
    streampos children[t+1];  
    bool isLeaf; 
    int numChildren; 
}; 

struct Entry {
    WordKey entryWord;
    streampos pos; 
    int ID; 
};



//functions
int fillFile(string arq_data_is, string arq_binary_is);
int readFile(string arq_binary_is);
Word construct(string line, int ID); 

Word searchWordID(int id); 
Word searchWordAdress(streampos pos); 
Word searchWord(string word); 
streampos insertWordFinal(Word word); 
void deleteWord (string classe, int id); 
int updateNumEntrys(int actualID); 
int updateWord (streampos pos, Word updated); 
Word doUserWord(); 
Word searchWordID(int id); 
Word searchWordAdress(streampos pos); 
Word searchWord(string word);

void saveInt(int a, int b, int c, int d); 
void lerInteiros(int& a, int& b, int& c, int& d);

//functions Btree
Node init(); 
streampos putInArq(Node node); 
Node readInArq (streampos pos);
int swapStruct(streampos pos, Node node);  
void traverse(streampos p); 
void sort(Key *keys, int numKeys); 
Key split_child(streampos x, int i); 
void insert(Key key);

//emotional breakdown
int generateInverted(string classe, string nomeArq);
int readInverted(string arq); 
int generateInvertedVerb(string nomeArq);
int insertInverted(Entry entryToInsert , string nomeArq);
Entry findInverted(streampos pos, string nomeArq); 
tuple<streampos, streampos, streampos, streampos, string> generateFrase (int fator, int op);

//functions index
int invertido();    
int classeInt(string auxclasse);
int lerIndex(string classe, int id);

//functions horoscopo
int horoscopo();
int generateRandom(int fator, int tam); 


//functions adm
int adm();
int includeWord();
int excludeWord();
int listWords();


#endif // BIB_H