#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>
using std::ifstream;
using std::ofstream;

bool headerCheck(ifstream &file, int n);
void makeMatrix(ifstream &file, int **v, int n);
void writeFile(ofstream &output, int **v, int n);

#endif