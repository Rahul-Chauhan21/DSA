/*
https://leetcode.com/problems/word-search-ii/
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used
more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]



Note:

    All inputs are consist of lowercase letters a-z.
    The values of words are distinct.


*/
/*
Time complexity Analysis LeetCode forum
https://leetcode.com/problems/word-search-ii/discuss/59780/Java-15ms-Easiest-Solution-(100.00)
let:
N = num of rows
M = num of columns
X = number of words in dictionary
Y = length of longest word in dictionary

Time complexity of using the trie tree

    We are doing a 4-child DFS traversal.
        The worst case depth in this case is the minimum of [traversing the entire board, traversing until we hit the end of a word].
        -> O of each traversal is4^(min(Y, NM))
        Note: min accounts for the case where we have words in the dictionary longer than the number of characters in the board itself.
    We are doing this N*M times since we need to check for words starting at each position in the board
    -> O(4^(min(Y, NM))*NM)

 // O(4^(min(Y, NM))*NM + XY) time
*/
class TrieNode{
public:
    TrieNode* children[26];
    string word;
    TrieNode() : word("")
    {
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};
class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board,i,j,board.size() - 1,board[0].size() - 1,this->root, result);
            }
        }
        return result;
    }
    void buildTrie(vector<string> words){
        this->root = new TrieNode();
        for(string word : words){
            TrieNode* currentNode = this->root;
                for(int i = 0; i < word.length(); i++){
                    char letter = word[i];
                    if(currentNode->children[letter-'a'] == NULL){
                        currentNode->children[letter-'a'] = new TrieNode();
                    }
                    currentNode = currentNode->children[letter-'a'];
                }
            currentNode->word = word;
        }
    }
    void dfs(vector<vector<char>>& board,int i,int j,int m,int n,TrieNode* currentNode, vector<string>& result){
        if(i<0 || j<0 || i > m || j> n || board[i][j] == '#' || !currentNode->children[board[i][j] - 'a'])
            return;
        char letter = board[i][j];
        currentNode = currentNode->children[letter - 'a'];
        if(currentNode -> word.size() > 0){
            result.push_back(currentNode->word);
            currentNode->word = "";
        }

        board[i][j] = '#';
        dfs(board,i-1,j,m,n,currentNode,result);
        dfs(board,i+1,j,m,n,currentNode,result);
        dfs(board,i,j-1,m,n,currentNode,result);
        dfs(board,i,j+1,m,n,currentNode,result);
        board[i][j] = letter;
    }
};
