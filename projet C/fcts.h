struct client 
{ 
	char nom[30] ;
	int cin ;
	char sexe[10] ;
	int age ;
	int telephone ;
	char mail[30];
};
typedef struct client CLIENT ;

struct date
{
	int jour ;
	int mois ;
	int annee ;
};
typedef struct date DATE ;

struct chambre
{
	int  categorie  ;
    int nb_nuit ;
	int numerochamb ;
	
};
typedef struct chambre CHAMBRE ;


struct reservation
{ 
	int numeroreserv ;
   float montantavance ;
	CLIENT cli ;
	CLIENT per[10] ;
	CHAMBRE chamb ;
	int nb_chambres ;
	int nb_personnes ;
	DATE arrivee ;
	DATE depart ;
	float rest ;
};
typedef struct reservation RESERVATION ;

struct personnes 
{
	char nom[30] ;
	int cin ;
	char sexe[10] ;
	int age ;
	int telephone ;
};
typedef struct personnes PERSONNESACCOMPANES ;
void datedejour (DATE *);
void remplissage ( CLIENT*);
void  affichage ( CLIENT);
RESERVATION reserver();
 void verification (RESERVATION );
 void modifications (RESERVATION** );
 void modifier ( RESERVATION*,int  );
 void tri ( RESERVATION  *, int );
void supp_res(RESERVATION *, int ,int  ) ;
 int  consulter ();
 void rechercher (RESERVATION *,int ,int);
 RESERVATION ajouter ( );
  int bis (int ) ;
 int verif_date(DATE );




 
 







