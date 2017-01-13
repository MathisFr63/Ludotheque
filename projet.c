#include "projet.h"

/*programme : projet.c
auteur: Mathis FRIZOT | Bernardo PEREIRA AUGUSTO | Pierre Lebon
date : 19/12/2016
finalité: Gestion d'une ludothèque
*/

/* Nom : choix
Finalité : lit et retourne le choix de l'utilisateur tout en effaçant les erreurs du flux
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: choix, choix de l'utilisateur
Variables : choix, choix de l'utilisateur
verif, caractère permettant de vérifier que l'utilisateur ai rentré un choix correct
*/
char saisirChoix(void){
	char choix, verif;

	scanf("%c", &choix);
	while (choix == ' ' || choix == '\t' || choix == '\n')
		scanf("%c", &choix);

	scanf("%c", &verif);
	if (verif != ' ' && verif != '\t' && verif != '\n')
		choix = '!';
	while (verif != '\n'){
		scanf("%c", &verif);
		if (verif != '\n')
			if (verif != ' ' && verif != '\t')
				choix = '!';
	}
	printf("Choix : \"%c\"\n", choix);
	return choix;
}

/* Nom : jVide
Finalité : retourne une liste vide
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: NULL
Variables : Aucune
*/
ListeJ jVide(void){
	return NULL;
}

/* Nom : lireEmp
Finalité : lit un emprunt grâce au fichier dans lequel sont stockés tout les emprunts
et stock les données dans un type Emprunt contenant le nom et le prénom de l'ahérent empruntant,
le nom du jeu emprunter, la date d'empunt, et la date de retour (sachant que la date de retour est "" si l'emprunt n'a pas était retourné)
Paramètres entrant: Aucun
Paramètres entrant-sortant: fe, flot contenant les emprunts
Valeur retourné: emp, Emprunt dans lequel ont été stockées les données
Variables : emp, Emprunt dans lequel ont été stockées les données
*/
Emprunt lireEmp(FILE *fe){
	Emprunt emp;

	fgets (emp.nom,21,fe);
	if (emp.nom[strlen(emp.nom)-1] == '\n')
		emp.nom[strlen(emp.nom)-1] = '\0';

	fgets (emp.prenom,21,fe);
	if (emp.prenom[strlen(emp.prenom)-1] == '\n')
		emp.prenom[strlen(emp.prenom)-1] = '\0';

	fgets (emp.jeux,21,fe);
	if (emp.jeux[strlen(emp.jeux)-1] == '\n')
		emp.jeux[strlen(emp.jeux)-1] = '\0';

	fgets (emp.dateE,12,fe);
	if (emp.dateE[strlen(emp.dateE)-1] == '\n')
		emp.dateE[strlen(emp.dateE)-1] = '\0';

	fgets (emp.dateR,12,fe);
	if (emp.dateR[strlen(emp.dateR)-1] == '\n')
		emp.dateR[strlen(emp.dateR)-1] = '\0';

	return emp;
}

/* Nom : chargeTEmprunts 
Finalité : charge un par un les Emprunt stockés dans un fichier prévu à cet effet,
et les stocks dans un tableau d'Emprunt grâce à l'appel de la fonction lireEmp
Paramètres entrant: Aucun
Paramètres entrant-sortant: nomFichier, nom du fichier dans lequel sont stockés touts les emprunts
nbEmp, nombre d'Emprunts au total étant stocké en tête du fichier
Valeur retourné: tEmp, tableau d'Emprunt
Variables : tEmp, tableau d'Emprunt
i, compteur permettant l'insertion des Emprunt au bon endroit dans le tableau
fe, flot contenant les Emprunts
*/
Emprunt *chargeTEmprunts(char * nomFichier, int * nbEmp){
	FILE * fe = fopen(nomFichier, "r");
	Emprunt * tEmp;
	int i;
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	fscanf (fe,"%d%*c",nbEmp);

	tEmp = (Emprunt *)malloc(*nbEmp * sizeof(Emprunt));
	if (tEmp == NULL){
		printf("Problème d'allocations mémoire\n");
		exit (1);
	}

	for(i = 0 ; i < *nbEmp; i++)
		tEmp[i]=lireEmp(fe);

	fclose(fe);
	return tEmp;
}

/* Nom : afficheEmp
Finalité : affiche un Emprunt (nom, prénom, jeu, date d'emprunt, date de retour (ou "non rendu"))
Paramètres entrant: emp, Emprunt à afficher
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/
void afficheEmp(Emprunt emp){

	if (strlen(emp.nom) > 7)
		printf("%s\t", emp.nom);
	else
		printf("%s\t\t", emp.nom);

	if (strlen(emp.prenom) > 7)
		printf("%s\t", emp.prenom);
	else
		printf("%s\t\t", emp.prenom);

	if (strlen(emp.jeux) > 7)
		printf("%s\t", emp.jeux);
	else
		printf("%s\t\t", emp.jeux);

	if (strcmp(emp.dateR,"") == 0)
		printf("%s\tNon rendu\n", emp.dateE);
	else
		printf("%s\t%s\n", emp.dateE, emp.dateR);
}

/* Nom : lireAdherent
Finalité : lit un adhérent grâce au fichier dans lequel sont stockés tout les adhérents
et stock les données dans un type Adherent contenant le nom, le prénom, la date de création,
le téléphone, la ville, et le nombre d'emprunts de l'ahérent
Paramètres entrant: Aucun
Paramètres entrant-sortant: fe, flot contenant les adhérents
Valeur retourné: adh, Adherent dans lequel ont été stockées les données
Variables : adh, Adherent dans lequel ont été stockées les données
*/
Adherent lireAdherent(FILE *fe){
	Adherent adh;

	fgets(adh.nom,21,fe);
	if (adh.nom[strlen(adh.nom)-1] == '\n')
		adh.nom[strlen(adh.nom)-1] = '\0';

	fgets(adh.prenom,21,fe);
	if (adh.prenom[strlen(adh.prenom)-1] == '\n')
		adh.prenom[strlen(adh.prenom)-1] = '\0';

	fgets(adh.date,12,fe);
	if (adh.date[strlen(adh.date)-1] == '\n')
		adh.date[strlen(adh.date)-1] = '\0';

	fgets(adh.tel,12,fe);
	if (adh.tel[strlen(adh.tel)-1] == '\n')
		adh.tel[strlen(adh.tel)-1] = '\0';

	fgets(adh.ville,31,fe);
	if (adh.ville[strlen(adh.ville)-1] == '\n')
		adh.ville[strlen(adh.ville)-1] = '\0';

	fscanf(fe,"%d ",&adh.nbEmp);


	return adh;
}

/* Nom : chargeTAdherent 
Finalité : charge un par un les Adherent stockés dans un fichier prévu à cet effet,
et les stockdans un tableau d'Adherent grâce à l'appel de la fonction lireAdherent
Paramètres entrant: Aucun
Paramètres entrant-sortant: nomFichier, nom du fichier dans lequel sont stockés touts les Adherent
nbAdh, nombre d'Adherent au total étant stocké en tête du fichier
Valeur retourné: tAdh, tableau d'Adherent
Variables : tAdh, tableau d'Adherent
i, compteur permettant l'insertion des Adherent au bon endroit dans le tableau
fe, flot contenant les Adherent
*/
Adherent *chargeTAdherent(char *nomFichier, int * nbAdh){
	FILE *fe = fopen(nomFichier, "r");
	Adherent * tAdh;
	int i;
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}
	fscanf(fe,"%d ",nbAdh);

	tAdh = (Adherent *)malloc(*nbAdh * sizeof(Adherent));
	if (tAdh == NULL){
		printf("Problème d'allocations mémoire\n");
		return;
	}

	for (i = 0 ; i < *nbAdh; i++){
		tAdh[i]=lireAdherent(fe);
	}

	fclose(fe);
	return tAdh;
}

/* Nom : afficheAdh
Finalité : affiche un Adherent (nom, prénom, jeu, date d'emprunt, date de retour (ou "non rendu"))
Paramètres entrant: adh, Adherent à afficher
choix, choix de l'affichage
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/
void afficheAdh(Adherent adh, char choix){
	if (choix == '1' || choix == '4'){
		if (strlen(adh.nom) > 7)
			printf("%s\t", adh.nom);
		else
			printf("%s\t\t", adh.nom);

		if (strlen(adh.prenom) > 7)
			printf("%s\t%s\t%s\t", adh.prenom, adh.date, adh.tel);
		else
			printf("%s\t\t%s\t%s\t", adh.prenom, adh.date, adh.tel);

		if (strlen(adh.ville) > 14)
			printf("%s\t%d\n", adh.ville, adh.nbEmp);
		else if (strlen(adh.ville) > 7 )
			printf("%s\t\t%d\n", adh.ville, adh.nbEmp);
		else
			printf("%s\t\t\t%d\n", adh.ville, adh.nbEmp);
	}

	else if (choix == '2'){
		if (strlen(adh.prenom) > 7)
			printf("%s\t", adh.prenom);
		else
			printf("%s\t\t", adh.prenom);

		if (strlen(adh.nom) > 7)
			printf("%s\t%s\t%s\t", adh.nom, adh.date, adh.tel);
		else
			printf("%s\t\t%s\t%s\t", adh.nom, adh.date, adh.tel);
		
		if (strlen(adh.ville) > 14)
			printf("%s\t%d\n", adh.ville, adh.nbEmp);
		else if (strlen(adh.ville) > 7 )
			printf("%s\t\t%d\n", adh.ville, adh.nbEmp);
		else
			printf("%s\t\t\t%d\n", adh.ville, adh.nbEmp);
	}

	else if (choix == '3'){
		if (strlen(adh.nom) > 7)
			printf("%s\t%s\t", adh.date, adh.nom);
		else
			printf("%s\t%s\t\t", adh.date, adh.nom);
		
		if (strlen(adh.prenom) > 7)
			printf("%s\t%s\t", adh.prenom, adh.tel);
		else
			printf("%s\t\t%s\t", adh.prenom, adh.tel);
		
		if (strlen(adh.ville) > 14)
			printf("%s\t%d\n", adh.ville, adh.nbEmp);
		else if (strlen(adh.ville) > 7 )
			printf("%s\t\t%d\n", adh.ville, adh.nbEmp);
		else
			printf("%s\t\t\t%d\n", adh.ville, adh.nbEmp);
	}
}

/* Nom : newAdherent
Finalité : Ajoute un Adherent dans le tableau d'Adherent et modifie le nombre total d'Adherent
Paramètres entrant: Aucun
Paramètres entrant-sortant: tAdh, tableau d'Adherent
nbAdh, nombre total d'Adherent
Valeur retourné: newAdh, tableau d'Adherent après modification (ou tAdh si l'Adherent existe déjà et qu'il n'y a aucune modification à faire)
Variables : newAdh, tableau d'Adherent après modification (ou tAdh si l'Adherent existe déjà et qu'il n'y a aucune modification à faire)
fe, flot dans lequel est écrit la date du jour, qui est ensuite lue afin de remplir automatiquement la date d'inscription
trouve, position de l'Adherent dans le tableau ou -1 si l'Adherent n'a as été trouvé
nom, nom de l'Adherent à inscrire
prenom, prénom de l'Adherent à inscrire
*/
Adherent * newAdherent(Adherent *tAdh, int *nbAdh){
	Adherent *newAdh;
	FILE * fe = fopen("date.txt", "r");
	int trouve;
	char nom[20], prenom[20];
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier \"date.txt\" en lecture\n");
		return tAdh;
	}

	newAdh = (Adherent *) realloc (tAdh,(*nbAdh+1) * sizeof(Adherent));
	if (newAdh == NULL){
		printf("Problème d'allocation mémoire\n");
		exit(1);
	}

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	trouve = rechAdherent(newAdh, *nbAdh, nom, prenom);

	if (trouve != -1){
		printf("\nL'adhérent %s %s existe déjà\n", newAdh[trouve].nom, newAdh[trouve].prenom);
		return tAdh;	
	}

	strcpy(newAdh[*nbAdh].nom, nom);
	strcpy(newAdh[*nbAdh].prenom, prenom);

	system("date +%Y-%m-%d>date.txt");
	fgets(newAdh[*nbAdh].date,12,fe);
	if (newAdh[*nbAdh].date[strlen(newAdh[*nbAdh].date)-1] == '\n')
		newAdh[*nbAdh].date[strlen(newAdh[*nbAdh].date)-1] = '\0';

	printf("Téléphone : ");
	fgets(newAdh[*nbAdh].tel,12,stdin);
	if (newAdh[*nbAdh].tel[strlen(newAdh[*nbAdh].tel)-1] == '\n')
		newAdh[*nbAdh].tel[strlen(newAdh[*nbAdh].tel)-1] = '\0';

	printf("Ville : ");
	fgets(newAdh[*nbAdh].ville,31,stdin);
	if (newAdh[*nbAdh].ville[strlen(newAdh[*nbAdh].ville)-1] == '\n')
		newAdh[*nbAdh].ville[strlen(newAdh[*nbAdh].ville)-1] = '\0';
	newAdh[*nbAdh].nbEmp = 0;

	(*nbAdh)++;
	fclose(fe);
	return newAdh;
}

