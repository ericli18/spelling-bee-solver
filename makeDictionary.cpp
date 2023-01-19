#include<bits/stdc++.h>
using namespace std;

struct trieNode{

    trieNode *child[26];

    bool isEnd;

};

void setio(string s) {

	freopen((s + ".txt").c_str(), "r", stdin);

	//freopen((s + ".out").c_str(), "w", stdout);

}

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
    setio("words_alpha");
    trieNode *root = new trieNode();
    string s;
    while(cin>>s){
        trieNode *temp = root;
        for(int i=0;i<s.length();i++){
            int index = s[i]-'a';
            if(temp->child[index]==NULL){
                temp->child[index] = new trieNode();
            }
            temp = temp->child[index];
        }
        temp->isEnd = true;
    }

    cout << findWord("hello", root) << endl;
    return 0;
}

