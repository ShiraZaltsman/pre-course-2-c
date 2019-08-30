#ifndef TARGIL2_BOOKS_H
#define TARGIL2_BOOKS_H
#include <stdio.h>
#include <stdlib.h>
#include "Genre.h"

#define COVER 0x01
#define INDEXING 0x02
#define MISSING_PAGE 0x04
#define BAR_CODE 0x08
#define SPINE 0x10
#define PAGE_STAINED 0x20

#define librarian_mask  0x00001011 /* mask problem with cover, index or bar code */
#define bookbinder_mask  0x00110100 /* mask problem with spine, or missing / stained pages */
#define repairable_mask 0x00100100 /* mask for missing or stained pages */
#define ok_mask 0x00000000

#define MIN_MOST_PROMOTION 50

/* order matter! */
typedef enum Zone {
    KIDS,
    HIGHSCHOOL,
    ADULT,
    DOCUMENTARY,
    COMICS
}Zone;

typedef enum Bool {
    FALSE=0,
    TRUE=1
}Bool;

typedef struct Book {
    unsigned short book_number;
    char  name[50];
    int   promotion;
    Zone zone;
    Genre genre;
    char gen;
}Book;


typedef struct BookCopy {
    int book_number;
    int serial_number;
    Bool is_borrowed;
    size_t num_borrow;
    char condition;

}BookCopy;

const char* get_zone_name(Zone z);
void print_book(const Book *book);
void print_copy(BookCopy *bookCopy);
void borrow_copy(BookCopy *bookCopy, Bool is_borrowed );
void init_copy(BookCopy *bookCopy, int booknumber);


Bool is_bookbinder_required(BookCopy* bookCopy);
Bool is_librarian_required(BookCopy* bookCopy);
Bool is_repairable(BookCopy* bookCopy);
Bool is_ok(struct BookCopy* bookCopy);
Bool is_useless(struct BookCopy* bookCopy);
Bool are_in_same_condition(struct BookCopy*, struct BookCopy*);

BookCopy* create_copy(int internal_number);

void get_nice_book_name(const char* src, char* dst);
void print_nicely(const Book* book);

#endif
