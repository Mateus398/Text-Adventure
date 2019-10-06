#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <string>

bool randomCombate() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1
	
	if (valor == 0) //Se o valor randomico for igual a zero a função retorna como true
		return true;
	return false; //Se não ela retorna como falso
}

bool randomPossuiChave() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1

	if (valor == 0) //Se o valor randomico for igual a zero a função retorna como true
		return true;
	return false; //Se não ela retorna como falso
}

int ataqueCombate(int vidas) {
		vidas -= 2; //Diminui duas vidas do atacado
		return vidas; //Retorna a quantidade de vida
}

int defesaCombate(int vidas) {
		vidas -= 1; //Diminui uma vida
		return vidas; //Retorna a quantidade de vida
}


int randomAtaqueOuDefesa() {
	srand(time(NULL));//Inicializa o random
	int valor = rand() % 2; //Gera o número randomico entre 0 e 1

	return valor; //Retorna o valor
}

void navegacao() {
	int porta = 0; //Esta variavel controlará o número de portas
	bool combate; //Esta variavel receberá o valor randomico de true ou false
	int ataque = 0;

	std::cout << "Escolha uma porta: \n"; //Mostra a mensagem no console
	std::cin >> porta; //Atribui o valor da porta para a variavel

	switch (porta) //Para cada valor atribuido a variavel porta este bloco de código executará uma serie de comandos. 
	{
	case 1: std::cout << "Voce entrou na porta 1 \n"; //Mostra a mensagem no console
		combate = randomCombate(); //Atribui o valor randomico para a variavel combate
		if (combate == false) { //Se o valor randomico for falso...
			std::cout << "SEM COMBATE SORTUDO!!"; //Mostra a mensagem no console
			navegacao();
		}
		else {
			//Inicializa a vida dos jogadores com 5
			int vidasMaquina = 5; 
			int VidaJogador = 5;
			//Pergunto se o jogador que defender ou atacar //
			std::cout << "Voce deseja atacar ou defender? Para atacar digite 1, para defender digite 2: \n";//Mostra a mensagem no console
			std::cin >> ataque; //Lê a variavel e insere o valor que o jogador digitou na variavek ataque
			if (ataque == 1) { //Se ataque for 1 o sistema roda o bloco de codigo abaixo
				int resultadoCombate = ataqueCombate(vidasMaquina); //Chamo a função ataque que retorno a quantidade de vida após o ataque
				std::cout << "Voce atacou. Quantidade de vida do inimigo:" + std::to_string(resultadoCombate)+"\n"; //Mostra a quantidade de vida no console
				int resultadoCombateRandomico = randomAtaqueOuDefesa(); //Retorna 0 ou 1
				if (resultadoCombateRandomico == 1) { // se for 1 executo o cogigo abaixo
					int resultado = ataqueCombate(VidaJogador); //Ataca o jogador
					std::cout << "Você foi atacado! Sua vida é:" + std::to_string(resultado) + "\n"; //Mostra o resultado
				}
				else {
					int resultado = defesaCombate(vidasMaquina); //A maquina se defende
					//Mostra a quantidade de vida da maquina
					std::cout << "Seu oponente se defendeu. Quantidade de vidas dele:" + std::to_string(resultado) + "\n";
				}
			}
			else {
				//Se o jogador o jorgador digitar 2
			int resultadoDefesa = defesaCombate(VidaJogador); //Jogador se defende
			std::cout << "Voce Defendeu. Sua quantidade de vida é:" + std::to_string(resultadoDefesa) + "\n";
			}
		}
		break;
	case 2: std::cout << "Você entrou na porta 2 \n"; break;
	case 3: std::cout << "Você entrou na porta 3 \n"; break;
	case 4: std::cout << "Você entrou na porta 4\n"; break;
	case 5: std::cout << "Você entrou na porta 5 \n"; break;
	default: std::cout << "Porta Inexistente \n"; break;
	}

}

int main()
{
	int start = 0; //Esta variavel irá controlar o inicio do jogo
    std::cout << "Para iniciar o jogo digite 1\n"; //Mostra a mensagem no console
    std::cout << "Ou digite qualquer tecla para sair do jogo\n";//Mostra a mensagem no console
	std::cin >> start; //O valor digitado pelo usuário no console será atribuido a variavel start
	if (start == 1) { //Se a variavel start receber 1 o jogo é iniciado
		std::cout << "Historinha\n"; //Mostra a mensagem no console
		navegacao(); // Chama a função navegação. 
	}
}