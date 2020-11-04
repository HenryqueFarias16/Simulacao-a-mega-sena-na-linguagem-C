/*
	Project: MegaSena Raffle
	Description: program to draw MegaSena, User informs amount of tens and which numbers you want to bet, and program performs
   	the random draw and pass on the values drawn and the amount of numbers hit by the user.

   	Author: Henryque Farias

	Date: 04/11/2020

*/
//			---importing libraries---
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
//			---Main function---
int main(){
inicio:
	setlocale(LC_ALL, "Portuguese");
	int M = 0, N = 0, i = 0,j, NumJaDigitado, VerificaNumero;	 									//Variables to store the numbers
    int numerosSorteados[6], numeroSorteado, numeroJaSorteado, acertos=0;							//Variables to store the numbers raffle
    char opcao;
	printf("\n		Sistema de Jogos da MegaSena\n");
    printf("\n 	Quantas dezenas você deseja jogar? ");
	scanf("%d",&M);
	getchar();																						//clear keyboard buffer
	int numeros [M];																				//vector creation of the size of the number of numbers that the user chose
if(M<6 || M>15){																					//checks if numbers of dozens are within the allowed range for betting
	printf("\n	Quantidade de dezenas invalidas, escolha entre 6 a 15 dezenas \n");
} //end if 
else{
	while(i<M){																						//repetition loop to check numbers typed.
		printf("	Digite um número entre 1 - 60: ");
		scanf("%d",&N);
		getchar();																					//clear keyboard buffer

		if(N <=0 || N >60){																			//Checking if the number entered is out of 1 and 60
			printf("\n 	Número invalido, por favor digite número entre 1 - 60 \n");
		}else{																						//The number is within 1 and 60.
			NumJaDigitado  = 0;
			for(VerificaNumero = 0; VerificaNumero<i; VerificaNumero++){							//Check if the number has already been entered.
				if(numeros[VerificaNumero]==N){
					NumJaDigitado = 1;
					printf("\n	Número já digitado \n");
					break;
				}
			}
		}
		if(NumJaDigitado ==0){
			numeros[i] = N;																			//insert numbers
			i++;																					//total increments of numbers typed
		}
		}//end else
	} //end while

//			---numbers raffle---
	srand(time(NULL));
	i=0;
    printf("\n	Números Sorteados foram: ");
while(i < 6){
        numeroSorteado = rand()  % 60;															//random selection from 1 to 60
        if(numeroSorteado==0){
        	numeroSorteado = rand()  % 60;															//random selection from 1 to 60
		}
        numeroJaSorteado = 0;
        for(VerificaNumero = 0; VerificaNumero < i; VerificaNumero++){								// from 0 to the total of numbers raffle
            if(numerosSorteados[VerificaNumero] == numeroSorteado){									//if the number has already been chosen it does not put in the raffle vector
                numeroJaSorteado = 1;
            }
        }
        if(numeroJaSorteado == 0){																	//if the number is not repeated put it in the vector of numbers raffle
            numerosSorteados[i] = numeroSorteado;
            i++;
            printf("%d ", numeroSorteado);															//prints raffled numbers
        }
    }//end while
    
//			---Checking total hits---
for(i = 0; i < 6; i++){																				//navigates through the vector of user numbers
    for(j = 0; j < 6; j++){																			//navigates in the numbers that were raffle
        if(numerosSorteados[i] == numeros[j]){							  						    //checks if the user's numbers are the same as in the raffle
            acertos++;																				//If it is hit, increments the value of the hit;
	        }
        }
    } //end for
    printf("\n	Você Acertou: %d\n", acertos);


	meio:
		printf("	Deseja fazer outro Jogo? s - sim, n - não\n");
		opcao =toupper(getche());
		getchar();
		printf("\n");
		switch(opcao){
			case'S':
				goto inicio;
				break;
			case 'N':
				goto fim;
				break;
			default:
				printf("		Opção invalida\n");
				goto meio;
		}

	fim:

    system("PAUSE");
	return 0;
}//end main  



