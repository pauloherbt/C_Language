Construir um interpretador léxico para expressões lógicas. Seu analisador léxico deverá analisar expressões da forma
(A+B)*C -> D
que significa "(A ou B) e C implica D" onde A, B e C são variáveis.
As variáveis deverão ser formadas por qualquer tipo de palavra e número. Não é permitido o uso de símbolos especiais no nome de uma variável, nem é permitido variáveis muito longas, com mais de 100 caractéres.
Seu analisador léxico deverá ignorar comentários. Os comentários sempre serão escritos após \\ e até o final da linha.
Uma expressão poderá usar
()
+ para "ou"
* para "e" 
True para "verdadeiro"
False para "falso"
-> para "implica"
<-> para "se e só se"
¬ para "não"
Por fim, seu programa deverá ler a entrada a partir de um arquivo chamado entrada.in

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
