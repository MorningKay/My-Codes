#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
void encrypt(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1]))
    {
        printf("key must contain exactly 26 unique lowercase letters.\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext:  ");
        encrypt(text, argv[1]);
        printf("ciphertext: %s\n", text);
        return 0;
    }
}

bool is_valid_key(string key)
{
    int count[26] = {0};
    int key_length = strlen(key);

    if (key_length != 26)
        return false;

    for (int i = 0; i < key_length; i++)
    {
        char c = tolower(key[i]);
        if (c < 'a' || c > 'z')
            return false;
        count[c - 'a']++;
        if (count[c - 'a'] > 1)
            return false;
    }
    return true;
}

void encrypt(string text, string key)
{
    int length = strlen(text);
    int l = strlen(key);
    char lower_key[l];
    for (int i = 0; i < l; i++)
    {
        lower_key[i] = tolower(key[i]);
    }
    for (int i = 0; i < length; i++)
    {
        if (islower(text[i]))
        {
            text[i] = lower_key[text[i] - 'a'];
        }
        else if (isupper(text[i]))
        {
            char lower = tolower(text[i]);
            text[i] = toupper(lower_key[lower - 'a']);
        }
        // printf("%c\n", text[i]);
    }
    // printf("%s\n", text);
}
