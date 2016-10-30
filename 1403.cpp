//ºó×ºÊý×é
#include<algorithm>
#include<cstdio>
const int INF = 200050;
const int MAX_N = 20005;

int n, k;
int rank[MAX_N], tmp[MAX_N], height[MAX_N];

bool compare_sa(int i, int j)
{
    if (rank[i] != rank[j])
        return rank[i] < rank[j];
    else
    {
        int ri = (i + k <= n ? rank[i + k] : -1);
        int rj = (j + k <= n ? rank[j + k] : -1);
        return ri < rj;
    }
}

void construct_sa(char *S, int *sa)
{
    for (int i = 0; i <= n; i++)
    {
        sa[i] = i;
        rank[i] = (i < n ? S[i] : -1);
    }
    for (k = 1; k <= n; k <<= 1)
    {
        std::sort(sa, sa + n + 1, compare_sa);
        tmp[sa[0]] = 0;
        for (int i = 1; i <= n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
        for (int i = 0; i <= n; i++)
            rank[i] = tmp[i];
    }
}

void set_height(char *S, int *sa)
{
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        if (d > 0)
            --d;
        int a = sa[rank[i]];
        if (rank[i] == 0)
        {
            height[rank[i]] = 0;
            continue;
        }
        int b = sa[rank[i] - 1];
        while (S[a + d] == S[b + d])
        {
            ++d;
        }
        height[rank[i]] = d;
    }
}
int find_min(int *num, int len)
{
    int res = INF;
    for (int i = 0; i < len; i++)
        if (res > num[i])
            res = num[i];
    return res;
}
int main()
{
    int K;
    int suff[MAX_N], data[MAX_N];
    char num[MAX_N];
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    if (K == 1)
    {
        printf("%d\n", n);
        return 0;
    }
    construct_sa(num, suff);
    set_height(num, suff);
    int ans = 0, temp = 0;
    for (int i = 0; i < n - K + 2; i++)
    {
        data[i] = find_min(height + i, K - 1);
        if (ans < data[i])
            ans = data[i];
    }
    printf("%d\n", ans);
    return 0;
}
