#include <stdio.h>
int main()
{
 int pages[50], frames[10];
 int n, f, i, j;
 int page_faults = 0, page_hits = 0;
 int found, pos, oldest;
 printf("Enter the number of pages: ");
 scanf("%d", &n);
 printf("Enter the page reference string:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &pages[i]);
 }
 printf("Enter the number of frames: ");
 scanf("%d", &f);
 // Initialize frames
 for (i = 0; i < f; i++)
 {
 frames[i] = -1;
 }
 printf("\nPage\tFrames\t\tStatus\n");
 // LRU Page Replacement
 for (i = 0; i < n; i++)
 {
 found = 0;
 // Check whether page is already present
 for (j = 0; j < f; j++)
 {
 if (frames[j] == pages[i])
 {
 found = 1;
 break;
 }
 }
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
else
 {
 page_faults++;
 // Check for an empty frame
 pos = -1;
 for (j = 0; j < f; j++)
 {
 if (frames[j] == -1)
 {
 pos = j;
 break;
 }
 }
 // If no empty frame, find LRU page
 if (pos == -1)
 {
 int last_used[10];
 for (j = 0; j < f; j++)
 {
 int k;
 last_used[j] = -1;
 // Find the last occurrence of frames[j]
 for (k = i - 1; k >= 0; k--)
 {
 if (pages[k] == frames[j])
 {
 last_used[j] = k;
 break;
 }
 }
 }
 // Find the least recently used page
 oldest = last_used[0];
 pos = 0;
 for (j = 1; j < f; j++)
 {
 if (last_used[j] < oldest)
 {
 oldest = last_used[j];
 pos = j;
 }
 }
 }
 // Replace the LRU page
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


