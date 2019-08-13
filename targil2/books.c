//
// Created by User on 8/11/2019.
//
#include "books.h"
#include <stdio.h>
#include <string.h>
static char* zones={
        "kids",
        "highschool",
        "adult",
        "documentary",
        "comics"
};


void print_book(struct Book *book){
    printf("book name: %s\n",book->name);
    printf("book number: %d\n",book->book_number);
    printf("book promotion: %d\n",book->promotion);
    printf("book zone: %s\n",zones[book->zone]);
}

void print_copy(struct BookCopy *bookCopy){
    printf("book number: %d\n",bookCopy->book_number);
    printf("is book borrowed: %d\n",bookCopy->is_borrowed);
    printf("book serial number: %d\n",bookCopy->serial_number);
    printf("book has been borrowed for: %d times\n",bookCopy->num_borrow);
}

void borrow_copy(struct BookCopy *bookCopy, bool isborrowed ){

    if(!bookCopy){
        printf("book copy is null");
    }
    else if(isborrowed&&bookCopy->is_borrowed){
        printf("error, this book already borrowed");
    }

    else if (!isborrowed && !bookCopy->is_borrowed) {
        printf("error, can't return not borrowed book");
    }

    else {

        bookCopy->is_borrowed = isborrowed;
        if (isborrowed){
            bookCopy->num_borrow++;
        }
    }
    {

    }
}

void init_copy(struct BookCopy *bookCopy, int booknumber) {

    static unsigned int i=10000;

    bookCopy->book_number=booknumber;
    bookCopy->is_borrowed=false;
    bookCopy->serial_number=i++;
    bookCopy->num_borrow=0;
    bookCopy->condition=0x0;
}

const char* get_zone_name(Zone z){
    if (z>0 && z<6){//or assert
        return (zones[z]);
    }
    return "error zone dont valid";
}

//phase 2
//change to hexdcimal
bool is_librarian_required(struct BookCopy* bookCopy){
    if(bookCopy->condition & librarian_mask){
        return true;
    }
    return false;
}
bool is_bookbinder_required(struct BookCopy* bookCopy){
    if(bookCopy->condition[2]||bookCopy->condition[4]||bookCopy->condition[5]){
        return true;
    }
    return false;
}

bool is_repairable(struct BookCopy* bookCopy){
    if(!bookCopy->condition[2]||!bookCopy->condition[5]){
        return true;
    }
    return false;
}
bool is_ok(struct BookCopy* bookCopy){
    for (int i = 0; i < 6; ++i) {
        if (bookCopy->condition[i]) {
            return false;
        }
    }
    return true;
}

bool is_useless(struct BookCopy* bookCopy){
    int count=0;
    for (int i = 0; i < 6; ++i) {
        if (bookCopy->condition[i]) {
            count++;
        }
    }
    if (count>3){
        return true;
    }
    return false;
}

bool are_in_same_condition(struct BookCopy* bookCopy1, struct BookCopy* bookCopy2){

    for (int i = 0; i < 6; ++i) {
        if (bookCopy1->condition[i]!=bookCopy2->condition[i]) {
            return false;
        }
    }

    return true;
}