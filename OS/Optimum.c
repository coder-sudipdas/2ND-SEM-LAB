#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k;
    int page_faults = 0, page_hits = 0;
    int found, pos, farthest, future;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    /* Initialize frames */
    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    /* Optimal Page Replacement */
    for (i = 0; i < n; i++)
    {
        found = 0;

        /* Check whether page is already present */
        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        /* Page Hit */
        if (found)
        {
            page_hits++;

            printf("%d\t", pages[i]);

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }

            printf("\tPage Hit\n");
        }

        /* Page Fault */
        else
        {
            page_faults++;

            /* Find empty frame */
            pos = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If no empty frame, find optimal page */
            if (pos == -1)
            {
                farthest = -1;

                for (j = 0; j < f; j++)
                {
                    future = -1;

                    /* Find next use of frames[j] */
                    for (k = i + 1; k < n; k++)
                    {
                        if (pages[k] == frames[j])
                        {
                            future = k;
                            break;
                        }
                    }

                    /* Page is never used again */
                    if (future == -1)
                    {
                        pos = j;
                        break;
                    }

                    /* Find page used farthest in future */
                    if (future > farthest)
                    {
                        farthest = future;
                        pos = j;
                    }
                }
            }

            /* Replace page */
            frames[pos] = pages[i];

            printf("%d\t", pages[i]);

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frames[j]);
            }

            printf("\tPage Fault\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    printf("Total Page Hits = %d\n", page_hits);

    return 0;
}