//
// Created by User on 8/11/2019.
//

#ifndef TARGIL2_BOOKS_H
#define TARGIL2_BOOKS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define  COVER 0x01
#define  INDEXING 0x02
#define MISSING_PAGE 0x03
#define BAR_CODE 0x04
#define SPINE 0x05
#define PAGE_STAINED 0x06

#define librarian_mask  0x110100,//mask for a problem with its cover, indexing or bar-code.
#define bookbinder_mask 0x001011,//mask for a problem with its spine, or there are missing or stained pages.
#define repairable_mask 0x001001,//mask for no missing or stained pages.
#define ok_mask  0x000000
//order matter!
typedef enum Zone {
    KIDS,
    HIGHSCHOOL,
    ADULT,
    DOCUMENTARY,
    COMICS
}Zone;

typedef enum condition{
    cover=0x01,
    indexing=0x02,
    missing_page=0x03,
    bar_code=0x04,
    spine=0x05,
    page_staind=0x06,

}condition;
//typedef enum bool{true,false}bool;
typedef struct Book {
    unsigned short book_number;// 0-50000
    char  name[50];
    int   promotion;// -100 till 1000
    Zone zone;
}Book;


typedef struct BookCopy {
    int book_number;
    int serial_number;
    bool is_borrowed;

    //phase 2
    size_t num_borrow;
    unsigned char condition; //unsing char or bit filde

}BookCopy;

const char* get_zone_name(Zone z);
void print_book(Book *book);
void print_copy(BookCopy *bookCopy);
void borrow_copy(BookCopy *bookCopy, bool is_borrowed );
void init_copy(BookCopy *bookCopy, int booknumber);

//phase 2

bool is_bookbinder_required(BookCopy* bookCopy);
bool is_librarian_required(BookCopy* bookCopy);
#endif //TARGIL2_BOOKS_H
