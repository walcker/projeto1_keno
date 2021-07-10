#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <string>
#include <fstream>
#include <iostream>
#include <new>

using namespace std;

int main(int argc, char *argv[]){

  //Permite usar acentos
  setlocale(LC_ALL,"");

	//Declaração de variáveis
  string line;
  string s, s2; 

	//Abrindo arquivo
	ifstream fin; 

	// padrão é o modo ios::in
	fin.open("bet_12stpors.dat"); 

  //Lendo as linhas até a terceira com os números
  getline(fin, line, '\n');
  cout << line << endl;

  getline(fin, line, '\n');
  cout << line << endl;

  getline(fin, line, '\n');
  cout << line << endl;
  
  fin.close();

	return 0; 
} 
