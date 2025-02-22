from cs50 import get_string
import re


def compute_L(text):
    text_lst = text.split()
    letters_sum = 0
    for i in text_lst:
        for elem in i:
            if elem.isalpha():
                letters_sum += 1
    L = (letters_sum / len(text_lst)) * 100
    return L


def compute_S(text):
    sentences_lst = re.split(r'[.!?]["\']?\s*', text)
    sentences_lst = [sentence for sentence in sentences_lst if sentence.strip()]
    text_lst = text.split()
    S = (len(sentences_lst) / len(text_lst)) * 100
    return S


def check_grade(L, S):
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    if (grade < 1):
        print("Before Grade 1")
    elif (1 <= grade < 16):
        print(f"Grade {grade}")
    else:
        print("Grade 16+")


text = input("Text: ")
L = compute_L(text)
S = compute_S(text)
check_grade(L, S)
