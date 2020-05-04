/*
Prefix search in a TODO list and returning the count for every actual word as prefix.
https://www.spoj.com/problems/ADAINDEX/
                                        root
                                    /      |    \
                                   b        d     c
                                 /          |       \
                                u           o        a
                               /  \         | \     /  \
                              g    d        n  g    m    t

6 4
bug
bud
dog
don
cam
cat

do : 2
ca : 2
hi : 0
on : 0

12 6
bulldog
dog
dogged
doggedly
doggerel
dogma
dogmatic
dogmatism
dogs
catastroph
catastroph
doctor
cat : 2
dog : 8
dogg : 3
do : 9
doctrinography : 0
dogge : 3
*/

#include <iostream>
using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    int pfx;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isEnd = false;
        pfx = 0;
    }
};

class SuffixTree{
public:
    TrieNode* root;

    SuffixTree(){
        this->root = new TrieNode();
    }

    void insertNodeSuffixTree(string str){ // O(S1+S2.. +SN) where Si is the length of string and n strings input
        TrieNode* node = this->root;
            for(int i = 0; i < str.length(); i++){
                char letter = str[i];
                if(node->children[letter - 'a'] == NULL){
                    node->children[letter-'a'] = new TrieNode();
                }
                node = node->children[letter-'a'];
                node->pfx++;
            }
        node->isEnd = true;
    }

    int contains(string str){ //O(R1 + R2...+RM) where Ri is the length of string searched and m queries performed.
        TrieNode* node = this->root;
            for(char c : str){
                if(node->children[c - 'a'] == NULL){
                    return 0;
                }
                node = node->children[c - 'a'];
            }
        return node->pfx;
    }
};

int main(){
    SuffixTree obj;
    int n,q;
    cin>>n>>q;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            obj.insertNodeSuffixTree(str);
        }

        while(q--){
            string str;
            cin>>str;
            cout<<obj.contains(str)<<endl;
        }
    return 0;
}
