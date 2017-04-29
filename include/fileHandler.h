#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
using std::ifstream;
using std::ofstream;

int headerCheck(ifstream &file, int n);
int **malloc(int n);
void makeMatrix(ifstream &file, int** v, int n);

#endif