/* Nom : supprAdherent
Finalité : supprime un Adherent du tableau d'Adherent lorsque celui-ci a été trouvé grâce à une recherche
et modifie le nombre total d'Adherent
Paramètres entrant: Aucun
Paramètres entrant-sortant: tAdh, tableau d'Adherent
nbAdh, nombre total d'Adherent
Valeur retourné: Aucune
Variables : nom, nom de l'Adherent à supprimer
prenom, prénom de l'Adherent à supprimer
pos, pos de l'adherent dans le tableau
i, compteur
*/
void supprAdherent(Adherent * tAdh, int * nbAdh){
	int pos, i;
	char nom[20],prenom[20];

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	pos = rechAdherent(tAdh, *nbAdh, nom, prenom);
	if(pos == -1){
		printf("\nL'adhérent %s %s n'a pas été trouvé\n", nom, prenom);
		return;
	}

	if (tAdh[pos].nbEmp != 0){
		printf("\nL'adhérent : %s %s a des emprunts en cours il doit les rendre avant de pouvoir être supprimer\n", tAdh[pos].nom, tAdh[pos].prenom);
		return;
	}
	
	for (i = pos; i < *nbAdh - 1; i++)
		tAdh[i] = tAdh[i+1];
	
	(*nbAdh)--;
}

/* Nom : modifAdh
Finalité : modifie les données d'un ahérents
Paramètres entrant: nbAdh, nombre total d'Adherent
nbEmp, nombre total d'Emprunt
nbAdhAprem, nombre total d'Adherent aux Après-midi thématiques
choix, choix de la modification sur l'Adherent (nom et/ou prénom, tel, ville)
Paramètres entrant-sortant: tAdh, tableau d'Adherent
tEmp, tableau d'Emprunt
tAdhAprem, tableau d'Adherent aux Après-midi thématiques
Valeur retourné: Aucune
Variables : nom, nom de l'Adherent à modifier
prenom, prénom de l'Adherent à modifier
tel, téléphone de l'Adherent à modifier
ville, ville de l'Adherent à modifier
pos, position dans le tableau d'Adherent de l'Adhernent à modifier
i, compteur
*/
void modifAdh (Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmp, AdhAprem * tAdhAprem, int nbAdhAprem, char choix){
	int pos, i;
	char nom[20], prenom[20], tel[11], ville[30];

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	pos = rechAdherent(tAdh, nbAdh, nom, prenom);
	if(pos == -1){
		printf("\nL'adhérent %s %s n'a pas été trouvé\n", nom, prenom);
		return;
	}

	if (choix == '3'){
		printf("\nAncien nom : %s\nAncien prénom : %s\n", tAdh[pos].nom, tAdh[pos].prenom);

		printf("! Si un élément n'est pas modifié vous pouvez mettre un ESPACE !\n");

		printf("Nouveau nom : ");
		fgets(nom,21,stdin);
		if (nom[strlen(nom)-1] == '\n')
			nom[strlen(nom)-1] = '\0';

		printf("Nouveau prénom : ");
		fgets(prenom,21,stdin);
		if (prenom[strlen(prenom)-1] == '\n')
			prenom[strlen(prenom)-1] = '\0';

		if (strcmp(nom, " ") == 0)
			strcpy(nom, tAdh[pos].nom);
		if (strcmp(prenom, " ") == 0)
			strcpy(prenom, tAdh[pos].prenom);

		for (i = 0; i < nbEmp; i++){
			if (strcasecmp(tEmp[i].nom, tAdh[pos].nom) == 0 && strcasecmp(tEmp[i].prenom, tAdh[pos].prenom) == 0){
				strcpy(tEmp[i].nom, nom);
				strcpy(tEmp[i].prenom, prenom);
			}
		}

		for (i = 0; i < nbAdhAprem; i++){
			if (strcasecmp(tAdhAprem[i].nom, tAdh[pos].nom) == 0 && strcasecmp(tAdhAprem[i].prenom, tAdh[pos].prenom) == 0){
				strcpy(tAdhAprem[i].nom, nom);
				strcpy(tAdhAprem[i].prenom, prenom);
			}
		}

		strcpy(tAdh[pos].nom, nom);
		strcpy(tAdh[pos].prenom, prenom);
	}

	if (choix == '4'){
		printf("\nAncien numéro de téléphone : %s\n", tAdh[pos].tel);

		printf("\n! Si vous ne voulez pas modifier le numéro de téléphone vous pouvez mettre un ESPACE !\n");

		printf("\nNouveau numéo de téléphone : ");
		fgets(tel,12,stdin);
		if (tel[strlen(tel)-1] == '\n')
			tel[strlen(tel)-1] = '\0';

		if (strcmp(tel, " ") != 0)
			strcpy(tAdh[pos].tel, tel);
	}

	if (choix == '5'){
	printf("Ancienne ville : %s\n", tAdh[pos].ville);

	printf("! Si vous ne voulez pas modifier la ville pouvez mettre un ESPACE !\n");

	printf("Nouvelle ville : ");
	fgets(ville,31,stdin);
	if (ville[strlen(ville)-1] == '\n')
			ville[strlen(ville)-1] = '\0';

	if (strcmp(ville, " ") != 0)
			strcpy(tAdh[pos].ville, ville);
	}
}

/* Nom : rechAdherent
Finalité : recherche de la position d'un Adherent dans un tableau d'Adherent grâce à son nom et à son prénom
Paramètres entrant: nbAdh, nombre total d'Adherent
Paramètres entrant-sortant: tAdh, tableau d'Adherent
nom, nom de l'Adherent à rechercher
prenom, prénom de l'Adherent à rechercher
Valeur retourné: i, position de l'Adherent dans le tableau ou -1 si l'Adherent n'a pas été trouvé
Variables : i, position de l'Adherent dans le tableau
*/
int rechAdherent(Adherent * tAdh, int nbAdh, char * nom, char * prenom){
	int i;

	for (i = 0; i < nbAdh; i++){
		if (strcasecmp(tAdh[i].nom,nom) == 0 && strcasecmp(tAdh[i].prenom,prenom) == 0)
			return i;
	}
	return -1;
}

/* Nom : rechJeux
Finalité : recherche de l'existance d'un Jeux dans une liste de Jeux grâce à son nom
Paramètres entrant: j, liste de Jeux
Paramètres entrant-sortant: jeu, nom du Jeux à rechercher
Valeur retourné: trouve, valeur supérieure à 0 lorsque le Jeux existe, -1 sinon
Variables : trouve, valeur supérieure à 0 lorsque le Jeux existe, -1 sinon
*/
int rechJeux(ListeJ j, char * jeu){
	int trouve = 0;

	while (j != NULL){
		if (strcasecmp(j->nom, jeu) == 0)
			return trouve;
		j = j->suiv;
		trouve++;
	}
	return -1;
}

/* Nom : rechEmpruntJeu
Finalité : Recherhe de la position d'un Emprunt dans un tableau d'Emprunt grâce au nom et au prénom de l'Adherent ainsi qu'au nom du jeu emprunté
Paramètres entrant: nbEmp, nombre total d'Emprunt
Paramètres entrant-sortant: tEmp, tableau d'Emprunt
nom, nom de l'Adherent dont on recherhe un emprunt
prenom, prénom de l'Adherent dont on recherche un emprunt
jeu, nom du jeu dont on recherche l'emprunt par un Adherent spécifique
Valeur retourné: i, position de l'Emprunt dans un tableau d'Emprunt ou -1 lorque l'Emprunt n'a pas été trouvé
Variables : i, position de l'Emprunt dans un tableau d'Emprunt
*/
int rechEmpruntJeu(Emprunt * tEmp, int nbEmp, char * nom, char * prenom, char * jeu){
	int i;

	for (i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].nom, nom) == 0 && strcasecmp(tEmp[i].prenom, prenom) == 0 && strcasecmp(tEmp[i].jeux, jeu) == 0)
			return i;
	}
	printf("\nL'emprunt du jeu : %s par %s %s n'a pas été trouvé\n", jeu, nom, prenom);
	return -1;
}

/* Nom : rechAprem
Finalité : Recherhe de la position d'un Aprem (après-midi thématique) dans un tableau d'Aprem
Paramètres entrant: nbAprem, nombre total d'Aprem
Paramètres entrant-sortant: tAprem, tableau d'Aprem
date, date de l'Aprem recherché
heure, heure de l'Aprem recherché
Valeur retourné: i, position de l'Aprem dans un tableau d'Aprem ou -1 lorque l'Aprem n'a pas été trouvé
Variables : i, position de l'Aprem dans un tableau d'Aprem
*/
int rechAprem(Aprem * tAprem, int nbAprem, char * date, char * heure){
	int i;

	for (i = 0; i < nbAprem; i++){
		if (strcasecmp(tAprem[i].date, date) == 0 && strcasecmp(tAprem[i].heure, heure) == 0)
			return i;
	}
	return -1;
}

