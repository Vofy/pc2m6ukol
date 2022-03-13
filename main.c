#include "stdio.h"
#include "string.h"

int main( void)
{
    char stext1[]="AKEQYHUQOTTSQT";			// prvni cast sifrovane zpravy
    char stext2[]="TQJHKSHYMMTTSR";			// druha cast sifrovane zpravy
    char rtext[150];						// vysledny retezec
    char c;

    // a)

    strcpy(rtext, stext1);
    strcpy(rtext + strlen(rtext), stext2);

    printf("\na) Concatenation:\n\n%s\n\n", rtext);			// tisk vysledku

    // b)

    for(size_t i = 0; i < strlen(rtext); i++)
    {
        if(rtext[i] == 'Q')
            rtext[i] = 'C';
        if(rtext[i] == 'T')
            rtext[i] = 'B';
    }

    printf("b) Replacement Q=>C and T=>B:\n\n%s\n\n", rtext); // tisk vysledku

    // c)

    for(size_t i = 0; i < strlen(rtext); i++)
    {
        if(rtext[i] != 'Z')
            rtext[i]++;
        else
            rtext[i]-= 31;
    }

    printf("c) Shift up in ASCII table:\n\n%s\n\n", rtext); // tisk vysledku

    // d

    char rm[] = {'R','M'};
    char *cc = rtext;

    do
        cc = strstr(cc, "CC");
    while(cc != NULL && strncpy(cc, rm, 2));

    printf("d) Replacement CC=>RM:\n\n%s\n\n", rtext);		// tisk vysledku

    // e)

    for(size_t i = 0; i < strlen(rtext); i++)
        rtext[i] = 155 - rtext[i];

    printf("e) Rotation in ASCII table:\n\n%s\n\n", rtext);	// tisk vysledku

    // f)

    for(size_t i = 0; i < strlen(rtext); i++)
        if (i > 0)
            rtext[i] += 32;

    printf("f) Replacement capital=>small:\n\n%s\n\n", rtext);// tisk vysledku

    // g)

    for(size_t i = 0; i < strlen(rtext); i++)
    {
        if(rtext[i] == 'w')
            rtext[i] = ' ';
        if(rtext[i] == 'h')
            rtext[i] = '.';
    }

    printf("g) Replacement w=><space> and h=>. :\n\n%s\n\n", rtext); // tisk vysledku

    scanf("%c", &c);										// cekani na klavesu
    return 0;												// programvraci 0
}
