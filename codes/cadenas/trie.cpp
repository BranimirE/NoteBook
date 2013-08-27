#include <iostream>
#include <vector>
using namespace std;
struct Node{
	char content;
	bool wordMarker;
	vector<Node*> children;
	Node() { content = ' '; wordMarker = false; }
	void setContent(char c) { content = c; }
	void setWordMarker() { wordMarker = true; }
	Node* findChild(char c);
	void appendChild(Node* child) { children.push_back(child); }
};


struct Trie {
	Node* root;
	Trie(){root=new Node();}
	void addWord(string s);
	bool searchWord(string s);
	void deleteWord(string s);   
};

Node* Node::findChild(char c){
	for ( int i = 0; i < children.size(); i++ ){
		Node* tmp = children.at(i);
		if ( tmp->content == c )
		{
			return tmp;
		}
	}

	return NULL;
}


void Trie::addWord(string s){
	Node* current = root;

	if ( s.length() == 0 ){
		current->setWordMarker(); 
		return;
	}

	for ( int i = 0; i < s.length(); i++ ){        
		Node* child = current->findChild(s[i]);
		if ( child != NULL ){
			current = child;
		}else{
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}
		if ( i == s.length() - 1 )
			current->setWordMarker();
	}
}


bool Trie::searchWord(string s)
{
	Node* current = root;

	while ( current != NULL )
	{
		for ( int i = 0; i < s.length(); i++ )
		{
			Node* tmp = current->findChild(s[i]);
			if ( tmp == NULL )
				return false;
			current = tmp;
		}

		if ( current->wordMarker )
			return true;
		else
			return false;
	}

	return false;
}


int main(){
	Trie* trie = new Trie();
	trie->addWord("algo");
	trie->addWord("ala");
	trie->addWord("abeja");
	trie->addWord("abel");
	trie->addWord("trie");

	if ( trie->searchWord("abel") )
		cout << "Encontrado" << endl;
	else cout << "No encontrado" << endl;


	delete trie;
}
