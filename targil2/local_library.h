#ifndef TARGIL2_LOCAL_LIBRARY_H
#define TARGIL2_LOCAL_LIBRARY_H

#include "books.h"

#define MIN(M,N) ((M<N)? M:N)

int num_books();
char* book_name(int book_number);

typedef void (*action)(const Book*);
const Book *firstBook();
void print_nicely(const Book* book);

void prints_non_fiction(const Book* book);
void print_most_promoted(const Book* book);
void do_for_books(const Book *books, int num, action _action);
int get_min_promotion(const Book *books);
float get_min_thrilling_factor(const Book *books);

#endif
