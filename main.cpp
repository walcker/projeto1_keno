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
  string s, s2, s3; 
  int creditos, rodadas, aux;

	//Abrindo arquivo
	ifstream fin; 

	// padrão é o modo ios::in
	fin.open("bet_12stpors.dat"); 

  //Informar de onde sai a aposta
  cout << "Aposta lida no arquivo bet_12stpors.dat." << endl;;
  cout << "===========================================" << endl;

  //Lendo as linhas até a terceira com os números
  getline(fin, s, '\n');
  //cout << s << endl;

  getline(fin, s2, '\n');
  //cout << s2 << endl;

  getline(fin, line, '\n');
  cout << "Seus números apostados são: " << line << endl;
  cout << "===========================================" << endl;


  fin.close();

  //Transformando para intstringstream cred;  
  stringstream cred;  
  cred << s;  
  cred >> creditos;

  //cout << creditos << endl;

  //Transformando para intstringstream rod;  
  stringstream rod;  
  rod << s2;  
  rod >> rodadas;

  //Transformando para intstringstream rod;  
  stringstream num(line);  
  vector<int> numeros;
  while( num >> aux)
  numeros.push_back( aux );

  //Informar total de créditos apostados
  cout << "Você apostará um total de: " << creditos << " créditos." << endl;
  cout << "===========================================" << endl;

  //Informar o número de rodadas
  cout << "Você jogará um total de: " << rodadas << " rodadas." << endl;
  cout << "===========================================" << endl;
  
  //Imprimeindo as variáveis para testar
  //cout << creditos << endl;
  //cout << rodadas << endl;
  cout << "Esta é sua aposta: ";
  for(auto i = numeros.begin() ;i != numeros.end(); i++){
    cout <<  *i << " ";
  }
  cout << endl;
  cout << "===========================================" << endl;

  cout << endl;

  //Gerando os 20 números aleatórios

  random_device rd; // obtain a random number from hardware
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distr(01, 80); // define the range

  //Criando vetor dos números sorteados
  vector<int> sorteio;

  //Loop principal para o número de rodadas
  for(int k = 0; k < rodadas; k++){
    int aux2 = 0;

  //Criando números aleatórios e colocando no vetor sorteio
  for(int i = 0 ;i < 20; i++){
        sorteio.push_back(distr(gen));
        cout << sorteio[i] << " ";
  }

  //Verifica quantos números acertou
  for(int i = 0; i < numeros.size(); i++){
    for(int j = 0; j < sorteio.size(); j++){
      if(numeros[i] == sorteio[j]){
        aux2++;
      }
    }
  }

  sorteio.clear();

  cout << endl;

  cout << "Você acertou: " << aux2 << " números." << endl;

  //criando tabela de retorno
  string c;

  //Abrindo arquivo
	ifstream tab; 

	// padrão é o modo ios::in
	tab.open("tabela.txt");

  double tabela[16][16];

  for(int i = 0; i < 16; i++){
    for(int j = 0; j < 16; j++){
   
      //jogando tabela na matriz
      tab >> tabela[i][j];

    }
  }


//Verificando quanto foi ganho
 cout << "Você ganhou: " << tabela[aux2][rodadas] * (creditos/rodadas) << endl;
  aux2 = 0;
  cout << endl;

  //Fim teste

  //Chamando a classe KenoBet
  //KenoBet* k = new KenoBet();

  }

	return 0; 
  
}