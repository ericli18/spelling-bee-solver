#include<bits/stdc++.h>
using namespace std;


struct trieNode{

    trieNode *child[26];

    bool isEnd;

};

void setio(string s) {
	freopen((s + ".txt").c_str(), "r", stdin);
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

//Display and search through treeNodes
void display(trieNode* root, char str[], int level, vector<char>& allowed, char necessary)
{
    if (root -> isEnd) 
    {

        str[level] = '\0';
        if(!(level < 4) && strchr(str, necessary) != nullptr)
            cout << str << endl;
    }
  
    for(auto i : allowed) 
    {
        if (root->child[i - 'a']) 
        {
            str[level] = i;
            display(root->child[i - 'a'], str, level + 1, allowed, necessary);
        }
    }
}


int main(){
    setio("words_alpha");
    trieNode *root = new trieNode();
    string s;
    while(cin>>s){
        trieNode *temp = root;
        if(s.length()<=3) continue;
        for(int i=0;i<s.length();i++){
            int index = s[i]-'a';
            if(temp->child[index]==NULL){
                temp->child[index] = new trieNode();
            }
            temp = temp->child[index];
        }
        temp->isEnd = true;
    }

    cout << findWord("agility", root) << endl;
// it doesn't find agility sooooo it needs some improvements

    vector<char> allowed = {'e', 'l', 'x', 'f', 'o', 'i', 'n'};
    int level = 0;
    char str[30];
    display(root, str, level, allowed, 'n');
    // serialize(root, "dictionary2.txt");
    return 0;
}




