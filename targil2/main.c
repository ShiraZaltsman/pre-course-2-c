#include <stdio.h>
#include "local_library.h"
#include "books.h"
#include <string.h>
void menu(BookCopy **book_copies, int size);
void print_books_in_library();
void add_BookCopys(BookCopy **book_copies, int size);
void free_memory(BookCopy** book_copies, int num);

void phase_1();
void phase_2();
void phase_3();

extern struct Book books[];

int main(){
    phase_1();
    phase_2();
    phase_3();
}

void phase_3() {
    printf("-------phase 3-------\n");

    do_for_books(firstBook(), num_books(), print_nicely);
    do_for_books(firstBook(), num_books(), prints_non_fiction);
    do_for_books(firstBook(), num_books(), print_most_promoted);
    printf("Worst book: %d\n", get_min_promotion(firstBook()));
    printf("Minimum thrilling factor: %f\n", get_min_thrilling_factor(firstBook()));

    phase_2();
}

void phase_1(){
    printf("-------phase 1-------\n");
    BookCopy **book_copies = malloc(10* sizeof(BookCopy*));
    print_books_in_library();
    add_BookCopys(book_copies,10);
    menu(book_copies, 10);
    free_memory(book_copies, 10);
}

void phase_2(){
    printf("-------phase 2-------\n");
    printf("How many book copies would you like to allocate? \n");
    int num;
    scanf("%d", &num);
    BookCopy **book_copies = malloc(num*sizeof(BookCopy*));
    print_books_in_library();
    add_BookCopys(book_copies, num);
    menu(book_copies, num);
    free_memory(book_copies, num);
}

void free_memory(BookCopy** book_copies, int num) {
    int i;
    for (i = 0; i < num; i++) {
        free(book_copies[i]);
    }
    free(book_copies);

}

void menu(BookCopy **book_copies, int size) {
    int userInput = 0;
    int serialnumber;
    Bool is_exsit = FALSE;
    while (userInput != 9) {
        printf("----------------------\n");
        printf("MENU:\npress 1 to borrow book\npress 2 to return book\npress 9 to exit\n");
        printf("----------------------\n");
        scanf("%d", &userInput);
        switch (userInput) {
            case 1:
                is_exsit = FALSE;
                while (!is_exsit) {
                    printf("Please enter book serial number to borrow: \n");
                    scanf("%d", &serialnumber);\
                    int i;
                    for (i = 0; i < size; ++i) {
                        if (book_copies[i]->serial_number == serialnumber) {
                            is_exsit = TRUE;
                            borrow_copy(book_copies[i], TRUE);
                        }
                    }
                    if (!is_exsit) {
                        printf("ERROR, wrong serial number!\n");
                    }
                }
                break;

            case 2:
                is_exsit = FALSE;
                while (!is_exsit) {
                    printf("Please enter book serial number to return: ");
                    scanf("%d", &serialnumber);
                    int i;
                    for (i = 0; i < size; ++i) {
                        if (book_copies[i]->serial_number == serialnumber) {
                            is_exsit = TRUE;
                            borrow_copy(book_copies[i], FALSE);
                        }
                    }
                    if (!is_exsit) {
                        printf("ERROR, wrong serial number!\n");
                    }
                }
                break;
            case 9:
                printf("Goodbye");
                break;
            default:
                printf("ERROR, re-enter: \n");
                scanf("%d", &userInput);

        }
    }
}

void print_books_in_library(){
    int i;
    for (i = 0; i <num_books() ; ++i) {
        print_book(&books[i]);
        printf("\n");
    }
}

void add_BookCopys(BookCopy **book_copies, int size){
    int num, j;
    for (j = 0; j < size; ++j) {
        printf("Enter a book number :");
        scanf("%d", &num);
        while (book_name(num) == NULL) {
            printf("internal number not found, Please re-enter a book number: ");
            scanf("%d", &num);
        }
        book_copies[j] = create_copy(num);
        print_copy(book_copies[j]);
    }
}