// This function reads in the file pointer and sends its contents to a provided char array.
void readInHTML(FILE *fptr, char input[], int lim)
{   // For every character in the input file until the end of file is reached,
    // set the char array's char at index i to the current character.
        // I set the second condition to lim-1 instead of lim because the final
        // character will be set to '\0', the string terminator character.
    int c, i;
    char *ptr = &*input;
    for (i = 0; i < lim-1 && (c = getc(fptr)) != EOF; ++i)
    {   *ptr = c;
        *ptr++;
    }
    *ptr = '\0';
}
