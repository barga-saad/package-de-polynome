#include "poly.h"
int min(int a,int b){
    if(a<b) return a ;
    return b;}





int max(int a,int b){
    if(a<b) return b ;
    return a;}

int valeur_absolue(int a){
    return max(a,(-1)*a);}


int null(const poly p){
        int a=0;
        for(int ini=0;ini<p.deg;ini++){if(*(p.N+ini)!=0){
                                                a=1;}}
        return a;

}

ostream& singe (ostream& o , int a)
{
    if (a>0)
        o<<"+";
    if(a<0)
        o<<"-";
}



ostream& affichage_du_plus_grand_degre(ostream& o ,const poly&p)
{
        if(*(p.N+p.deg)!=0 and p.deg>1){
            if(*(p.N+p.deg)!=1)
                    o<<*(p.N+p.deg)<<"X^"<<p.deg;
            if(*(p.N+p.deg)==1)
                    o<<"X^"<<p.deg;
            if(*(p.N+p.deg-1)!=0)
                singe(o,*(p.N+p.deg-1) );
                        }
}

ostream& affichage_du_degre_moiyenne(ostream& o ,const poly&p){


    for(int init=p.deg-1;init>1;init--){
        if(*(p.N+init)!=0){
                if(*(p.N+init)!=1){
                    o<<valeur_absolue(*(p.N+init))<<"X^"<<init;
                    if(*(p.N+init-1)!=0)
                            singe(o,*(p.N+init-1) );

                                    }
                if(*(p.N+init)==1 ){
                            o<<"X^"<<init;
                    if(*(p.N+init-1)!=0)
                            singe(o,*(p.N+init-1) );
                                        }
                                        }
                                        }
                                        }


ostream& affichage_du_premier_zero_degre(ostream& o ,const poly&p){
        if(*(p.N+1)!=0){
                if(*(p.N+1)!=1)
                    o<< valeur_absolue(*(p.N+1))<<"X";
                if(*(p.N+1)==1)
                    o<<"X";
                        }

        if(*(p.N)!=0)
            singe(o,*(p.N) );

        if(*(p.N)!=0)
            o<<valeur_absolue(*(p.N));}



 poly::poly(){
        N=new int;
        deg=1;
        *N=1;
}



poly::poly(int a ){
        deg=a;
        N=(int *)malloc(a*sizeof(int));
        cout<<"entrer les coef du polynome "<<endl;
        for(int init=0;init<=a;init++){cout<<"entrer le coef numero "<<init<<":";cin>>*(N+init);}
}


poly::poly( const poly& p)
{
        deg=p.deg;
        this->N=p.N;
}


void poly::degre()
{
    cout<<"le degre de se polynome est "<<deg;
}




ostream& operator<<(ostream& o,const poly& p){
    o<<" le polynome de degree : "<<p.deg<<"  a un expression ";

    affichage_du_plus_grand_degre(o,p);

    affichage_du_degre_moiyenne(o,p);

    affichage_du_premier_zero_degre(o,p);


       if ((null(p))==0){o<<"0";}


       o<<endl;
                                            }


poly poly::operator+( poly p ){
                poly sum;
                sum.deg=max(deg,p.deg);


                for(int ini=0;ini<=min(deg,p.deg);ini++){
                    *(sum.N+ini)=*(N+ini)+*(p.N+ini);
                }
                for(int ini=min(deg,p.deg);ini<=sum.deg;ini++){
                    *(sum.N+ini)=*(N+ini)+*(p.N+ini);
                }
                int ini=sum.deg;
                while(*(sum.N+ini)==0){sum.deg--;ini--;}

                return sum;
}



poly poly::operator-( poly p ){
                poly sum;
                sum.deg=max(deg,p.deg);


                for(int ini=0;ini<=min(deg,p.deg);ini++){
                    *(sum.N+ini)=*(N+ini)-*(p.N+ini);
                }
                for(int ini=min(deg,p.deg);ini<=sum.deg;ini++){
                    *(sum.N+ini)=*(N+ini)-*(p.N+ini);
                }
                int ini=sum.deg;
                while(*(sum.N+ini)==0){sum.deg--;ini--;}

                return sum;
}








