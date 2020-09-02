#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
	char nome[20]; 
	int idade;
} Pessoa; 

Pessoa criaPessoa(char *nome, char *idade) {

	Pessoa p; 

	strcpy(p.nome,nome);
	p.idade = atoi(idade);

	return p; 
}

int insere(Pessoa p) {

	int fd = open("data",O_CREAT | O_APPEND | O_RDWR,0666);

	write(fd,&p,sizeof(Pessoa));

	int num_bytes = lseek(fd,-sizeof(Pessoa),SEEK_CUR); 

	return num_bytes/sizeof(Pessoa);
}

int mudaPorNome(Pessoa p) {

	int fd = open("data",O_CREAT | O_APPEND | O_RDWR,0666);

	Pessoa aux; 

	while (read(fd,&aux,sizeof(Pessoa)) > 0) {

		if (!strcmp(aux.nome,p.nome)) {

			lseek(fd,-sizeof(Pessoa),SEEK_CUR); 

			write(fd,&p,sizeof(Pessoa));

			return 0;
		}
	}

	printf("Nao encontrado!\n");

	return 0; 
}

int mudaPorPosicao(int pos, int idade) {

	Pessoa new, aux; 

	int fd = open("data",O_CREAT | O_APPEND | O_RDWR,0666);

	new.idade = idade; 

	lseek(fd,pos*sizeof(Pessoa),SEEK_SET); 

	read(fd,&aux,sizeof(Pessoa)); 

	strcpy(new.nome,aux.nome);

	lseek(fd,-sizeof(Pessoa),SEEK_CUR);

	write(fd,&new,sizeof(Pessoa)); 

	return 0; 
}

int encontra(int pos) {

	int fd = open("data",O_CREAT | O_APPEND | O_RDWR,0666);

	Pessoa p; 

	lseek(fd,pos*sizeof(Pessoa),SEEK_SET);

	read(fd,&p,sizeof(Pessoa));

	printf("Nome: %s Idade: %d\n",p.nome,p.idade);

	return 0;

}

int main(int argc, char **argv) {


	if (argc<3 && argc>4) {
		write(1,"Erro!",5); 
		return 1; 
	}

	if (!strcmp(argv[1],"-i")) {

		Pessoa p = criaPessoa(argv[2],argv[3]);

		printf("Inserido em: %d\n",insere(p));

	} else if (!strcmp(argv[1],"-u")) {

		Pessoa p = criaPessoa(argv[2],argv[3]); 

		mudaPorNome(p);

		printf("Alterado!\n");

	} else if (!strcmp(argv[1],"-o")) {

		int pos = atoi(argv[2]);
		int idade = atoi(argv[3]);

		mudaPorPosicao(pos,idade); 

		printf("Alterado!\n");

	} else if (!strcmp(argv[1],"-b")) {

		int pos = atoi(argv[2]);

		encontra(pos);
	}

	return 0;
}