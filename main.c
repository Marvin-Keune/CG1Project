#include <stdio.h>
//Assert Header zum Absichern
#include<assert.h>  
//Open() and creat()  
#include<fcntl.h>   
//Acces Permission for open (Read Only)
#include<sys/stat.h> 
//close(), read(), write(), lsek()
#include<unistd.h>   
#include <string.h> 
//Um die Zeit zu stoppen 
#include <time.h> 
// fuer gettimeofday()
#include <sys/time.h>     
#include <errno.h>  
//for use of wide character with more than 1 byte per character
#include <wchar.h>  



#define BUFFERSIZE 100      



int aufgabe3(void){
	int fehler_nr=0;
	for(fehler_nr=1; fehler_nr<=99;fehler_nr++){
		fprintf(stderr, "%3d->strerror : %s\n", fehler_nr, strerror(fehler_nr));
		errno = fehler_nr;
		perror("     perror");
	}
	return 0;
}

int aufgabe4(void){
	int character;
	while( (character=fgetc(stdin)) != EOF){  //EOF  Strg+d
		fputc(character,stdout);
	}
	return 0;
}
//Man kann ein Textdokument in stdin im Programm umleiten mit  ./ausfuehren <textdokument.txt
//  ./ausfuehren < textdokument.txt > kopietext.txt     Das zweite ist die stdout in kopietext.txt umleiten.
int aufgabe4b(void){
	struct timeval t1, t2;
   	gettimeofday(&t1, NULL);

	aufgabe4();

	gettimeofday(&t2, NULL);
	printf("S= %ld + MS= %ld",t2.tv_sec - t1.tv_sec, t2.tv_usec - t1.tv_usec);
	return 0;
}

int aufgabe4c(void){
	char character[BUFFERSIZE];
	printf("Write something : ");
	fgets(character, BUFFERSIZE, stdin);
	if(fputs(character,stdout)==EOF) perror(strerror(errno));
	
	return 0;
}


int main(void) {
    aufgabe4c();
    return 0;
}

















































