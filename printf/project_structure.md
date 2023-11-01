│
├──
└──

project/
│
├── src/
│   ├── ft_printf.c
│   ├── ...
│   └── other_source_files.c
│
├── includes/
│   ├── ft_printf.h
│   └── ...
│
├── libft/           (If applicable)
│   ├── libft.a
│   ├── ...
c Makefile
├── _bonus.c        (If needed for bonus part)
├── _bonus.h        (If needed for bonus part)
├── main.c          (For testing if applicable)
└── ...


├──correr a string ate encontrar % ou \
├──dar print do que veio antes
├──dai verificar se as flags são usáveis
│	├──se sim chamar va_list (ver como se faz isso), 
│	│	└──imprimir logo, fazer conversar usando as flags dadas
│	└──caso falhe passar erro
└──continua até ao fim da string

\a      Write a <bell> character.
\b      Write a <backspace> character.
\f      Write a <form-feed> character.
\n      Write a <new-line> character.
\r      Write a <carriage return> character.
\t      Write a <tab> character.
\v      Write a <vertical tab> character.
\'      Write a <single quote> character.
\\      Write a backslash character.
\num    Write a byte whose value is the 1-, 2-, or 3-digit octal number num.  Multibyte characters can be constructed using multiple \num sequences.


Ter função onde entra o va, retira o ultimo val da flag e chama f. de conversão

cada uma destas f. tera uma string com flags aceitáveis e lida uma a uma com cada.
Primeiro flags de conversão (#, +, " ", .num, *0), depois de formatação (- 0 num) ver melhor
antes chamar f. para simplificar e partir as flags, (se - remove 0, se num no fim remove num inicio)
existe o problema que # e + aplicam-se ao inicio se - e fora se 0

%c convert int to char
%s get string
%p get memory adress &
%d 
%i igual a d, se existir 
%u
%x conversão, com escola x ou X
%X

teste:  1234%
teste: 1234%  
 