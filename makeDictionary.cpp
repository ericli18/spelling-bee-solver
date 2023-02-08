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

// string serialize_trie(trieNode* root) {
//     string result = "";
//     for (int i = 0; i < 26; i++) {
//         if (root->child[i] != nullptr) {
//             result += char(i + 'a');
//             result += serialize_trie(root->child[i]);
//         }
//     }
//     result += root->isEnd ? '$' : '#';
//     return result;
// }

// void serialize(trieNode* root, string filename) {
//     ofstream file(filename);
//     if (file.is_open()) {
//         string trie_str = serialize_trie(root);
//         file.write(trie_str.c_str(), trie_str.length());
//         file.close();
//     }
// }

//serialize trie to file
// void serialize(trieNode* root, string filename) {
//     ofstream file(filename);
//     if (file.is_open()) {
//         queue<trieNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             trieNode* current = q.front();
//             q.pop();
//             for (int i = 0; i < 26; i++) {
//                 if (current->child[i] != nullptr) {
//                     file << char(i + 'a');
//                     q.push(current->child[i]);
//                 }
//             }
//             file << (current->isEnd ? '$' : '#');
//         }
//         file.close();
//     }
// }

// string constructWords(vector<char> &validLetters, trieNode* root)
// {
//     string result = "";

//     stack<trieNode*> q;
//     string running = "";
//     q.push(root);
//     unordered_map<trieNode*, bool> visited();
//     while(!q.empty())
//     {
//         trieNode* curr = q.top();
//         bool finished = true;
//         for(auto x : validLetters)
//         {
//             if(curr -> child[x-'a'] != nullptr && )
//             {
//                 finished = false;
//                 running += to_string(x);
//                 q.push(curr -> child[x-'a'])
//             }
//         }
//     }
// }

void display(trieNode* root, char str[], int level, vector<char>& allowed, char necessary)
{
    // If node is leaf node, it indicates end
    // of string, so a null character is added
    // and string is displayed
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
            display(root->child[i - 'a'], str, level + 1, allowed, 'i');
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

    vector<char> allowed = {'g', 'e', 'i', 'l', 'a', 'y', 't'};
    int level = 0;
    char str[30];
    display(root, str, level, allowed, 'i');
    // serialize(root, "dictionary2.txt");
    return 0;
}




