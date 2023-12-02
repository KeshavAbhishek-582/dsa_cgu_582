/*

Linear search, also known as sequential search, is a simple searching algorithm that checks each element in a list one by one until a match is found or the entire list has been searched. It works well for small lists, but its time complexity is O(n), where n is the number of elements in the list. This means the time it takes to execute the algorithm grows linearly with the size of the input.

Here's a simple explanation of the linear search algorithm:

Linear Search Algorithm:
1.	Start at the beginning of the list.
2.	Compare the target element with the current element.
3.	If the target element is found, return its index.
4.	If the target element is not found, move to the next element in the list.
5.	Repeat steps 2-4 until the end of the list is reached.
6.	If the entire list is searched and the target element is not found, return a special value (e.g., -1) to indicate that the element is not in the list.


*/

#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

int main() {
    int myArray[] = {12, 45, 67, 23, 56, 89, 34, 8};
    int targetElement = 56;

    // Perform linear search
    int result = linearSearch(myArray, sizeof(myArray) / sizeof(myArray[0]), targetElement);

    // Display the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", targetElement, result);
    } else {
        printf("Element %d not found in the array.\n", targetElement);
    }

    return 0;
}