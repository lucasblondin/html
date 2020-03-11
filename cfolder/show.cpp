#include <iostream>
#include <stdio.h>
#include <mysql/mysql.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include "user.h"

using namespace std;
string tab[8][8] = 
{"♜","♞","♝","♛","♚","♝","♞","♜",
"♟","♟","♟","♟","♟","♟","♟","♟",
" "," "," "," "," "," "," "," ",
" "," "," "," "," "," "," "," ",
" "," "," "," "," "," "," "," ",
" "," "," "," "," "," "," "," ",
"♙","♙","♙","♙","♙","♙","♙","♙",
"♖","♘","♗","♕","♔","♗","♘","♖",
};
/*
string tab[8][8] = 
{
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
    " "," "," "," "," "," "," "," ",
};*/

void create_tab(){
    for(int x = 0 ; x < 8; x++){
        for(int y = 0 ; y < 8 ; y++){
            tab[x][y] = " ";
        }
    } 
}

void autre_enigme(string s){

    string delimiter = " ";    
    vector<string> position;

    //position.push_back(s);
    
    int i = 0;
    while(s.length() > 3){
    position.push_back(s.substr(0,s.find(delimiter)));
    s.erase(0,s.find(delimiter) + delimiter.length());
    }
    
    cout << "<div id=\"boiteEnigme\">\n";
    cout << "<h2> Choisire une autre enigme <h2>" << endl;
    cout << "<div id=\'listes\'>\n";
    cout << "<ul>\n";

    for(int i = 0 ; i < position.size()-1; i+=2){
            cout << "<li> <label  class=\"enigmes\" >" << position[i] << " " << position[i+1] << "<label> </li> \n"; 
            //cout << "<li> <label  class=\"enigmes\" >" << position[i] << "<label> </li> \n";  
    }

    cout << "</ul>\n";
    cout << "</div>\n";
    cout << "</div>\n";
}


void affichageReponse(string s){
    cout << "<button id=\"boutonVoir\">résultat</button>\n";
    cout << "<button id=\"debut\"> terminé </button> <button id=\"retour\"> < </button> <button id=\"avance\"> > </button> <button id=\"fin\" > état initial </button>";    
    string delimiter = " ";    
    vector<string> position;


    int i = 0;
    while(s.length() > 3){
    position.push_back(s.substr(0,s.find(delimiter)));
    s.erase(0,s.find(delimiter) + delimiter.length());
    }


    cout << "<div id=\'listeRep\'>\n";
    cout << "<ul>\n";
    cout << "<div id=\"hide\"class=\"hidden\">\n";
    
    for(int i = 0 ; i < position.size(); i++){
            
            cout << "<li><label class=\"rep\"> " << position[(position.size()-1) - i] << "</label></li> \n";   

    }
    cout << "</div>\n";

    cout << "</ul></div>";
}



void affichageReponseChangement(string s){
    
    string delimiter = " ";    
    vector<string> position;

    int i = 0;
    while(s.length() > 3){
    position.push_back(s.substr(0,s.find(delimiter)));
    s.erase(0,s.find(delimiter) + delimiter.length());
    }
    for(int i = 0 ; i < position.size(); i++){
            cout << "<li><label class=\"rep\"> " << position[(position.size()-1) - i] << "</label></li> \n";   
    }

}


void show_tab(){
    cout << "<table id=\"idTab\" class=\"tab\">\n";
    for(int x = 0 ; x <= 8; x++){
        if(x == 8){
            cout << "<tr><th>" << "</th>";
        }else {
            cout << "<tr class=\"ligne\"><th>" << (8 - x ) << "</th>\n";
        }
        if (x == 8){
            for(int y = 0 ; y < 8 ; y++){
                    cout << "<td style=\"background: darkgray;font-size:40px;color:white;\">" << (char)('a' + y) << "</td>\n";
            }
        }else {
                for(int y = 0 ; y < 8 ; y++){
                    cout << "<span style=\"display:none;\" class=\"init\">" << tab[x][y] << "<td id=\" " << (x*8+y) << " \" class=\"cellule\">" << tab[x][y] << "</td>\n";
            }
        } 
        cout << "</tr>\n";
    } 

    cout << "</table>\n";
}