/* Nom : rechAdhAprem
Finalité : Recherhche de la position d'un AdhAprem (adhérent à un après-midi thématique) dans un tableau d'AdhAprem
Paramètres entrant: nbAdhAprem, nombre total d'adhérents aux après-midi thématiques
Paramètres entrant-sortant: tAdhAprem, tableau d'AdhAprem
date, date de l'Aprem recehrché
heure, heure de l'Aprem recherché
nom, nom de l'Adherent recherché
prenom, prénom de l'Adherent recherché
Valeur retourné: i, position de l'AdhAprem dans un tableau d'AdhAprem ou -1 lorque l'AdhAprem n'a pas été trouvé
Variables : i, position de l'AdhAprem dans un tableau d'AdhAprem ou -1 lorque l'AdhAprem n'a pas été trouvé
*/
int rechAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char * date, char * heure, char * nom, char * prenom){
	int i;

	for (i = 0; i < nbAdhAprem; i++){
		if (strcasecmp(tAdhAprem[i].date, date) == 0 && strcasecmp(tAdhAprem[i].heure, heure) == 0 && strcasecmp(tAdhAprem[i].nom, nom) == 0 && strcasecmp(tAdhAprem[i].prenom, prenom) == 0)
			return i;			
	}
	return -1;
}

/* Nom : rendreJeu
Finalité : Permet à un Adherent de rendre un Jeux emprunter ultérieurement,
modifie ainsi le nombre d'emprunts en cours de cet adhérent et la date de retour de l'Emprunt
Paramètres entrant: nbAdh, nombre total d'Adherent
nbEmp, nombre total d'Emprunt
j, liste de Jeux
Paramètres entrant-sortant: tAdh, tableau d'Adherent
tEmp, tableau d'Emprunt
Valeur retourné: Aucune
Variables : nom, nom de l'Adherent voulant rendre/retourner un jeu
prenom, prénom de l'Adherent
jeu, nom du Jeux voulant être retourné
trouve, position de l'Emprunt dans un tableau d'Emprunt ou -1 si celui si n'a pas été trouvé
i, compteur
fe, flot dans lequel est écrit la date du jour, qui est ensuite lue afin de remplir automatiquement la date de retour
*/
void rendreJeu(Adherent * tAdh, int nbAdh, Emprunt * tEmp, int nbEmp, ListeJ j){
	FILE * fe = fopen("date.txt", "r");
	int trouve, i;
	char nom[20], prenom[20], jeu[30];

	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';
	
	printf("Jeu : ");
	fgets(jeu,21,stdin);
	if (jeu[strlen(jeu)-1] == '\n')
		jeu[strlen(jeu)-1] = '\0';

	trouve = rechEmpruntJeu(tEmp, nbEmp, nom, prenom, jeu);
	if (trouve == -1){
		return;
	}

	system("date +%Y-%m-%d>date.txt");
	fgets(tEmp[trouve].dateR,12,fe);
	if (tEmp[trouve].dateR[strlen(tEmp[trouve].dateR)-1] == '\n')
		tEmp[trouve].dateR[strlen(tEmp[trouve].dateR)-1] = '\0';

	trouve = rechAdherent(tAdh, nbAdh, nom, prenom);
	if (trouve == -1)
		return;
	tAdh[trouve].nbEmp--;
	
	trouve = rechJeux(j, jeu);
	if (trouve == -1){
		printf("Le jeu \"%s\" n'a pas été trouvé\n", jeu);
		return;
	}

	for (i = 0; i < trouve; i++)
		j = j->suiv;
	
	j->stock++;
	fclose(fe);
}

/* Nom : newEmprunt
Finalité : Enregistrer un nouvel Emprunt dans un tableau d'Emprunt
Paramètres entrant: nbAdh, nombre total d'Adherent
j, liste de Jeux
Paramètres entrant-sortant: tEmp, tableau d'Emprunt
nbEmp, nombre total d'Emprunt
tAdh, tableau d'Adherent
Valeur retourné: newEmp, nouveau tableau d'Emprunt après réallocation si l'Adherent a moins de 3 emprunts en cours,
que le Jeux et l'Adherent ont été trouvé et que le Jeux est encore en stock
Variables : newEmp, nouveau tableau d'Emprunt
date, date d'Emprunt
nom, nom de l'Adherent voulant emprunté
prenom, prénom de l'Adherent
jeu, nom du jeu voulant être emprunté
trouveAdh, position de l'Adherent dans un tableau d'Adherent
trouveJeu, position du Jeux dans une liste de Jeux
i, compteur
fe, flot dans lequel est écrit la date du jour, qui est ensuite lue afin de remplir automatiquement la date d'Emprunt
*/
Emprunt * newEmprunt(Emprunt *tEmp, int *nbEmp, Adherent * tAdh, int nbAdh, ListeJ j){
	FILE * fe = fopen("date.txt", "r");
	Emprunt *newEmp;
	int trouveAdh, trouveJeu, i;
	char date[11], nom[20], prenom[20], jeu[30];
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	newEmp = (Emprunt *) realloc (tEmp,(*nbEmp+1) * sizeof(Emprunt));
	if (newEmp == NULL){
		printf("Erreur lors de l'allocation mémoire\n");
		exit(1);
	}

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';

	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	trouveAdh = rechAdherent(tAdh, nbAdh, nom, prenom);
	if (trouveAdh == -1){
		printf("\nL'adhérent %s %s n'a pas été trouvé\n", nom, prenom);
		return tEmp;
	}

	if (tAdh[trouveAdh].nbEmp == 3){
		printf("\nL'adhérent : %s %s a déjà 3 emprunts non rendus il doit rendre un jeu avant de pouvoir emprunter à nouveau\n", tAdh[trouveAdh].nom, tAdh[trouveAdh].prenom);
		return tEmp;
	}

	printf("Jeux : ");
	fgets(jeu,21,stdin);
	if (jeu[strlen(jeu)-1] == '\n')
		jeu[strlen(jeu)-1] = '\0';

	trouveJeu = rechJeux(j, jeu);
	if (trouveJeu == -1){
		printf("\nLe jeu %s n'a pas été trouvé\n", jeu);
		return tEmp;
	}

	for (i = 0; i < trouveJeu; i++)
		j = j->suiv;
	
	if (j->stock == 0){
		printf("\nLe jeu \"%s\" n'est plus en stock. Revenez plus tard\n", j->nom);
		return tEmp;
	}

	strcpy(newEmp[*nbEmp].nom, tAdh[trouveAdh].nom);
	strcpy(newEmp[*nbEmp].prenom, tAdh[trouveAdh].prenom);
	strcpy(newEmp[*nbEmp].jeux, j->nom);
	
	system("date +%Y-%m-%d>date.txt");
	fgets(newEmp[*nbEmp].dateE,12,fe);
	if (newEmp[*nbEmp].dateE[strlen(newEmp[*nbEmp].dateE)-1] == '\n')
		newEmp[*nbEmp].dateE[strlen(newEmp[*nbEmp].dateE)-1] = '\0';
	strcpy(newEmp[*nbEmp].dateR,"");

	tAdh[trouveAdh].nbEmp++;
	j->stock--;

	(*nbEmp)++;
	fclose(fe);
	return newEmp;
}

/* Nom : lireAprem
Finalité : lit un Aprem grâce au fichier dans lequel sont stockés tout les après-midi thématiques
et stock les données dans un type Aprem contenant la date, l'heure, le nombre de places, et le nombre de places libres de chaque Aprem
Paramètres entrant: Aucun
Paramètres entrant-sortant: fe, flot contenant les après-midi thématiques
Valeur retourné: ap, Aprem dans lequel ont été stockées les données
Variables : ap, Aprem dans lequel ont été stockées les données
*/
Aprem lireAprem(FILE *fe){
	Aprem ap;
	fscanf(fe,"%s %s %d %d%*c", ap.date, ap.heure, &ap.places, &ap.placesL);

	return ap;
}

/* Nom : chargeAprem
Finalité : charge un par un les Aprem stockés dans un fichier prévu à cet effet,
et les stocks dans un tableau d'Aprem grâce à l'appel de la fonction lireAprem
Paramètres entrant: Aucun
Paramètres entrant-sortant: nomFichier, nom du fichier dans lequel sont stockés touts les Aprem
nbAprem, nombre d'Aprem au total étant stocké en tête du fichier
Valeur retourné: tAprem, tableau d'Aprem
Variables : tAprem, tableau d'Aprem
i, compteur permettant l'insertion des Aprem au bon endroit dans le tableau
fe, flot contenant les Aprem
*/
Aprem *chargeAprem(char *nomFichier, int * nbAprem){
	FILE *fe = fopen(nomFichier,"r");
	Aprem * tAprem;
	int i;
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	fscanf(fe,"%d%*c",nbAprem);

	tAprem = (Aprem *)malloc(*nbAprem * sizeof(Aprem));
	if (tAprem == NULL){
		printf("Problème d'allocations mémoire\n");
		return;
	}

	for (i = 0 ; i < *nbAprem; i++){
		tAprem[i]=lireAprem(fe);
	}

	fclose(fe);
	return tAprem;
}

/* Nom : afficheAprem
Finalité : affiche un Aprem (date, heure, nombre de places totales, nombre de places libres)
Paramètres entrant: ap, Aprem à afficher
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/
void afficheAprem(Aprem ap){
	printf("%s\t%s\t%d\t%d\n", ap.date, ap.heure, ap.places, ap.placesL);
}

/* Nom : newAprem
Finalité : Ajoute un Aprem dans le tableau d'Aprem et modifie le nombre total d'Aprem
Paramètres entrant: Aucun
Paramètres entrant-sortant: tAprem, tableau d'Aprem
nbAprem, nombre total d'Aprem
Valeur retourné: newAprem, tableau d'Aprem après modification (ou tAprem si l'Aprem existe déjà et qu'il n'y a aucune modification à faire)
Variables : newAprem, tableau d'Aprem après modification (ou tAprem si l'Aprem existe déjà et qu'il n'y a aucune modification à faire)
trouve, position de l'Aprem dans le tableau d'Aprem ou -1 si l'Aprem n'a pas été trouvée
date, date de l'Aprem à créer
heure, heure de l'Aprem à créer
*/
Aprem * newAprem(Aprem * tAprem, int * nbAprem){  // L'APREM NE DOIT PAS DEJA EXISTER
	Aprem *newAprem;
	int trouve;
	char date[11], heure[5];

	newAprem = (Aprem *) realloc (tAprem,(*nbAprem+1) * sizeof(Aprem));
	if(newAprem == NULL){
		printf("Erreur lors de l'allocation mémoire\n");
		exit(1);
	}

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s", heure);

	
	trouve = rechAprem(newAprem, *nbAprem, date, heure);
	if (trouve != -1){
		printf("\nL'après-midi thématique du %s à %s existe déjà\n", date, heure);
		return tAprem;
	}

	strcpy(newAprem[*nbAprem].date, date);
	strcpy(newAprem[*nbAprem].heure, heure);
	printf("Places : ");
	fscanf(stdin,"%d", &newAprem[*nbAprem].places);
	newAprem[*nbAprem].placesL = newAprem[*nbAprem].places;

	(*nbAprem)++;
	return newAprem;
}

