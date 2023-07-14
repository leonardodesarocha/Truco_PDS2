# Trabalho Final de Programação e Desenvolvimento de Software II

### Desenvolvedores: <p>
• Daniel Augusto <p>
• Leonardo D'avila <p>
• Leonardo Fernandes <p>

### Funcionamento do Projeto: <p>
Nosso grupo decidiu realizar para o trabalho final um jogo de cartas, o Truco Mineiro. O truco é composto por duas
duplas onde cada integrante possui três cartas por rodada e jogam uma melhor de três. O objetivo do jogo é vencer duas quedas
“matando” as cartas do seu oponente, ou seja, jogando uma carta mais forte. Dessa maneira, caso uma dupla ganhe a primeira queda, 
a dupla oponente ganhe a outra queda e durante a terceira queda ocorra um empate devido ao lançamento de cartas do mesmo peso,
ninguém ganha a pontuação da rodada. <p>

Nosso trabalho consiste em um jogo single player no qual o jogador terá um bot aliado e 2 bots
inimigos, formando assim as duas duplas. Vale ressaltar que a principal diferença em relação ao projeto implementado e o Truco Mineiro é o momento para pedir truco. O primeiro implementa a lógica de forma que quando algum jogador pede truco os demais conseguem aceitar ou recusar, se aceitarem aumenta o valor da aposta, caso contrário o jogo continua. Porém, para o outro tipo, caso o pedido de truco seja realizado, os jogadores poderão aceitar ou aumentar a aposta, se recussarem perderão a rodada. Além disso, no nosso projeto não existe a "mão de ferro". A função da "mão de ferro" no Truco Mineiro é, em caso de empate em 10 a 10, as duas duplas disputam a mão as cegas. As cartas permanecem viradas de cabeça para baixo, ninguém pode ver suas próprias cartas. Quem vencer a mão ganha o jogo.<p>

Dentro do sistema o truco terá a implementação de um sistema de login de usuários, por meio da checagem do nome de usuário 
e da senha cadastrada em um arquivo txt, que servirá para controlar a quantidade de partidas jogadas, vitórias e derrotas
de cada jogador. Ao iniciar o jogo será exibido um menu de opções onde o jogador poderá se cadastrar, exibir o ranking de
jogadores (baseado nos históricos das outras partidas salvas) ou iniciar a partida. Caso inicie a partida o usuário entrada
em um fluxo de jogadas que simulará o truco real. Ao final desse partida, o resultado será automaticamente cadastrado
no arquivo que salva os históricos, e novamente o menu de opções será exibido. 


### Diagrama de Classe

<img src="https://github.com/acpDaniel/TP-PDS2/blob/main/Modelagem%20do%20Sistema.png" width="1000" height="750" title="DIAGRAMA DE CLASSES">

### User Stories 

1- Como jogador eu quero salvar meu histórico de partidas para acompanhar meu progresso. <p>

Critérios de aceitação: <p>
• Visualização do histórico ao final de cada partida. <p>
• Visualização da porcentagem de vitórias. <p>
• Cada partida deve ser salva automaticamente após seu encerramento. <p>

2- Como jogador eu quero jogar com bots para praticar quando estiver sozinho. <p>

Critérios de aceitação: <p>
• Cada bot deve executar jogadas de maneira autônoma. <p>
• As decisões de cada bot são feitas randomicamente. <p>
• Cada partida deverá apresentar 3 bots. <p>

3- Como jogador eu quero poder ver as cartas na mesa e as minhas a cada rodada para bolar minha estratégia. <p>
Critérios de aceitação: <p>
• Visualização de todas as cartas na mesa, pelo nome e naipe. <p>
• Diferenciação das cartas da dupla adversária. <p>
• Visualização das cartas do usuário. <p>

4- Como usuário eu quero ter a possibilidade de iniciar uma nova partida após encerrar a atual para decidir se continuarei a jogar. <p>
Critérios de aceitação: <p>
• Visualização de um menu final após o jogo. <p>
• Mostrar uma opção para jogar novamente. <p>
• Mostrar uma opção para encerrar o jogo. <p>

5- Como usuário eu quero registar meu nome para me identificar no ranking e na partida. <p>
Critérios de aceitação: <p>
• Visualização de uma opção para registar o nome completo ao inicializar o jogo. <p>
• Cada usuário terá suas informações cadastradas no ranking. <p>
• O ranking será ordenado pela porcentagem de vitórias de cada usuário. <p>

### Compilar e rodar o jogo: 
• Digitar make e depois rodar o main.exe. <p>

### Compilar e rodar os testes:
• Digitar make test e depois ./test.exe < entradas.txt  <p>
