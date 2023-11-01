#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>

int charClass; 
char lexeme [100]; 
char nextChar; 
int lexLen; 
int token; 
int nextToken;
FILE *in_fp, *fopen(); 
/* Declarações de função */
void addChar(); 
void getChar(); 
void getNonBlank(); 
int lex();
void getNonComments();
/* Classes de caracteres */ 
#define LETTER 0 
#define DIGIT 1
#define KEYWORD 98
#define UNKNOWN 99
/* Códigos de tokens */ 
#define INT_LIT 10 
#define IDENT 11 
#define OR_OP 20 
#define AND_OP 21 
#define TRUE_OP 22 
#define FALSE_OP 23 
#define IMPLY_OP 24 
#define LEFT_PAREN 25 
#define RIGHT_PAREN 26
#define IF_ONLY_OP 27
#define NOT_OP 28

int main(){
    in_fp=fopen("entrada.in","r");
    if(in_fp==NULL){
        printf("Erro ao abrir arquivo\n");
    }
    else{
        getChar();
        do{
            lex();
        }while (nextToken!=EOF);
        
    }
}
int lookup(char ch){
    switch (ch)
    {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    case '+':
        addChar();
        nextToken = OR_OP;
        break;
    case '*':
        addChar();
        nextToken = AND_OP;
        break;
    case '~':
        addChar();
        nextToken = NOT_OP;
        break;                                       
    default:
        addChar();
        nextToken = EOF;
        break;
    }
}
void addChar(){ //formar o lexema
    if(lexLen<99){
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen]= 0;
    }
    else
        printf("Lexema mt grande!/n");
}
void getChar(){ //le o prox char e atualiza a sua classe
    nextChar=getc(in_fp);
    if(nextChar!=EOF)
        if(isalpha(nextChar))
            charClass=LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else if(nextChar=='-'||nextChar=='>'||nextChar=='<')
            charClass = KEYWORD;    
        else
            charClass = UNKNOWN;    
    else
        charClass = EOF;
}
void getNonBlank(){ //ignorar espaços em branco
    while(isspace(nextChar)){
        getChar();
    } 
}
int lex(){
    lexLen=0;
    getNonBlank();//primeira chamada getchar
    getNonComments();
    //printf("char que sera analisado: %c", nextChar);
    switch (charClass)
    {
    case LETTER:
        addChar();
        getChar();
        while(charClass == LETTER || charClass == DIGIT){
            addChar();
            getChar();
        }
        nextToken=IDENT;
        break;
    case DIGIT:
        addChar();
        getChar();
        while (charClass==DIGIT){
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;
    case KEYWORD:
        addChar();
        getChar();
        while(charClass==KEYWORD){
            addChar();
            getChar();
        }
        if(strcmp(lexeme,"->")==0)
        nextToken = IMPLY_OP;
        if(strcmp(lexeme,"<->")==0)
        nextToken = IF_ONLY_OP;
        break;

    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;   
    case EOF:
        nextToken=EOF;
        lexeme[0]='E';
        lexeme[1]='O';
        lexeme[2]='F';
        lexeme[3]=0;
        break;
    }
    if(strcmp(lexeme,"True")==0)
        nextToken = TRUE_OP;
    if(strcmp(lexeme,"False")==0)
        nextToken = FALSE_OP;
    printf("Proximo token: %d, Proximo lexema: %s\n",nextToken,lexeme);
    return nextToken;
}
void getNonComments(){
    //ignorar comentarios
        if(nextChar=='/'){
        char next =getc(in_fp);
        if(next=='/'){
            while(next!='\n' && next!= EOF){
                next=getc(in_fp);
            }
            //ungetc(next,in_fp);
            getChar();
            //printf("valor do nextChar: %c", nextChar);
            getNonComments();
        }
        else{
            ungetc(next,in_fp);
        }
    }
}

