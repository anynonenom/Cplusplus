/*
  @20/10/2024
*/
#include <iostream>
#include <string>
#include "../header/bookshop.hpp"

using namespace std ;
 // namespace std ;
int main(){
    // -- Book Shop : ///
    bookshop bkinfo ;
    string opt  , file_name , new_file ;
    int N , k , count  , op ; 

    
                
        operate :
          
        cout << " \n\t\t- System Management Of The Book&Store (SMBS) \n\n " ;
        cout << "\t 1. Ajouter Les Données           .... \n" ;
        cout << "\t 2. Afficher tous Les Données     .... \n" ;
        cout << "\t 3. Vérifier  Les Données         .... \n" ;
        cout << "\t 4. Modifier Les Données          .... \n" ;
        cout << "\t 5. supprimer Les Données         .... \n" ;
        cout << "\t 6. reteuer à la list des opttion .... \n" ;
        cout << "\t 7. Exit .... " ;
        cout << "\n\n\t\t Enter the choice  __  " ;
        cin >> count;
        switch (count)
        {
        case 1 :
            /* code */
            cout << "\t\t 1. Ajouter Les Données          ....\n\n " ;
            std::cout << "\tEnter the name of the original file : "  ;
                std::cin >> file_name ;
             cout << "Combien d'information voulez-vous Entrer - __  " ; cin >> N  ;
            std::cout << "\t\t ± Saisir les données suivants : \n\n" ;
                while( N != 0){
                        // Add les books :
                        bkinfo.addbook(file_name) ;
                            // decrementation :
                            N-- ;
                        }
            break;
        case 2 :
            /* code */
        cout << "\t\t 2. Afficher tous Les Données            ....\n\n " ;
        std::cout << "\tEnter the name of the original file : "  ;
                std::cin >> file_name ;
             bkinfo.showbook(file_name );
            break;
            case  3 :
                // Check the details of the biblio throught the Id :
        cout << "\t\t 3. Vérifier  Les Données            .... \n\n" ;
        std::cout << "\tEnter the name of the original file : "  ;
                std::cin >> file_name ;
                loop :
                cout << "\nEnter roll number :  " ; 
                cin >> k ;
                bkinfo.checkbook(file_name,k) ;
                std::cout << "\n Do you reenter your number ? (1.Oui/2.Non) _ " ; 
                std::cin >> op ;
                if(op == 1 ){
                    goto loop ;
                }
               
            break;
            case 4 :
            /* code */
                // Modification state  : 
                cout << "\t\t 4. Modifier Les Données         ....\n\n " ;
                 std::cout << "\n\tEnter the name of the new file to restore : "  ;
                std::cin >> new_file ;
                bkinfo.modifybook(file_name , new_file) ;
                // rename("../../dataFiles/"+file_name ,"../../dataFiles/"+ new_file );

            break;
            case 5 :
            /* code */
               // suppression : 
                    cout << "\t\t 5. supprimer Les Données        .... \n\n" ;
                      std::cout << "\n\tEnter the name of the new file to restore : "  ;
                std::cin >> new_file ;
                     std::cout << "\t\t-- Delete the speciefic information -- " << endl << endl ;
                        bkinfo.deletebook(file_name , new_file);
                        // rename("../../dataFiles/"+file_name.c_str() ,"../../dataFiles/"+ new_file.c_str());

            break;
            case 6 :
            /* code */
                cout << "\t 6. reteurn à la list des options ....\n " ;
            goto operate ;
            break;
            case 7 :
            std::cout << "Vous-êtes sure ? (Oui/Non) __ " ;
            cin >> opt ;
            if(opt == "Oui" || opt == "oui" ) {
                std::cout << "No hésiter pas de nos visitons dans la semettre prochaine , Merci infiniment ! :) ," ;
                exit(0) ;
            }
            else {
                goto operate ;
            }
            /* code */
            break;
        }
        goto operate ;
    // cout << "\t\t - Book Shop - \n\n" <<" id  |   Nom   |" << book.toString() ;
    return 0 ;
}