/* Nom : supprAprem
Finalité : supprime un Aprem du tableau d'Aprem lorsque celui-ci a été trouvé grâce à une recherche et qu'il n'y a aucun inscrit,
et modifie le nombre total d'Aprem
Paramètres entrant: Aucun
Paramètres entrant-sortant: tAprem, tableau d'Aprem
tAdhAprem, tableau d'AdhAprem
nbAprem, nombre total d'Aprem
nbAdhAprem, nombre total d'AdhAprem
Valeur retourné: Aucune
Variables : date, date de l'Aprem à supprimer
heure, heure de l'Aprem à supprimer
choix, choix de l'utilisateur quant à la suppression lorque l'Aprem existe mais que des adhérents sont inscrits
trouve, position de l'Aprem dans le tableau d'Aprem ou -1 si l'Aprem n'a pas été trouvée
i, compteur
j, compteur
*/
void supprAprem(Aprem * tAprem, int * nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem){
	int trouve, i, j;
	char date[11], heure[5], choix;

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s", heure);
	
	trouve = rechAprem(tAprem, *nbAprem, date, heure);
	if (trouve == -1){
		printf("\nL'après-midi thématique du %s à %s n'existe pas\n", date, heure);
		return;
	}

	if (tAprem[trouve].places - tAprem[trouve].placesL != 0){
		printf("\nDes adhérents sont inscrits à l'après-midi thématique du %s à %s\n", date, heure);
		printf("\nVoulez-vous vraiment supprimer cet après-midi thématique (O/N) ?");
		choix = saisirChoix();
		
		while (choix != 'O' && choix != 'o' && choix != 'N' && choix != 'n'){
			printf("Vous-devez répondre par 'O' ou 'N' retapez : ");
			choix = saisirChoix();
		}

		if (choix == 'N' || choix == 'n')
			return;
	}

	for (i = trouve; i < *nbAprem - 1; i++)
		tAprem[i] = tAprem[i+1];

	for (i = 0; i < *nbAdhAprem - 1; i++){
		if (strcasecmp(tAdhAprem[i].date, date) == 0 && strcasecmp(tAdhAprem[i].heure, heure) == 0){
			for (j = i; j < *nbAdhAprem; j++)
				tAdhAprem[j] = tAdhAprem[j+1];
			(nbAdhAprem)--;
		}
	}

	(*nbAprem)--;
}

/* Nom : modifAprem
Finalité : modifie les données d'un après-midi thématique
Paramètres entrant: nbAprem, nombre total d'Aprem
nbAdhAprem, nombre total d'Adherent aux Après-midi thématiques
choix, choix de la modification sur l'Aprem (nom et/ou heure, nombre de places)
Paramètres entrant-sortant: tAprem, tableau d'Aprem
tAdhAprem, tableau d'Adherent aux Après-midi thématiques
Valeur retourné: Aucune
Variables : date, date de l'Aprem à modifier puis date modifiée
heure, heure de l'Aprem à modifier puis heure modifiée
pos, position de l'Aprem à modifier dans le tableau d'Aprem
i, compteur
diff, différence entre l'ancien et le nouveau nombre de places
permettant de vérifier si le nombre de places peut-être midifier en fonction du nombre d'Adherent déjà inscrits
*/
void modifAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem, char choix){
	char date[11], heure[5];
	int pos, i, newplaces, diff;

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s%*c", heure);

	pos = rechAprem(tAprem, nbAprem, date, heure);
	if (pos == -1){
		printf("\nL'après-midi thématique du %s à %s n'existe pas\n", date, heure);
		return;
	}

	if (choix == '3'){
		printf("\nAncienne date : %s\nAncienne heure : %s\n", date, heure);

		printf("\n! Si un élément n'est pas à modifier vous pouvez mettre un ESPACE !\n");

		printf("\nNouvelle date (AAAA-MM-JJ) : ");
		fgets(date, 12, stdin);
		if (date[strlen(date)-1] == '\n')
			date[strlen(date)-1] = '\0';
		
		printf("Nouvelle heure (HH:MM) : ");
		fgets(heure, 12, stdin);
		if (heure[strlen(heure)-1] == '\n')
			heure[strlen(heure)-1] = '\0';

		if (strcmp(date, " ") == 0)
			strcpy(date, tAprem[pos].date);
		
		if (strcmp(heure, " ") == 0)
			strcpy(heure, tAprem[pos].heure);

		for (i = 0; i < nbAdhAprem; i++){
			if (strcasecmp(tAdhAprem[i].date, tAprem[pos].date) == 0 && strcasecmp(tAdhAprem[i].heure, tAprem[pos].heure) == 0){
				strcpy(tAdhAprem[i].date, date);
				strcpy(tAdhAprem[i].heure, heure);
			}
		}

		strcpy(tAprem[pos].date, date);
		strcpy(tAprem[pos].heure, heure);
	}

	if (choix == '4'){
		printf("\nAncien nombre de places : %d\n", tAprem[pos].places);

		printf("\nNouveau nombre de places : ");
		scanf("%d%*c", &newplaces);

		diff = newplaces - tAprem[pos].places;
		if (tAprem[pos].placesL + diff < 0){
			printf("\nVous ne pouvez pas diminuer le nombre de places trop d'adhérents sont inscrits\n");
			return;
		}

		tAprem[pos].places = newplaces;
		tAprem[pos].placesL += diff; 
	}
}

/* Nom : lireAdhAprem
Finalité : lit un AdhAprem (adhérent à un après-midi thématique) grâce au fichier dans lequel sont stockés tout les adhérents aux après-midi thématiques
et stock les données dans un type AdhAprem contenant la date et l'heure de l'après-midi thématique, et le nom et le prénom de l'adhérent
Paramètres entrant: Aucun
Paramètres entrant-sortant: fe, flot contenant les adhérents aux après-midi thématiques
Valeur retourné: aap, AdhAprem dans lequel ont été stockées les données
Variables : aap, AdhAprem dans lequel ont été stockées les données
*/
AdhAprem lireAdhAprem(FILE *fe){
	AdhAprem aap;

	fscanf(fe,"%s %s%*c", aap.date, aap.heure);
	fgets(aap.nom,21,fe);
	if (aap.nom[strlen(aap.nom)-1] == '\n')
		aap.nom[strlen(aap.nom)-1] = '\0';
	fgets(aap.prenom,21,fe);
	if (aap.prenom[strlen(aap.prenom)-1] == '\n')
		aap.prenom[strlen(aap.prenom)-1] = '\0';

	return aap;
}

/* Nom : chargeAdhAprem
Finalité : charge un par un les AdhAprem stockés dans un fichier prévu à cet effet,
et les stocks dans un tableau d'AdhAprem grâce à l'appel de la fonction lireAdhAprem
Paramètres entrant: Aucun
Paramètres entrant-sortant: nomFichier, nom du fichier dans lequel sont stockés touts les AdhAprem
nbAdhAprem, nombre d'AdhAprem au total étant stocké en tête du fichier
Valeur retourné: tAdhAprem, tableau d'AdhAprem
Variables : tAdhAprem, tableau d'AdhAprem
i, compteur permettant l'insertion des AdhAprem au bon endroit dans le tableau
fe, flot contenant les AdhAprem
*/
AdhAprem *chargeAdhAprem(char *nomFichier, int * nbAdhAprem){
	AdhAprem * tAdhAprem;
	int i;
	FILE *fe = fopen(nomFichier,"r");
	
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	fscanf(fe,"%d%*c",nbAdhAprem);

	tAdhAprem = (AdhAprem *)malloc(*nbAdhAprem * sizeof(AdhAprem));
	if (tAdhAprem == NULL){
		printf("Problème d'allocations mémoire\n");
		return;
	}

	for (i = 0 ; i < *nbAdhAprem; i++){
		tAdhAprem[i]=lireAdhAprem(fe);
	}

	fclose(fe);
	return tAdhAprem;
}

/* Nom : afficheAdhAprem
Finalité : affiche un AdhAprem (date, heure, nom, prénom)
Paramètres entrant: aap, AdhAprem à afficher
choix, choix de l'utilisateur concernant l'affichage
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/
void afficheAdhAprem(AdhAprem aap, char choix){
	if (choix == '1'){
		printf("%s\t%s\t", aap.date, aap.heure);
		if(strlen(aap.nom) > 7)
			printf("%s\t%s\n", aap.nom, aap.prenom);
		else
			printf("%s\t\t%s\n", aap.nom, aap.prenom);
	}

	else if (choix == '2'){
		if (strlen(aap.nom) > 7)
			printf("%s\t", aap.nom);
		else
			printf("%s\t\t", aap.nom);
		if (strlen(aap.prenom) > 7)
			printf("%s\t%s\t%s\n", aap.prenom, aap.date, aap.heure);
		else
			printf("%s\t\t%s\t%s\n", aap.prenom, aap.date, aap.heure);
	}

	else if (choix == '3'){
		if (strlen(aap.prenom) > 7)
			printf("%s\t", aap.prenom);
		else
			printf("%s\t\t", aap.prenom);
		if (strlen(aap.nom) > 7)
			printf("%s\t%s\t%s\n", aap.nom, aap.date, aap.heure);
		else
			printf("%s\t\t%s\t%s\n", aap.nom, aap.date, aap.heure);
	}
}

/* Nom : newAdhAprem
Finalité : Ajoute un AdhAprem dans le tableau d'AdhAprem et modifie le nombre total d'AdhAprem
Paramètres entrant: nbAdh, nombre total d'Adherent
nbAprem, nombre total d'Aprem
Paramètres entrant-sortant: tAdhAprem, tableau d'AdhAprem
tAdh, tableau d'Adherent
tAprem, tableau d'Aprem
nbAdhAprem, nombre total d'AdhAprem
Valeur retourné: newAdhAprem, tableau d'AdhAprem après modification (ou tAdhAprem si l'Aprem ou l'Adherent n'ont pas été trouvés ou si l'Adherent est déjà inscrit ou si il n'y a plus de places libres)
Variables : newAdhAprem, tableau d'AdhAprem après modification (ou tAdhAprem si l'Aprem ou l'Adherent n'ont pas été trouvés ou si l'Adherent est déjà inscrit ou si il n'y a plus de places libres)
date, date de l'Aprem recherchée
heure, heure de l'Aprem recherchée
nom, nom de l'Adherent à inscrire pour cet Aprem
prenom, prénom de l'Adherent
trouveAdh, position de l'Adherent dans le tableau d'Adherent
trouveAprem, position de l'Aprem dans le tableau d'Aprem
trouveAdhAprem, position de l'AdhAprem dans le tableau d'AdhAprem
*/
AdhAprem * newAdhAprem(AdhAprem * tAdhAprem, int * nbAdhAprem, Adherent * tAdh, int nbAdh, Aprem * tAprem, int nbAprem){
	AdhAprem *newAdhAprem;
	char date[11], heure[5], nom[20], prenom[20];
	int trouveAdh, trouveAprem, trouveAdhAprem;

	newAdhAprem = (AdhAprem *) realloc (tAdhAprem,(*nbAdhAprem+1) * sizeof(AdhAprem));
	if(newAdhAprem == NULL){
		printf("Erreur lors de l'allocation mémoire\n");
		exit(1);
	}

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s%*c", heure);

	trouveAprem = rechAprem(tAprem, nbAprem, date, heure);

	if (trouveAprem == -1){
		printf("\nL'après-midi thématique du %s à %s est introuvable\n", date, heure);
		return tAdhAprem;
	}
	if (tAprem[trouveAprem].placesL == 0){
		printf("\nIl n'y a plus de places libres pour cet après-mid thématique\n");
		return tAdhAprem;
	}

	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	trouveAdh = rechAdherent(tAdh, nbAdh, nom, prenom);

	if (trouveAdh == -1){
		printf("\nL'adhérent : %s %s n'existe pas\n", nom, prenom);
		return tAdhAprem;
	}

	trouveAdhAprem = rechAdhAprem(newAdhAprem, *nbAdhAprem, date, heure, nom, prenom);
	if (trouveAdhAprem != -1){
		printf("\nL'adhérent : %s %s est déjà inscrit à cet après-midi thématique\n", tAdhAprem[trouveAdhAprem].nom, tAdhAprem[trouveAdhAprem].prenom);
		return tAdhAprem;
	}

	strcpy(newAdhAprem[*nbAdhAprem].date, date);
	strcpy(newAdhAprem[*nbAdhAprem].heure, heure);
	strcpy(newAdhAprem[*nbAdhAprem].nom, tAdh[trouveAdh].nom);
	strcpy(newAdhAprem[*nbAdhAprem].prenom, tAdh[trouveAdh].prenom);
	tAprem[trouveAprem].placesL--;

	(*nbAdhAprem)++;
	return newAdhAprem;
}

