#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
};

class SuffixTree{
public:
    TrieNode* root;
    char endSymbol;

    SuffixTree(){
        this->root = new TrieNode();
        this->endSymbol = '*';
    }

    void insertSubstringStartingAt(string str){
        TrieNode* node = this->root;
            for(int i = 0; i < str.length(); i++){
                char letter = str[i];
                if(node->children.find(letter) == node->children.end()){
                    TrieNode* newNode = new TrieNode();
                    node->children.insert({letter,newNode});
                }
                node = node->children[letter];
            }
            node->children.insert({this->endSymbol,NULL});
    }

    bool contains(string str){
        TrieNode* node = this->root;
            for(char letter:str){
                if(node->children.find(letter) == node->children.end()){
                    return false;
                }
                node  = node->children[letter];
            }
        return node->children.find(this->endSymbol) != node->children.end();
    }
    void deleteFromSuffixTree(string str){
        deleteSuffixEndingAt(this->root,str,0);
    }
    bool deleteSuffixEndingAt(TrieNode* current,string str,int index){
        if(index == str.length()){
            //check if this is a suffix by checking for endSymbol
            if(current->children.find(this->endSymbol) == current->children.end()){
                return false;
            }
            current->children.erase(this->endSymbol);
            return current->children.size() == 0;
        }

        char letter = str[index];
        if(current->children.find(letter) == current->children.end()){
            return false;
        }
        current = current->children[letter];
        bool shouldDelete = deleteSuffixEndingAt(current,str,index+1);
        if(shouldDelete){
            current->children.erase(str[index+1]);
            return current->children.size() == 0;
        }
        return false;
    }
};

int main(){
    SuffixTree obj;
    obj.insertSubstringStartingAt("Hello");
    obj.insertSubstringStartingAt("Hell");
    obj.contains("Hell") ? cout << "true"<<endl : cout<<"false"<<endl;
    obj.deleteFromSuffixTree("Hell");
    obj.contains("Hell") ? cout << "true" : cout<<"false";
}
