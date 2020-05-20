#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
};

class SuffixTrie{
public:
    TrieNode* root;
    char endSymbol;

    SuffixTrie(string str){
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }
    // O(n^2) time | O(n^2) space where n is length of string str
    void populateSuffixTrieFrom(string str){
        for(int i = 0; i < str.length(); i++){
            this->insertSubstringStartingAt(i,str);
        }
    }

    void insertSubstringStartingAt(int i, string str){
        TrieNode *currentNode = this->root;
            for(int j = i; j < str.length(); j++){
                char letter = str[j];
                if(currentNode->children.find(letter) == currentNode->children.end()){
                    TrieNode* newNode = new TrieNode();
                    currentNode->children.insert({letter,newNode});
                }
                currentNode = currentNode->children[letter];
            }
        currentNode->children.insert({this->endSymbol,NULL});
    }
    // O(m) time | O(1) space where m is the length of suffix searched.
    bool contains(string str){
        TrieNode* currentNode = this->root;
        for(char c : str){
            if(currentNode->children.find(c) == currentNode->children.end()){
                return false;
            }
            currentNode = currentNode->children[c];
        }
        return currentNode->children.find(this->endSymbol) != currentNode->children.end();
    }
};

int main(){
    string str;
    cin>> str;
    SuffixTrie* strie = new SuffixTrie(str);
    cout << strie->contains("abc");
    return 0;
}
