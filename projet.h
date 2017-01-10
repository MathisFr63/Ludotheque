#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nom[20];
	char prenom[20];
	char date[12];
	char tel[11];
	char ville[30];
	int nbEmp;
	// int duree;
}Adherent;

typedef struct{
	char nom[20];
	char prenom[20];
	char jeux[30];
	char dateE[12];
	char dateR[12];
}Emprunt;

typedef struct{
	char date[12];
	char heure[6];
	int places;
	int placesL;
}Aprem;

typedef struct{
	char date[12];
	char heure[6];
	char nom[20];
	char prenom[20];
}AdhAprem;

typedef struct{
	char nom[30];
	int nbEx;
	int stock;
	char type[30];
}Jeux;

typedef struct cell{
	char nom[30];
	int nbEx;
	int stock;
	char type[30];
	struct cell * suiv;
}Cellule;

typedef Cellule * testJeux;

testJeux jVide(void);
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
Emprunt * newEmprunt(Emprunt *tEmp, int *nbEmp, Adherent * tAdh, int nbAdh, testJeux j);
Aprem lireAprem(FILE *fe);
Aprem *chargeAprem(char *nomFichier, int * nbAprem);
void afficheAprem(Aprem ap);
Aprem * newAprem(Aprem * tAprem, int * nbAprem);
void supprAprem(Aprem * tAprem, int * nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
void modifAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
AdhAprem lireAdhAprem(FILE *fe);
AdhAprem *chargeAdhAprem(char *nomFichier, int * nbAdhAprem);
void afficheAdhAprem(AdhAprem aap);
void afficheAdhAprem2(AdhAprem aap);
void afficheAdhAprem3(AdhAprem aap);
AdhAprem * newAdhAprem(AdhAprem * tAdhAprem, int * nbAdhAprem, Adherent * tAdh, int nbAdh, Aprem * tAprem, int nbAprem);
void supprAdhAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
testJeux newJeu(testJeux j, int *nbJeux);
testJeux supprJeu(testJeux j,int * nbJeux, char * nomJ);
testJeux modifJeu(testJeux j, Emprunt * tEmp, int nbEmp, char choix, char * nomJ);

testJeux lireJeux(FILE *fe);
testJeux chargeJeux(char *nomFichier, int * nbJeux, Emprunt * tEmp, int nbEmp);
testJeux insererEnTete(testJeux j);
void afficheJeux(testJeux j);

int rechJeux(testJeux j, char * jeu);
void rendreJeu(Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmpT, testJeux j);
int rechEmpruntJeu(Emprunt * tEmp, int nbEmpT, char * nom, char * prenom, char * jeu);
int rechAprem(Aprem * tAprem, int nbAprem, char * date, char * heure);
int rechAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char * date, char * heure, char * nom, char * prenom);
int verifDateEmprunt(Emprunt tEmp);
int triSelectEmp(Emprunt * tEmp, int nbEmp, char choix);
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
void rechJeu(testJeux j, int nbJeux, Emprunt * tEmp, int nbEmp);
void rechAdh(Adherent * tAdh, int nbAdh, AdhAprem * tAdhAprem, int nbAdhAprem, Emprunt * tEmp, int nbEmp);
void rechAp(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem);
void affichMenu(void);
void affichGrandMenu(void);

testJeux insererEnTete2(testJeux triJeux, testJeux j);
testJeux triJeux(testJeux j, int nbJeux, char choix);
testJeux ajouter(testJeux triJeux, testJeux j, char choix);