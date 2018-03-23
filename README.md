# speller CS50/pset5

Speller is a a program that spell-checks a file. 
That was the most challenging task in CS50.

I had to implement a spell-checks program that loads dictionary in memory, 
then loads some text in memory, checks every word in a text 
and make a conclusion about how many words are misspelled, 
how long does it takes to load a dictionary and so on.

I had a lot of distribution code for this task but I fully implemented following functions
in dictionary.c:

- load 
- check
- size
- unload

Besides my program should not cause any memory leaks and use memory
as efficiently as it's possible.
For the load function I had to decide what structure should I use: 
double or single linked lists, hashtable or trie.
I decided to use trie because it's the most efficient
and the most difficult on my opinion.

This challenging task helped me to understand what memory management is and how powerful this tool is.
