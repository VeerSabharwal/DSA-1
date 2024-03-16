#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
FILE*file;
char*message ="HELLO WORLD";
char read_message[100];

//write a message to file
file =fopen("hello_world.txt","w");
fwrite(message,sizeof(char),strlen(message),file);
fclose(file);

//read a message from file
file=fopen("hello_world.txt","r");
fread(read_message,sizeof(char),strlen(message),file);
fclose(file);

// print the message
printf("%s\n",read_message);
return 0;
}
