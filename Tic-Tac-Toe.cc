#include<iostream>
#include <stdlib.h>
#include<time.h>

using namespace std;

void asignarComputer(int &computer){ //Número random para el COMPUTER
	
	srand(time(NULL));
	
	computer = 1 + rand() % (9 - 1);
	
}

void dataInput(int &player, int &computer){
	
	int printComputer=computer+1;
	
	cout << "Enter your desired location [1-9] : ";
	cin >> player;
	
	player -= 1; //Restamos uno a player
	
	cout << "The computer picked: " << printComputer;
	
}

void playerPosition(int &player, int &fPlayer){
	
	if(player < 3){
		
		fPlayer = 0;
		
	}else if(player >= 3 && player < 6){
		
		fPlayer = 1;
		
	}else if(player >= 6){
		
		fPlayer = 2;
		
	}
	
}

void adjustmentPlayer(int &player){
	
	switch(player){
		
		case 3:
			
			player = 0;
			
			break;
			
		case 4:
			
			player = 1;
			
			break;
			
		case 5:
			
			player = 2;
			
			break;
			
		case 6:
			
			player = 0;
			
			break;
			
		case 7:
			
			player = 1;
			
			break;
			
		case 8:
			
			player = 2;
			
			break;
		
	}
	
}

void computerPosition(int &computer, int &fComputer){
	
	if(computer < 3){
		
		fComputer = 0;
		
	}else if(computer >= 3 && computer < 6){
		
		fComputer = 1;
		
	}else if(computer >= 6){
		
		fComputer = 2;
		
	}
	
}

void adjustmentComputer(int &computer){
	
	switch(computer){
		
		case 3:
			
			computer = 0;
			
			break;
			
		case 4:
			
			computer = 1;
			
			break;
			
		case 5:
			
			computer = 2;
			
			break;
			
		case 6:
			
			computer = 0;
			
			break;
			
		case 7:
			
			computer = 1;
			
			break;
			
		case 8:
			
			computer = 2;
			
			break;
		
	}
	
}

void asignarDatosTablero(char tablero[][3], int &fPlayer, int &player, int &fComputer, int &computer){
	
	int i, j;
	
	for(i=0;i<3;i++){

		for(j=0;j<3;j++){
				
			if(i==fPlayer && j==player){
		
				tablero[i][j] = 'X';
					
			}else if(tablero[i][j] != 'X' && tablero[i][j] != 'O'){
					
				tablero[i][j] = ' ';
					
			}
				
			if(i==fComputer && j==computer){
				
				tablero[i][j] = 'O';
					
			}else if(tablero[i][j] != 'O' && tablero[i][j] != 'X'){
					
				tablero[i][j] = ' ';
					
			}
				
		}
					
	}
	
}

int main(){
	
	int player, computer; //Variables de PLAYER y de COMPUTER
	char tablero[3][3]; //Tablero
	int fPlayer, fComputer; //Fila del tablero
	int printComputer=0;
	int i, j;
	bool verificar;
	
	cout << "Welcome to Tic Tac Toe. Player is X, computar is O." << endl;
	cout << "This is a new game. Board numbres are folows:" << endl;
		
	cout << "1 | 2 | 3" << endl; //cout << "0 | 1 | 2" << endl; //Fila 0
	cout << "4 | 5 | 6" << endl; //cout << "3 | 4 | 5" << endl; //Fila 1
	cout << "7 | 8 | 9" << endl; //cout << "6 | 7 | 8" << endl; //Fila 2
	
	do{
	
		asignarComputer(computer); //Inicializamos un número aleatorio para la jugada de la máquina	
		
		dataInput(player, computer); //Pedir posición al PLAYER e imprimir la posicion de COMPUTER
		
		playerPosition(player, fPlayer); //Le otorga la fila correspondiente a la posición de PLAYER
		adjustmentPlayer(player); //Ajusta el numero del PLAYER a la columna y fila correspondientes
		
		computerPosition(computer, fComputer); //Le otorga la fila correspondiente a la posición de Computer
		adjustmentComputer(computer); //Ajusta el numero del Computer a la columna y fila correspondientes
		
		if(player == computer && fPlayer == fComputer){
			
			asignarComputer(computer);
			
			computerPosition(computer, fComputer); //Le otorga la fila correspondiente a la posición de Computer
			adjustmentComputer(computer); //Ajusta el numero del Computer a la columna y fila correspondientes
			
			printComputer = computer+1;
			
			cout << endl << "The computer picked again and the second position picked is: " << printComputer;
			
		}
		
		cout << endl;
		
		asignarDatosTablero(tablero, fPlayer, player, fComputer, computer);
		
		for(i=0;i<3;i++){
			
			for(j=0;j<3;j++){
				
				if(j<2){
					
					cout << tablero[i][j] << " | ";	
					
				}else{
					
					cout << tablero[i][j];
					
				}
				
			}
			
			cout << endl;
		
		}
		
		for(i=0;i<3;i++){
			
			for(j=0;j<3;j++){
				
				if(tablero[0][j] == 'X' && tablero[1][j] == 'X' && tablero[2][j] == 'X'){
					
					verificar = true;
					
				}else if(tablero[i][0] == 'X' && tablero[i][1] == 'X' && tablero[i][2] == 'X'){
					
					verificar = true;
				
				}else if(tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X'){
					
					verificar = true;
					
				}else if(tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X'){
					
					verificar = true;
					
				}
				
				if(tablero[0][j] == 'O' && tablero[1][j] == 'O' && tablero[2][j] == 'O'){
					
					verificar = true;
					
				}else if(tablero[i][0] == 'O' && tablero[i][1] == 'O' && tablero[i][2] == 'O'){
					
					verificar = true;
				
				}else if(tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O'){
					
					verificar = true;
					
				}else if(tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O'){
					
					verificar = true;
					
				}
				
			}
			
		}
				
	}while(verificar == false);
	
	return 0;
	
}
