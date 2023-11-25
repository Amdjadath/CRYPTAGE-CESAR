#include <iostream>
#include <string>
#include <locale>
using namespace std;
 string chiffrementcesar
(const string&texte, int key)
{
  string resultat;
  char caractere;
  for (char caractere:texte)
    if(isalpha(caractere)){
        char base=isupper(caractere)? 'A': 'a';
        int decalage=caractere-base;
        int new_decalage=(decalage+key)%26;
        char new_caractere=base+new_decalage;
        resultat+=new_caractere;
    } else{
    resultat+=caractere;
    }

  return resultat;
}
 string dechiffrementcesar
(const string&resultat, int key)
{
  string message;
  for (char caractere:resultat){
    if(isalpha(caractere)){
        char base=isupper(caractere)? 'A': 'a';
        int decalage=caractere-base;
        int new_decalage=(decalage-key)%26;
        char new_caractere=base+new_decalage;
        message+=new_caractere;
    } else{
    message+=caractere;
    }
  }
  return message;
}
int main(){

setlocale(LC_ALL, "");
string message;
string resultat;
int key,num;

cout<<"saisissez un numero:"<<endl;
cout<<"numero 1 pour le cryptage 2 pour le decryptage"<<endl;
cin>>num;

if(num==1){
    cout<<"entrer le message a crypter:";
    cin>>message;

    cout<<"entrer la cle de cryptage:";
    cin>>key;

    string
    resultat=chiffrementcesar(message, key);
    cout<<"voici le message chiffre"<<resultat<<endl;
}
else if(num==2){
    cout<<"entrer le message a decrypter:";
    cin>>resultat;

    cout<<"entrer la cle de decryptage:";
    cin>>key;

    string
    resultat2=dechiffrementcesar(resultat, key);
    cout<<"voici le message dechiffre"<<resultat2<<endl;
}

else{
    cout<<"num incorrecte";
}
return 0;
}








