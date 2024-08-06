//
//  main.cpp
//  coding
//
//  Created by mac on 30/7/2024.
//
#include "Account.hpp"
#include <iostream>
#include <ostream>


using namespace std ;

void Menu() {
    // Sign up Compte :
    Account acc   ;
   // list des information d'un compt
        list<data_info> deta ;
        list<data_info> nouv ;  // nouvelle list
    // Menu
    
    // variable pour organiser les processuces :
    int x =0 , id ;
    char opt , ch ;
    bool b = false ;
   /**/
    while (!b &&   cout << "\t\t Alors voilà ici les steps pour vous utilisez le compte de cette societé : , Appuyez sur  : \n a.Cree le Compte ... \n b.Afficher le Compte ... "
           <<"\n c.Ajouter au Compte ... \n d.Supprimer le Compte ... \n e.Modifier le Compte ... \n\n f.Exit \n\t option _  " && cin >> ch ) {
    switch (ch) {
        case 'a':
            while (true) {
                // creer le compte :
                cout << "\t [!]. La Création de compte :  "<< endl ;
                deta.push_back(acc.create_account())   ;
                cout << " \n -------- [!] Voullez-vous Continue (Y/N) : " ;
                cin >> opt ;
                if (opt == 'N'  or opt == 'n') {
                    break;
                }
                x++ ;
            }
            break;
       
        case  'c':
            cout << "\t [!]. Addition au compte : " ;
            acc.update_account_info(deta) ;
            break;
        case  'd':
            cout << "_ Entrez-vous pass-id pour supprimer votre compte : " ;
            cin >> id ;
          
           
            // pour push les élements non supprimer
            nouv.push_back(acc.delete_account(acc , deta , id));
            // pour cleaner tous les elements
            deta.clear() ;
            //acc.display_info(nouv) ;
            deta.push_back(acc.return_new_list(nouv)); //acc.display_info(nouv) ;
            break;
        case  'e':
            cout << "_ Entrez-vous pass-id pour Modify votre compte : " ;
            cin >> id ;
            acc.modify_account_info(deta,id );
            acc.display_info(deta) ;
            break;
        case  'b':
            cout << "\t [!].Afficher les donnees de tous les comptes " << endl  ;
            acc.display_info(deta) ;
            break;
        default:
            cout << "再见 ！👋 🎉" << endl;
            b = true ;
            break;
    }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << " \t\t Hello, World! cplusplus # \n";
    Menu() ;
    return 0;
}
