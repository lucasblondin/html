#ifndef USER_INFO_H
#define USER_INFO_H
#include <iostream>
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class UserInfo{
    const char* MY_HOSTNAME;
    const char* MY_DATABASE;
    const char* MY_USERNAME;
    const char* MY_PASSWORD;
    const char* MY_SOCKET;
    const char* query;

    string resultat_query;

    enum {
        MY_PORT_NO = 3306,
        MY_OPT = 0
    };

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
public:

    string resQuery(){
        return resultat_query;
    }

    UserInfo(){
        //Initialiser les constantes
        MY_HOSTNAME = "localhost";
        MY_DATABASE = "CHESS_ENIGMA";
        MY_USERNAME = "connection";
        MY_PASSWORD = "iutgeii";
        MY_SOCKET   = NULL;
        query = "vide";
        resultat_query = "vide";
    }

    bool execMain(string stringQ){
        try {

            //mettre la stringQ dans query
            query = stringQ.c_str();
            //formater un objet MySQL
            conn = mysql_init(NULL);

            // établir une connection MySQL
            if (!mysql_real_connect(
                        conn,
                        MY_HOSTNAME, MY_USERNAME,
                        MY_PASSWORD, MY_DATABASE,
                        MY_PORT_NO, MY_SOCKET, MY_OPT)){
                cerr << mysql_error(conn) << endl;
                cerr << "connection annulé" << endl;
            }

            //executer une requête SQL
            if(mysql_query(conn,query)){
                cerr << mysql_error(conn) << endl;
                return false;
            }

            //récupérer les résultats
            res = mysql_use_result(conn);

            // enregistrer resultat query dans une string

            //string s = "SHOW TABLES IN DATABASE ";
            //s += MY_DATABASE;
            string s ;
            unsigned int num_fields;
            num_fields = mysql_num_fields(res);
            while((row = mysql_fetch_row(res)) != NULL){
                for(int i = 0; i < num_fields ;i++){
                    s += row[i];
                    s += " ";
                }
                s+="\n";
            }

            resultat_query = s +  " IL Y A " + num_fields;

            //resultat_query = (const)s.c_str();
            // libérer la mémoire
            mysql_free_result(res);

            //fermer la connection
            mysql_close(conn);
        } catch (char * e){
            cerr << "[EXCEPTION] " << e << endl;
            return false;
        }
        return false;
    }

};

#endif