/* Nom : supprAdhAprem
Finalité : supprime un AdhAprem du tableau d'Aprem lorsque celui-ci a été trouvé grâce à une recherche,
puis modifie le nombre total d'AdhAprem
Paramètres entrant: nbAprem, nombre total d'Aprem
Paramètres entrant-sortant: tAprem, tableau d'Aprem
tAdhAprem, tableau d'AdhAprem
nbAdhAprem, nombre total d'AdhAprem
Valeur retourné: Aucune
Variables : date, date de l'AdhAprem à supprimer
heure, heure de l'AdhAprem à supprimer
nom, nom de l'adhérent à l'apès-midi thématique à supprimer
prenom, prénom de l'adhérent à l'apès-midi thématique à supprimer
trouveAdhAprem, position de l'AdhAprem dans le tableau d'AdhAprem ou -1 si l'AdhAprem n'a pas été trouvée
trouveAprem, position de l'Aprem dans le tableau d'Aprem ou -1 si l'Aprem n'a pas été trouvée
i, compteur
*/
void supprAdhAprem(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int * nbAdhAprem){
	char date[11], heure[5], nom[20], prenom[20];
	int trouveAprem, trouveAdhAprem, i;

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s%*c", heure);
	
	printf("Nom : ");
	fgets(nom,21,stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	
	printf("Prénom : ");
	fgets(prenom,21,stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	trouveAprem = rechAprem(tAprem, nbAprem, date, heure);
	if (trouveAprem == -1){
		printf("\nL'après-midi thématique du %s à %s est introuvable\n", date, heure);
		return;
	}

	trouveAdhAprem = rechAdhAprem(tAdhAprem, *nbAdhAprem, date, heure, nom, prenom);
	if (trouveAdhAprem == -1){
		printf("\nL'adhérent : %s %s n'est pas inscrit à cet après-midi thématique\n", nom, prenom);
		return;
	}

	for (i = trouveAdhAprem; i < *nbAdhAprem - 1; i++)
		tAdhAprem[i] = tAdhAprem[i+1];

	tAprem[trouveAprem].placesL++;
		
	(*nbAdhAprem)--;
}

/* Nom : lireJeux
Finalité : lit un Jeux grâce au fichier dans lequel sont stockés tout les jeux
et stock les données dans une liste de jeux contenant le nom, le nombre d'exemplaires, le stock restant et le type du jeu
Paramètres entrant: Aucun
Paramètres entrant-sortant: fe, flot contenant les jeux
Valeur retourné: jeu, liste de jeux dans laquelle ont été stockées les données
Variables : jeu, liste de jeux dans laquelle ont été stockées les données
*/
ListeJ lireJeux(FILE *fe){
	ListeJ jeu;

	fread(jeu->nom, 30, 1, fe);
	fread(&jeu->nbEx, 4, 1, fe);
	jeu->stock = jeu->nbEx;
	fread(jeu->type, 30, 1, fe);


	return jeu;
}

/* Nom : chargeJeux
Finalité : charge un par un les jeux stockés dans un fichier prévu à cet effet,
et les stocks dans une liste de jeux grâce à l'appel de la fonction lireJeux
Paramètres entrant: nbEmp, nombre total d'Emprunt
Paramètres entrant-sortant: nomFichier, nom du fichier dans lequel sont stockés touts les jeux
nbJeux, nombre de jeux au total étant stocké en tête du fichier
tEmp, tableau d'Emprunt
Valeur retourné: jeux, liste de jeux
Variables : jeux, liste de jeux
fe, flot contenant les jeux
i, compteur permettant l'insertion des jeux un par un en tête de liste
j, compteur permettant la mise à jour du stock de chaque jeux
*/
ListeJ chargeJeux(char * nomFichier, int * nbJeux, Emprunt * tEmp, int nbEmp){
	FILE *fe = fopen(nomFichier,"rb");
	ListeJ jeux;
	int i, j;
	
	if(fe == NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}

	fscanf(fe,"%d%*c",nbJeux);

	for (i = 0; i < *nbJeux; i++){
		jeux = insererEnTete(jeux);
		jeux = lireJeux(fe);
		for(j = 0 ; j < nbEmp; j++){
			if (strcasecmp(tEmp[j].jeux, jeux->nom) == 0 && strcmp(tEmp[j].dateR, "") == 0){
				jeux->stock--;
			}
		}
	}

	fclose(fe);
	return jeux;
}

/* Nom : insererEnTete
Finalité : insertion d'un jeux (Cellule) en tête de liste
Paramètres entrant: j, liste de jeux
Paramètres entrant-sortant: Aucun
Valeur retourné: tmp, pointeur sur Cellule (liste de jeux) allouée et pointant avec son pointeur "suivant" sur la liste j
Variables : tmp, pointeur sur Cellule (liste de jeux) allouée et pointant avec son pointeur "suivant" sur la liste j
*/
ListeJ insererEnTete(ListeJ j){
	Cellule * tmp;

	tmp = (Cellule*)malloc(sizeof(Cellule));
		if (tmp == NULL){
			printf("Prblème lors de l'allocation mémoire\n");
			exit(1);
		}
	
	tmp->suiv = j;

	return tmp;
}

/* Nom : insererEnTete
Finalité : insertion des jeux de la liste j dans la liste triJeux mais triés
Paramètres entrant: j, liste de jeux
triJeux, liste de jeux dans laquelle les jeux sont triés
Paramètres entrant-sortant: Aucun
Valeur retourné: tmp, pointeur sur Cellule (liste de jeux) allouée et pointant avec son pointeur "suivant" sur la liste triJeux. Les valeurs de tmp sont les valeurs de j
Variables : tmp, pointeur sur Cellule (liste de jeux) allouée et pointant avec son pointeur "suivant" sur la liste triJeux. Les valeurs de tmp sont les valeurs de j
*/
ListeJ insererEnTete2(ListeJ triJeux, ListeJ j){
	Cellule * tmp;

	tmp = (Cellule*)malloc(sizeof(Cellule));
		if (tmp == NULL){
			printf("Prblème lors de l'allocation mémoire\n");
			exit(1);
		}
	
	strcpy(tmp->nom, j->nom);
	tmp->nbEx = j->nbEx;
	tmp->stock = j->stock;
	strcpy(tmp->type, j->type);
	tmp->suiv = triJeux;

	return tmp;
}

/* Nom : afficheJeux
Finalité : affiche un jeu (nom, nombre d'exemplaires, stock, type)
Paramètres entrant: j, liste de jeux 
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/
void afficheJeux(ListeJ j){
	while (j != NULL){
		if(strlen(j->nom) > 14)
			printf("%s\t%d\t\t%d\t%s\n", j->nom, j->nbEx, j->stock, j->type);
		
		else if(strlen(j->nom) > 7)
			printf("%s\t\t%d\t\t%d\t%s\n", j->nom, j->nbEx, j->stock, j->type);
		
		else
			printf("%s\t\t\t%d\t\t%d\t%s\n", j->nom, j->nbEx, j->stock, j->type);
	
		j = j->suiv;
	}
}

/* Nom : newJeu
Finalité : Ajoute un jeu dans la liste de jeux j et modifie le nombre total de jeux
Paramètres entrant: j, liste de jeux
Paramètres entrant-sortant: nbJeux, nombre total de jeux
Valeur retourné: j, liste de jeux modifiée ou non selon le respect des contraintes (le jeu ne doit pas déjà exister)
Variables : jeu, nom du nouveau jeu à enregistrer
trouve, valeur de la recherche du nouveau jeu dans la liste de jeux (-1 si le jeu n'existe pas encore; un nombre positif sinon)
*/
ListeJ newJeu(ListeJ j,int * nbJeux){
	int trouve;
	char jeu[30];

	printf("Nom : ");
	fgets(jeu,30,stdin);
	if (jeu[strlen(jeu)-1] == '\n')
		jeu[strlen(jeu)-1] = '\0';
	
	trouve = rechJeux(j, jeu);
	if (trouve != -1){
		printf("\nLe jeu : %s existe déjà\n", jeu);
		return j;
	}

	j = insererEnTete(j);

	strcpy(j->nom, jeu);
	
	printf("Exemplaires : ");
	fscanf(stdin,"%d%*c", &j->nbEx);
	j->stock = j->nbEx;
	
	printf("1- Jeux de plateforme | 2- Jeux de cartes | 3- Jeux de construction | 4- Jeux de logique |\n");
	
	printf("Type (tapez un chiffre ou le type souhaité) : ");
	fgets(j->type,21,stdin);
	if (j->type[strlen(j->type)-1] == '\n')
		j->type[strlen(j->type)-1] = '\0';

	if (strcmp(j->type, "1") == 0)
		strcpy(j->type, "Jeux de plateforme");
	
	else if (strcmp(j->type, "2") == 0)
		strcpy(j->type, "Jeux de cartes");
	
	else if (strcmp(j->type, "3") == 0)
		strcpy(j->type, "Jeux de construction");
	
	else if (strcmp(j->type, "4") == 0)
		strcpy(j->type, "Jeux de logique");

	(*nbJeux)++;
	return j;
}

/* Nom : supprJeu
Finalité : supprime un jeu de la liste de jeux lorsque celui-ci a été trouvé grâce à une recherche,
puis modifie le nombre total de jeux
Paramètres entrant: j, liste de jeux
Paramètres entrant-sortant: nbJeux, nombre total de jeux
nomJ, nom du jeu à supprimer
Valeur retourné: j, liste de jeux
Variables : tmp, pointeur sur Cellule (liste de jeux) permettant la suppression d'un jeu de la liste et la libération de la mémoire pour ce jeu qui n'est plus utile
*/
ListeJ supprJeu(ListeJ j, int * nbJeux, char * nomJ){
	Cellule * tmp;
	int comp;

	comp = strcasecmp(j->nom, nomJ);

	if (j == NULL || comp > 0){
		printf("Le jeu \"%s\" n'a pas été trouvé\n", nomJ);
		return j;
	}

	if (comp == 0){
		if (j->nbEx - j->stock != 0){
			printf("Le jeu :\"%s\" ne peux pas être supprimé car il est en cours d'emprunt\n", j->nom);
			return j;
		}

		tmp = j;
		j = j->suiv;

		free(tmp);

		(*nbJeux)--;

		return j;
	}

	j->suiv = supprJeu(j->suiv, nbJeux, nomJ); 
	return j;
}

/* Nom : modifJeu
Finalité : modifie les données d'un jeu et les emprunts associés
Paramètres entrant: nbEmp, nombre total d'Emprunt
j, liste de jeux
choix, choix de la modification (nom du jeu ou nombre d'exemplaires)
Paramètres entrant-sortant: tEmp, tableau d'Emprunt
nomJ, nom du jeu à modifier
Valeur retourné: j, liste de jeux (modifier ou non selon si les contraintes sont respectés car le nom du jeu ne doit pas déjà exister
et le nombre d'exemplaires e doit pas conduire à un stock négatif)
Variables : i, compteur
trouve, position du jeu dans la liste de jeux
diff, différence entre l'ancien nombre d'exemplaires et le nouveau permettant de vérifier que e stock n'est pas négatif
nb, nouveau nombre d'exemplaires
*/
ListeJ modifJeu(ListeJ j, Emprunt * tEmp, int nbEmp, char choix, char * nomJ){
	int i, trouve, diff, nb;

	if (j == NULL || strcasecmp(j->nom, nomJ) > 0){
		printf("Le jeu \"%s\" n'a pas était trouvé\n", nomJ);
		return j;
	}

	if (choix == '3'){
		if (strcasecmp(j->nom, nomJ) == 0){
			printf("Ancien nom : %s\n", j->nom);
	
			printf("! Si vous ne voulez pas modifier le nom du jeu vous pouvez mettre un ESPACE !\n");
	
			printf("Nouveau nom : ");
			fgets(nomJ, 31, stdin);
			if (nomJ[strlen(nomJ)-1] == '\n')
				nomJ[strlen(nomJ)-1] = '\0';
	
			if (strcmp(nomJ, " ") == 0)
				return j;
	
			trouve = rechJeux(j, nomJ);
			if (trouve != -1){
				printf("Un jeu possède déjà le nom : \"%s\" !\n", nomJ);
				return j;
			}
	
			for (i = 0; i < nbEmp; i++){
				if (strcasecmp(tEmp[i].jeux, j->nom) == 0)
					strcpy(tEmp[i].jeux, nomJ);
			}

			strcpy(j->nom, nomJ);

			return j;
		}
	}

	if (choix == '4'){
		if (strcasecmp(j->nom, nomJ) == 0){
			printf("Ancien nombres d'exemplaires : %d\n", j->nbEx);
	
			printf("Nouveau nombre d'exemplaires : ");
			scanf("%d%*c", &nb);
	
			diff = nb - j->nbEx;
			if (j->stock + diff < 0){
				printf("Vous ne pouvez pas diminuer le nombre d'exemplaires, trop d'adhérents ont un emprunt en cours avec ce jeu\n");
				return j;
			}
	
			j->nbEx = nb;
			j->stock += diff;
		}
		return j;
	}

	j->suiv = modifJeu(j->suiv, tEmp, nbEmp, choix, nomJ);
	return j;
}

/* Nom : save
Finalité : sauvegarde tous les tableaux (Adherent, Emprunt, Aprem, AdhAprem) et la liste (Jeux)
dans des fchiers (chargés au d"but du programme) permettant à la ludothèque de réutiliser les données
Paramètres entrant: j, liste de jeux
nbAdh, nombre total d'Adherent
nbEmp, nombre total d'Emprunt
nbAprem, nombre total d'Aprem
nbAdhAprem, nombre total d'AdhAprem
nbJeux, nombre total de jeux
Paramètres entrant-sortant: tAdh, tableau d'Adherent
tEmp, tableau d'Emprunt
tAprem, tableau d'Aprem
tAdhAprem, tableau d'AdhAprem
Valeur retourné: Aucune
Variables : i, compteur
flot1, flot d'écriture dans lequel vont être stockés les Adherent
flot2, flot d'écriture dans lequel vont être stockés les Emprunt
flot3, flot d'écriture dans lequel vont être stockés les Aprem
flot4, flot d'écriture dans lequel vont être stockés les AdhAprem
flot5, flot binaire d'écriture dans lequel vont être stockés les jeux
*/
void save(Adherent * tAdh, Emprunt * tEmp, Aprem * tAprem, AdhAprem * tAdhAprem, ListeJ j, int nbAdh, int nbEmp, int nbAprem, int nbAdhAprem, int nbJeux){
	int i;
	
	FILE * flot1 = fopen("adhérents.don","w");
	if (flot1 == NULL){
		printf("Erreur lors de l'ouverture du fichier adhérents.don\n");
		return;
	}
	FILE * flot2 = fopen("emprunts.don","w");
	if (flot2 == NULL){
		printf("Erreur lors de l'ouverture du fichier emprunts.don\n");
		return;
	}
	FILE * flot3 = fopen("am_thématiques.don","w");
	if (flot3 == NULL){
		printf("Erreur lors de l'ouverture du fichier am_thématiques.don\n");
		return;
	}
	FILE * flot4 = fopen("inscription_am_th.don","w");
	if (flot4 == NULL){
		printf("Erreur lors de l'ouverture du fichier inscription_am_th.don\n");
		return;
	}
	FILE * flot5 = fopen("jeux.bin","wb");
	if (flot5 == NULL){
		printf("Erreur lors de l'ouverture du fichier jeux.don\n");
		return;
	}

	fprintf(flot1, "%d\n", nbAdh);
	for(i = 0; i < nbAdh; i++){
		fprintf(flot1, "%s\n%s\n%s\n%s\n%s\n%d\n", tAdh[i].nom, tAdh[i].prenom, tAdh[i].date, tAdh[i].tel, tAdh[i].ville, tAdh[i].nbEmp);
	}

	fprintf(flot2, "%d\n", nbEmp);
	for(i = 0; i < nbEmp; i++){
		fprintf(flot2, "%s\n%s\n%s\n%s\n%s\n", tEmp[i].nom, tEmp[i].prenom, tEmp[i].jeux, tEmp[i].dateE, tEmp[i].dateR);
	}

	fprintf(flot3, "%d\n", nbAprem);
	for(i = 0; i < nbAprem; i++){
		fprintf(flot3, "%s %s %d %d\n", tAprem[i].date, tAprem[i].heure, tAprem[i].places, tAprem[i].placesL);
	}

	fprintf(flot4, "%d\n", nbAdhAprem);
	for(i = 0; i < nbAdhAprem; i++){
		fprintf(flot4, "%s %s\n%s\n%s\n", tAdhAprem[i].date, tAdhAprem[i].heure, tAdhAprem[i].nom, tAdhAprem[i].prenom);
	}

	fprintf(flot5, "%d\n", nbJeux);
	while (j != NULL){
		fwrite(j->nom, 30, 1, flot5);
		fwrite(&j->nbEx, 4, 1, flot5);
		fwrite(j->type, 30, 1, flot5);
		j = j->suiv;
	}

	fclose(flot1);
	fclose(flot2);
	fclose(flot3);
	fclose(flot4);
	fclose(flot5);
}

/* Nom : verifDateEmprunt
Finalité : Vérifie qu'un emprunt (qui n'a pas de date de retour) n'est pas en retard c'est à dire qu'il n'est pas emprunté depuis plus de 3 semaines
Paramètres entrant: emp, Emprunt dont on veut vérifier le retard
Paramètres entrant-sortant: Aucun
Valeur retourné: 1, si l'Emprunt n'est pas en retard; 0 si il y a eu une erreur d'ouverture avec un fichier et -1 si l'Emprunt est en retard
Variables : jourA, valeur du jour actuel
moisA, valeur du mois actuel
anneeA, valeur de l'année actuelle
jourR, valeur du jour maximal (3 semaines avant la date d'aujourd'hui) pour lequel les emprunts sont encore en règle
moisR, valeur du mois maximal
anneeR, valeur de l'année maximale
rendre, chaîne de caractère de la forme AAAA-MM-JJ à comparer avec la date d'emprunt  pour vérifier le respect des contraintes par l'Emprunt
*/
int verifDateEmprunt(Emprunt emp){
	int jourA, moisA, anneeA, jourR, moisR, anneeR;
	char rendre[11];

	FILE * fe = fopen("date.txt", "r");
	FILE * fs = fopen("retard.don","w");
	if (fe == NULL){
		printf("Erreur lors de l'ouverture du fichier date.txt\n");
		return 0;
	}
	if (fs == NULL){
		printf("Erreur lors de l'ouverture du fichier retard.don\n");
		return 0;
	}
	
	if(strcmp(emp.dateR, "") == 0){
		system("date +%Y-%m-%d>date.txt");
		fscanf(fe, "%d%*c%d%*c%d", &anneeA, &moisA, &jourA);
		anneeR = anneeA;
		moisR = moisA;
		jourR = jourA;

		if(moisR == 1 || moisR == 2 || moisR == 4 || moisR == 6 || moisR == 8 || moisR == 9 || moisR == 11 && jourR > 21){
			jourR -= 21;
		}
		else if(moisR == 1 || moisR == 2 || moisR == 4 || moisR == 6 || moisR == 8 || moisR == 9 || moisR == 11 && jourR <= 21){
			jourR += 10;
			moisR--;
		}
		else if(moisR == 3 || moisR == 5 || moisR == 7 || moisR == 10 || moisR == 12 && jourR > 21){
			jourR -= 21;
		}
		else if(moisR == 3 || moisR == 5 || moisR == 7 || moisR == 10 || moisR == 12 && jourR <= 21){
			jourR +=9;
			moisR--;
		}
		if(moisR == 0){
			moisR = 12;
			anneeR--;
		}

		if ((moisR == 1 || moisR == 2 || moisR == 3 || moisR == 4 || moisR == 5 || moisR == 6 || moisR == 7 || moisR == 8 || moisR == 9) && (jourR == 1 || jourR == 2 || jourR == 3 || jourR == 4 || jourR == 5 || jourR == 6 || jourR == 7 || jourR == 8 || jourR == 9))
			fprintf(fs, "%d-0%d-0%d\n", anneeR, moisR, jourR);

		else if (moisR == 1 || moisR == 2 || moisR == 3 || moisR == 4 || moisR == 5 || moisR == 6 || moisR == 7 || moisR == 8 || moisR == 9)
			fprintf(fs, "%d-0%d-%d\n", anneeR, moisR, jourR);
		
		else if (jourR == 1 || jourR == 2 || jourR == 3 || jourR == 4 || jourR == 5 || jourR == 6 || jourR == 7 || jourR == 8 || jourR == 9)
			fprintf(fs, "%d-%d-0%d\n", anneeR, moisR, jourR);
		
		else
			fprintf(fs, "%d-%d-%d\n", anneeR, moisR, jourR);

		fclose(fs);
		FILE * fs = fopen("retard.don","r");
		if (fs == NULL){
			printf("Erreur lors de l'ouverture du fichier test.don\n");
			return 0;
		}
		
		fgets(rendre,16,fs);
		if (rendre[strlen(rendre)-1] == '\n')
			rendre[strlen(rendre)-1] = '\0';

		if (strcasecmp(emp.dateE, rendre) < 0)
			return -1;
	}

	fclose(fe);
	fclose(fs);
	return 1;
}

/* Nom : triSelectEmp
Finalité : tri un tableau d'emprunt selon le choix de l'utilisateur
Paramètres entrant: nbEmp, nombre total d'Emprunt
choix, choix de l'utilisateur
Paramètres entrant-sortant: tEmp, tableau d'Emprunt
Valeur retourné: Aucune
Variables : pos, position d'insertion de l'Emprunt à replacer dans un tableau d'Emprunt trié
emp, Emprunt temporaire pemettant d'interchanger deux emprunts et ainsi de trier le tableau
*/
void triSelectEmp(Emprunt * tEmp, int nbEmp, char choix){
	int pos;
	Emprunt emp;

	if (nbEmp > 1){
		if (choix == '1')
			pos = rechminEN(tEmp, nbEmp);
		if (choix == '2')
			pos = rechminEP(tEmp, nbEmp);
		if (choix == '3')
			pos = rechminEJ(tEmp, nbEmp);
		
		emp = tEmp[0];
		tEmp[0] = tEmp[pos];
		tEmp[pos] = emp;

		triSelectEmp(tEmp+1, nbEmp-1, choix);
	}
}

int rechminEN(Emprunt * tEmp, int nbEmp){
	int i, pos = 0;

	for (i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].nom, tEmp[pos].nom) < 0)
			pos = i;
		
		if (strcasecmp(tEmp[i].nom, tEmp[pos].nom) == 0 && strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) < 0)
			pos = i;
		
		if (strcasecmp(tEmp[i].nom, tEmp[pos].nom) == 0 && strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) == 0 && strcasecmp(tEmp[i].jeux, tEmp[pos].jeux) < 0)
			pos = i;
	}

	return pos;
}

