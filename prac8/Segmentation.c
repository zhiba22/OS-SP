#include <stdio.h>

struct Segment {
    int base;
    int limit;
};

int main() {

    struct Segment seg[10];
    int n, i;
    int seg_num, offset;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    // Input base and limit for each segment
    for(i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d %d", &seg[i].base, &seg[i].limit);
    }

    printf("\nEnter segment number: ");
    scanf("%d", &seg_num);

    printf("Enter offset: ");
    scanf("%d", &offset);

    // Validation
    if(seg_num >= n) {
        printf("Invalid Segment Number!\n");
    }
    else if(offset >= seg[seg_num].limit) {
        printf("Segmentation Fault! Offset exceeds limit.\n");
    }
    else {
        int physical_address = seg[seg_num].base + offset;
        printf("Physical Address = %d\n", physical_address);
    }

    return 0;
}