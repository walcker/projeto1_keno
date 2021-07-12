#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <new>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char *argv[]){

  //Permite usar acentos
  setlocale(LC_ALL,"");

	//Declaração de variáveis
  string line;
  string s, s2; 
  int creditos, rodadas, aux;

	//Abrindo arquivo
	ifstream fin; 

	// padrão é o modo ios::in
	fin.open("bet_12stpors.dat"); 

  //Lendo as linhas até a terceira com os números
  getline(fin, s, '\n');
  cout << s << endl;

  getline(fin, s2, '\n');
  cout << s2 << endl;

  getline(fin, line, '\n');
  cout << line << endl;

  fin.close();

  //Transformando para intstringstream cred;  
  stringstream cred;  
  cred << s;  
  cred >> creditos;

  cout << creditos << endl;

  //Transformando para intstringstream rod;  
  stringstream rod;  
  rod << s2;  
  rod >> rodadas;

  //Transformando para intstringstream rod;  
  stringstream num(line);  
  vector<int> numeros;
  while( num >> aux)
  numeros.push_back( aux );
  
  //Imprimeindo as variáveis para testar
  cout << creditos << endl;
  cout << rodadas << endl;
  for(auto i = numeros.begin() ;i != numeros.end(); i++){
    cout << *i << " ";
  }

  cout << endl;

  //Gerando os 20 números aleatórios

  random_device rd; // obtain a random number from hardware
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distr(01, 80); // define the range

  //Criando vetor dos números sorteados
  vector<int> sorteio;

  //Criando números aleatórios e colocando no vetor sorteio
  for(int i = 0 ;i < 20; i++){
        //cout << distr(gen) << " ";
        //int b = rand() % 20 + 1;
        sorteio.push_back(distr(gen));
        cout << sorteio[i] << " ";
  }


  //Chamando a classe KenoBet
  //KenoBet* k = new KenoBet();

	return 0; 
} 
