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
  double tabela [16][16];
  tabela [0][1] = 0;
  tabela [0][2] = 0;
  tabela [0][3] = 0;
  tabela [0][4] = 0;
  tabela [0][5] = 0;
  tabela [0][6] = 0;
  tabela [0][7] = 0;
  tabela [0][8] = 0;
  tabela [0][9] = 0;
  tabela [0][10] = 0;
  tabela [0][11] = 0;
  tabela [0][12] = 0;
  tabela [0][13] = 0;
  tabela [0][14] = 0;
  tabela [0][15] = 0;

  tabela [1][1] = 3;
  tabela [1][2] = 1;
  tabela [1][3] = 1;
  tabela [1][4] = 0.5;
  tabela [1][5] = 0.5;
  tabela [1][6] = 0.5;
  tabela [1][7] = 0.5;
  tabela [1][8] = 0.5;
  tabela [1][9] = 0.5;
  tabela [1][10] = 0;
  tabela [1][11] = 0;
  tabela [1][12] = 0;
  tabela [1][13] = 0;
  tabela [1][14] = 0;
  tabela [1][15] = 0;

  tabela [2][1] = 0;
  tabela [2][2] = 9;
  tabela [2][3] = 2;
  tabela [2][4] = 2;
  tabela [2][5] = 1;
  tabela [2][6] = 1;
  tabela [2][7] = 0.5;
  tabela [2][8] = 0.5;
  tabela [2][9] = 0.5;
  tabela [2][10] = 0.5;
  tabela [2][11] = 0.5;
  tabela [2][12] = 0;
  tabela [2][13] = 0;
  tabela [2][14] = 0;
  tabela [2][15] = 0;

  tabela [3][1] = 0;
  tabela [3][2] = 0;
  tabela [3][3] = 16;
  tabela [3][4] = 6;
  tabela [3][5] = 3;
  tabela [3][6] = 2;
  tabela [3][7] = 1;
  tabela [3][8] = 1;
  tabela [3][9] = 1;
  tabela [3][10] = 1;
  tabela [3][11] = 1;
  tabela [3][12] = 0.5;
  tabela [3][13] = 0.5;
  tabela [3][14] = 0.5;
  tabela [3][15] = 0.5;

  tabela [4][1] = 0;
  tabela [4][2] = 0;
  tabela [4][3] = 0;
  tabela [4][4] = 12;
  tabela [4][5] = 15;
  tabela [4][6] = 3;
  tabela [4][7] = 6;
  tabela [4][8] = 3;
  tabela [4][9] = 2;
  tabela [4][10] = 2;
  tabela [4][11] = 1;
  tabela [4][12] = 1;
  tabela [4][13] = 0.5;
  tabela [4][14] = 0.5;
  tabela [4][15] = 0.5;

  tabela [5][1] = 0;
  tabela [5][2] = 0;
  tabela [5][3] = 0;
  tabela [5][4] = 0;
  tabela [5][5] = 50;
  tabela [5][6] = 30;
  tabela [5][7] = 12;
  tabela [5][8] = 6;
  tabela [5][9] = 4;
  tabela [5][10] = 3;
  tabela [5][11] = 2;
  tabela [5][12] = 2;
  tabela [5][13] = 3;
  tabela [5][14] = 2;
  tabela [5][15] = 1;

  tabela [6][1] = 0;
  tabela [6][2] = 0;
  tabela [6][3] = 0;
  tabela [6][4] = 0;
  tabela [6][5] = 0;
  tabela [6][6] = 75;
  tabela [6][7] = 36;
  tabela [6][8] = 19;
  tabela [6][9] = 8;
  tabela [6][10] = 5;
  tabela [6][11] = 6;
  tabela [6][12] = 4;
  tabela [6][13] = 4;
  tabela [6][14] = 3;
  tabela [6][15] = 2;

  tabela [7][1] = 0;
  tabela [7][2] = 0;
  tabela [7][3] = 0;
  tabela [7][4] = 0;
  tabela [7][5] = 0;
  tabela [7][6] = 0;
  tabela [7][7] = 100;
  tabela [7][8] = 90;
  tabela [7][9] = 20;
  tabela [7][10] = 10;
  tabela [7][11] = 15;
  tabela [7][12] = 24;
  tabela [7][13] = 5;
  tabela [7][14] = 5;
  tabela [7][15] = 5;

  tabela [8][1] = 0;
  tabela [8][2] = 0;
  tabela [8][3] = 0;
  tabela [8][4] = 0;
  tabela [8][5] = 0;
  tabela [8][6] = 0;
  tabela [8][7] = 0;
  tabela [8][8] = 720;
  tabela [8][9] = 80;
  tabela [8][10] = 30;
  tabela [8][11] = 25;
  tabela [8][12] = 72;
  tabela [8][13] = 20;
  tabela [8][14] = 12;
  tabela [8][15] = 15;

  tabela [9][1] = 0;
  tabela [9][2] = 0;
  tabela [9][3] = 0;
  tabela [9][4] = 0;
  tabela [9][5] = 0;
  tabela [9][6] = 0;
  tabela [9][7] = 0;
  tabela [9][8] = 0;
  tabela [9][9] = 1200;
  tabela [9][10] = 600;
  tabela [9][11] = 180;
  tabela [9][12] = 250;
  tabela [9][13] = 80;
  tabela [9][14] = 50;
  tabela [9][15] = 50;

  tabela [10][1] = 0;
  tabela [10][2] = 0;
  tabela [10][3] = 0;
  tabela [10][4] = 0;
  tabela [10][5] = 0;
  tabela [10][6] = 0;
  tabela [10][7] = 0;
  tabela [10][8] = 0;
  tabela [10][9] = 0;
  tabela [10][10] = 1800;
  tabela [10][11] = 1000;
  tabela [10][12] = 500;
  tabela [10][13] = 240;
  tabela [10][14] = 150;
  tabela [10][15] = 150;

  tabela [11][1] = 0;
  tabela [11][2] = 0;
  tabela [11][3] = 0;
  tabela [11][4] = 0;
  tabela [11][5] = 0;
  tabela [11][6] = 0;
  tabela [11][7] = 0;
  tabela [11][8] = 0;
  tabela [11][9] = 0;
  tabela [11][10] = 0;
  tabela [11][11] = 3000;
  tabela [11][12] = 2000;
  tabela [11][13] = 500;
  tabela [11][14] = 500;
  tabela [11][15] = 300;

  tabela [12][1] = 0;
  tabela [12][2] = 0;
  tabela [12][3] = 0;
  tabela [12][4] = 0;
  tabela [12][5] = 0;
  tabela [12][6] = 0;
  tabela [12][7] = 0;
  tabela [12][8] = 0;
  tabela [12][9] = 0;
  tabela [12][10] = 0;
  tabela [12][11] = 0;
  tabela [12][12] = 4000;
  tabela [12][13] = 3000;
  tabela [12][14] = 1000;
  tabela [12][15] = 600;

  tabela [13][1] = 0;
  tabela [13][2] = 0;
  tabela [13][3] = 0;
  tabela [13][4] = 0;
  tabela [13][5] = 0;
  tabela [13][6] = 0;
  tabela [13][7] = 0;
  tabela [13][8] = 0;
  tabela [13][9] = 0;
  tabela [13][10] = 0;
  tabela [13][11] = 0;
  tabela [13][12] = 0;
  tabela [13][13] = 6000;
  tabela [13][14] = 2000;
  tabela [13][15] = 1200;

  tabela [14][1] = 0;
  tabela [14][2] = 0;
  tabela [14][3] = 0;
  tabela [14][4] = 0;
  tabela [14][5] = 0;
  tabela [14][6] = 0;
  tabela [14][7] = 0;
  tabela [14][8] = 0;
  tabela [14][9] = 0;
  tabela [14][10] = 0;
  tabela [14][11] = 0;
  tabela [14][12] = 0;
  tabela [14][13] = 0;
  tabela [14][14] = 7500;
  tabela [14][15] = 2500;

  tabela [15][1] = 0;
  tabela [15][2] = 0;
  tabela [15][3] = 0;
  tabela [15][4] = 0;
  tabela [15][5] = 0;
  tabela [15][6] = 0;
  tabela [15][7] = 0;
  tabela [15][8] = 0;
  tabela [15][9] = 0;
  tabela [15][10] = 0;
  tabela [15][11] = 0;
  tabela [15][12] = 0;
  tabela [15][13] = 0;
  tabela [15][14] = 0;
  tabela [15][15] = 10000;

  //Verificando quanto foi ganho
  //for(int i = 0; i < rodadas; i++){
  cout << "Você ganhou: " << tabela[aux2][rodadas] * (creditos/rodadas) << endl;
  cout << endl;
  }
  //Fim teste

  //Chamando a classe KenoBet
  //KenoBet* k = new KenoBet();

	return 0; 
} 
