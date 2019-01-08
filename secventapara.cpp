#include <bits/stdc++.h>

using namespace std;
ifstream fin("secventapara.in");
ofstream fout("secventapara.out");

int main()
{
        int maxim = 0, nrmax = 0;
        int x, nr = 0;
            while(fin >> x)
            {
                if(x % 2 == 0) ++nr;else
                {

                    if(nr > maxim) maxim = nr, nrmax = 1;else
                        if(nr == maxim) ++nrmax;
                        nr = 0;
                }
            }
            if(nr > maxim) maxim = nr, nrmax = 1;else
                        if(nr == maxim) ++nrmax;
                        fout << nrmax;
    return 0;
}
