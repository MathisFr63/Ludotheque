#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nom[21];
	char prenom[21];
	char date[11];
	char tel[11];
	char ville[31];
	int nbEmp;
}Adherent;

typedef struct{
	char nom[21];
	char prenom[21];
	char jeux[31];
	char dateE[11];
	char dateR[11];
}Emprunt;

typedef struct{
	char date[11];
	char heure[6];
	int places;
	int placesL;
}Aprem;

typedef struct{
	char date[11];
	char heure[6];
	char nom[21];
	char prenom[21];
}AdhAprem;

typedef struct cell{
	char nom[31];
	int nbEx;
	int stock;
	char type[31];
	struct cell * suiv;
}Cellule;

typedef Cellule * ListeJ;

char saisirChoix(void);
ListeJ jVide(void);
Emprunt lireEmp(FILE *fe);
Emprunt *chargeTEmprunts(char *nomFichier, int * nbEmpT);
void afficheEmp(Emprunt emp);
Adherent lireAdherent(FILE *fe);
Adherent *chargeTAdherent(char *nomFichier, int * nbAdh);
void afficheAdh1(Adherent adh);
void afficheAdh2(Adherent adh);
void afficheAdh3(Adherent adh);
Adherent * newAdherent(Adherent *tAdh,int *nbAdh);
void supprAdherent(Adherent * tAdh, int * nbAdh);
void modifAdh (Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmp, AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
int rechAdherent(Adherent * tAdh, int nbAdh, char * nom, char * prenom);
Emprunt * newEmprunt(Emprunt *tEmp, int *nbEmp, Adherent * tAdh, int nbAdh, ListeJ j);
Aprem lireAprem(FILE *fe);
Aprem *chargeAprem(char *nomFichier, int * nbAprem);
void afficheAprem(Aprem ap);
Aprem * newAprem(Aprem * tAprem, int * nbAprem);
void supprAprem(Aprem * tAprem, int * nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
void modifAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
AdhAprem lireAdhAprem(FILE *fe);
AdhAprem *chargeAdhAprem(char *nomFichier, int * nbAdhAprem);
void afficheAdhAprem(AdhAprem aap, char choix);
AdhAprem * newAdhAprem(AdhAprem * tAdhAprem, int * nbAdhAprem, Adherent * tAdh, int nbAdh, Aprem * tAprem, int nbAprem);
void supprAdhAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
ListeJ newJeu(ListeJ j, int *nbJeux);
ListeJ supprJeu(ListeJ j,int * nbJeux, char * nomJ);
ListeJ modifJeu(ListeJ j, Emprunt * tEmp, int nbEmp, char choix, char * nomJ);

ListeJ lireJeux(FILE *fe);
ListeJ chargeJeux(char *nomFichier, int * nbJeux, Emprunt * tEmp, int nbEmp);
ListeJ insererEnTete(ListeJ j);
void afficheJeux(ListeJ j);

int rechJeux(ListeJ j, char * jeu);
void rendreJeu(Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmpT, ListeJ j);
int rechEmpruntJeu(Emprunt * tEmp, int nbEmpT, char * nom, char * prenom, char * jeu);
int rechAprem(Aprem * tAprem, int nbAprem, char * date, char * heure);
int rechAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char * date, char * heure, char * nom, char * prenom);
int verifDateEmprunt(Emprunt tEmp);
void triSelectEmp(Emprunt * tEmp, int nbEmp, char choix);
int rechminEN(Emprunt * tEmp, int nbEmp);
int rechminEP(Emprunt * tEmp, int nbEmp);
int rechminEJ(Emprunt * tEmp, int nbEmp);
void triInsertionAdh(Adherent * tAdh, int nbAdh);
int rechPosDichoAN(Adherent  * tAdh, int nbAdh, Adherent adh);
void bulleAdhP(Adherent  * tAdh, int nbAdh);
void bulleAdhD(Adherent  * tAdh, int nbAdh);
void bulleAdhnbE(Adherent  * tAdh, int nbAdh);
void bulleApremD(Aprem * tAprem, int nbAprem);
void bulleApremP(Aprem * tAprem, int nbAprem, char choix);
void bulleAdhApremD(AdhAprem * tAdhAprem, int nbAdhAprem);
void bulleAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
void rechJeu(ListeJ j, int nbJeux, Emprunt * tEmp, int nbEmp);
void rechAdh(Adherent * tAdh, int nbAdh, AdhAprem * tAdhAprem, int nbAdhAprem, Emprunt * tEmp, int nbEmp);
void rechAp(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem);
void affichMenu(void);
void affichGrandMenu(void);

ListeJ insererEnTete2(ListeJ triJeux, ListeJ j);
ListeJ triJeux(ListeJ j, int nbJeux, char choix);
ListeJ ajouter(ListeJ triJeux, ListeJ j, char choix);