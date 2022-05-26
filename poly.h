#include <iostream>
using namespace std;


class poly{
        public:
        int *N;
        int deg;
        poly();
        poly(int a );
        poly(const poly & p);
        void degre();
        poly operator+(poly );
        poly operator-(poly );

        friend int null(const poly p);
        friend ostream& operator<<(ostream& o,const poly& p);
        friend ostream& affichage_du_plus_grand_degre(ostream& o ,const poly&p);
        friend ostream& affichage_du_degre_moiyenne(ostream& o ,const poly&p);
        friend ostream& affichage_du_premier_zero_degre(ostream& o ,const poly&p);
        friend int re(int deg,int *N ,poly sum ,poly p);
;






};
