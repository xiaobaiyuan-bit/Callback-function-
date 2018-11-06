//字符排序

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int char_cmp(const void *p1, const void *p2)
{
	return (*(char *)p1 > *(char *)p2);
}

int main()
{
	char arr[] = { 'a', 'd', 'c', 'b' };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char), char_cmp);
	int i = 0;
	for (; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c\n", arr[i]);
	}
	system("pause");
	return 0;
}


//整型数字排序

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int int_cmp(const void *p1, const void *p2)
{
	return (*(int *)p1 > *(int *)p2);
}

int main()
{
	int arr[] = { 1, 2, 3, 6, 5, 4 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	int i = 0;
	for (; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}


//模拟实现qsort函数比较整型

#include <stdio.h>
#include <windows.h>

int int_cmp(const void *p1, const void *p2)
{
	return (*(int *)p1 > *(int *)p2);
}

void _swap(void *p1, void *p2, int size)
{
	char *p11 = (char *)p1;
	char *p22 = (char *)p2;
	int i = 0;
	for (; i < size; i++)
	{
		int tmp = *(p11 + i);
		*(p11 + i) = *(p22 + i);
		*(p22 + i) = tmp;
	}
}

void my_qsort(void *arr, int count, int size, int(*cmp)(void *, void *))
{
	char *p = (char *)arr;//强转为字符指针（意思是每次以一个字节为单位进行操作）
	int i = 0;
	for (; i < count - 1; i++)
	{
		int j = 0;
		for (; j < count - 1 - i; j++)
		{
			if (cmp(p + j*size, p + (j + 1)*size) > 0)
			{
				_swap(p + j*size, p + (j + 1)*size, size);
			}
		}
	}

}

int main()
{
	int arr[] = { 1, 2, 3, 6, 5, 4 };
	my_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	int i = 0;
	for (; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


//模拟实现qsort函数比较字符类型

#include <stdio.h>
#include <windows.h>

int char_cmp(const void *p1, const void *p2)
{
	return (*(char *)p1 > *(char *)p2);
}

void _swap(void *p1, void *p2, int size)
{
	char *p11 = (char *)p1;
	char *p22 = (char *)p2;
	int i = 0;
	for (; i < size; i++)
	{
		int tmp = *(p11 + i);
		*(p11 + i) = *(p22 + i);
		*(p22 + i) = tmp;
	}
}

void my_qsort(void *arr, int count, int size, int(*cmp)(void *, void *))
{
	char *p = (char *)arr;//强转为字符指针（意思是每次以一个字节为单位进行操作）
	int i = 0;
	for (; i < count - 1; i++)
	{
		int j = 0;
		for (; j < count - 1 - i; j++)
		{
			if (cmp(p + j*size, p + (j + 1)*size) > 0)
			{
				_swap(p + j*size, p + (j + 1)*size, size);
			}
		}
	}

}

int main()
{
	char arr[] = { 'a', 'c', 'b', 'g', 'e', 'f', 'd' };
	my_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(char), char_cmp);
	int i = 0;
	for (; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}