#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int chiffrer(int nombreRand, int cle);
int cleAgent(const char* cleAgent);
int ma1();
int ma2();
int ma3();
int ma4();
int ma5();
int modexp(int a, int clePublique, int n);
int id;
                //---------------------------------------MA1---------------------------------------//

int ma1() {
    int etat;
    char reponse[1]; // On fixe la réponse a 1 caractere maximum

    printf("Quel est le projet du MI7 ?\n");
    printf("1 >> MI7 Security \n");
    printf("2 >> Strongbox 2.0 \n");
    printf("3 >> StrongBox 3000 \n");
    printf("4 >> Agent Double \n");
    scanf(" %1s", reponse); // Lis une chaine de 1 caractere maximum

    if (reponse[0] == '3') { // Compare le seul caractere de la chaine avec la reponse attendue

        printf("[Niveau 1] >> Reussi \n");
        printf("Quel est le nom de notre ecole ? \n");
        printf("1 >> ESILV \n");
        printf("2 >> ECE \n");
        printf("3 >> EMLV \n");
        printf("4 >> CESI \n");
        scanf(" %1s", reponse);

        if (reponse[0] == '4') {
            printf("[Niveau 2] >> Acces reussi \n");
            printf("Quel est le nom de la promotion de cette annee \n");
            printf("1 >> CPI A1 \n");
            printf("2 >> CPI A2 \n");
            scanf(" %1s", reponse);

            if (reponse[0] == '1') {
                printf("[Niveau 3] >> Reussi \n");
                printf("Vous pouvez passer au prochain niveau de securite \n");
                etat = 1; //etat defini sur True
            } else {
                printf("Acces refuse \n");
                etat = 0; //etat defini sur False
                exit(-1);
            }

        } else {
            printf("Acces refuse \n");
            exit(-1);
        }
    } else {
        printf("Acces refuse \n");
        etat = 0;
        exit(-1);
    }
    return etat;
}
                //---------------------------------------MA1---------------------------------------//


                //---------------------------------------MA2---------------------------------------//

int ma2() {
    srand((unsigned int)time(NULL));   //  Generateur nb aleatoire
    int etat;
    int magent = 0;
    int clePublique, m, mp, c;
    char nomAgent[1]; // Le nom de l agent est constitue seulement d une lettre

    printf("Veuillez-vous identifier \n");
    scanf("%s", nomAgent);
    m = rand() % 2881;
    clePublique = cleAgent(nomAgent);
    c = chiffrer(m, clePublique);
    while (m != magent) {
        printf("Message à dechiffrer \n");
        printf("%d\n", c);
        scanf("%d", &magent);
    }
    printf("Authentification autorisee \n");
    etat = 1;
    return etat;
}


int chiffrer(int nombreRand, int cle) {
    int n = 43 * 67;
    int chiffre = modexp(nombreRand, cle, n);
    return chiffre;
}

int cleAgent(const char* cleAgent) {
    int cle = 0;
    if (strcmp(cleAgent, "A") == 0) { //Utilisation de strcmp pour comparer de chaine de caractere
        cle = 601;
    } else if (strcmp(cleAgent, "B") == 0) {
        cle = 619;
    } else if (strcmp(cleAgent, "C") == 0) {
        cle = 631;
    } else if (strcmp(cleAgent, "D") == 0) {
        cle = 641;
    } else if (strcmp(cleAgent, "E") == 0) {
        cle = 647;
    } else if (strcmp(cleAgent, "F") == 0) {
        cle = 653;
    } else if (strcmp(cleAgent, "H") == 0) {
        cle = 739;
    } else if (strcmp(cleAgent, "I") == 0) {
        cle = 673;
    } else if (strcmp(cleAgent, "J") == 0) {
        cle = 691;
    } else if (strcmp(cleAgent, "K") == 0) {
        cle = 701;
    } else if (strcmp(cleAgent, "L") == 0) {
        cle = 733;
    } else if (strcmp(cleAgent, "M") == 0) {
        cle = 739;
    } else if (strcmp(cleAgent, "N") == 0) {
        cle = 751;
    } else if (strcmp(cleAgent, "O") == 0) {
        cle = 797;
    } else if (strcmp(cleAgent, "P") == 0) {
        cle = 809;
    } else if (strcmp(cleAgent, "Q") == 0) {
        cle = 811;
    }
    return cle;
}


int modexp(int a, int clePublique, int n) {
    int r = 1;

    if (clePublique < 0) {
        printf("Cle publique invalide \n");
        exit(-1);
    }
    if (a == 0 || n == 1) {
        r = 0;
    } else {
        while (clePublique > 0) {
            if (clePublique % 2 == 1) {
                r = (r * a) % n;
            }
            a = (a * a) % n;
            clePublique /= 2;
        }
    }

    return r;
}


                //---------------------------------------MA2---------------------------------------//


                //---------------------------------------MA3---------------------------------------//

