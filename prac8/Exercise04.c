#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int n, f;
    int i, j, k;
    int page_faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {

        int found = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // Page fault occurs
        if(found == 0) {

            int lru_index = -1;
            int least_recent = i;

            // Find LRU page
            for(j = 0; j < f; j++) {
                int last_used = -1;

                for(k = i - 1; k >= 0; k--) {
                    if(frames[j] == pages[k]) {
                        last_used = k;
                        break;
                    }
                }

                if(last_used == -1) {
                    lru_index = j;
                    break;
                }

                if(last_used < least_recent) {
                    least_recent = last_used;
                    lru_index = j;
                }
            }

            frames[lru_index] = pages[i];
            page_faults++;
        }

        // Print frames
        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}