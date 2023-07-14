CC := g++
FLAGS := -I include/ -Wall -g
BUILD := build/
SRC := src/
TESTEDIR := tests
TARGET := main.exe

all: main 

carta:
	$(CC) $(FLAGS) -c $(SRC)/carta.cpp -o $(BUILD)/carta.o

baralho:
	$(CC) $(FLAGS) -c $(SRC)/baralho.cpp -o $(BUILD)/baralho.o

jogador:
	$(CC) $(FLAGS) -c $(SRC)/jogador.cpp -o $(BUILD)/jogador.o

humano:
	$(CC) $(FLAGS) -c $(SRC)/humano.cpp -o $(BUILD)/humano.o

bot:
	$(CC) $(FLAGS) -c $(SRC)/bot.cpp -o $(BUILD)/bot.o

rodada:
	$(CC) $(FLAGS) -c $(SRC)/rodada.cpp -o $(BUILD)/rodada.o

jogo:
	$(CC) $(FLAGS) -c $(SRC)/jogo.cpp -o $(BUILD)/jogo.o

menu:
	$(CC) $(FLAGS) -c $(SRC)/menu.cpp -o $(BUILD)/menu.o

main: carta baralho jogador humano bot rodada menu jogo
	$(CC) $(FLAGS) $(BUILD)/*.o $(SRC)/main.cpp -o $(TARGET)

test: carta	baralho jogador humano bot rodada menu jogo
	$(CC) $(FLAGS) $(TESTEDIR)/truco_test.cpp $(BUILD)/*.o -o test.exe

clean: 
	$(RM) -r $(BUILD)/* $(TARGET)