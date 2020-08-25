 #include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "fcts.h"
void datedejour (DATE *d )
{
	int w;
	do
	{
	printf(" \n saisir la date du jour \n");
	scanf_s("%d%d%d",&d->jour ,&d->mois, &d->annee);
	w=verif_date(*d);
	}
	while( !w );

}
 

void remplissage ( CLIENT*t) // REMPLISSAGE DES INFOMATIONS D'UN CLIENT
{
	 
	printf("\n Saisir Le Nom \n");
	scanf("%s", t->nom);
	 
	do 
	{
    printf(" \n saisir le cin \n");
	scanf("%d", &t->cin);
	} while ((t->cin<10000000) || ((t->cin)>99999999)); 
	do
	{
	printf(" \n Saisir l' Age \n");
	scanf("%d", &t->age);
	} while( (t->age <0 ) || (t->age >100) );
	printf(" \n Saisir le Sexe (H/F)  \n");
    scanf("%s", t->sexe);
	do
	{
	printf(" \n Saisir numero du telephone \n");
	scanf("%d",&t->telephone);
	} while ((t->telephone<10000000) || ((t->telephone)>99999999)); 
    printf(" \n Saisir  mail \n");
	scanf("%s", t->mail);

}

void  affichage ( CLIENT t) // AFFICHAGE DES INFORMATIONS D'UN CLIENT
{

	printf("\n      Le Nom est : %s", t.nom);
	printf(" \n    Le cin est : %d", t.cin);
	printf(" \n    L' Age est : %d", t.age);
	printf(" \n    Le Sexe  est : %s", t.sexe);
	printf(" \n    Le numero du telephone %d",t.telephone);
    printf(" \n    Le mail %s", t.mail);

}
 
RESERVATION reserver()  // RESERVATION DANS L'HOTEL ( les infos sur le client /  details des chambres a reserver / montant a payer)
{
	 int i=0,q,p ;
	 float  x=00.00, a=00.00 ;
	RESERVATION *tab ;
	CHAMBRE chamb[10];
 
	tab=(RESERVATION*)malloc(sizeof(RESERVATION));
	if(!tab) exit(-1);
 
 	do
	{
	printf("\n Entrer le  numero de reservation qui est donnee par l'hotel et il est comprisee entre  100 et 500 \n ");
	scanf("%d", &tab->numeroreserv);
	}
	while ( (tab->numeroreserv < 100) || (tab->numeroreserv >	500) );
	
	remplissage(  &(tab->cli));
	
	printf("\n Entrer le nombre des chambres a reserver \n ");
	scanf("%d", &tab->nb_chambres);
     
	
	printf(" \n ________Les informations sur la ou les chambres a reserver________\n");
    
    for ( int k=0;k<tab->nb_chambres ; k++)
	{
	
	 do
	{
	printf("\n Choisir la categorie de(s) chambre(s) \n 1 : Simple \n 2 : Double \n 3 : Triple \n 4 :  Familiale \n ");
	scanf("%d", &tab->chamb.categorie);
	}
    while ( (tab->chamb.categorie < 1) || ( tab->chamb.categorie>4)) ;

	printf("\n Saisir le nombre des nuits \n");
	scanf("%d", &tab->chamb.nb_nuit);
	 
	 if (tab->chamb.categorie == 1)
		  a=float( 30*tab->chamb.nb_nuit);
	 if (tab->chamb.categorie == 2)
		 a= float (50*tab->chamb.nb_nuit);
	 if (tab->chamb.categorie == 3)
		 a= float ( 80*tab->chamb.nb_nuit);
	  if (tab->chamb.categorie == 4)
	    a= float (120*tab->chamb.nb_nuit);
	   x+=a ; 
 	}

	printf("\n saisir le montant a  payer en avance s'il vous plait \n ");
	scanf("%f",&tab->montantavance);
	tab->rest=x- tab->montantavance;
	printf("\n  il vous reste  %5.2f DT a payer merci ! \n ", tab->rest ); 
	  
     printf("\n S'il vous plait entrer le nombre des personnes qui vont etre presents avec le client \n");
	 scanf("%d", &tab->nb_personnes);
  	 for (int i=0 ; i<tab->nb_personnes ;i++)
		 remplissage( &tab->per[i]);
	 do
	 {
	 printf(" \n  Saisir la date d'arrivee \n");
	 scanf("%d%d%d", &tab->arrivee.jour ,&tab->arrivee.mois , &tab->arrivee.annee);
	 q=verif_date(tab->arrivee);
	 } while (!q);
	 do
	 {
     printf(" \n  Saisir la date de depart \n");
	 scanf("%d%d%d",  &tab->depart.jour ,&tab->depart.mois , &tab->depart.annee);
	 p=verif_date(tab->depart);
	 }while(!p);
	 for ( int i=0 ; i< tab->nb_chambres ;i++) 
	 { 
		 (tab->chamb.numerochamb)= (tab->numeroreserv)+i;
		 printf( " \n Le numero de chambre reservee n'%d est %d \n " , i ,tab->chamb.numerochamb);
	 } 
	return *tab;
}

  int  consulter ()
 {
	 int w;
 	 printf("\n    Taper 1  : Pour  afficher toutes les reservations des clients \n \n"); 
	 printf(" \n    Taper 2  : Pour  trier  les reservations  \n \n");
	 printf(" \n    Taper 3  : Pour  modifier  l'une ou les reservations \n \n "); 
	 printf(" \n    Taper 4  : Pour supprimer une ou des reservations \n \n "); 
	 printf(" \n    Taper 5 : Pour  ajouter  une ou  des reservations \n \n "); 
	 printf(" \n    Taper 6 : Pour  rechercher une reservation \n \n "); 
	 do
	 scanf("%d",&w);
	 while((w<1)||(w>6));
	 return w;
  }