int rechminEP(Emprunt * tEmp, int nbEmp){
	int i, pos = 0;

	for (i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) < 0)
			pos = i;
		if (strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) == 0 && strcasecmp(tEmp[i].nom, tEmp[pos].nom) < 0)
			pos = i;
		if (strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) == 0 && strcasecmp(tEmp[i].nom, tEmp[pos].nom) == 0 && strcasecmp(tEmp[i].jeux, tEmp[pos].jeux) < 0)
			pos = i;
	}
	return pos;
}

int rechminEJ(Emprunt * tEmp, int nbEmp){
	int i, pos = 0;

	for (i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].jeux, tEmp[pos].jeux) < 0)
			pos = i;
		if (strcasecmp(tEmp[i].jeux, tEmp[pos].jeux) == 0 && strcasecmp(tEmp[i].nom, tEmp[pos].nom) < 0)
			pos = i;
		if (strcasecmp(tEmp[i].jeux, tEmp[pos].jeux) == 0 && strcasecmp(tEmp[i].nom, tEmp[pos].nom) == 0 && strcasecmp(tEmp[i].prenom, tEmp[pos].prenom) < 0)
			pos = i;
	}
	return pos;
}


void triInsertionAdh(Adherent * tAdh, int nbAdh){
	int pos, i, j;
	Adherent adh;

	for (i = 0; i < nbAdh; i++){
		pos = rechPosDichoAN(tAdh, nbAdh, tAdh[i]);
		if (pos != i){
			adh = tAdh[i];
			for (j = i; j > pos; j--){
				tAdh[j] = tAdh[j-1];
			}
			tAdh[j] = adh;
		}
	}
}

