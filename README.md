# puzzle_8

Universidade Tecnológica Federal do Paraná (UTFPR)
Departamento Acadêmico de Informática (DAINF)
Algoritmos II - 2 semestre de 2015
Professor: Rodrigo Minetto 
Trabalho Prático - T1

# 1 Objetivo
  O objetivo desse trabalho pr ́atico  ́e aplicar os conceitos do Tipo Abstrato de Dados (TAD)
Fila, Lista ou Pilha para a resolução de um jogo conhecido como Quebra Cabȩca de Pastinha
(8-Puzzle).
#2 O jogo
  O jogo desse laboratório trata-se de uma pequena caixa quadrada, com 9 ou 16 espaços combertos por 8 ou 15 peças também quadradas, que contém números, figuras ou desenhos, e um espaço vazio para que se possa movimentá-las. As peças devem ser ordenadas na caixa em sequência, deslocando-se as peças ocupando o espaço vazio, fazendo quantos movimentos quiser sem retirá-las da caixa, colocando-as na ordem ou em alguma ordem pré-estabelecida.
# 3 Entrada
  Nesse primeiro trabalho pr ́atico iremos trabalhar com o jogo 8-puzzle. A entrada para o seu
programa ser ́a uma matriz de tamanho 9 × 9, que cont ́em n ́
umeros de 1 a 8 em ordem aleat ́oria
e um caractere especial ‘*’ que por conven ̧c ̃ao define o espa ̧co livre para movimentar as pe ̧cas.
A matriz abaixo  ́e um poss ́ıvel exemplo para o seu programa
12 8 3
1 * 4
7 6 5
A solu ̧c ̃ao desse jogo acontece quando a matriz  ́e manipulada de tal forma a ficar com a seguinte
configura ̧c a  ̃ o
1 2 3
8 * 4
7 6 5
ou seja com caractere ‘*’ (espa ̧co) no meio do tabuleiro e os n ́
umeros respeitando ordena ̧c a  ̃ o
acima e ao redor do ‘*’.
O objetivo desse laborat ́orio  ́e determinar o n ́
umero m ́ınimo de movimentos para atingir a
solu ̧c a  ̃ o. Por exemplo, para o exemplo acima temos os seguintes movimentos
N ́
umero
2 8 3
2 * 3
*
1 * 4 -> 1 8 4 -> 1
7 6 5
7 6 5
7
C
Solu ̧
c~
ao: 4 movimentos (C
de movimentos
2 3
1 2 3
8 4 -> * 8 4
6 5
7 6 5
E
B
E B D).
->
1 2 3
8 * 4
7 6 5
D
(CIMA/ESQ/BAIXO/DIR)
Matrizes com diferentes configura ̧c ̃oes podem exigir muito esfor ̧co computacional:
1 3 4
8 * 5
7 2 6
Solu ̧
c~
ao: 6 movimentos.
2 3 1
7 * 8
6 5 4
Solu ̧
c~
ao: 14 movimentos.
2 3 1
8 * 4
7 6 5
Solu ̧
c~
ao: 16 movimentos.
8 7 6
1 * 5
2 3 4
Solu ̧
c~
ao: 28 movimentos.
8 7 6
1 b 5
2 3 4
Solu ̧
c~
ao: ? (deus sabe -> desafio).

# 4 Algoritimo
  Nesse trabalho vocˆe  ́e livre para escolher se vai utilizar uma pilha ou fila, utilizando vetor
ou lista. Tome cuidado para o seu programa n ̃ao estourar as possibilidades facilmente. Pense
em solu ̧c o  ̃ es criativas. A referˆencia abaixo, que foi utilizada para definir esse laborat ́orio,
http://web.mit.edu/6.034/wwwbob/EightPuzzle.pdf
descreve algoritmos mais aprimorados para resolver esse problema, no entanto vocˆe consegue
resolver o problema com os TADS vistos em sala (para solu ̧c o  ̃ es com pelo menos 16 movimentos).
A minha solu ̧c ̃ao com TAD simples resolveu para 28 movimentos (sendo necess ́ario um certo
tempo para isso).

# 5 Especificação do trabalho
O trabalho deve preferencialmente ser feito em dupla, e  ́e composto pelas partes:
❼ relat ́
orio (pdf)
❼ c ́
odigo-fonte (zip)
O relat ́orio deve conter uma descri ̧c ̃ao detalhada do que foi feito. Mostre no relat ́orio
execu ̧c o  ̃ es do seu programa e indique como devem ser colocados os dados de entrada. Vocˆe deve
obrigatoriamente utilizar os modelos de TAD vistos em aula (com Lista ou Vetor) apenas com
as modifica ̧c ̃oes necess ́arias.
# 5.1 Sobre a organização do seu programa
Modularize o que for poss ́ıvel no seu c ́odigo, implemente fun ̧c o  ̃ es razoavelmente curtas,
separe a parte de defini ̧c ̃ao das opera ̧c o  ̃ es da parte de implementa ̧c a  ̃ o (.c e .h). Seu c ́odigo deve
ser comentado e indentado.

# 6 Informações sobre entrega
❼ Data de entrega: 16/10/2015 (sexta-feira).

# 7 Informações adicionais
❼ D ́
uvidas e ajuda para o trabalho preferencialmente com o monitor da disciplina ou ap ́os
o hor ́ario da aula (no atendimento ao aluno).
❼ Trabalhos com relat ́
orios sem nome receber ̃ao nota ZERO.
❼ C ́
opias (com ou sem eventuais disfarces) receber ̃ao nota ZERO.
❼ Trabalho atrasados ser ̃ao descontados em 50% por dia de atraso (enviar para o meu e-mail
em caso de atraso).
