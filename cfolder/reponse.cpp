#include <iostream>
#include <stdio.h>
#include <mysql/mysql.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include "user.h"

void affichageReponse(string s){
    string delimiter = " ";    
    vector<string> position;

    int i = 0;
    while(s.length() > 3){
    position.push_back(s.substr(0,s.find(delimiter)));
    s.erase(0,s.find(delimiter) + delimiter.length());
    }
    for(int i = 0 ; i < position.size(); i++){
            cout << position[i] << " ";   
    }
}

int main(int argc, char **argv){

   cout << "Content-type: text/html\r\n\r\n";

   string queryCoup = "select coup from COUPS inner join AUTEUR on AUTEUR.id_aut=COUPS.id_enigme where AUTEUR.nom_aut=\'" + string(argv[1]) + "\'";
   
   UserInfo recupCoups;
   recupCoups.execMain(queryCoup);
   string resultat_coups = recupCoups.resQuery();
   affichageReponse(resultat_coups);

    return 1;
}