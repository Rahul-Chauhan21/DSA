//Searching Valid Suffix in a trie data structure.
#include <iostream>
using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode* root;

    Trie(){
        this->root = new TrieNode();
    }

    void insertNodeSuffixTree(string str){ // O(S1 + S2 +...+SN) si is the length of each string
        TrieNode* node = this->root;
            for(int i = 0; i < str.length(); i++){
                char letter = str[i];
                if(node->children[letter-'a'] == NULL){
                    node->children[letter-'a'] = new TrieNode();
                }
                node = node->children[letter-'a'];
            }
        node->isEnd = true;
    }

    bool contains(string str){// O(R1 + R2 +...+ RM) ri is the searched string in the trie structure
        TrieNode* node = this->root;
            for(char c : str){
                if(node->children[c-'a'] == NULL){
                    return false;
                }
                node = node->children[c-'a'];
            }
        return node->isEnd;
    }
};

int main(){
    Trie* obj = new Trie();
    int t,n,q;
    cin>>t>>n>>q;
    while(t--){
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            obj->insertNodeSuffixTree(str);
        }
        for(int i = 0; i < q; i++){
            string str;
            cin>>str;
            obj->contains(str) ? cout<<"1"<<endl : cout<<"0"<<endl;
        }
    }
    return 0;
}
