#include<cstdio>
struct trie
{
    trie *next[26];
    int son;
    trie()
    {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        son = 0;
    }
};
int main()
{
    char word[26], que[26];
    int n, m;
    scanf("%d", &n);
    trie *root = new trie;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        trie *temp = root;
        for (int i = 0; word[i]; i++)
        {
            if(temp->next[word[i] - 'a'] == nullptr)
                temp->next[word[i] - 'a'] = new trie;
            temp->next[word[i] - 'a']->son++;
            temp = temp->next[word[i] - 'a'];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", que);
        trie *temp = root;
        bool flag = false;
        for (int i = 0; que[i]; i++)
        {
            if (temp->next[que[i] - 'a'])
                temp = temp->next[que[i] - 'a'];
            else
                flag = true;
        }
        if (flag)
            printf("0\n");
        else
            printf("%d\n", temp->son);
    }
    return 0;
}