// AFFICHAGE DES DETAILS DU RESERVATION  ( les infos sur le client /  details des chambres a reserver / montant a payer)
 void verification (RESERVATION tab) 
{
	  
 	affichage (tab.cli);
	printf("\n  la date d'arrivee  est : %d/%d/%d \n",tab.arrivee.jour ,tab.arrivee.mois , tab.arrivee.annee);
	printf("\n  la date de depart est : %d/%d/%d \n",tab.depart.jour ,tab.depart.mois , tab.depart.annee);
	printf("\n");
	printf(" \n ----Affichage  des informations sur la ou les chambres a reserver----\n");
	printf("\n	 le nombre des chambres reservees %d  \n",tab.nb_chambres);
	printf("\n	les  categories des  chambres disponibles sont : \n 1 : Simple \n 2 : Double \n 3 : Triple \n 4 :  Familiale \n ");
	 for ( int k=0;k<tab.nb_chambres ; k++)
		 printf(" \n le choix de chambre n'%d  etait de categorie n' %d \n", k , tab.chamb.categorie );
	 printf("\n");
	 for ( int i=0 ; i< tab.nb_chambres ;i++) 
	     printf( "\n  Le numero de chambre reservee n'%d est %d \n " , i ,tab.chamb.numerochamb+i);
	 printf("\n");

	printf("\n le nombre des personnes qui vont etre presents  %d", tab.nb_personnes);
	printf(" \n les personnes sont : \n ");
	 
	 for (int i=0 ; i<tab.nb_personnes ;i++)
		 affichage(   tab.per[i]);
	 printf("\n");

	 printf("\n   le montant  deja  paye en avance est : %5.2f \n",tab.montantavance);
	 printf("\n");
	 printf("\n Il reste  %5.2f DT a payer merci ! \n ", tab.rest ); 

}





 void  modifications (RESERVATION** re)
 {
	 
	 float a=00.00,x=00.00;
	 int c ;
	 do
	 {
	 printf("\n Si vous voulez modifier les infos du client Taper  :  1 " );
	 printf(" \n Si vous voulez modifier des infos consernant les dates (arrivee/depart) Taper  : 2 \n");   
	 printf("\n Si vous voulez modifier les infos de chambres reservees Taper :   3   \n  ");
	 scanf("%d", &c);
	 } while( (c<1)|| (c>3));
	 if (c==1)
	 {
	 printf("\n modification du client");
	 remplissage(&((*re)->cli));
	 }
	 if (c==2)
	 {
	 printf("\n modification du date d'arrivee");
	 scanf("%d%d%d ",&(*re)->arrivee.jour,&(*re)->arrivee.mois,&(*re)->arrivee.annee );
	 printf("\n modification du date de depart  ");
	 scanf("%d%d%d ",&(*re)->depart.jour,&(*re)->depart.mois,&(*re)->depart.annee);
	 }
	 if(c==3)
	 {
	 printf("\n &&&&&&    modification du nombre des chambres a reservee   &&&&& \n "); 
	 printf(" Saisir le nouveau nombre de chambres ");
	 scanf("%d",&(*re)->nb_chambres );
	 printf("\n modification de categories des chambres \n");
	  for ( int k=0;k<(*re)->nb_chambres ; k++)
	{
	 do
	{
	printf("\n Choisir la categorie de  nouvelle(s) chambre(s) \n 1 : Simple \n 2 : Double \n 3 : Triple \n 4 :  Familiale \n ");
	scanf("%d", &(*re)->chamb.categorie);
	}
    while ( ((*re)->chamb.categorie < 1) || ( (*re)->chamb.categorie>4)) ;
	 
	printf("\n Saisir le nombre des nuits \n");
	scanf("%d", &(*re)->chamb.nb_nuit);
	 
	 if ((*re)->chamb.categorie == 1)
		  a=float( 30*((*re)->chamb.nb_nuit));
	 if ((*re)->chamb.categorie == 2)
		 a= float (50*((*re)->chamb.nb_nuit));
	 if (((*re)->chamb.categorie == 3))
		 a= float ( 80*((*re)->chamb.nb_nuit));
	  if (((*re)->chamb.categorie == 4))
	    a= float (120*((*re)->chamb.nb_nuit));
	   x+=a ; 
	  }
 	 
	printf("\n saisir le montant a  payer en avance s'il vous plait \n ");
	scanf("%f",&(*re)->montantavance);
	(*re)->rest=x- (*re)->montantavance;
	printf("\n  il vous reste  %5.2f DT a payer merci ! \n ", (*re)->rest ); 
	
	}
 

 }
 void modifier ( RESERVATION	*p ,int n )
 {
	 int x,i ;
	 printf("\n donner le numero de carte d'identite");
	 scanf("%d",&x);
	 for ( i=0 ; i<n ;i++)
	 {
		 if ((p+i)->cli.cin ==x)
		 {
			  modifications(&p+i);
		 }
	 }
 }
 void tri ( RESERVATION  *t, int n) // tri dand l'ordre croissant selon le numero de reservation 
 { 
	 RESERVATION aux; 
	 int i,j;
     for (i = 1; i < n; i++)
 { 
	j = i-1;   
	while((j>=0)&&(((t+j)->numeroreserv)>((t+j+1)->numeroreserv)))
	{
		aux=*(t+j);
		*(t+j)=*(t+j+1);
		*(t+j+1)=aux ;
		j--;
     } 
   }
	
 }
 
 void rechercher (RESERVATION *t,int  a,int n) // recherche d'un client selon cin
 {
	 int i ;
	
	 for(i=0 ;i<n ;i++)
	 {
		 if((t+i)->cli.cin==a)
		 {
			 printf("\n le client recherche est : \n ");
			 verification(*(t+i));
		 }
	 }
 }

 void supp_res (RESERVATION *t,int n,int a)
 {
	 int i ;
	 for( i=0; i<n ;i++)
	 {
		 if ( (t+i)->cli.cin == a)
		 {
			 *(t+i)= *(t+n-1) ;
		 }
		 n=n-1;
		 
	 }
	

 }

 RESERVATION ajouter (  ) // Ajouter une reservation 
 {
	 RESERVATION t;
  	  t=reserver();
 	 return t;
 }

 int bis (int a) 
 { 
	 if (a%400==0)
		 return 1 ;
	 return 0;
 }
 int verif_date(DATE d)
 {
	 if((d.jour>31)||(d.mois> 12) || (d.annee<1900) || (d.annee>2018))
		 return 0 ;
	 else if(( (d.mois==4) || (d.mois==6)||(d.mois==9)||(d.mois==11)) && (d.jour>30) )	
		
			return 0;	
		
		else if ((d.mois==2)&&(bis(d.annee))  && (d.jour>29) )
		
			return 0;
		
		else if ((d.mois==2)&&(! bis(d.annee))  && (d.jour>28) )
		
			return  0 ;
		
		return 1;
}


 
