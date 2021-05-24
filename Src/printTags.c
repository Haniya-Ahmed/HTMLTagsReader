void printTags(char* start[], char* end[], int tagCount[], int numTags)
{
    int i;
    char *st = &**start, *en = &**end;
    for (i = 0; i < numTags; ++i)
    {

        for (; *st != '\0' && *st != ' ' && *st != '>' && /* *st != '\n' &&*/ (&*st <= &*en);)
        {
            printf("%c", *st);
            *st++;
        }
        printf(" %i \n", *tagCount);
        *start++;
        *end++;
        *tagCount++;
        st = &**start;
        en = &**end;
    }
}
