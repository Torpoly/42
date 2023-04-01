#include <stdio.h>
#include <stdlib.h>

int get_width(int n) {
    int width = 1;
    int add = 2;
    for (int i = 1; i <= n; ++i) {
        width += 2 * add;
        if (i % 2 == 0) {
            add += 2;
        }
    }
    return width;
}

void print_pyramid(int size) {
    int width = get_width(size);
    int height = 3 + 2 * size;
    int spaces, stars;
    int row = 0;
    for (int level = 1; level <= size; ++level) {
        int add = level + 1;
        int door_width = level - !(level % 2);
        int door_height = level;
        for (int i = 0; i < add; ++i) {
            stars = 1 + 2 * row;
            spaces = (width - stars) / 2;
            for (int j = 0; j < spaces; ++j) printf(" ");
            printf("/");
            for (int j = 0; j < stars - 2; ++j) {
                if (level == size && i >= add - door_height && j >= (stars - door_width) / 2 && j < (stars + door_width) / 2 - 1) {
                    if (i == add - door_height + door_height / 2 && j == (stars + door_width) / 2 - 2 && level >= 5) {
                        printf("$");
                    } else {
                        printf("|");
                    }
                } else {
                    printf("*");
                }
            }
            printf("\\\n");
            ++row;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    print_pyramid(size);
    return 0;
}