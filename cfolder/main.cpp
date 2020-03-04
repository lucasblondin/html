#include <iostream>
#include <mysql/mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "user.h"
#include <vector>

//#define limite 1000000
//#define ratio 0


using namespace std;
//int j;

int main()
{

    UserInfo connectionBase;
    string insert ;
    
    insert = "SELECT max(id_pro) FROM produit";
    cout << "test\n";
    connectionBase.execMain(insert);
    cout << connectionBase.resQuery() << "\n";
    return 0;
}
