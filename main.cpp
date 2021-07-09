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

  /*int ic; //initial credit
  int nr; //number of rounds
  int spots;// numeros apostados, máximo 15*/

  string vetor[3];

  //imprime todos os argumentos recebidos na execução
  //do programa, para testar, compile e faça
  //./a.out arg1 arg2 arg2
  //o primeiro argumento é sempre o nome 
  //do programa (a.out, neste exemplo)

  //Coloca os argumentos no vetor argv
  for(int i = 0; i < argc; i++){
    cout << "Argumento[" <<i<< "]: " << argv[i] << endl;
    vetor[i] = argv[i]; //atribui os valores do argv a um vetor
  }

  cout << endl;

  //Imprime o vetor que recebe os valores do argv
  for(int i = 0; i <= 3; i++){
    cout << vetor[i] << " " << endl;
  }
  
  ofstream fout; 

	string line; 

	// Por padrão, ios::out sempre deleta os conteúdos atuais 
	// do arquivo. Para não deletar os conteúdos, use ios:app 
	// fout.open("sample.txt", ios::app) 
	fout.open("bet_12stpors.dat", ios::app); 

	// Se o arquivo foi aberto 
	while (fout) { 

		getline(cin, line); 

		// digite -1 para sair 
		if (line == "-1") 
			break; 

		// escreve no arquivo
		fout << line << endl; 
	} 

  
  // fecha o arquivo 
	fout.close(); 

	ifstream fin; 

	// padrão é o modo ios::in
	fin.open("bet_12stpors.dat"); 

	// Executa o loop enquanto fin não é EOF(end of file)
	while (fin) { 

		// lê uma linha do arquivo
		getline(fin, line); 

		cout << line << endl; 
	} 

	// fehca o arquivo
	fin.close(); 

	return 0; 
} 
