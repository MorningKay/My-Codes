#include <stdio.h>

char GRADE_MAP[] = { 'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};

class Grade
{
    char letter;
    int percent;

public:
    void setByPercent(int percent);
    void setByLetter(char letter);
    void print();
};

void Grade::setByPercent(int percent)
{
    this->percent = percent;
    this->letter = GRADE_MAP[percent / 10];
}

void Grade::setByLetter(char letter)
{
    this->letter = letter;
    this->percent = 100 - (letter - 'A') * 10 - 5;
}

void Grade::print()
{
    printf("Grade: %d: %c\n", percent, letter);
}

int main()
{
    Grade g;
	int percent;
	
	printf("Enter two grades separated by a space. Use a percentage for \
the first and letter for the second: ");
	scanf("%d", &percent);
	scanf("\n");
	
	g.setByPercent(percent);
	g.print();
	
	g.setByLetter(getchar());
	g.print();

	return 0;
}