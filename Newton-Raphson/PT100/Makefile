prefix = bear --
all:
	@$(prefix) gcc -o PT PT_Base.c ./src/PT100.c ./src/PT100.h -I./src
	@gcc -o PTEs PT_Estimate.c ./src/PT100.c ./src/PT100.h -I./src
Base:
	@$(prefix) gcc -o PT PT_Base.c ./src/PT100.c ./src/PT100.h -I./src
Esti:
	@$(prefix) gcc -o PTEs PT_Estimate.c ./src/PT100.c ./src/PT100.h -I./src
clean:
	@rm PT PTEs compile_commands.json
