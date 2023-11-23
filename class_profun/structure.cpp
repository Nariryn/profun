#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>

int main()
{
	int i;
	struct students {
		int id;
		char name[50];
		int age;
	};
	students s[3];
	for (i = 0; i < 3; i++) {
		strcpy(s[i].name, "Anonymous");
		s[i].id = i;
		s[i].age = i;
	}

	for (int i = 0; i < 3; i++) {
		printf("Enter data for student %d:\n", i + 1);
		printf("Student ID: ");
		scanf("%d", &s[i].id);
		printf("Name: ");
		scanf("%s", s[i].name);
		printf("Age: ");
		scanf("%d", &s[i].age);
		printf("\n");
	}
	printf("Student Data:\n");

	for (i = 0; i < 3; i++) {
		printf("id number: %d\t", s[i].id);
		printf("name : %s\t", s[i].name);
		printf("age : %d\n", s[i].age);
	}
	return 0;
}