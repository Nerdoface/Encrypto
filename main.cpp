#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>


using namespace std;

string leesBestand(char* loc);
string encrypt(string inhoud, int encWaarde);
void schrijfBestand(string shit, char* loc);

// Main functie
int main(int argc, char* argv[])
{
 // Alleen iets doen als je een cmd argument meegeeft
 if(argc > 2)
 {
  // De bestandsnaam/locatie is standaard het eerste (en enige verwachtte) argument

  char* fNaam = argv[1];
  // De offset voor de ASCII verplaatsing is het tweede argument
  int offset = atoi(argv[2]);
  string inhoud = leesBestand(fNaam);
  string nieuw = encrypt(inhoud, offset);
  schrijfBestand(nieuw, fNaam);
 }


 return 0;
}

// Deze functie leest een bestand, returned de inhoud als string
string leesBestand(char* loc)
{
string regel, volBestand;
cout << "De bestandsnaam is: " << loc << endl;
ifstream bestand(loc);

  if(bestand.is_open())
  {

   while(getline(bestand, regel))
   {
    volBestand += regel + " ";
   }

  }
 cout << "Het bestand: " << volBestand;
 return volBestand;
}

string encrypt(string inhoud, int encWaarde)
{

 string encryptie;
 for(int i = 0; i < inhoud.size(); i++)
 {
  char c = inhoud[i];
  int asc = (int) c;
  if(asc + encWaarde < 255)
      asc += encWaarde;
  char d = (char) asc;
  encryptie += d;
 }
 cout << "De encryptie is: " << encryptie << endl;
 return encryptie;

}

void schrijfBestand(string shit, char* oudeNaam)
{

  string nNaam;
  nNaam = "enc-";
  nNaam.append(oudeNaam);
  ofstream nBestand(nNaam.c_str());
  if(nBestand.is_open())
  {
  nBestand << shit;
  nBestand.close();

  } 



}
