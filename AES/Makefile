prefix = bear --
all:
	@$(prefix) gcc -o AES test/AES.c aes.c aes.h -I./
	@gcc -o DEAES test/DEAES.c aes.c aes.h -I./
aes:
	@$(prefix) gcc -o AES test/AES.c aes.c aes.h
deaes:
	@$(prefix) gcc -o DEAES test/DEAES.c aes.c aes.h
clean:
	@rm  AES DEAES compile_commands.json
