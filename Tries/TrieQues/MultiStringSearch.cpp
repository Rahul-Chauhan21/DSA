//Multi String Search
/*
Write a function that takes in a big string and an array of small strings, all of which are
smaller in length than the big string. The function should return an Array of booleans, where
each boolean represents whether the small string at that index in the array of small strings
is contained in the big string.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//test case
// this is a big string
// ["this", "his", "yo", "is", "a", "bigger", "string", "kappa"]
// [true, true, false, true, true, false, false]


class TrieNode{
public:
    unordered_map<char,TrieNode*> children;
    string word;
};

class Trie{
public:
    TrieNode* root;
    char endSymbol;
    Trie(){
        this->root = new TrieNode();
        this->endSymbol = '*';
    }

    void insert(string str){
        TrieNode* currentNode = this->root;
        for(int i = 0; i < str.length(); i++){
            char letter = str[i];
            if(currentNode->children.find(letter) == currentNode->children.end()){
                TrieNode* newNode = new TrieNode();
                currentNode->children.insert({letter,newNode});
            }
            currentNode = currentNode->children[letter];
        }
        currentNode->children.insert({this->endSymbol,NULL});
        currentNode->word = str;
    }
};
void findPrefixBigStringStartingAtInTrie(string,int,Trie*,unordered_map<string,bool>*);
// O(nS+ bS) time | O(nS) space

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings){
    Trie* trie = new Trie();
    //O(nS) time and space construct Trie tree where S is the length of largest string in small String Array
    for(string smallString : smallStrings){
        trie->insert(smallString);
    }
    unordered_map<string,bool> containedStrings;// O(1) lookup smallString and placing boolean at correct index.
    /*
    Iterating through all the b characters of the big string we check atmost s characters
    in the trie tree of n strings.
    */
    //O(bS) time
    for(int i = 0; i < bigString.length(); i++){
    findPrefixBigStringStartingAtInTrie(bigString,i,trie,&containedStrings);
    }

    vector<bool> result;
    for(string smallString : smallStrings){
        result.push_back(containedStrings.find(smallString) != containedStrings.end());
    }
    return result;
}

void findPrefixBigStringStartingAtInTrie(string str,int startIdx, Trie* trie, unordered_map<string,bool>* containedStrings){
    TrieNode* currentNode = trie->root;
    for(int i = startIdx; i < str.length(); i++){
        char letter = str[i];
            if(currentNode->children.find(letter) == currentNode->children.end()){
                break; // Either S characters in the Trie traversed or Prefix of big String is of maximum length
            }
        currentNode = currentNode->children[letter];
        if(currentNode->children.find(trie->endSymbol) != currentNode->children.end()){
            containedStrings->insert({currentNode->word,true});
        }
    }
}

int main(){
    string bigString;
    vector<string> smallStrings;
    getline(cin,bigString);
    int n;
    cin >> n;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            smallStrings.push_back(str);
        }
    vector<bool> result;
    result = multiStringSearch(bigString,smallStrings);

    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
}
