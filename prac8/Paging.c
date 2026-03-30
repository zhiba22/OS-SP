#include <stdio.h>

int main() {

    int page_table[20];
    int n;
    int page_size;
    int logical_address;
    int page_number, offset;
    int frame_number, physical_address;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page table (frame number for each page):\n");
    for(int i = 0; i < n; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &page_table[i]);
    }

    printf("Enter page size: ");
    scanf("%d", &page_size);

    printf("Enter logical address: ");
    scanf("%d", &logical_address);

    page_number = logical_address / page_size;
    offset = logical_address % page_size;

    if(page_number >= n) {
        printf("Invalid Page Number!\n");
        return 0;
    }

    frame_number = page_table[page_number];
    physical_address = frame_number * page_size + offset;

    printf("\nPage Number = %d\n", page_number);
    printf("Offset = %d\n", offset);
    printf("Frame Number = %d\n", frame_number);
    printf("Physical Address = %d\n", physical_address);

    return 0;
}