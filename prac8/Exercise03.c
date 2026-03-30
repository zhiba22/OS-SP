#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int n, f;
    int i, j, k;
    int page_faults = 0;
    int index = 0;
    int found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames as empty
    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page already in frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If page not found -> page fault
        if(found == 0) {
            frames[index] = pages[i];
            index = (index + 1) % f; // FIFO replacement
            page_faults++;
        }

        // Print frames
        printf("%d\t", pages[i]);
        for(k = 0; k < f; k++) {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}