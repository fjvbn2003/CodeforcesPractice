#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(){

#pragma omp parallel
{cout <<"Hello OpenMP thread"<<endl;}

}