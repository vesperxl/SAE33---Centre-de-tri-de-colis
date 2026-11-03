#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include "common.h"

int main(int argc, char *argv[]) 
{
    char cmd[5];
    pid_t pid;


    
    pid = fork();

    if(pid == -1)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    /*
    * BOUCLE PRINCIPALE : jusqu'à 20 colis || "QUIT"
    *
    * il y a 2 struct : Colis et Zones
    *
    * syntaxe : "COLIS <id> <destination> <poids>" poids positif, destination = A, B, C.
    *
    * ici on aura 2 processus donc le fils = processus Tri et le pere = processus Main
    * 
    * Processus main il a juste à gérer les entrées utilisateurs (à définir);
    * SI "COLIS" -> envoyer infos dans le pipe nommé vers processus tri
    * SI "QUIT"  -> envoyer dans pipe nommé processus tri: thread main;
    * SI "ETAT"  -> ????????
    * 
    * Processus tri il faudra faire 6 threads: 
    *    - Thread main (thread principal): met en place tous les autres threads, gérer la synchro, gérer toutes les commandes du processus main : "COLIS" -> tri & routage, "QUIT" -> géré seul, "ETAT" -> ??.
    * 
    *    - Thread tri & routage : validation de chaque colis puis transmission pour la bonne zone -> 3 pipes anonymes
    * 
    *    - Thread Supervision : recupère les infos des 3 zones, mets les stats à jour, vérifie si 20 colis atteints -> transmets à affichage par pipe nommé et processus main par signaux. (si 20 colis -> stop)
    * 
    *    - Threads zones : mets à jour les stats -> communique avec Supervision par ????
    * 
    * Processus affichage : état du centre de tri (surement via la commande "ETAT") -> historique des colis traités -> fichier de log tout ça par des signaux. 
    */

    while(true)
    {


        scanf("%s", cmd);

        for (int i = 0; cmd[i] != '\0'; i++) 
        {
            cmd[i] = tolower(cmd[i]);
        }

        switch(cmd)
        {
            case "quit" :

                //transmettre des infos dans le pipe

            case "colis" :



            case "etat" :
        }
    }

    printf("Hello World!\n");
    return EXIT_SUCCESS; 
}