int ma3() {
    int etat;
    int cpt;
    char retine[8];  //Le code de retine est composé de 5 element + un terminateur nul
    char* retine_id[] = {
            "retineA", "retineB", "retineC", "retineD", "retineE", "retineF",
            "retineH", "retineI", "retineJ", "retineK", "retineL", "retineM",
            "retineN", "retineO", "retineP", "retineQ"};
    printf("Veuillez approchez votre oeil du capteur : ");
    scanf("%7s", retine);  // Lis une chaine de caractere de 7 caracteres maximum
    for (cpt = 0; cpt < 16; cpt++) {
        if (strcmp(retine_id[cpt], retine) == 0) {
            if (cpt == id) {
                printf("Scan retinien reconnu \n");
                etat = 1;
                break;

            }else{
                printf("[Erreur] >> Scan retinien non reconnu");
                etat = 0;
            }
        }

    }
    return etat;
}

            //---------------------------------------MA3---------------------------------------//


            //---------------------------------------MA4---------------------------------------//

int ma4() {
    int etat;
    int cpt;
    char doigt[8];  //Le code digital est composé de 8 element + un terminateur nul
    char* doigt_id[] = {
            "doigtA", "doigtB", "doigtC", "doigtD", "doigtE", "doigtF",
            "retineH", "doigtI", "doigtJ", "doigtK", "doigtL", "doigtM",
            "doigtN", "doigtO", "doigtP", "doigtQ"};
    printf("Veuillez approchez votre doigt du capteur : ");
    scanf("%7s", doigt);  // Lis une chaine de caractere de 7 caracteres maximum
    for (cpt = 0; cpt < 16; cpt++) {
        if (strcmp(doigt_id[cpt], doigt) == 0) {
            if (cpt == id) {
                printf("Scan digital reconnu \n");
                etat = 1;
                break;

            }else{
                printf("[Erreur] >> Scan digital non reconnu \n");
                etat = 0;
            }
        }

    }
    return etat;
}

            //---------------------------------------MA4---------------------------------------//


            //---------------------------------------MA5---------------------------------------//

int ma5() {
    int groupe;
    int compteur;
    char aTrouve[6];  //Le code est composé de 5 element + un terminateur nul
    char* codes[] = {
            "A1258", "B2865", "C1658", "D1100", "E0101", "F0110",
            "G0111", "H1000", "I1001", "K1010", "L1011", "M1100",
            "N1101", "O1835", "P8563", "Q7569"};
    int etat = 0;

    printf("Entrez votre lettre et code d'agent\n");
    scanf("%5s", aTrouve);  // Lis une chaine de caractere de 5 caracteres maximum
    while (!etat) {
        for (compteur = 0; compteur < 16; compteur++) {
            if (strcmp(codes[compteur], aTrouve) == 0) {
                id = compteur;
                etat = 1;
                groupe = compteur;
                break;
            } else {
                printf("Erreur");
                break;

            }
        }
    }

    return groupe;
}

            //---------------------------------------MA5---------------------------------------//


int main() {
    int grp;
    grp = ma5();
    if (grp < 3) {
        printf("Vous appartenez au Groupe 1, vous allez donc passer le niveau de securite 1\n");
        if (ma1() == 1 && ma3() == 1) {
            printf("[Niveau Securite 1] >> Reussi\n");
            printf("Coffre Ouvert !\n");
        } else {
            printf("[Niveau Securite 1] >> Erreur\n");
            printf("Destruction du coffre\n");
        }
    } else if (grp < 6) {
        printf("Vous appartenez au Groupe 2, vous allez donc passer le niveau de securite 2\n");
        if (ma1() == 1 && ma4() == 1) {
            printf("[Niveau de securite 2] >> Reussi\n");
            printf("Coffre ouvert !\n");
        } else {
            printf("[Niveau Securite 2] >> Erreur\n");
            printf("Destruction du coffre\n");
        }
    } else if (grp < 9) {
        printf("Vous appartenez au Groupe 3, vous allez donc passer le niveau de securite 3\n");
        if (ma2() == 1 && ma5() == 1) {
            printf("[Niveau de securite 3] >> Reussi\n");
            printf("Coffre ouvert !\n");
        } else {
            printf("[Niveau Securite 3] >> Erreur\n");
            printf("Destruction du coffre\n");
        }
    }else if (grp < 12) {
        printf("Vous appartenez au Groupe 4, vous allez donc passer le niveau de securite 4\n");
        if (ma2() == 1 && ma3() == 1 && ma4() == 1) {
            printf("[Niveau de securite 4] >> Reussi\n");
            printf("Coffre ouvert !\n");
        } else {
            printf("[Niveau Securite 4] >> Erreur\n");
            printf("Destruction du coffre\n");
        }
    }else if (grp < 16) {
        printf("Vous appartenez au Groupe 5, vous allez donc passer le niveau de securite 5\n");
        if (ma1() == 1 && ma2() == 1 && ma3() == 1 && ma5() == 1) {
            printf("[Niveau de securite 5] >> Reussi\n");
            printf("Coffre ouvert !\n");
        } else {
            printf("[Niveau Securite 5] >> Erreur\n");
            printf("Destruction du coffre\n");
        }
    }


    return 0;
}