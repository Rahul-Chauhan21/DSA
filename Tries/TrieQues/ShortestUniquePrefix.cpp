/*
https://www.interviewbit.com/problems/shortest-unique-prefix/
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov

    NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 


*/
#include <iostream>
#include <vector>

using namespace std;

class TrieNode{
public:
    TrieNode* children[26];
    int pfx;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        pfx = 0;
    }
};

class Trie{
 public:
    TrieNode* root;
    Trie(){
        this->root = new TrieNode();
    }

    void insert(string str){
        TrieNode* currentNode = this->root;
            for(int i = 0; i < str.length(); i++){
                char letter = str[i];
                if(currentNode->children[letter-'a'] == NULL){
                    currentNode->children[letter-'a'] = new TrieNode();
                }
                currentNode = currentNode->children[letter-'a'];
                currentNode->pfx++;
            }
    }
    string findPrefix(string str){
        TrieNode* currentNode = this->root;
        string prefix = "";
        int i = 0;
        prefix+=str[i];
        currentNode = currentNode->children[str[i] - 'a'];
            for(int i = 1; i < str.length(); i++){
                if(currentNode->pfx == 1){
                    return prefix;
                }
                prefix+=str[i];
                currentNode = currentNode->children[str[i] - 'a'];
            }
        return prefix;
    }
};
//O(nS) time | O(n) space
vector<string> prefix(vector<string> &A) {
    Trie* trie = new Trie();
    vector<string> result;
    if(A.empty())
        return result;
    for(string word : A){
        trie->insert(word);
    }
    for(string word: A){
        string res = trie->findPrefix(word);
        result.push_back(res);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<string> input;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            input.push_back(str);
        }
    vector<string> res = prefix(input);
    for(int i = 0; i < res.size(); i++){
        cout<< res[i] << " ";
    }
return 0;
}