int rechPosDichoAN(Adherent  * tAdh, int nbAdh, Adherent adh){
	int deb = 0, fin = nbAdh -1, m, comp;

	while (deb <= fin){
		m = (deb + fin) / 2;
		comp = strcasecmp(adh.nom, tAdh[m].nom);
		if (comp == 0)
			comp = strcasecmp(adh.prenom, tAdh[m].prenom);
		if (comp == 0)
			return m;
		if (comp < 0)
			fin = m-1;
		else
			deb = m+1;
	}
	return deb;
}

void bulleAdhP(Adherent  * tAdh, int nbAdh){
		int i;
		Adherent tmp;

		if (nbAdh <= 1)
			return;

		for (i = 0; i < nbAdh - 1; i++){
			if (strcasecmp(tAdh[i].prenom, tAdh[i+1].prenom) > 0 || strcasecmp(tAdh[i].prenom, tAdh[i+1].prenom) == 0 && strcasecmp(tAdh[i].nom, tAdh[i+1].nom) > 0){
				tmp = tAdh[i];
				tAdh[i] = tAdh[i+1];
				tAdh[i+1] = tmp;
			}
		}
		bulleAdhP(tAdh, nbAdh-1);
}

void bulleAdhD(Adherent  * tAdh, int nbAdh){
		int i;
		Adherent tmp;

		if (nbAdh <= 1)
			return;

		for (i = 0; i < nbAdh - 1; i++){
			if (strcasecmp(tAdh[i].date, tAdh[i+1].date) > 0 || strcasecmp(tAdh[i].date, tAdh[i+1].date) == 0 && strcasecmp(tAdh[i].nom, tAdh[i+1].nom) > 0 || strcasecmp(tAdh[i].date, tAdh[i+1].date) == 0 && strcasecmp(tAdh[i].nom, tAdh[i+1].nom) == 0 && strcasecmp(tAdh[i].prenom, tAdh[i+1].prenom) > 0){
				tmp = tAdh[i];
				tAdh[i] = tAdh[i+1];
				tAdh[i+1] = tmp;
			}
		}
		bulleAdhD(tAdh, nbAdh-1);
}

void bulleAdhnbE(Adherent  * tAdh, int nbAdh){
		int i;
		Adherent tmp;

		if (nbAdh <= 1)
			return;

		for (i = 0; i < nbAdh - 1; i++){
			if (tAdh[i].nbEmp - tAdh[i+1].nbEmp > 0 || tAdh[i].nbEmp - tAdh[i+1].nbEmp == 0 && strcasecmp(tAdh[i].nom, tAdh[i+1].nom) > 0 || tAdh[i].nbEmp - tAdh[i+1].nbEmp == 0 && strcasecmp(tAdh[i].nom, tAdh[i+1].nom) == 0 && strcasecmp(tAdh[i].prenom, tAdh[i+1].prenom) > 0){
				tmp = tAdh[i];
				tAdh[i] = tAdh[i+1];
				tAdh[i+1] = tmp;
			}
		}
		bulleAdhnbE(tAdh, nbAdh-1);
}


void bulleApremD(Aprem * tAprem, int nbAprem){
		int i;
		Aprem tmp;

		if (nbAprem <= 1)
			return;

		for (i = 0; i < nbAprem - 1; i++){
			if (strcasecmp(tAprem[i].date, tAprem[i+1].date) > 0 || strcasecmp(tAprem[i].date, tAprem[i+1].date) == 0 && strcasecmp(tAprem[i].heure, tAprem[i+1].heure) > 0){
				tmp = tAprem[i];
				tAprem[i] = tAprem[i+1];
				tAprem[i+1] = tmp;
			}
		}
		bulleApremD(tAprem, nbAprem-1);
}

void bulleApremP(Aprem * tAprem, int nbAprem, char choix){
		int i;
		Aprem tmp;

		if (nbAprem <= 1)
			return;

		for (i = 0; i < nbAprem - 1; i++){
			if (choix == '2'){
				if (tAprem[i].places > tAprem[i+1].places){
					tmp = tAprem[i];
					tAprem[i] = tAprem[i+1];
					tAprem[i+1] = tmp;
				}
			}

			if (choix == '3'){
				if (tAprem[i].placesL > tAprem[i+1].placesL){
					tmp = tAprem[i];
					tAprem[i] = tAprem[i+1];
					tAprem[i+1] = tmp;
				}
			}
		}
		bulleApremP(tAprem, nbAprem-1, choix);
}


ListeJ triJeux(ListeJ j, int nbJeux, char choix){
	ListeJ triJeux = jVide();
	int i;

	for (i = 0; i < nbJeux; i++){
		triJeux = ajouter(triJeux, j, choix);
		j = j->suiv;
	}
	return triJeux;
}

ListeJ ajouter(ListeJ triJeux, ListeJ j, char choix){
	if (choix == '1'){
		if (triJeux == NULL || strcasecmp(triJeux->nom, j->nom) >= 0){
			triJeux = insererEnTete2(triJeux, j);
		}
		else
			triJeux->suiv = ajouter(triJeux->suiv, j, choix);
		
		return triJeux;
	}

	else if (choix == '2'){
		if (triJeux == NULL || triJeux->nbEx >= j->nbEx){
			triJeux = insererEnTete2(triJeux, j);
		}
		else
			triJeux->suiv = ajouter(triJeux->suiv, j, choix);
		return triJeux;
	}

	else if (choix == '3'){
		if (triJeux == NULL || strcasecmp(triJeux->type, j->type) >= 0){
			triJeux = insererEnTete2(triJeux, j);
		}
		else
			triJeux->suiv = ajouter(triJeux->suiv, j, choix);
		return triJeux;
	}
}


void bulleAdhApremD(AdhAprem * tAdhAprem, int nbAdhAprem){
		int i;
		AdhAprem tmp;

		if (nbAdhAprem <= 1)
			return;

		for (i = 0; i < nbAdhAprem - 1; i++){
			if (strcasecmp(tAdhAprem[i].date, tAdhAprem[i+1].date) > 0){
				tmp = tAdhAprem[i];
				tAdhAprem[i] = tAdhAprem[i+1];
				tAdhAprem[i+1] = tmp;
			}
		}
		bulleAdhApremD(tAdhAprem, nbAdhAprem-1);
}

void bulleAdhAprem(AdhAprem * tAdhAprem, int nbAdhAprem, char choix){
		int i;
		AdhAprem tmp;

		if (nbAdhAprem <= 1)
			return;

		for (i = 0; i < nbAdhAprem - 1; i++){
			if (choix == '2'){
				if (strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) > 0 || strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) == 0 && strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) > 0 || strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) == 0 && strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) == 0 && strcasecmp(tAdhAprem[i].date, tAdhAprem[i+1].date) > 0 || strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) == 0 && strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) == 0 && strcasecmp(tAdhAprem[i].date, tAdhAprem[i+1].date) == 0 && strcasecmp(tAdhAprem[i].heure, tAdhAprem[i+1].heure) > 0){
					tmp = tAdhAprem[i];
					tAdhAprem[i] = tAdhAprem[i+1];
					tAdhAprem[i+1] = tmp;
				}
			}

			if (choix == '3'){
				if (strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) > 0 || strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) == 0 && strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) > 0 || strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) == 0 && strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) == 0 && strcasecmp(tAdhAprem[i].date, tAdhAprem[i+1].date) > 0 || strcasecmp(tAdhAprem[i].prenom, tAdhAprem[i+1].prenom) == 0 && strcasecmp(tAdhAprem[i].nom, tAdhAprem[i+1].nom) == 0 && strcasecmp(tAdhAprem[i].date, tAdhAprem[i+1].date) == 0 && strcasecmp(tAdhAprem[i].heure, tAdhAprem[i+1].heure) > 0){
					tmp = tAdhAprem[i];
					tAdhAprem[i] = tAdhAprem[i+1];
					tAdhAprem[i+1] = tmp;
				}
			}
		}
		bulleAdhAprem(tAdhAprem, nbAdhAprem-1, choix);
}


