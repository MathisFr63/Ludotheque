#include <stdio.h>

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
Adherent lireAdherent(FILE *fe);
Emprunt lireEmp(FILE *fe);
Aprem lireAprem(FILE *fe);
AdhAprem lireAdhAprem(FILE *fe);
ListeJ lireJeux(FILE *fe);
Adherent *chargeTAdherent(char *nomFichier, int * nbAdh);
Emprunt *chargeTEmprunts(char *nomFichier, int * nbEmpT);
Aprem *chargeAprem(char *nomFichier, int * nbAprem);
AdhAprem *chargeAdhAprem(char *nomFichier, int * nbAdhAprem);
ListeJ chargeJeux(char *nomFichier, int * nbJeux, Emprunt * tEmp, int nbEmp);
ListeJ insererEnTete(ListeJ j);
Adherent * newAdherent(Adherent *tAdh,int *nbAdh);
Emprunt * newEmprunt(Emprunt *tEmp, int *nbEmp, Adherent * tAdh, int nbAdh, ListeJ j);
Aprem * newAprem(Aprem * tAprem, int * nbAprem);
AdhAprem * newAdhAprem(AdhAprem * tAdhAprem, int * nbAdhAprem, Adherent * tAdh, int nbAdh, Aprem * tAprem, int nbAprem);
ListeJ newJeu(ListeJ j, int *nbJeux);
void supprAdherent(Adherent * tAdh, int * nbAdh);
void rendreJeu(Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmpT, ListeJ j);
void supprAprem(Aprem * tAprem, int * nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
void supprAdhAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem);
ListeJ supprJeu(ListeJ j,int * nbJeux, char * nomJ);
void modifAdh(Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmp, AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
void modifAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
ListeJ modifJeu(ListeJ j, Emprunt * tEmp, int nbEmp, char choix, char * nomJ);
// Tri
void bulleAdhN(Adherent  * tAdh, int nbAdh);
void bulleAdhP(Adherent  * tAdh, int nbAdh);
void bulleAdhD(Adherent  * tAdh, int nbAdh);
void bulleAdhnbE(Adherent  * tAdh, int nbAdh);
void triSelectEmp(Emprunt * tEmp, int nbEmp, char choix);
int rechminEN(Emprunt * tEmp, int nbEmp);
int rechminEP(Emprunt * tEmp, int nbEmp);
int rechminEJ(Emprunt * tEmp, int nbEmp);
void bulleApremD(Aprem * tAprem, int nbAprem);
void bulleApremP(Aprem * tAprem, int nbAprem, char choix);
void bulleAdhApremD(AdhAprem * tAdhAprem, int nbAdhAprem);
void bulleAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char choix);
ListeJ triJeux(ListeJ j, int nbJeux, char choix);
ListeJ jVide(void);
ListeJ ajouter(ListeJ triJeux, ListeJ j, char choix);
ListeJ insererEnTete2(ListeJ triJeux, ListeJ j);
// Affichages données
void afficheAdh(Adherent adh, char choix);
void afficheEmp(Emprunt emp);
void afficheAprem(Aprem ap);
void afficheAdhAprem(AdhAprem aap, char choix);
void afficheJeux(ListeJ j);
// Vérifications
int rechAdherent(Adherent * tAdh, int nbAdh, char * nom, char * prenom);
int rechEmpruntJeu(Emprunt * tEmp, int nbEmpT, char * nom, char * prenom, char * jeu);
int rechAprem(Aprem * tAprem, int nbAprem, char * date, char * heure);
int rechAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char * date, char * heure, char * nom, char * prenom);
int rechJeux(ListeJ j, char * jeu);
int verifDateEmprunt(Emprunt tEmp);
int rechNbAD(Aprem *tAprem, int nbAprem, char * date);
// Recherche (choix 7)
void rechAdh(Adherent * tAdh, int nbAdh, AdhAprem * tAdhAprem, int nbAdhAprem, Emprunt * tEmp, int nbEmp);
void rechAp(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem);
void rechJeu(ListeJ j, int nbJeux, Emprunt * tEmp, int nbEmp);
// Sortie du programme
void save(Adherent * tAdh, Emprunt * tEmp, Aprem * tAprem, AdhAprem * tAdhAprem, ListeJ j, int nbAdh, int nbEmp, int nbAprem, int nbAdhAprem, int nbJeux);
ListeJ supprListeJeux(ListeJ j);
// Affichage Menus
void affichMenu(void);
void affichGrandMenu(void);