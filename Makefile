CLT = client
SRV = server

CC = cc

CFLAGS = -W -W -W

HDR = Minitalk.h

SRC = client.c server.c outils.c

OBJ = $(SRC:.c=.o)

all: $(CLT) $(SRV)

$(CLT): outils.c client.c
	$(CC) $(CFLAGS) $^ -o $(CLT)

$(SRV): outils.c server.c
	$(CC) $(CFLAGS) $^ -o $(SRV)

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(CLT) $(SRV)

re: fclean all