#include <stdio.h>


#define MAXLINES 5000


char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


int main()
{
	int nlines;

	if ( (nlines = readlines(lineptr, MAXLINES)) >=0 )
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
	}
	else
	{
		printf("error: input too big to sort.\n");
		return 1;
	}

return 0;
}


#define MAXLEN 1000
int mygetline(char *, int);
char *alloc(int);
void mystrcpy(char *, char *);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ( (len = mygetline(line, MAXLEN) ) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL )
			return -1;
		else
		{
			line[len-1] = '\0';	/* delete the newline char */
			mystrcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

int mygetline(char *line, int limit)
{
	int c, i;
	for (i=0; i<limit-1 && (c=getchar()) != EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

void mystrcpy(char *s, char *t)
{
	while ( *s++ = *t++ )
		;
}

/**
	Needed for alloc
*/
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/**
	Needed for qsort
*/
int mystrcmp(char *, char *);

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i , int j);

	if (left >= right)
		return;

	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (mystrcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);

	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i , int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int mystrcmp(char *s, char *t)
{
	while (*s == *t && *s)
		s++, t++;
	return *s - *t;
}
