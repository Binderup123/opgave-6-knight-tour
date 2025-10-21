#include <stdbool.h> // for bool type
#ifndef pis_h
#define pis_h

// definere standart størrelse af borad
#define DEFAULT_SIZE 8

// antal evægelser
#define MOVE_COUNT 8

//
extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];
/**
 * //sætter paramter for at tjekke for mulige bevægelser
 * @param move_id   //hvilken nr bevægelsen er,
 * @param x         //x koordinate
 * @param y         //y coordinate
 * @param visited   //gemmer moves
 * @param size      //størrelse af board
 * @return          //retunere tru hvis det er mugligt at bevæge sig
 */
bool move_is_possible(int move_id, int x, int y, unsigned int visited[][DEFAULT_SIZE], int size);

/**
 * //starter turen, (start_x, start_y) med greedy algorithm.
 * @param start_x   //Start x koordinate
 * @param start_y   //Start y koordinate
 * @param size      //størrese
 * @param visited   //gemmer moves
 * @return          //retuner antal pladser
 */
unsigned int tour_greedy(int start_x, int start_y, int size, unsigned int visited[][DEFAULT_SIZE]);

/**
 * //kører greedy tour
 * @param size      
 */
void greedy_tour(int size);

#endif