void rechJeu(ListeJ j, int nbJeux, Emprunt * tEmp, int nbEmp){
	char nomJ[30];
	int trouve, exemp, i;

	printf("Nom du jeu : ");
	fgets(nomJ, 31, stdin);
	if (nomJ[strlen(nomJ)-1] == '\n')
		nomJ[strlen(nomJ)-1] = '\0';

	trouve = rechJeux(j, nomJ);
	if (trouve == -1){
		printf("\nLe jeu : %s n'a pas été trouvé\n", nomJ);
		return;
	}

	for (i = 0; i < trouve; i++)
		j = j->suiv;

	if (j->stock == 0)
		printf("\nIl ne reste plus d'exemplaires du jeu \"%s\" en stock\n", j->nom);
	else
		printf("\nIl reste %d exemplaires du jeu \"%s\" en stock\n", j->stock, j->nom);

	if (j->nbEx - j->stock == 0)
		printf("Aucun n'emprunt n'est en cours avec le jeu \"%s\"\n", j->nom);
	else if (j->nbEx - j->stock == 1)
		printf("\nL'adhérent ayant un empunt en cours avec le jeu \"%s\" est :\n", j->nom);
	else
		printf("\nLes adhérents ayant un emprunt en cours avec le jeu \"%s\" sont :\n", j->nom);
	for( i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].jeux, nomJ) == 0 && strcmp(tEmp[i].dateR, "") == 0){
			if (strlen(tEmp[i].nom) > 7)
				printf("%s\t%s\n", tEmp[i].nom, tEmp[i].prenom);
			else
				printf("%s\t\t%s\n", tEmp[i].nom, tEmp[i].prenom);
		}
	}
}


void rechAdh(Adherent * tAdh, int nbAdh, AdhAprem * tAdhAprem, int nbAdhAprem, Emprunt * tEmp, int nbEmp){
	int i, trouve, retard;
	char nom[20], prenom[20];

	printf("Nom : ");
	fgets(nom, 31, stdin);
	if (nom[strlen(nom)-1] == '\n')
		nom[strlen(nom)-1] = '\0';
	printf("Prénom : ");
	fgets(prenom, 31, stdin);
	if (prenom[strlen(prenom)-1] == '\n')
		prenom[strlen(prenom)-1] = '\0';

	trouve = rechAdherent(tAdh, nbAdh, nom, prenom);
	if (trouve == -1){
		printf("\nL'adhérent : %s %s n'a pas été trouvé\n", nom, prenom);
		return;
	}

	printf("\nNom\t\tPrénom\t\tInscription\tTel\t\tVille\t\t\tEmprunts\n");
	printf("¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯\t\t\t¯¯¯¯¯¯¯¯\n");
	if (strlen(tAdh[trouve].nom) > 7)
		printf("%s\t", tAdh[trouve].nom);
	else
		printf("%s\t\t", tAdh[trouve].nom);
	if (strlen(tAdh[trouve].prenom) > 7)
		printf("%s\t%s\t%s\t", tAdh[trouve].prenom, tAdh[trouve].date, tAdh[trouve].tel);
	else
		printf("%s\t\t%s\t%s\t", tAdh[trouve].prenom, tAdh[trouve].date, tAdh[trouve].tel);
	if (strlen(tAdh[trouve].ville) > 14)
		printf("%s\t%d\n", tAdh[trouve].ville, tAdh[trouve].nbEmp);
	else if (strlen(tAdh[trouve].ville) > 7)
		printf("%s\t\t%d\n", tAdh[trouve].ville, tAdh[trouve].nbEmp);
	else
		printf("%s\t\t\t%d\n", tAdh[trouve].ville, tAdh[trouve].nbEmp);

	if (tAdh[trouve].nbEmp == 0)
		printf("\nL'adhérent : %s %s n'a aucun emprunt en cours\n", tAdh[trouve].nom, tAdh[trouve].prenom);

	else if (tAdh[trouve].nbEmp == 1)
		printf("\nL'adhérent : %s %s a un emprunt en cours qui est :\n", tAdh[trouve].nom, tAdh[trouve].prenom);
	else
		printf("\nL'adhérent : %s %s a plusieurs emprunts en cours qui sont :\n", tAdh[trouve].nom, tAdh[trouve].prenom);
	for (i = 0; i < nbEmp; i++){
		if (strcasecmp(tEmp[i].nom, nom) == 0 && strcasecmp(tEmp[i].prenom, prenom) == 0 && strcmp(tEmp[i].dateR, "") == 0){
			retard = verifDateEmprunt(tEmp[i]);
			if (retard != -1)
				printf("%s emprunté le %s\n", tEmp[i].jeux, tEmp[i].dateE);
			else
				printf("%s emprunté le %s RETARD !!\n", tEmp[i].jeux, tEmp[i].dateE);
		}
	}

	printf("\n");
	for (i = 0; i < nbAdhAprem; i++){
		if (strcasecmp(tAdhAprem[i].nom, nom) == 0 && strcasecmp(tAdhAprem[i].prenom, prenom) == 0)
			printf("L'adhérent %s %s est inscrit à l'après-midi thématique du %s à %s\n", tAdh[trouve].nom, tAdh[trouve].prenom, tAdhAprem[i].date, tAdhAprem[i].heure);
	}
}

void rechAp(Aprem * tAprem, int nbAprem, AdhAprem * tAdhAprem, int nbAdhAprem){
	char date[11], heure[5];
	int trouve, i;

	printf("Date (AAAA-MM-JJ) : ");
	fscanf(stdin,"%s", date);
	printf("Heure (HH:MM) : ");
	fscanf(stdin,"%s%*c", heure);

	trouve = rechAprem(tAprem, nbAprem, date, heure);
	if (trouve == -1){
		printf("\nL'après-midi thématique du %s à %s n'existe pas\n", date, heure);
		return;
	}

	printf("\nDate\t\tHeure\tPlaces\tPlaces libres\n");
	printf("¯¯¯¯\t\t¯¯¯¯¯\t¯¯¯¯¯¯\t¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
	printf("%s\t%s\t%d\t%d\n", tAprem[trouve].date, tAprem[trouve].heure, tAprem[trouve].places, tAprem[trouve].placesL);

	if (tAprem[trouve].places - tAprem[trouve].placesL == 0)
		printf("\nAucun adhérent n'est pour l'instant inscrit à cet après-midi thématique\n");
	else if (tAprem[trouve].places - tAprem[trouve].placesL == 1)
		printf("\nL'adhérent inscrit à l'après-midi thématique du %s à %s est :\n", date, heure);
	else
		printf("\nLes adhérents inscrits à l'après-midi thématique du \"%s\" à \"%s\" sont :\n", date, heure);

	for( i = 0; i < nbAdhAprem; i++){
		if (strcasecmp(tAdhAprem[i].date, date) == 0 && strcasecmp(tAdhAprem[i].heure, heure) == 0){
			if (strlen(tAdhAprem[i].nom) > 7)
				printf("%s\t%s\n", tAdhAprem[i].nom, tAdhAprem[i].prenom);
			else
				printf("%s\t\t%s\n", tAdhAprem[i].nom, tAdhAprem[i].prenom);
		}
	}
}


void affichMenu(void){
	printf("\t\\\\ Menu //\n");
	printf("0) Afficher le Menu\n");
	printf("1) Modification sur Adhérent\n");
	printf("2) Modification sur Emprunt\n");
	printf("3) Modification sur Après-midi Thématique\n");
	printf("4) Modification sur Adhérent à un Après-midi Thématique\n");
	printf("5) Modification sur Jeu\n");
	printf("6) Menu d'affichage\n");
	printf("7) Rechercher\n");
	printf("8) Sommaire\n");
	printf("9) Quitter\n");
}

void affichGrandMenu(void){
	printf("\t\\\\ Sommaire //\n\n");
	printf("0) Afficher le Menu\n\n");
	printf("1) Modification sur Adhérent\n");
	printf("\t1. Inscrire un Adhérent\n");
	printf("\t2. Supprimer un Adhérent\n");
	printf("\t3. Modifier le nom et/ou le prénom d'un Adhérent\n");
	printf("\t4. Modifier le numéro de téléphone d'un Adhérent\n");
	printf("\t5. Modifier la ville d'un Adhérent\n\n");
	printf("2) Modification sur Emprunt\n");
	printf("\t1. Enregistrer un Emprunt\n");
	printf("\t2. Retourner un Emprunt\n\n");
	printf("3) Modification sur Après-midi Thématique\n");
	printf("\t1. Créer un Après-midi Thématique\n");
	printf("\t2. Supprimer un Après-midi Thématique\n");
	printf("\t3. Modifier la date ou l'heure d'un Après-midi Thématique\n");
	printf("\t4. Modifier le nombre de places d'un Après-midi Thématique\n\n");
	printf("4) Modification sur Adhérent à un Après-midi Thématique\n");
	printf("\t1. Inscrire un Adhérent à un Après-midi Thématique\n");
	printf("\t2. Supprimer un Adhérent d'un Après-midi Thématique\n\n");
	printf("5) Modification sur Jeu\n");
	printf("\t1. Enregistrer un Jeu\n");
	printf("\t2. Supprimer un Jeu\n");
	printf("\t3. Modifier le nom d'un Jeu\n");
	printf("\t4. Modifier le nombre d'exemplaires d'un Jeu\n\n");
	printf("6) Menu d'affichage\n");
	printf("\t1. Adhérents\n");
	printf("\t\t1- Afficher les adhérents par Nom\n");
	printf("\t\t2- Afficher les adhérents par Prénom\n");
	printf("\t\t3- Afficher les adhérents par date d'incription\n");
	printf("\t\t4- Afficher les adhérents par nombre d'emprunts\n");
	printf("\t\t5- Afficher les adhérents ayant un retard\n");
	printf("\t2. Emprunts\n");
	printf("\t\t1- Afficher les emprunts par Nom\n");
	printf("\t\t2- Afficher les emprunts par Prénom\n");
	printf("\t\t3- Afficher les emprunts par Jeu\n");
	printf("\t3. Après-midi Thématiques\n");
	printf("\t\t1- Afficher les aprem par Date\n");
	printf("\t\t2- Afficher les aprem par Places\n");
	printf("\t\t3- Afficher les aprem par Places Libres\n");
	printf("\t4. Adhérents à des après-midi thématiques\n");
	printf("\t\t1- Afficher les aprem par Date\n");
	printf("\t\t2- Afficher les adhérents par Nom\n");
	printf("\t\t3- Afficher les adhérents par Prénom\n");
	printf("\t5. Jeux\n");
	printf("\t\t1- Afficher les jeux par Nom\n");
	printf("\t\t2- Afficher les jeux par Nombre d'exemplaires\n");
	printf("\t\t3- Afficher les jeux par Type\n\n");
	printf("7) Rechercher\n");
	printf("\t1. Adhérents\n");
	printf("\t2. Après-midi thématique\n");
	printf("\t3. Jeux\n\n");
	printf("8) Sommaire\n\n");
	printf("9) Quitter\n");
}