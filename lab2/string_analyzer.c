/*
 * String Analyzer - Class 1 Demonstration Program
 * Analyzes a string and reports character statistics
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void print_usage(void);
void analyze_string(const char *input);
int count_vowels(const char *str);
int count_consonants(const char *str);
void print_results(const char *input, int vowels, int consonants);

int main(int argc, char *argv[]) {
    // Check if string argument was provided
    if (argc < 2) {
        print_usage();
        return 0;
    }
    
    // Analyze the provided string
    analyze_string(argv[1]);
    
    return 0;
}

/*
 * Prints program description and usage information
 */
void print_usage(void) {
    printf("String Analyzer v1.0\n");
    printf("====================\n");
    printf("This program analyzes a text string and reports statistics.\n");
    printf("\n");
    printf("Usage: string_analyzer <text>\n");
    printf("Example: string_analyzer \"Hello World\"\n");
    printf("\n");
    printf("The analyzer will report:\n");
    printf("  - Total character count\n");
    printf("  - Number of vowels\n");
    printf("  - Number of consonants\n");
    printf("  - Number of spaces and other characters\n");
}

/*
 * Main analysis coordinator - calls helper functions
 */
void analyze_string(const char *input) {
    int vowels = count_vowels(input);
    int consonants = count_consonants(input);
    print_results(input, vowels, consonants);
}

/*
 * Counts vowels in the string (case-insensitive)
 */
int count_vowels(const char *str) {
    int count = 0;
    const char *vowels = "aeiouAEIOU";
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr(vowels, str[i]) != NULL) {
            count++;
        }
    }
    
    return count;
}

/*
 * Counts consonants in the string (case-insensitive)
 */
int count_consonants(const char *str) {
    int count = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            // It's a letter - check if it's not a vowel
            char lower = tolower(str[i]);
            if (strchr("aeiou", lower) == NULL) {
                count++;
            }
        }
    }
    
    return count;
}

/*
 * Displays the analysis results
 */
void print_results(const char *input, int vowels, int consonants) {
    int total_length = strlen(input);
    int letters = vowels + consonants;
    int other = total_length - letters;
    
    printf("\n");
    printf("String Analysis Results\n");
    printf("=======================\n");
    printf("Input string: \"%s\"\n", input);
    printf("\n");
    printf("Total characters: %d\n", total_length);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Spaces/Other: %d\n", other);
    printf("\n");
    
    if (letters > 0) {
        double vowel_percentage = (double)vowels / letters * 100.0;
        printf("Vowel percentage: %.1f%%\n", vowel_percentage);
    }
}
