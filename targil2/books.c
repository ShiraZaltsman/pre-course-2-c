#include "books.h"
#include <stdio.h>
#include "Genre.h"
#include <ctype.h>

/*-----------------------phase 1------------------------*/

/*order matter!!!*/
static char* zones[]={
        "kids",
        "highschool",
        "adult",
        "documentary",
        "comics"
};


void print_book(const Book *book){
    printf("book name: %s\n",book->name);
    printf("book number: %d\n",book->book_number);
    printf("book promotion: %d\n",book->promotion);
    printf("book zone: %s\n",zones[book->zone]);
    switch (book->genre.name){
        case Drama:
            print_drama_genre((book->genre.additional_data.drama));
            break;
        case Thriller:
            print_thriller_genre((book->genre.additional_data.thriller));
            break;
        case Comedy:
            print_comedy_genre((book->genre.additional_data.comedy));
            break;
        case Non_Fiction:
            print_nonFiction_genre((book->genre.additional_data.nonFiction));
            break;
    }
}

void print_copy(BookCopy *bookCopy){
    printf("book number: %d\n",bookCopy->book_number);
    printf("is book borrowed: %d\n",bookCopy->is_borrowed);
    printf("book serial number: %d\n",bookCopy->serial_number);
    int num=bookCopy->num_borrow;/* convert size_t to int */
    printf("book has been borrowed for: %d times\n",num);
}

void borrow_copy(BookCopy *bookCopy, Bool isborrowed ){

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
}

void init_copy(BookCopy *bookCopy, int booknumber) {

    static unsigned int i=10000;

    bookCopy->book_number=booknumber;
    bookCopy->is_borrowed=FALSE;
    bookCopy->serial_number=i++;
    bookCopy->num_borrow=0;
    bookCopy->condition=0x0;
}

const char* get_zone_name(Zone z){
    if (z>0 && z<6){
        return (zones[z]);
    }
    return "error zone dont valid";
}

/*-----------------------phase 2------------------------*/

Bool is_librarian_required(struct BookCopy* bookCopy){
    if(librarian_mask & bookCopy->condition){
        return TRUE;
    }
    return FALSE;

}

Bool is_bookbinder_required(struct BookCopy* bookCopy){
    if (bookbinder_mask & (bookCopy->condition)){
        return TRUE;
    }
    return FALSE;
}

Bool is_repairable(BookCopy* bookCopy){
    if((bookCopy->condition && ( MISSING_PAGE && PAGE_STAINED )) == 0)
    {
        return TRUE;
    }
    return  FALSE;
}

Bool is_ok(struct BookCopy* bookCopy){
    if (bookCopy->condition == ok_mask){
        return TRUE;
    }
    return FALSE;
}

Bool is_useless(struct BookCopy* bookCopy){
    int num_conditions=0;
    if(bookCopy->condition & COVER)
        ++num_conditions;
    if(bookCopy->condition & INDEXING)
        ++num_conditions;
    if(bookCopy->condition & MISSING_PAGE)
        ++num_conditions;
    if(bookCopy->condition & BAR_CODE)
        ++num_conditions;
    if(bookCopy->condition & SPINE)
        ++num_conditions;
    if(bookCopy->condition & PAGE_STAINED)
        ++num_conditions;
    if(num_conditions>=4)
        return TRUE;
    else
        return FALSE;
}

Bool are_in_same_condition(struct BookCopy* bookCopy1, struct BookCopy* bookCopy2){

    if ((bookCopy1->condition & bookCopy2->condition) == bookCopy1->condition){
        return TRUE;
    }
    return FALSE;
}

BookCopy* create_copy(int internal_number) {
    BookCopy* bookCopy = malloc(1*sizeof(BookCopy));
    init_copy(bookCopy, internal_number);
    return bookCopy;
}

/*-----------------------phase 3------------------------*/

void get_nice_book_name(const char* src, char* dst){
    int i;
    /* lowercase the string */
    for(i=0; src[i]; i++) {
        dst[i] = tolower(src[i]);
    }
    /* uppercase the first latter */
    dst[0]=toupper(dst[0]);

    /* uppercase the other first latter */
    for(i=1; dst[i]; i++) {
        if (dst[i]==' ') {
            dst[i+1] = toupper(dst[i+1]);
        }
    }
}
