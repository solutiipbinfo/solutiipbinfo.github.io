void inserare(nod * & p, nod * q, int x)
{
    if(p == q)
    {
        nod *nodut = new nod;
        nodut -> info = x;
        nodut -> urm = p;
        p = nodut;
    } else
    {
        nod * p1 = p;
        nod * p2 = p;
         nod * nodut = new nod;
        nodut -> info = x;
        while(p1 != NULL && p1 -> urm != q) p1 = p1 -> urm, p2 = p2 -> urm;
        p2 = p2 -> urm;
            if(p2 != NULL)
            {
                nodut -> urm = p2;
                p1 -> urm = nodut;
            }
    }
}