#include <stdio.h>

int main()
{
    int pages[20], frame[10];
    int n, f, i, j, k = 0;
    int fault = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check page is already present
        for(j = 0; j < f; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        // Page fault
        if(found == 0)
        {
            frame[k] = pages[i];
            k = (k + 1) % f;
            fault++;
        }

        printf("\n%d : ", pages[i]);

        for(j = 0; j < f; j++)
            printf("%d ", frame[j]);
    }

    printf("\n\nTotal Page Faults = %d", fault);
    printf("\nTotal Page Hits = %d\n", n - fault);

    return 0;
}


