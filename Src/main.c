#include <stdio.h>
#include <stdlib.h>
#define MAXINPUTLENGTH 100000
#define MAXCOUNT 100

void readInHTML(FILE *fptr, char str[], int lim);
void readTags(char* start[], char* end[], int tagCount[], int numTags);
void searchTags(char input[], int lim, char* start[], char* end[], int tagCount[], int *numTags);

// This is the input string which we will be examining.
char input[MAXINPUTLENGTH];
// These char pointers point to the start '<' and end {'>' or ' '} of every unique tag, respectively.
char* start[MAXCOUNT];
char* end[MAXCOUNT];
// This is the int array storing the tag count per tag.
int tagCount[MAXCOUNT];
// This is the total number of stored tags, stored here for convenience.
int numTags = 0;

int main(int argc, char **argv)
{
    // Read in the HTML file.
    if (argc != 2)
        return EXIT_FAILURE;
    FILE* fptr = fopen(*(argv+1), "r");
    if (fptr == NULL)
        return EXIT_FAILURE;

    // Call readInHTML to store the HTML file contents to input.
    readInHTML(fptr, input, MAXINPUTLENGTH);

    /*
    // TEST: PRINTF ENTIRETY OF input.
    int i;
    printf("%s","\n[Contents of input HTML file]\n");
    for (i = 0; i < MAXINPUTLENGTH-1 && input[i] != '\0'; ++i)
        printf("%c", input[i]);
    printf("%s", "\n");
    */

    /*
    numTags = 2;
    start[0] = &input[1]; end[0] = &input[4];
    start[1] = &input[7]; end[1] = &input[10];
    tagCount[0] = 3;
    tagCount[1] = 1;
    */

    searchTags(input, MAXINPUTLENGTH, start, end, tagCount, &numTags);

    readTags(start, end, tagCount, numTags);

}
