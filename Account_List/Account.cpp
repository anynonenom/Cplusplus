//
//  Account.cpp
//  coding
//
//  Created by mac on 30/7/2024.
//

#include "Account.hpp"
#include<algorithm>
int Account::cmpt = 0;
string frtna="" ;
string lstna="" ;
string eml="" ;
 string phe ="";
string pssd  ="";
string bih = "" ;

Account::Account() {
    // default ;
    d.id = 0  ;
    d.lastname = "" ;
    d.firstname = "" ;
   d.email = "" ;
    d.phone = "" ;
    d.password = "" ;
    d.birth = "" ;
   
}
Account::Account(data_info de ) {
    d.id = de.id;
    d.firstname =  de.firstname ;
    d.lastname =   de.lastname ;
    d.password =   de.password ;
    d.birth =      de.birth ;
    d.phone = de.phone ;
    d.email    =      de.email ;
}

data_info Account::create_account() {
    Account acc ;
    // cout << "\t\t Sign up :" << endl  ;
    // stocker_info() :
    // stocker tous les informations dans une fichier name List_Data.txt :
     data_info ld  ;

    
    cout << " Saisez-vous Le Nom : " ;
    cin >> lstna ;
    cout << "Saisez-vous Le  Prenom : " ;
    cin >> frtna ;
    cout << "Saisez-vous Le phone : " ;
    cin >> phe ;
    cout << "Saisez-vous L'email : " ;
    cin >> eml ;
    cout << "Saisez-vous Le password  : " ;
    cin >> pssd;
    cout << "Saisez-vous Le né : " ;
    cin >> bih ;
   
    ld.id =cmpt ;
    ld.phone = phe ;
    ld.lastname = lstna ;
    ld.firstname = frtna ;
    ld.password = pssd ;
    ld.email = eml ;
    ld.birth = bih ;
    Account Acc(ld) ;
    //Acc.L.push_back(Acc.d); // stocke the elements in List #
    cmpt++;
    return ld ;
}

void Account::display_info(list<data_info> lst) {
    
    //cout << lst.begin()->id << endl ;
    for(list<data_info>::iterator it = lst.begin(); it != lst.end(); ++it) {

    //for(auto &n : lst ) {
    cout << " -  Nom : " << (*it).lastname << endl
        << " -  Prenom : " << (*it).firstname << endl
        << " -  Telephone: " << (*it).phone << endl
        << " -  Email : " << (*it).email << endl
        << " -  Mot de Pass : " << (*it).password << endl
        << " -  Né: " << (*it).birth  << endl << "\n------------------------------\n"<<endl 
         ;
      }
}


data_info  Account::delete_account(Account acc, list<data_info> L ,  int identity){
    list<data_info>::iterator iter ;
    //list<data_info > new_L  ;
    data_info p ;
    iter = L.begin() ;
    while(iter != L.end() ){
    //for(auto &k : L ){
        if (iter->id != identity ) {
            //  L.erase(iter) ;
            //cout << iter->id << endl ;
            p.password = iter->password ;
            p.lastname = iter->lastname ;
            p.phone = iter->phone ;
            p.firstname = iter->firstname ;
            p.email = iter->email ;
            p.birth = iter->birth ;
            
            
        }
        // stocker les élèmentes en p ;
        ++iter ;
    }
    return p ;
   // cout << " this is the : " << iter->id << ":" << iter->lastname << endl ;
   
    
    
}

// ajouter une compt :
void Account::update_account_info(list<data_info> &L ){
    list<data_info>::iterator iter ;
    data_info info ;
    iter = L.begin();
    while(iter != L.end() ){
        ++iter ;
    }
    info.id = iter->id ;
    cout << " Ajoutez-vous Le Nom : " ;
    cin >> lstna ;
    cout << "Ajoutez-vous Le  Prenom : " ;
    cin >> frtna ;
    cout << "Ajoutez-vous Le phone : " ;
    cin >> phe ;
    cout << "Ajoutez-vous L'email : " ;
    cin >> eml ;
    cout << "Ajoutez-vous Le password  : " ;
    cin >> pssd;
    cout << "Ajoutez-vous Le né : " ;
    cin >> bih ;
    info.password = pssd ;
    info.firstname = frtna ;
    info.lastname = lstna ;
    info.phone = phe ;
    info.email = eml ;
    info.birth = bih ;
    // 
    L.insert(iter, info);
}
void Account::modify_account_info(list<data_info> &L , int &i){
//    I can do it
    list<data_info>::iterator iter ;
    data_info info ;
    int x ;
    string strconst1 , strconst2  , strconst3  , strconst4  , strconst5 , strconst6 ;
    string strconst ;
    iter = L.begin();
    while(iter != L.end() ){
        if(iter->id == i ){
            // Modifying the data :
            cout << "\t\t what do you want to modify ? , Press : \n 1.FirstName \n 2.LastName "
            <<"\n 3.Phone \n 4.Email \n 5.Password \n 6.Birth \n 0.All data \n [!].return to the Menu \n\t option _  " ;
            cin >> x ;
            
            switch (x) {
                case 0:
                   
                    cout << "Saisez Le  Prenom : [" << x << ".] "  ;
                    cin >> strconst1 ;
                    iter->firstname = strconst1 ; // fisrtname
                    cout << "Saisez Le  Nom : [" << x << ".] "  ;
                    cin >> strconst2 ;
                    iter->lastname =strconst2  ; // Lastname
                    cout << "Saisez Le  Phone : [" << x << ".] "  ;
                    cin >> strconst3 ;

                    iter->phone = strconst3 ; // Phone
                    cout << "Saisez L'email : [" << x << ".] "  ;
                    cin >> strconst4 ;

                    iter->email = strconst4 ;// Email
                    cout << "Saisez Le  mot de pass  : [" << x << ".] "  ;
                    cin >> strconst5 ;

                    iter->password = strconst5 ; // Passwor
                    cout << "Saisez Le  né : [" << x << ".] "  ;
                    cin >> strconst6 ;

                    iter->birth = strconst6 ; // Birth
              

                    break;
                case 1 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->firstname = strconst ; // fisrtname
                    break;
                case 2 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->lastname =strconst  ; // Lastname
                    break;
                case 3 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->phone = strconst ; // Phone
                    break;
                case 4 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->email = strconst ;// Email
                    break;
                case 5 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->password = strconst ; // Password
                    break;
                case 6 :
                    cout << "Saisez Le  : [" << x << ".] "  ;
                    cin >> strconst ;
                    iter->birth = strconst ; // Birth
                    break;
              
                default:
                    exit(0) ;
                   break;
                    
            }
            strconst="" ;
            break;
        }
        ++iter ;
    }
}

data_info Account::return_new_list(list<data_info> L) {
    data_info l ;
    
    list<data_info>::iterator iter ;
    iter = L.begin() ;
    while (iter != L.end()) {
        l.password = iter->password ;
        l.email = iter->email ;
        l.phone = iter->phone ;
        l.firstname = iter->firstname ;
        l.lastname = iter->lastname ;
        l.birth = iter->birth ;
        ++iter ;
    }
    return l;
    
}
