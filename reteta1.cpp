#include <bits/stdc++.h>

using namespace std;
ifstream fin("reteta1.in");
ofstream fout("reteta1.out");
int t[50][50], p[50], m, n;
double s, minim = 1234567890, v[50];
int fr[50];
void bk(int x)
{
    for(int i = p[x - 1] + 1; i <= m; ++i)
    {
        p[x] = i;
        bool gata = 0, mai_trebuie = 0;
        int nr = t[i][1] + 1, op = t[i][0];
        if(op == 1)
        {
            for(int j = 2; j <= nr; ++j) s +=  v[t[i][j]], fr[t[i][j]]++;
        } else
        {
            for(int j = 2; j <= nr; ++j) s +=  (v[t[i][j]] / 2), fr[t[i][j]]++;
        }
        for(int i = 1; i <= n && !gata; ++i)
            if( !fr[i]) mai_trebuie = 1;else
            if(fr[i] > 1) gata = 1;
            if(!mai_trebuie && !gata)
            {
                if(s < minim) minim =  s;
            } else
            if(mai_trebuie && !gata) bk(x + 1);

            if(op == 1)
        {
            for(int j = 2; j <= nr; ++j) s -= v[t[i][j]], fr[t[i][j]]--;
        } else
        {
            for(int j = 2; j <= nr; ++j) s -= (v[t[i][j]] / 2), fr[t[i][j]]--;
        }

    }
}
int main()
{
       fin >> n >> m;
       for(int i = 1; i <= m; ++i)
       {
           fin >> t[i][0] >> t[i][1];
           int nr = t[i][1] + 1;
           for(int j = 2; j <= nr; ++j) fin >> t[i][j];
       }
       for(int i = 1; i <= n; ++i) fin >> v[i];
       bk(1);
       fout << fixed << setprecision(1) << minim;
    return 0;
}
