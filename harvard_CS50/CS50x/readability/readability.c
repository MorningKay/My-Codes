#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters_num = count_letters(text);
    int words_num = count_words(text);
    int sentences_num = count_sentences(text);
    float L = ((float) letters_num / (float) words_num) * 100;
    float S = ((float) sentences_num / (float) words_num) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    printf("index: %d\n", index);
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index > 1 && index < 16)
        printf("Grade %d\n", index);
    else
        printf("Grade 16+\n");
}

int count_letters(string text)
{
    int letters_num = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (isalpha(text[i]))
            letters_num += 1;
    }
    printf("letters: %d\n", letters_num);
    return letters_num;
}

int count_words(string text)
{
    int words_num = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == ' ')
            words_num += 1;
    }
    words_num += 1;
    printf("words: %d\n", words_num);
    return words_num;
}

int count_sentences(string text)
{
    int sentences_num = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences_num += 1;
    }
    printf("sentences: %d\n", sentences_num);
    return sentences_num;
}
