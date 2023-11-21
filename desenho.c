#include "desenho.h"
#include <stdio.h>

void desenho(int contador, int flagInicio) {
    if(flagInicio==0)
    {
        switch(contador)
        {
        case 0:
            printf("_____________	\n");
            printf("|.|__________|   \n");
            printf("|.|        _|_	\n");
            printf("|.|          	\n");
            printf("|.|        		\n");
            printf("|.|      	    \n");
            printf("|.| 			\n");
            printf("|.|				\n");
            printf("|.| 			\n\n");
            
            break;

        case 1:
			printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;

        case 2:
			printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|         |   \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;

        case 3:
            printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|        /|   \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;

        case 4:
			printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|        /|\\  \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;

        case 5:
			printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|        /|\\  \n");
			printf("|.|        /    \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;
        case 6:
			printf("_____________   \n");
			printf("|.|__________|   \n");
			printf("|.|        _|_  \n");
			printf("|.|         O   \n");
			printf("|.|        /|\\  \n");
			printf("|.|        / \\  \n");
			printf("|.|            \n");
			printf("|.|            \n");
			printf("|.|            \n\n");
            break;
        }

    }
    else
    {
        puts("______________                                                  ");
		puts("|.|___________|                                                 ");
		puts("|.|         _|_   \t\t                                          ");
		puts("|.|          O                                                  ");
		puts("|.|         /|\\                                                ");
		puts("|.|         / \\                                                ");
		puts("|.| ");
		puts("|.| ");
		puts("|.| ");
		puts("|.| ");
		puts("|.| ");

    }

}

