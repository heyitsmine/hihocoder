#include<cstdio>
#include<algorithm>
using namespace std;;
const int MAX = 1000000 + 15;
char pre[MAX], str[MAX * 2];
int p[MAX * 2];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", pre);
        int len = 0, ans = 0;
        for (int i = 0; pre[i]; i++)
        {
            str[i * 2 + 1] = '#';
            str[i * 2 + 2] = pre[i];
            ++len;
        }
        str[0] = '$';
        str[len * 2 + 1] = '#';
        int mx = 0, id = 0;
        for (int i = 0; i < 2 * len; i++)
        {
            if (i < mx)
                p[i] = min(p[id * 2 - i], mx - i);
            else
                p[i] = 1;
            while(str[i - p[i]] == str[i + p[i]])
                p[i]++;
            if (mx < i + p[i])
            {
                mx = i + p[i];
                id = i;
            }
            ans = max(ans, p[i] - 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}