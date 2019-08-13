#include <stdio.h>
#include "local_library.h"
#include "books.h"
#include <string.h>

extern struct Book books[];
int main() {

    int book_num;
    char *name;
    struct BookCopy book_copies[10];
    //test();

    for (int i = 0; i < num_books(); ++i) {
        print_book(&books[i]);

        printf("\n");
    }
    int numbers[]={1001,1002,1003,1004,1005,1008,1009,1010,1012,1013};
    for (int j = 0; j < 10; ++j) {
       // printf("/nPlease enter book number: ");
     //   scanf("%d", &book_num);
      //  while (book_name(book_num) == NULL) {
       //     printf("EROOR! Please re-enter book number: ");
        //    scanf("%d", &book_num);
        //}
        struct BookCopy newbookCopy;
        init_copy(&newbookCopy, numbers[j]);
        book_copies[j] = newbookCopy;
        print_copy(&newbookCopy);
    }
    int userInput=0;

    int serialnumber;
    bool is_exsit=false;

    while(userInput!=9){
        printf("enter 1 to borrow book, 2 to return book, 9 to exit");
        scanf("%d", &userInput);

        switch(userInput) {
            case 1:
                is_exsit=false;
                while (!is_exsit) {
                    printf("Please enter book serial number to borrow: \n");
                    scanf("%d", &serialnumber);
                    for (int i = 0; i < 10; ++i) {
                        if (book_copies[i].serial_number == serialnumber) {
                            is_exsit = true;
                            borrow_copy(&book_copies[i], true);

                        }
                    }
                    if (!is_exsit) {
                        printf("ERROR, wrong serial number!\n");
                    }
                }break;

            case 2:
                is_exsit = false;
                while (!is_exsit) {
                    printf("Please enter book serial number to return: ");
                    scanf("%d", &serialnumber);
                    for (int i = 0; i < 10; ++i) {
                        if (book_copies[i].serial_number == serialnumber) {
                            is_exsit = true;
                            borrow_copy(&book_copies[i], false);
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


    return 0;
}