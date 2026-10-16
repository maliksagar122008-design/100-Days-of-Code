#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int main(void)
{
    size_t capacity = 16;
    size_t length = 0;
    char *s = malloc(capacity);
    int ch;
    size_t last_seen[UCHAR_MAX + 1];
    size_t window_start = 0;
    size_t longest = 0;

    if (s == NULL) {
        fprintf(stderr, "Unable to allocate memory.\n");
        return 1;
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length == capacity) {
            size_t new_capacity = capacity * 2;
            char *new_s = realloc(s, new_capacity);

            if (new_s == NULL) {
                free(s);
                fprintf(stderr, "Unable to allocate memory.\n");
                return 1;
            }
            s = new_s;
            capacity = new_capacity;
        }
        s[length++] = (char)ch;
    }

    for (size_t i = 0; i <= UCHAR_MAX; i++) {
        last_seen[i] = SIZE_MAX;
    }

    for (size_t i = 0; i < length; i++) {
        unsigned char current = (unsigned char)s[i];

        if (last_seen[current] != SIZE_MAX &&
            last_seen[current] >= window_start) {
            window_start = last_seen[current] + 1;
        }
        last_seen[current] = i;

        if (i - window_start + 1 > longest) {
            longest = i - window_start + 1;
        }
    }

    printf("%zu\n", longest);
    free(s);
    return 0;
}
    
    
