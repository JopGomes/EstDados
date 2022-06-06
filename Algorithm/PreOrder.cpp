void preOrd(no* aux)
{  
    fs<< aux ->ch;//see
    if(aux->lf)preOrd(aux->lf);
    if(aux->rt)preOrd(aux->rt);
}