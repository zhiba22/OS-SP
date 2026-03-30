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

        // Check if page already in frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {

            int replace_index = -1;
            int farthest = i + 1;

            // Find the page with farthest future use
            for(j = 0; j < f; j++) {

                int k;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k])
                        break;
                }

                if(k == n) {  // Page not used again
                    replace_index = j;
                    break;
                }

                if(k > farthest) {
                    farthest = k;
                    replace_index = j;
                }
            }

            if(replace_index == -1)
                replace_index = 0;

            frames[replace_index] = pages[i];
            page_faults++;
        }

        // Print frame status
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