void positionnement(string s){
    string delimiter = ",";    
    vector<string> position;

    int i = 0;
    while(s.length() > 6){
    position.push_back(s.substr(0,s.find(delimiter)));
    s.erase(0,s.find(delimiter) + delimiter.length());
    }

    position.push_back(s);
    for(int y = 0 ; y < position.size(); y++){

            char piece = position[y].at(0);
            string p;
            char couleur =  position[y].at(1);
            int colonne = ((int)(position[y].at(2) - 'a'));
            int ligne = 8 - ((int)(position[y].at(3) - 48)); 
            
            /*
            cout << "NUMERO = " << y << endl;
            cout << "piece = " << piece << endl;
            cout << "couleur = " << couleur << endl;
            cout << "colonne = " << colonne << endl;
            cout << "ligne = " << ligne << endl;
            */

            switch(couleur){
                case 'b':

                    switch(piece){
                        case 'K':
                            p = "♚" ;
                            break;
                        case 'Q':
                            p = "♛" ;
                            break;
                        case 'B':
                            p = "♝" ;
                            break;
                        case 'N':
                            p = "♞" ;
                            break;
                        case 'R':
                            p = "♜" ;
                            break;
                        case 'P':
                            p = "♟" ;
                            break;
                        default:
                        p = " ";
                    }
                break;

                case 'w':

                    switch(piece){
                        case 'K':
                            p = "♔" ;
                            break;
                        case 'Q':
                            p = "♕" ;
                            break;
                        case 'B':
                            p = "♗" ;
                            break;
                        case 'N':
                            p = "♘" ;
                            break;
                        case 'R':
                            p = "♖" ;
                            break;
                        case 'P':
                            p = "♙" ;
                            break;
                        default:
                        p = " ";
                    }
                break;
            }
           
           tab[ligne][colonne] = "" + p; 
    }
}



int main(int argc, char **argv){
   

   

   // Recuperer le positionnement des pieces   
   UserInfo connectionBase;
   
   string queryCoup; 

   cout << "Content-type: text/html\r\n\r\n";

   if (argc == 2){
   //cout << "resultat " <<  string(argv[1]) << endl;
   //cout << "select placement_enigme from ENIGME inner join AUTEUR on AUTEUR.id_aut=ENIGME.id_enigme where AUTEUR.aut_nom=" + string(argv[1]) << endl;
   //connectionBase.execMain("select placement_enigme from ENIGME inner join AUTEUR on AUTEUR.id_aut=ENIGME.id_enigme where AUTEUR.nom_aut=\'" + string(argv[1]) + "\'");
   queryCoup = "select coup from COUPS inner join ENIGME on ENIGME.id_enigme=COUPS.id_enigme inner join AUTEUR on AUTEUR.id_aut=ENIGME.id_aut where AUTEUR.nom_aut=\'" + string(argv[1]) + "\'";
   //connectionBase.execMain(queryCoup);
   //string res = connectionBase.resQuery();
   //positionnement(res);
   // Recuperer les coups + les mettres dans le formulaire
   UserInfo recupCoups;
   recupCoups.execMain(queryCoup);
   string resultat_coups = recupCoups.resQuery();
   affichageReponseChangement(resultat_coups);
   // afficher les pieces 
   //show_tab();

   }else {
   
   //cout << "<html id=\"body\">\n";
   cout << "<head>\n";
   cout << "<title>ChessWeb</title>\n";
   cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"../styles.css\">\n";
   cout << "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js\"></script>\n" ;
   cout << "<link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"../ressources/favicon.ico\"/>\n";
   cout << "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\n" ;
   cout << "</head>\n";
   cout << "<body >\n";
   cout << "<h1>CHESSWEB</h1>\n";
   cout << "<div id=\"centre\">\n";
   //connectionBase.execMain("select placement_enigme from ENIGME where id_enigme=1");
   queryCoup = "select coup from COUPS where id_enigme=1";

   //string res = connectionBase.resQuery();
   //positionnement(res);

   // afficher les pieces 
   show_tab();
   
   // Recuperer les coups + les mettres dans le formulaire
   UserInfo recupCoups;
   recupCoups.execMain(queryCoup);
   string resultat_coups = recupCoups.resQuery();
   cout << "</div>\n";

   //formulaire(resultat_coups);
   cout << "<div id=\"nav_droite\">\n";
   cout << "<div id=\"boiteReponse\">\n";
   affichageReponse(resultat_coups);
   cout << "</div>\n";

   // Recup prochaines parties
   UserInfo recupEnigmes;
   recupEnigmes.execMain("select nom_aut,id_enigme from AUTEUR inner join ENIGME on ENIGME.id_aut=AUTEUR.id_aut");
   string resultat_enigme = recupEnigmes.resQuery();
   //cout << "RESULTAT DE QUERY " << resultat_enigme << endl;
   //cout << resultat_enigme ;
   autre_enigme(resultat_enigme);

   cout << "<h4 for=\"story\">Notez vos coups ! </h4>";

   cout << "<textarea id=\"story\" name=\"story\"\n";
   cout << "rows=\"5\" cols=\"33\" >\n";
   cout << "\n";
   cout << "</textarea>\n";

   cout << "</div>\n";

   cout << "<div id=\'liste\'>";
   
   cout << "</div>";

   cout << "<script id=\"js\" src=\"../js/javascript.js\"></script>\n";
   cout << "</body>\n";
   //cout << "</html>\n";

    //creat_tab();
    //show_tab();
   }

    return 1;
}