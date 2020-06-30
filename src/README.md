Project 1: Tokenizer
====================
# Instructions:

This program is written in C and uses advance concepts like pointers, double pointers, memory allocation, and structs.
To start, enter a string, this will be processed for spaces and separated words. Each word will have memory allocated and have its pointer, at the end of the pointer is an '\0' to indicate termination. The word will be kept in a struct containing the ID and the pointer to the next item. The pointers for the entered words will be stored in an array of pointers (double-pointers) which will have a '0' at the end of the array. Also, each string entered will be kept track of in a list using Structs. 

Example: String entered = Hello World!

Display: 

Token 1: Hello

Token 2: World!

By entering !* you print all of the strings you entered

By printing !(number) you print the word stored at ID
