void posOrd(no* aux)
{  
    if(aux->lf)posOrd(aux->lf);
    if(aux->rt)posOrd(aux->rt);
    fs<< aux ->ch;//see

}