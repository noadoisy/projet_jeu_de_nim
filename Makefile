all : jeu_de_nim_sae jeu_de_nim_avance

jeu_de_nim_sae: jeu_de_nim_sae.c
	gcc -Wall -o jeu_de_nim_sae jeu_de_nim_sae.c

jeu_de_nim_avance: jeu_de_nim_avancé.c
	gcc -Wall -o jeu_de_nim_avance jeu_de_nim_avancé.c

clean:
	rm jeu_de_nim_avance jeu_de_nim_sae