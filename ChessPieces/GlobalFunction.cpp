#include "GlobalFunction.h"

int abs(int x){
    return x > 0 ? x : -x; 
};

int min(int x, int y){
    return x < y ? x : y;
};

int max(int x, int y){
    return x > y ? x : y;
}