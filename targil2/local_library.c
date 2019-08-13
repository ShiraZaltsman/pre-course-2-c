//
// Created by User on 8/12/2019.
//
#include "local_library.h"
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
const struct Book *first_book() {

    return &books[0];
}

int num_books() {
    return sizeof(books)/sizeof(struct Book);
}

char *book_name(int book_number) {
    for (int i = 0; i < num_books(); ++i) {
        if (book_number==books[i].book_number){
            return books[i].name;
        }
    }
    return NULL;
}



