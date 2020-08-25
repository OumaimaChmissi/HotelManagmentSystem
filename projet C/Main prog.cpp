#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "fcts.h"
void main()
{   
	int i,n ;
	int quit,nb ,v, w,z,y;
	RESERVATION tab[60];
 	DATE d ;
	 
  

	printf("\n");
	 printf("  *******************WELCOME TO OUR HOTEL********************** \n");
     printf("\n  --------------------------PLAN-----------------------------------------\n");
	 printf(" \n   Commencant  par le remplissage de tableau de  reservations                              \n");
	 printf("\n Apres avoir remplir le tableau des reservations  , On peut : \n");
	 printf("\n      **   1  : Pour  afficher toutes les reservations des clients   **\n \n"); 
	 printf(" \n      **   2  : Pour  trier  les reservations   **  \n \n");
	 printf(" \n      **   3  : Pour  modifier  l'une ou les reservations   ** \n \n "); 
	 printf(" \n      **   4  : Pour supprimer une ou des reservations   ** \n \n "); 
	 printf(" \n      **   5 : Pour  ajouter  une ou  des reservations   ** \n \n "); 
	 printf(" \n      **   6 : Pour  rechercher une reservation   ** \n \n "); 
	 printf("\n       ***********************************************************\n");
	 
	 datedejour(&d);
	
	 printf(" \n Saisir le nombre de clients ");
     scanf("%d", &nb);
     
	for (  i =0 ; i<nb ;i++) // remplissage du tableau des reservations
	{ 
		printf(" \n ------------  Remplissage des informations consernant le Client n'%d  ---------\n ",i+1);
	    tab[i]=reserver();
	 }
	 
	system("cls");
	 printf("\n      ********************************************************************\n");
     printf("\n                  ***************************************                  \n");
     
	 w=consulter(); // les changements qui on veut les changer dans le tableau ( supp, ajout, modifier....)
	  
	do

	 {
	 if(w==1)  //affichage du tableau des reservations
	 {
	     for (  i =0 ; i<nb ;i++)   
	   { 
		 printf(" \n ------------  Affichage des informations consernant le Client n'%d -----------\n ",i+1);
	     verification(tab[i]  );
	     printf("\n --------------------------------------------------------------------------------\n"); 
	   }
	 }  
	  
	 printf("\n      ********************************************************************\n");
     printf("\n                  ***************************************                  \n");
	  

	 if(w==2) //trier  des reservations 
	{ 
	     printf(" \n  ---------- TRIE SELON  LE NUMERO DE RESERVATION  ---------- \n");
  		 tri(tab,nb);
	     for (  i =0 ; i<nb ;i++)   
	  { 	
		 printf(" \n ------------  Affichage  de resultat de trie n'%d -----------\n ",i+1);
	     verification(tab[i]  );
	     printf("\n --------------------------------------------------------------------------------\n"); 
	   }
	 }

	


	 if(w==3) // modifier du tableau des reservations
	 {
		 printf("\n------------ MODIFICATION D'UNE RESERVATION-------------\n");
		 for ( int i=0 ; i<nb ;i++)
		 modifier(&(tab[i]),nb);
		 for (  i =0 ; i<nb ;i++)   
	 { 	 
		printf(" \n ------------  affichage apres modification n'%d -----------\n ",i+1);
	     verification(tab[i]  );
	     printf("\n --------------------------------------------------------------------------------\n"); 
	 }
	 }




	 if(w==4) //supprimer une reservation + affichage 
	 {
		  printf(" \n-------   SUPPRESSION D'UNE RESERVATION---------\n");
		  printf("\n donner le numero de carte d'identitee de client a supprimer \n");
	      scanf("%d",&y);
		 for (  i =0 ; i<nb ;i++)  
		  supp_res(&tab[i],nb,y);
		 for (  i =0 ; i<nb ;i++)   
	 { 	
		 printf(" \n ------------  Affichage  apes suppression n'%d -----------\n ");
	     verification(tab[i]  );
	     printf("\n --------------------------------------------------------------------------------\n"); 
	   }
	  }

	 
	 
	 
	 if (w==5) // Ajouter une reservation  + affichage
	 {
	     printf("\n Entrer le nombre de reservation a ajouter \n");
         scanf("%d",&n);
	     for (i=nb ;i< nb+n ;i++)
		   tab[i]=ajouter();
		 for (  i =0 ; i<nb+n ;i++)   
	     { 	
		    printf(" \n ------------  Affichage apres ajout n'%d -----------\n ",i+1);
	        verification(tab[i] );
	        printf("\n --------------------------------------------------------------------------------\n"); 
	     }
	  }



	 if(w==6) //rechercher + Affichage
	 {
	 printf(" \n-------  RECHERCHE D'UN CLIENT SELON SA CARTE D'IDENTIEE-------\n");
	 printf("\n donner le numero de carte d'identitee \n");
	 scanf("%d",&z);
	 for ( int i=0 ;i<nb ;i++)
		 rechercher(&tab[i],z,nb);
	 }
	
	
	printf(" si vous voulez quitter taper 1");
	scanf("%d",&quit);
	system("cls");
	w=consulter();
	 }
	 while(quit!=1);
	
	
	 
	 
 
	 


getch(); 
}

