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
#define UNKNOW_TOKEN 29

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
void addAndGetNextChar(){
    addChar();
    getChar();
}
int lookup(int ch){ //responsavel por identificar o token
    switch (ch)
    {
    case '(':
        addAndGetNextChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addAndGetNextChar();
        nextToken = RIGHT_PAREN;
        break;
    case '+':
        addAndGetNextChar();
        nextToken = OR_OP;
        break;
    case '*':
        addAndGetNextChar();
        nextToken = AND_OP;
        break;
    case '~':
        addAndGetNextChar();;
        nextToken = NOT_OP;
        break;
    case '-':
        addAndGetNextChar();
        if(nextChar =='>'){
            addAndGetNextChar();
            nextToken=IMPLY_OP;
            break;
        }
        nextToken = UNKNOW_TOKEN;
        break;
    case '<':
        addAndGetNextChar();
        if(nextChar=='-'){
            char nextCharaux = getc(in_fp);
            if(nextCharaux=='>'){
                addChar();
                ungetc(nextCharaux,in_fp);
                getChar();
                addAndGetNextChar();
                nextToken = IF_ONLY_OP;
                break;
            }
             ungetc(nextCharaux,in_fp);   
        }
        nextToken = UNKNOW_TOKEN;
        break;
    default:
        if(nextChar!=EOF)
            nextToken = UNKNOW_TOKEN;
        else    
            nextToken = EOF;
        addAndGetNextChar();
        break;
    }
}
void addChar(){ //formar o lexema
    if(lexLen<99){
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen]= 0;
    }
    else
        printf("Lexema mt grande!\n");
}
void getChar(){ //le o prox char e atualiza a sua classe
    nextChar=getc(in_fp);
    if(nextChar!=EOF)
        if(isalpha(nextChar))
            charClass=LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;   
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
void isKeyWord(){
    if(strcmp(lexeme,"True")==0) nextToken=TRUE_OP;
    if(strcmp(lexeme,"False")==0) nextToken=FALSE_OP;
}
int lex(){
    lexLen=0;
    getNonBlank();
    getNonComments();
    switch (charClass)
    {
    case LETTER:
        addAndGetNextChar();
        while(charClass == LETTER || charClass == DIGIT){
            addAndGetNextChar();
        }
        nextToken=IDENT;
        break;
    case DIGIT:
        addAndGetNextChar();
        while (charClass==DIGIT){
            addAndGetNextChar();
        }
        nextToken = INT_LIT;
        break;
    case UNKNOWN:
        lookup(nextChar);
        break;   
    case EOF:
        nextToken=EOF;
        lexeme[0]='E';
        lexeme[1]='O';
        lexeme[2]='F';
        lexeme[3]=0;
        break;
    }
    isKeyWord();//verifica se o lexema da vez eh o operador True or False
    if(nextToken==UNKNOW_TOKEN)
        printf("Lexema: %s nao reconhecido\n", lexeme);
    else
        printf("Proximo token: %d, Proximo lexema: %s\n",nextToken,lexeme);
    return nextToken;
}
void getNonComments(){
        if(nextChar=='/'){
        char next =getc(in_fp);
        if(next=='/'){
            while(next!='\n' && next!= EOF){
                next=getc(in_fp);
            }
            getChar();
            getNonComments();//chamada recursiva para verificar se a prox linha tem //
        }
        else{
            ungetc(next,in_fp);
        }
    }
}

