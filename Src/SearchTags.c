void searchTags(char input[], int lim, char* start[], char* end[], int tagCount[], int* numTags)
{
    int i;
    // *st and *en are the start and end of the read-in new tag.
    char *st, *en;
    // *ptr will help us read along the input char array.
    char *ptr = &*input;
    // Go through the entire input char array.
    for (i = 0; i < lim && *ptr != '\0'; ++i)
    {
        // Start of tag detected!
        // (Condition: if the current char is '<' and the next char (if available) isn't '/')
        if (*ptr == '<' && i+1 < lim)
        {
            // Set *ptr to the beginning of the tag's name.
            *ptr++;
            // Check for if the tag's first character is a '/', which disqualifies potential tags.
            // If the first character of a tag's potential name is not a '/':
            if (*ptr != '/') {
                // Set the tag's start char to *ptr's address.
                st = &*ptr;
                // Start looking for the end of the tag now:
                for (; i < lim && *ptr != '\0'; ++i)
                {
                    // End of tag detected!
                    if ((*ptr == '>' || *ptr == ' ' || *ptr == '\n' || *ptr == '<') && i+1 < lim)
                    {
                        // Set end of tag to *ptr's address.
                        *ptr--;
                        en = &*ptr;

                        //printf("\n -[%c,%c]-\t", *st, *en);

                        /////////////////////////////////////////////////////////////////////
                        // Store the tags now, into the index array!

                        // Base case: no tags stored at all.
                        if (*numTags == 0)
                        {
                            *start = &*st;
                            *end = &*en;
                            *numTags = 1;
                            *tagCount = 1;
                            //printf("(%c,%c):%i", *st, *en, *numTags);
                        }
                        // When more than one tag is stored:
                        else
                        {
                            int a, b, nT = *numTags;

                            // match is a functional boolean variable where (0 == false : 1 == true).
                            int match;

                            // For loop to search through the index table.
                            for (a = 0; a < nT; ++a)
                            {
                                //printf("(%c,%c)\n", *st, *en);
                                //printf("\n");

                                // Assume 'match' is true until proven false.
                                match = 1;

                                int length = (&*en - &*st)+1;

                                // For loop to match tag names in the index table.
                                for (b = 0; b < length; ++b)
                                {
                                    //printf(" t:%i ", length);
                                    //printf("(%c,%c)", *st, **start);

                                    if ((!(*st == '\0' || *st == '>' || *st == ' ')) && (*st != **start))
                                    {
                                        //printf("[%c,%c]", *st, **start);
                                        match = 0;
                                        break;
                                    }
                                    st+=1;
                                    *start+=1;
                                }
                                if (match == 1)
                                {
                                    st-=b;
                                    *start -= b;
                                }
                                else
                                {
                                    st-=(b);
                                    *start -= (b);
                                }

                                //printf("\tm:%i\n", match);

                                // If tag names match, increment tagCount for that tag.
                                if (match == 1)
                                {
                                    //printf(" matched\t\t[%c,%c]", *st, *en);
                                    //printf("\t\t^|%c,%c|^\t", **start, **end);
                                    tagCount += a;
                                    *tagCount += 1;
                                    tagCount -= a;

                                    break;
                                }
                                else if (a == (nT - 1))
                                {
                                    //printf(" reached_end\t\t[%c,%c]", *st, *en);
                                    *numTags+=1;

                                    tagCount += a+1;
                                    *tagCount += 1;
                                    tagCount -= a+1;

                                    *(start+=1);
                                    *start = &*st;
                                    *(end+=1);
                                    *end = &*en;
                                    //printf("\t\t^|%c,%c|^", **start, **end);
                                    *(start-=1);
                                    *(end-=1);
                                    break;
                                }

                                // Progress through tags in the index table.
                                start+=1;
                                end+=1;
                            }
                            start -= a;
                            end-=a;
                        }

                        /////////////////////////////////////////////////////////////////////
                        break;
                    }
                    // Increment *ptr.
                    *ptr++;
                }
            }
        }
        // Increment *ptr.
        *ptr++;
    }
