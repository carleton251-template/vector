#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "vector.h"
#include <stdio.h>


void test1(bool exemplary) {
    // Create an empty vector with memory capacity of 10
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    init(vector,100);

    // Insert 50 numbers into it
    for (int i=0; i < 50; i++) {
        assert(insert(vector,0,i));
    }

    int value;
    for (int i=0; i < 50; i++) {
        int status = get(vector,50-i-1,&value);
        assert(1==status);
        assert(i==value);
    }

    if (exemplary) {
        for (int i=-5; i < -2; i++) {
            int status = get(vector, i, &value);
            assert(0==status);
        }
        for (int i=50; i < 53; i++) {
            int status = get(vector, i, &value);
            assert(0==status);
        }
    }

    // Clean up memory
    cleanup(vector);
    free(vector);

}



void test2(bool exemplary) {
    // Create an empty vector with memory capacity of 10
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    init(vector,10);

    // Insert 50 numbers into it
    for (int i=0; i < 50; i++) {
        assert(insert(vector,0,i));
    }

    int value;
    for (int i=0; i < 50; i++) {
        int status = get(vector,50-i-1,&value);
        assert(1==status);
        assert(i==value);
    }

    if (exemplary) {
        for (int i=-5; i < -2; i++) {
            int status = get(vector, i, &value);
            assert(0==status);
        }
        for (int i=50; i < 53; i++) {
            int status = get(vector, i, &value);
            assert(0==status);
        }
    }

    // Delete a few values, and display again
    assert(delete(vector,6));
    assert(delete(vector,12));

    // Location 49 should no longer be there, vector has shrunk
    if (exemplary) {
        assert(!delete(vector,49));
    }

    for (int i=0; i < 6; i++) {
        int status = get(vector,i,&value);
        assert(status);
        assert(50-i-1 == value);
    }

    for (int i=6; i < 12; i++) {
        int status = get(vector,i,&value);
        assert(status);
        assert(50-i-2 == value);
    }

    for (int i=12; i < 48; i++) {
        int status = get(vector,i,&value);
        assert(status);
        assert(50-i-3 == value);
    }

    if (exemplary) {
        for (int i=48; i < 53; i++) {
            int status = get(vector,i,&value);
            assert(!status);
        }
    }


    // Clean up memory
    cleanup(vector);
    free(vector);

}

int main(int argc, char **argv) {
    bool exemplary = false;
    if (argc > 2 && !strcmp(argv[2], "E")) {
        exemplary = true;
    }

    if (argc > 1 && !strcmp(argv[1],"1")) {
        test1(exemplary);
    } else if (argc > 1 && !strcmp(argv[1],"2")) {
        test2(exemplary);
    } else {
        test1(exemplary);
        test2(exemplary);
    }
}
