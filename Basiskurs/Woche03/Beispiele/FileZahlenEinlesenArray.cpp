/*

Datei.txt Inhalt:
x 8 y  45 test100
Hallo 55 Welt -23
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
    int array[100];
    int i = 0;

	FILE* ptr = fopen("Datei.txt", "r");

    if (ptr == NULL)
    {
		printf("File konnte nicht geoeffnet werden.\n");
		return 1;
    }

    while (fscanf(ptr, " %*[^-0-9]%d", &array[i]) != EOF) //Lies und überspringe alle Zeichen, die keine Ziffer sind
    {
        printf("Zahl: %d\n", array[i]);
        i++;
    }

    return 0;
}

/*
	int main(void)
	{
	    FILE* ptr = fopen("data.txt", "r");
	    if (ptr == NULL) {
	        printf("File could not be opened\n");
	        return 0;
	    }

	    int c = 0;
	    int num = 0;

	    while ((c = fgetc(ptr)) != EOF)
	    {
	        if (c >= '0' && c <= '9')
	        {
	            num = c - '0'; // '0' hat ASCII 48 → Zahl = Zeichen - 48
	            printf("%d\t", num);
	        }
	    }

	    fclose(ptr);
	    return 0;
	}


	#define MAX 100

	int main(void)
	{
	    FILE *ptr = fopen("data.txt", "r");
	    if (ptr == NULL) {
	        printf("File could not be opened\n");
	        return 0;
	    }

	    int num = 0;
	    char name[MAX];

	    // Lies jedes "Wort" (getrennt durch Leerzeichen oder Zeilenumbruch)
	    while (fscanf(ptr, "%s", name) == 1)
	    {
	        num = atoi(name);  // wandelt Text in Zahl (liefert 0, wenn keine Zahl)
	        if (num != 0)
	            printf("%d\t", num);
	    }

	    fclose(ptr);
	    return 0;
	}

	char name[MAX];

	while ((fscanf(ptr, "%s", name)) != EOF)
	{
		sum = 0;
		k = strlen(name);

		for (int i = 0; name[i] != '\0'; i++)
		{
			if (name[i] >= '0' && name[i] <= '9')
			{
				num = name[i] - 48;
				sum = sum + num * pow(10, k - 1);
				k--;
			}
		}

		if (sum != 0)
		{
			printf("%d\n", sum);
		}
}
*/