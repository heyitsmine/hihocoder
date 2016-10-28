#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
char line[5000];
char seg[105];
struct trie
{
    string name;
    int isbook;
    int cnt;
    trie* next[105];
    trie()
    {
        name = "";
        isbook = 0;
        cnt = 0;
    }
};
bool cmp(trie* a, trie *b)
{
    if (a->isbook == b->isbook)
        return a->name < b->name;
    else
        return a->isbook < b->isbook;
}
void dfs(trie *far, int deep)
{
    for (int i = 0; i < deep * 4; i++)
        printf(" ");
    cout << far->name << endl;
    sort(far->next, far->next + far->cnt, cmp);
    for (int i = 0; i < far->cnt; i++)
        dfs(far->next[i], deep + 1);
}
int main()
{
    int time = 0;
    trie *root = new trie;
    while (gets_s(line) != nullptr)
    {
        if (line[0] == '0'&&line[1] == '\0')
        {
            ++time;
            printf("Case %d:\n", time);
            sort(root->next, root->next + root->cnt, cmp);
            for (int i = 0; i < root->cnt; i++)
                dfs(root->next[i], 0);
            root = new trie;
            continue;
        }
        trie *p = root;
        int index = 0;
        for (int i = 0; line[i] != '\0'; i++)
        {
            seg[index++] = line[i];
            if (line[i] == '/')
            {
                seg[index - 1] = '\0';
                string tname(seg);
                bool flag = true;
                for (int i = 0; i < p->cnt; i++)
                {
                    if (!p->next[i]->isbook &&p->next[i]->name == tname)
                    {
                        flag = false;
                        p = p->next[i];
                    }
                }
                if (flag)
                {
                    trie *pnext = new trie;
                    pnext->name = tname, pnext->isbook = 0;
                    p->next[p->cnt] = pnext;
                    p->cnt++;
                    p = pnext;
                }
                index = 0;
            }
        }
        seg[index] = '\0';
        string tname(seg);
        bool flag = true;
        for (int i = 0; i < p->cnt; i++)
        {
            if (p->next[i]->isbook && p->next[i]->name == tname)
                flag = false;
        }
        if (flag)
        {
            trie *pnext = new trie;
            pnext->name = tname, pnext->isbook = 1;
            p->next[p->cnt] = pnext;
            p->cnt++;
        }
    }
    return 0;
}