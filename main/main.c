#include <stdio.h>
// Function to find the longest mountain in an array..
int longestMountain(int arr[], int n)
{
    if (n < 3) return 0; 

    int ans = 0;
    int i = 1;

    while (i < n) {    
        int upper = 0, lower = 0;                  

        // Skip flat terrain (equal adjacent values)
        while (i < n && arr[i - 1] == arr[i])    
            i++;                            

        // Ascend (increasing sequence)
        while (i < n && arr[i - 1] < arr[i]) {  
            upper++;
            i++;
        }

        // Descend (decreasing sequence)
        while (i < n && arr[i - 1] > arr[i]) {
            lower++;
            i++;    
        } 

        // A valid mountain must have both an ascent and a descent
        if (upper > 0 && lower > 0) { 
            ans = (ans > (lower + upper + 1)) ? ans : (lower + upper + 1);
        }
    }
    
    return ans;
}
