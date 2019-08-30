#include "Genre.h"
#include <stdio.h>

void print_drama_genre(const DRAMA drama){

    printf("Drama:\ntext quality: %c\nplot quality: %c\n", drama.text_quality, drama.plot_quality);
}

void print_thriller_genre(const THRILLER thriller){
    printf("Thriller:\nthrilling factor: %.2f\n",thriller.thrilling_factor);
}

void print_comedy_genre(const COMEDY comedy){
    printf("Comedy:\nhumor quality: %d\nhumor type: %c\n",comedy.quality_of_humor, comedy.humor_type);
}

void print_nonFiction_genre(const NON_FICTION nonFiction){
    printf("Non Fiction:\ncode: %s\n",nonFiction.field);
}
