void symOrd(no* aux) 
{  
    if(aux->lf)symOrd(aux->lf);
    fs<< aux ->ch;//see
    if(aux->rt)symOrd(aux->rt);
    
}