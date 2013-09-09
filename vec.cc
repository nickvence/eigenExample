#include<iostream>
#include<fstream>

int main(int argc, char* argv[]) {
    printf("Hello argc = %d\n",argc);
    std::ifstream f;
    f.open("star.tsv");
    return 0;
}
