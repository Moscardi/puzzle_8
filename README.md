# puzzle_8

Universidade Tecnológica Federal do Paraná (UTFPR)
Departamento Acadêmico de Informática (DAINF)
Algoritmos II - 2 semestre de 2015
Professor: Rodrigo Minetto 
Trabalho Prático - T1

# 1 Objetivo
  O objetivo desse trabalho prático é aplicar os conceitos do Tipo Abstrato de Dados (TAD)
Fila, Lista ou Pilha para a resolução de um jogo conhecido como Quebra Cabȩca de Pastinha
(8-Puzzle).

#2 O jogo
  O jogo desse laboratório trata-se de uma pequena caixa quadrada, com 9 ou 16 espaços combertos por 8 ou 15 peças também quadradas, que contém números, figuras ou desenhos, e um espaço vazio para que se possa movimentá-las. As peças devem ser ordenadas na caixa em sequência, deslocando-se as peças ocupando o espaço vazio, fazendo quantos movimentos quiser sem retirá-las da caixa, colocando-as na ordem ou em alguma ordem pré-estabelecida.
  
# 3 Entrada
  Nesse primeiro trabalho prático iremos trabalhar com o jogo 8-puzzle. A entrada para o seu
programa será uma matriz de tamanho 9 × 9, que contém números de 1 a 8 em ordem aleatória
e um caractere especial ‘*’ que por convenção define o espaço livre para movimentar as peças.
A matriz abaixo é um possível exemplo para o seu programa:

12 8 3
 1 * 4
 7 6 5

A solução desse jogo acontece quando a matriz é manipulada de tal forma a ficar com a seguinte
configuração:

1 2 3
8 * 4
7 6 5

ou seja com caractere ‘*’ (espaço) no meio do tabuleiro e os números respeitando ordenação
acima e ao redor do ‘*’.

O objetivo desse laboratório é determinar o número mínimo de movimentos para atingir a
solução. Por exemplo, para o exemplo acima temos os seguintes movimentos
Número

2 8 3    2 * 3    * 2 3	   1 2 3    1 2 3
1 * 4 -> 1 8 4 -> 1 8 4 -> * 8 4 -> 8 * 4
7 6 5    7 6 5    7 6 5	   7 6 5    7 6 5

(CIMA/ESQUERDA/BAIXO/DIREITA)
	Matrizes com diferentes configura ̧c ̃oes podem exigir muito esfor ̧co computacional:
1 3 4
8 * 5
7 2 6
Solução: 6 movimentos.

2 3 1
7 * 8
6 5 4
Solução: 14 movimentos.

2 3 1
8 * 4
7 6 5
Solução: 16 movimentos.

8 7 6
1 * 5
2 3 4
Solução: 28 movimentos.

8 7 6
1 b 5
2 3 4
Solução: ? (deus sabe -> desafio).

# 4 Algoritimo
  Nesse trabalho você é livre para escolher se vai utilizar uma pilha ou fila, utilizando vetor
ou lista. Tome cuidado para o seu programa não estourar as possibilidades facilmente. Pense
em soluções criativas. A referência abaixo, que foi utilizada para definir esse laboratório,

http://web.mit.edu/6.034/wwwbob/EightPuzzle.pdf

descreve algoritmos mais aprimorados para resolver esse problema, no entanto você consegue
resolver o problema com os TADS vistos em sala (para soluções com pelo menos 16 movimentos).
A minha solução com TAD simples resolveu para 28 movimentos (sendo necessário um certo
tempo para isso).

# 5 Especificação do trabalho
O trabalho deve preferencialmente ser feito em dupla, e  ́e composto pelas partes:
	-> relatório (pdf)
	-> código-fonte (zip)

O relatório deve conter uma descrição detalhada do que foi feito. Mostre no relatório
execuções do seu programa e indique como devem ser colocados os dados de entrada. Você deve
obrigatoriamente utilizar os modelos de TAD vistos em aula (com Lista ou Vetor) apenas com
as modificações necessárias.
# 5.1 Sobre a organização do seu programa
Modularize o que for possível no seu código, implemente funções razoavelmente curtas,
separe a parte de definição das operações da parte de implementação (.c e .h). Seu código deve
ser comentado e indentado.

# 6 Informações sobre entrega
	-> Data de entrega: 16/10/2015 (sexta-feira).

# 7 Informações adicionais

	-> Dúvidas e ajuda para o trabalho preferencialmente com o monitor da disciplina ou após
o horário da aula (no atendimento ao aluno).
	-> Trabalhos com relatórios sem nome receberão nota ZERO.
	-> Cópias (com ou sem eventuais disfarces) receberão nota ZERO.
	-> Trabalho atrasados serão descontados em 50% por dia de atraso (enviar para o meu e-mail
em caso de atraso).
	-> O relatório e os códigos devem ser entregues via Moodle, através da conta de um dos
membros da dupla. Identifique o trabalho com os registros academicos da dupla e sem
espaços: XXXX YYYY.{rar,zip,tgz}.
	-> Peso do trabalho: 1.
