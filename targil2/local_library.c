#include "local_library.h"
#include "Genre.h"
#include <string.h>
struct Book books[] = {
        {1001, "Sun Don't Shine", 40, ADULT},
        {1002, "Irma la dos", -100, DOCUMENTARY},
        {1003, "Starship Troopers: Invasion", -68, KIDS},
        {1004, "Year of the Jellyfish", 5, ADULT},
        {1005, "After Life", -95, DOCUMENTARY},
        {1006, "Rest Stop", 20, HIGHSCHOOL},
        {1007, "Wuthering Heights", 56, KIDS},
        {1008, "New Adventures of Pippi Longstocking", 11, HIGHSCHOOL},
        {1009, "She Does Not Drink, Smoke or Flirt", 23, KIDS},
        {1010, "F.I.S.T.", 97, HIGHSCHOOL},
        {1011, "Cruise", -97, HIGHSCHOOL},
        {1012, "Letter to Elia, A", 54, KIDS},
        {1013, "To Be and to Have", -57, ADULT},
        {1014, "Get Hard", -66, HIGHSCHOOL},
        {1015, "A Nation's Battle for Life", 51, ADULT},
        {1016, "Place Called Chiapas", 76, COMICS},
        {1017, "A Drama of the Wilderness", 55, COMICS},
        {1018, "Ladies Man", 46, ADULT},
        {1019, "Film Geek", -100, COMICS},
        {1020, "Raining Stones", -83, DOCUMENTARY}
};

const Book *firstBook() {

    return &books[0];
}

int num_books() {
    return sizeof(books)/sizeof(struct Book);
}

char *book_name(int book_number) {
    int i;
    for (i = 0; i < num_books(); ++i) {
        if (book_number==books[i].book_number){
            return books[i].name;
        }
    }
    return NULL;
}

void print_nicely(const Book* book){
    char* dst = malloc(strlen(book->name));
    get_nice_book_name(book->name, dst);
    printf("%s\n", dst);
    free(dst);
}

void prints_non_fiction(const Book* book){
    if(book->genre.name==Non_Fiction){
        printf("%s\n%s\n", book->name, book->genre.additional_data.nonFiction.field);
    }
    else
        printf("---\n");
}

void print_most_promoted(const Book* book){
    if(book->promotion>=MIN_MOST_PROMOTION)
        print_book(book);
}

int get_min_promotion(const Book *books){
    int min = books[0].promotion;
    int i;
    for (i = 0; i < num_books(); ++i) {
        min = MIN(books[i].promotion, min);
    }
    return min;
}

float get_min_thrilling_factor(const Book *books){
    float min = books[0].genre.additional_data.thriller.thrilling_factor;
    int i;
    for (i = 0; i < num_books(); ++i) {
        min = MIN(books[i].genre.additional_data.thriller.thrilling_factor, min);
    }
    return min;
}

void do_for_books(const Book *books, int num, action _action){
    int i;
    for (i = 0; i < num; ++i) {
        _action(&books[i]);
    }
}



