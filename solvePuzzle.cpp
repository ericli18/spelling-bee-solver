#include<bits/stdc++.h>
using namespace std;


struct trieNode{

    trieNode *child[26];

    bool isEnd;

};

//deserialize trie from file
// trieNode* deserialize(string filename) {
//     ifstream file(filename);
//     trieNode* root = new trieNode();
//     if (file.is_open()) {
//         queue<trieNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             trieNode* current = q.front();
//             q.pop();
//             char c;
//             while (file.get(c)) {
//                 if (c == '#') {
//                     break;
//                 }
//                 if (c == '$') {
//                     current->isEnd = true;
//                     continue;
//                 }
//                 int index = c - 'a';
//                 current->child[index] = new trieNode();
//                 q.push(current->child[index]);
//             }
//         }
//         file.close();
//     }
//     return root;
// }

bool findWord(string s, trieNode *root){
    trieNode *temp = root;
    for(int i=0;i<s.length();i++){
        int index = s[i]-'a';
        if(temp->child[index]==NULL){
            return false;
        }
        temp = temp->child[index];
    }
    return temp->isEnd;
}

int main(){
    //trieNode *root = deserialize("dictionary2.txt");
    //cout << root->child[0];
    //cout << findWord("hello", root) << endl;
    return 0;
}
