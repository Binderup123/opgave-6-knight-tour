#include <stdio.h>
#include "../include/pis.h"
// Definer bevæglser ud fra L form, så fx 2 hen og 1 op 
const int MOVES_X[MOVE_COUNT] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int MOVES_Y[MOVE_COUNT] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Tjekker om trækket
bool move_is_possible(int move_id, int x, int y, unsigned int visited[][DEFAULT_SIZE], int size) {
    // finder nye position
    int new_x = x + MOVES_X[move_id];
    int new_y = y + MOVES_Y[move_id];

    if (new_x < 0 || new_y < 0 || new_x >= size || new_y >= size)
        return false;

    // Check if the new square was already visited
    if (visited[new_y][new_x] != 0)
        return false;

    // Move is valid
    return true;
}
//køre turen med start koordinater
unsigned int tour_greedy(int start_x, int start_y, int size, unsigned int visited[][DEFAULT_SIZE]) 
{
    for (int  i = 0; i < size; i++) 
    {
    for (int j = 0; j < size; j++) 
    {
        visited[i][j] = 0;
    }
    }
    // Starting position
    int x = start_x;
    int y = start_y;
    visited[y][x] = 1; //sætter første position
    
    unsigned int move_count = 1; //int for antal bevægelser

    while (1) // køre intil der ikke er flere bevægelser
    {
        bool moved = false;
        for (int move_id = 0; move_id < MOVE_COUNT; move_id++) 
        {
            if (move_is_possible(move_id, x, y, visited, size)) 
            {
                // opdaterer position
                x += MOVES_X[move_id];
                y += MOVES_Y[move_id];
                move_count++;
                visited[y][x] = move_count;
                moved = true;
                break;
            }
        }
        if (!moved) break; //slutter den når der ikke er flere 
    }

    return move_count;
}
// kører greedy tour for alle pladser 
void greedy_tour(int size) 
{
    unsigned int visited[DEFAULT_SIZE][DEFAULT_SIZE]; // genbruges for alle 
    unsigned int results[DEFAULT_SIZE][DEFAULT_SIZE]; // gemmer resultater

    // køre fra alle pladser
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            results[y][x] = tour_greedy(x, y, size, visited);
        }
    }
    // Print the result matrix
    printf("Greedy:\n");
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            printf("%3u ", results[y][x]);
        }
        printf("\n");
    }
}
