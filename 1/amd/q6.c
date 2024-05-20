#include <stdlib.h>
#include <stdio.h>

int main() {
    int *p, *q;
    int *r;
    int *s;
    
    p = (int *)malloc(sizeof(int)); // Allocate memory for an integer and assign its address to p
    r = p; // Assign the value of p to r (both point to the same memory location)
    *p = 5; // Store the value 5 in the memory location pointed to by p

    // Print the value stored at the memory location pointed to by r
    printf("\n%d\n", *r); // Value: 5, Address: address of the memory location allocated for p

    p = (int *)malloc(sizeof(int)); // Allocate memory for another integer and assign its address to p
    q = p; // Assign the value of p to q (both point to the same memory location)

    // Print the value stored at the memory location pointed to by p (newly allocated memory)
    printf("\n%d\n", *p); // Value: uninitialized (garbage value), Address: address of the new memory location allocated for p

    s = r; // Assign the value of r to s (both point to the same memory location)

    // Print the value stored at the memory location pointed to by r (which still holds 5)
    printf("\n%d\n", *r); // Value: 5, Address: address of the memory location allocated for p

    // Print the value stored at the memory location pointed to by s (which still holds 5)
    printf("\n%d\n", *s); // Value: 5, Address: address of the memory location allocated for p

    *q = *s + 1; // Store the value in s (5) plus 1 in the memory location pointed to by q

    // Print the value stored at the memory location pointed to by q (6)
    printf("\n%d\n", *q); // Value: 6, Address: address of the memory location allocated for p

    *r = *p * 2; // Store twice the value in the memory location pointed to by p (uninitialized) in the memory location pointed to by r

    // Print the value stored at the memory location pointed to by r (twice the value of p, uninitialized)
    printf("\n%d\n", *r); // Value: uninitialized (garbage value), Address: address of the memory location allocated for p

    // Print the value stored at the memory location pointed to by p (uninitialized)
    printf("\n%d\n", *p); // Value: uninitialized (garbage value), Address: address of the memory location allocated for p

    free(r); // Free the dynamically allocated memory pointed to by r
    r = NULL; // Set r to NULL

    free(q); // Free the dynamically allocated memory pointed to by q
    q = NULL; // Set q to NULL
    
    return 0;
}
