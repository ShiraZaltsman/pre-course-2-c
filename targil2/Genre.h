
#ifndef TARGIL2_GENRE_H
#define TARGIL2_GENRE_H
typedef enum {Drama, Thriller, Comedy, Non_Fiction} genre_name;

typedef struct
{
    unsigned char text_quality; /* 0—100 */
    unsigned char plot_quality; /* 0—100 */
}DRAMA;

typedef struct
{
    unsigned short quality_of_humor; /* 1—1000 */
    unsigned char humor_type; /* ‘N’ – nonsense humor, ‘S’ – sophisticated humor, ‘P’ – puns, ‘O’ – other */
}COMEDY;

typedef struct
{
    float thrilling_factor;
}THRILLER;

typedef struct
{
    char field[4];
}NON_FICTION;

typedef struct Genre{
    genre_name name;
    union{
        DRAMA drama;
        THRILLER thriller;
        COMEDY comedy;
        NON_FICTION nonFiction;
    }additional_data;
}Genre;


void print_drama_genre(DRAMA drama);
void print_thriller_genre(THRILLER thriller);
void print_comedy_genre(COMEDY comedy);
void print_nonFiction_genre(NON_FICTION nonFiction);
#endif

