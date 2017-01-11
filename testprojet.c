#include "projet.h"

int main(void){
	Emprunt *tEmp;
	Adherent *tAdh;
	Aprem *tAprem;
	AdhAprem *tAdhAprem;
	ListeJ j;
	int nbEmpT, nbAdh, nbAprem, nbAdhAprem, nbJeux = 0, i, retard;
	char choix, choix2, choix3, test, nomJ[30];
	Cellule * tmp;

	tAdh = chargeTAdherent("adhérents.don", &nbAdh);
	tEmp = chargeTEmprunts("emprunts.don", &nbEmpT);
	tAprem = chargeAprem("am_thématiques.don", &nbAprem);
	tAdhAprem = chargeAdhAprem("inscription_am_th.don", &nbAdhAprem);
	j = jVide();
	j = chargeJeux("jeux.bin", &nbJeux, tEmp, nbEmpT);

	affichMenu();
	printf("\nMenu : Que voulez vous faire ? (tapez un chiffre) : ");
	choix = saisirChoix();
	printf("\n");
	while (choix != '9'){
		while (choix != '0' && choix != '1' && choix != '2' && choix != '3' && choix != '4' && choix != '5' && choix != '6' && choix != '7' && choix != '8' && choix != '9'){
			printf("Retapez s'il vous plaît (le chiffre doit être compris entre 0 et 9)\n");
			printf("\nMenu : Que voulez vous faire ? (tapez un chiffre) ");
			choix = saisirChoix();
			printf("\n");
		}

		if (choix == '0')
			affichMenu();
			
		if (choix == '1'){
			printf("\t\\\\ Modification sur Adhérent //\n");
			printf("0) Retour au Menu\n");
			printf("1) Inscrire un Adhérent\n");
			printf("2) Supprimer un Adhérent\n");
			printf("3) Modifier le nom et/ou le prénom d'un Adhérent\n");
			printf("4) Modifier le numéro de téléphone d'un Adhérent\n");
			printf("5) Modifier la ville d'un Adhérent\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2' && choix2 != '3' && choix2 != '4' && choix2 != '5'){
				printf("Vous devez taper un chiffre entre 0 et 5. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					tAdh = newAdherent(tAdh, &nbAdh);
					break;
	
				case '2' :
					triInsertionAdh(tAdh, nbAdh);
					printf("Adhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					printf("\n");
					supprAdherent(tAdh, &nbAdh);
					break;

				case '3' :
				case '4' :
				case '5' :
					triInsertionAdh(tAdh, nbAdh);
					printf("Adhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					printf("\n");
					modifAdh(tAdh, nbAdh, tEmp, nbEmpT, tAdhAprem, nbAdhAprem, choix2);
					break;
			}
		}

		if (choix == '2'){
			printf("\t\\\\ Modification sur Emprunt //\n");
			printf("0) Retour au Menu\n");
			printf("1) Enregistrer un Emprunt\n");
			printf("2) Retourner un Emprunt\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2'){
				printf("Vous devez taper un chiffre entre 0 et 2. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;
		
				case '1' :
					triInsertionAdh(tAdh, nbAdh);
					j = triJeux(j, nbJeux, '1');
					printf("Adhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					tmp = j;
					printf("\nJeux : ");
					for (i = 0; i < nbJeux; i++){
						if (j->stock > 0)
							printf("%s | ", j->nom);
						j = j->suiv;
					}
					printf("\n");
					tEmp = newEmprunt(tEmp, &nbEmpT, tAdh, nbAdh, j);
					break;
					
	
				case '2' :
					triInsertionAdh(tAdh, nbAdh);
					j = triJeux(j, nbJeux, '1');
					printf("Adhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					tmp = j;
					printf("\nJeux : ");
					for (i = 0; i < nbJeux; i++){
						printf("%s | ", tmp->nom);
						tmp = tmp->suiv;
					}
					printf("\n");
					rendreJeu(tAdh, nbAdh, tEmp, nbEmpT, j);
					break;
				}
		}		

		if (choix == '3'){
			printf("\t\\\\ Modification sur Après-midi Thématique //\n");
			printf("0) Retour au Menu\n");
			printf("1) Créer un Après-midi Thématique\n");
			printf("2) Supprimer un Après-midi Thématique\n");
			printf("3) Modifier la date ou l'heure d'un Après-midi Thématique\n");
			printf("4) Modifier le nombre de places d'un Après-midi Thématique\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2' && choix2 != '3' && choix2 != '4'){
				printf("Vous devez taper un chiffre entre 0 et 4. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					tAprem = newAprem(tAprem, &nbAprem);
					break;
	
				bulleApremD(tAprem, nbAprem);
				printf("Aprem : ");
				for (i = 0; i < nbAprem; i++)
					if (tAprem[i].placesL > 0)
						printf("%s à %s | ", tAprem[i].date, tAprem[i].heure);
				printf("\n");
				case '2' :
					bulleApremD(tAprem, nbAprem);
					printf("Aprem : ");
					for (i = 0; i < nbAprem; i++)
						if (tAprem[i].placesL > 0)
							printf("%s à %s | ", tAprem[i].date, tAprem[i].heure);
					printf("\n");
					supprAprem(tAprem, &nbAprem, tAdhAprem, &nbAdhAprem);
					break;
				case '3' :
				case '4' :
					bulleApremD(tAprem, nbAprem);
					printf("Aprem : ");
					for (i = 0; i < nbAprem; i++)
						if (tAprem[i].placesL > 0)
							printf("%s à %s | ", tAprem[i].date, tAprem[i].heure);
					printf("\n");
					modifAprem(tAprem, nbAprem, tAdhAprem, nbAdhAprem, choix2);
					break;
			}
		}

		if (choix == '4'){
			printf("\t\\\\ Modification sur Adhérent à un Après-midi Thématique //\n");
			printf("0) Retour au Menu\n");
			printf("1) Inscrire un Adhérent à un Après-midi Thématique\n");
			printf("2) Supprimer un Adhérent d'un Après-midi Thématique\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2'){
				printf("Vous devez taper un chiffre entre 0 et 2. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					bulleApremD(tAprem, nbAprem);
					triInsertionAdh(tAdh, nbAdh);
					printf("Aprem : ");
					for (i = 0; i < nbAprem; i++)
						if (tAprem[i].placesL > 0)
							printf("%s à %s | ", tAprem[i].date, tAprem[i].heure);
					printf("\nAdhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					printf("\n");
					tAdhAprem = newAdhAprem(tAdhAprem, &nbAdhAprem, tAdh, nbAdh, tAprem, nbAprem);
					break;
	
				case '2' :
					bulleAdhApremD(tAdhAprem, nbAdhAprem);
					printf("Aprem\\Adhérent: ");
					for (i = 0; i < nbAprem; i++)
							printf("%s à %s\\%s . %s | ", tAdhAprem[i].date, tAdhAprem[i].heure, tAdhAprem[i].nom, tAdhAprem[i].prenom);
					printf("\n");
					supprAdhAprem(tAprem, nbAprem, tAdhAprem, &nbAdhAprem);
					break;
			}
		}

		if (choix == '5'){
			printf("\t\\\\ Modification sur Jeu //\n");
			printf("0) Retour au Menu\n");
			printf("1) Enregistrer un Jeu\n");
			printf("2) Supprimer un Jeu\n");
			printf("3) Modifier le nom d'un Jeu\n");
			printf("4) Modifier le nombre d'exemplaires d'un Jeu\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2' && choix2 != '3' && choix2 != '4'){
				printf("Vous devez taper un chiffre entre 0 et 4. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					j = newJeu(j, &nbJeux);
					break;

				case '2' :
					j = triJeux(j, nbJeux, '1');
					tmp = j;
					printf("Jeux : ");
					for (i = 0; i < nbJeux; i++){
						printf("%s | ", tmp->nom);
						tmp = tmp->suiv;
					}
					printf("\n");
					printf("Nom : ");
					fgets(nomJ,30,stdin);
					if (nomJ[strlen(nomJ)-1] == '\n')
						nomJ[strlen(nomJ)-1] = '\0';
					j = supprJeu(j, &nbJeux, nomJ);
					break;
				case '3' :
				case '4' :
					j = triJeux(j, nbJeux, '1');
					tmp = j;
					printf("Jeux : ");
					for (i = 0; i < nbJeux; i++){
						printf("%s | ", tmp->nom);
						tmp = tmp->suiv;
					}
					printf("\n");
					printf("Nom du jeu : ");
					fgets(nomJ, 31, stdin);
					if (nomJ[strlen(nomJ)-1] == '\n')
						nomJ[strlen(nomJ)-1] = '\0';
					j = modifJeu(j, tEmp, nbEmpT, choix2, nomJ);
					break;
			}
		}

		if (choix == '6'){
			printf("\t\\\\ Affichage //\n");
			printf("0) Retour au Menu\n");
			printf("1) Adhérents\n");
			printf("2) Emprunts\n");
			printf("3) Après-midi Thématiques\n");
			printf("4) Adhérents à des après-midi thématiques\n");
			printf("5) Jeux\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2' && choix2 != '3' && choix2 != '4' && choix2 != '5'){
				printf("Vous devez taper un chiffre entre 0 et 5. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					printf("\t\\\\ Adhérents //\n");
					printf("0) Retour au Menu\n");
					printf("1) Afficher les adhérents par Nom\n");
					printf("2) Afficher les adhérents par Prénom\n");
					printf("3) Afficher les adhérents par date d'incription\n");
					printf("4) Afficher les adhérents par nombre d'emprunts\n");
					printf("5) Afficher les adhérents ayant un retard\n");
					printf("\nQue voulez vous faire ? (tapez un chiffre) ");
					choix3 = saisirChoix();
					printf("\n");
					
					while (choix3 != '0' && choix3 != '1' && choix3 != '2' && choix3 != '3' && choix3 != '4' && choix3 != '5'){
						printf("Vous devez taper un chiffre entre 0 et 5. Retapez : ");
						choix3 = saisirChoix();
					}

					switch (choix3){
						case '0' :
							affichMenu();
							break;
	
						case '1' :
							triInsertionAdh(tAdh, nbAdh);
							printf("\nNom\t\tPrénom\t\tInscription\tTel\t\tVille\t\t\tEmprunts\n");
							printf("¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯\t\t\t¯¯¯¯¯¯¯¯\n");
							for(i = 0; i < nbAdh; i++)
			 					afficheAdh(tAdh[i], choix3);
			 				break;
		
			 			case '2' :
			 				bulleAdhP(tAdh, nbAdh);
							printf("\nPrénom\t\tNom\t\tInscription\tTel\t\tVille\t\t\tEmprunts\n");
							printf("¯¯¯¯¯¯\t\t¯¯¯\t\t¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯\t\t\t¯¯¯¯¯¯¯¯\n");
			 				for(i = 0; i < nbAdh; i++)
			 					afficheAdh(tAdh[i], choix3);
			 				break;
		
			 			case '3' :
			 				bulleAdhD(tAdh, nbAdh);
							printf("\nInscription\tNom\t\tPrénom\t\tTel\t\tVille\t\t\tEmprunts\n");
							printf("¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯\t\t¯¯¯¯¯\t\t\t¯¯¯¯¯¯¯¯\n");
			 				for(i = 0; i < nbAdh; i++)
			 					afficheAdh(tAdh[i], choix3);
			 				break;
		
			 			case '4' :
			 				bulleAdhnbE(tAdh, nbAdh);
							printf("\nNom\t\tPrénom\t\tInscription\tTel\t\tVille\t\t\tEmprunts\n");
							printf("¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯\t\t\t¯¯¯¯¯¯¯¯\n");
			 				for(i = 0; i < nbAdh; i++)
			 					afficheAdh(tAdh[i], choix3);
			 				break;
		
						case '5' :
							triInsertionAdh(tAdh, nbAdh);
							for (i = 0; i< nbEmpT; i++){
								retard = verifDateEmprunt(tEmp[i]);
								if (retard == -1)
									printf("L'adhérent : %s %s à un retard avec le jeu \"%s\" emprunté le %s\n", tEmp[i].nom, tEmp[i].prenom, tEmp[i].jeux, tEmp[i].dateE);
							}
							break;
					}
					break;

				case '2' :
					printf("\t\\\\ Emprunts //\n");
					printf("0) Retour au Menu\n");
					printf("1) Afficher les emprunts par Nom\n");
					printf("2) Afficher les emprunts par Prénom\n");
					printf("3) Afficher les emprunts par Jeu\n");
					printf("\nQue voulez vous faire ? (tapez un chiffre) ");
					choix3 = saisirChoix();
					printf("\n");
	
					while (choix3 != '0' && choix3 != '1' && choix3 != '2' && choix3 != '3'){
						printf("Vous devez taper un chiffre entre 0 et 3. Retapez : ");
						choix3 = saisirChoix();
					}
	
					switch (choix3){
						case '0' :
							affichMenu();
							break;
	
						case '1' :
						case '2' :
						case '3' :
							triSelectEmp(tEmp, nbEmpT, choix3);
								printf("\nNom\t\tPrénom\t\tJeux\t\tDateE\t\tDateR\n");
							printf("¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯¯\t\t¯¯¯¯¯\t\t¯¯¯¯¯\n");
							for(i = 0; i < nbEmpT; i++)
							 	afficheEmp(tEmp[i]);
							break;
					}
					break;
		
				case '3' :
					printf("\t\\\\ Après-midi Thématiques //\n");
					printf("0) Retour au Menu\n");
					printf("1) Afficher les aprem par Date\n");
					printf("2) Afficher les aprem par Places\n");
					printf("3) Afficher les aprem par Places Libres\n");
					printf("\nQue voulez vous faire ? (tapez un chiffre) ");
					choix3 = saisirChoix();
					printf("\n");
	
					while (choix3 != '0' && choix3 != '1' && choix3 != '2' && choix3 != '3'){
						printf("Vous devez taper un chiffre entre 0 et 3. Retapez : ");
						choix3 = saisirChoix();
					}
	
					switch (choix3){
						case '0' :
							affichMenu();
							break;
	
						case '1' :
							bulleApremD(tAprem, nbAprem);
		
						case '2' :
						case '3' :
							bulleApremP(tAprem, nbAprem, choix3);
		
						printf("\nDate\t\tHeure\tPlaces\tPlaces libres\n");
						printf("¯¯¯¯\t\t¯¯¯¯¯\t¯¯¯¯¯¯\t¯¯¯¯¯¯¯¯¯¯¯¯¯\n");
						for (i = 0; i < nbAprem; i++)
							afficheAprem(tAprem[i]);
					}
					break;
	
				case '4' :
					printf("\t\\\\ Adhérents à des après-midi thématiques //\n");
					printf("0) Retour au Menu\n");
					printf("1) Afficher les aprem par Date\n");
					printf("2) Afficher les adhérents par Nom\n");
					printf("3) Afficher les adhérents par Prénom\n");
					printf("\nQue voulez vous faire ? (tapez un chiffre) ");
					choix3 = saisirChoix();
					printf("\n");
	
					while (choix3 != '0' && choix3 != '1' && choix3 != '2' && choix3 != '3'){
						printf("Vous devez taper un chiffre entre 0 et 3. Retapez : ");
						choix3 = saisirChoix();
					}
	
					switch (choix3){
						case '0' :
							affichMenu();
							break;
	
					case '1' :
						bulleAdhApremD(tAdhAprem, nbAdhAprem);
						printf("\nDate\t\tHeure\tNom\t\tPrénom\n");
						printf("¯¯¯¯\t\t¯¯¯¯¯\t¯¯¯\t\t¯¯¯¯¯¯\n");
						for (i = 0; i < nbAdhAprem; i++)
							afficheAdhAprem(tAdhAprem[i], choix3);
						break;
	
					case '2' :
						bulleAdhAprem(tAdhAprem, nbAdhAprem, choix3);
						printf("\nNom\t\tPrénom\t\tDate\t\tHeure\n");
						printf("¯¯¯\t\t¯¯¯¯¯¯\t\t¯¯¯¯\t\t¯¯¯¯¯\n");
						for (i = 0; i < nbAdhAprem; i++)
							afficheAdhAprem(tAdhAprem[i], choix3);
						break;
					case '3' :
						bulleAdhAprem(tAdhAprem, nbAdhAprem, choix3);
						printf("\nPrénom\t\tNom\t\tDate\t\tHeure\n");
						printf("¯¯¯¯¯¯\t\t¯¯¯\t\t¯¯¯¯\t\t¯¯¯¯¯\n");
						for (i = 0; i < nbAdhAprem; i++)
							afficheAdhAprem(tAdhAprem[i], choix3);
						break;
					}
					break;
	
				case '5' :
					printf("\t\\\\ Jeux //\n");
					printf("0) Retour au Menu\n");
					printf("1) Afficher les jeux par Nom\n");
					printf("2) Afficher les jeux par Nombre d'exemplaires\n");
					printf("3) Afficher les jeux par Type\n");
					printf("\nQue voulez vous faire ? (tapez un chiffre) ");
					choix3 = saisirChoix();
					printf("\n");
	
					while (choix3 != '0' && choix3 != '1' && choix3 != '2' && choix3 != '3'){
						printf("Vous devez taper un chiffre entre 0 et 3. Retapez : ");
						choix3 = saisirChoix();
					}
	
					switch (choix3){
						case '0' :
							affichMenu();
							break;
	
						case '1' :
						case '2' :
						case '3' :
							j = triJeux(j, nbJeux, choix3);
							printf("\nNom\t\t\tExemplaires\tEn Stock\tType\n");
							printf("¯¯¯\t\t\t¯¯¯¯¯¯¯¯¯¯¯\t¯¯¯¯¯¯¯¯\t¯¯¯¯\n");
							afficheJeux(j);
							break;
					}
					break;
			}
		}
	
		if (choix == '7'){
			printf("\t\\\\ Recherche //\n");
			printf("0) Retour au Menu\n");
			printf("1) Adhérents\n");
			printf("2) Après-midi thématique\n");
			printf("3) Jeux\n");
			printf("\nQue voulez vous faire ? (tapez un chiffre) ");
			choix2 = saisirChoix();
			printf("\n");

			while (choix2 != '0' && choix2 != '1' && choix2 != '2' && choix2 != '3'){
				printf("Vous devez taper un chiffre entre 0 et 3. Retapez : ");
				choix2 = saisirChoix();
			}

			switch (choix2){
				case '0' :
					affichMenu();
					break;

				case '1' :
					triInsertionAdh(tAdh, nbAdh);
					printf("Adhérents : ");
					for (i = 0; i < nbAdh; i++)
						printf("%s . %s | ", tAdh[i].nom, tAdh[i].prenom);
					printf("\n");
					rechAdh(tAdh, nbAdh, tAdhAprem, nbAdhAprem, tEmp, nbEmpT);
					break;
				
				case '2' :
					bulleApremD(tAprem, nbAprem);
					printf("Aprem : ");
					for (i = 0; i < nbAprem; i++)
						printf("%s à %s | ", tAprem[i].date, tAprem[i].heure);
					printf("\n");
					rechAp(tAprem, nbAprem, tAdhAprem, nbAdhAprem);
					break;
	
				case '3' :
					j = triJeux(j, nbJeux, '1');
					tmp = j;
					printf("Jeux : ");
					for (i = 0; i < nbJeux; i++){
						printf("%s | ", tmp->nom);
						tmp = tmp->suiv;
					}
					printf("\n");
					rechJeu(j, nbJeux, tEmp, nbEmpT);
					break;
			}
		}

		if (choix == '8'){
			affichGrandMenu();
		}
			triInsertionAdh(tAdh, nbAdh);
			triSelectEmp(tEmp, nbEmpT, '1');
			bulleApremD(tAprem, nbAprem);
			bulleAdhApremD(tAdhAprem, nbAdhAprem);
			j = triJeux(j, nbJeux, '1');
			save(tAdh, tEmp, tAprem, tAdhAprem, j, nbAdh, nbEmpT, nbAprem, nbAdhAprem, nbJeux);
			printf("\nMenu : Que voulez vous faire ? (tapez un chiffre) ");
			choix = saisirChoix();
			printf("\n");
	}
	if (choix == '9')
		save(tAdh, tEmp, tAprem, tAdhAprem, j, nbAdh, nbEmpT, nbAprem, nbAdhAprem, nbJeux);

	free(tAdh);
	free(tEmp);
	free(tAprem);
	free(tAdhAprem);
	free(j);
	
	return 0; 
}