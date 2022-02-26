#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//work 1
/*
	程序的执行结果
*/
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("%d %d", a + b, c);
//	return 0;
//}

//work 2
/*
	在32位处理器上大端模式，b的值为
*/
//int main()
//{
//	unsigned int a = 0x1234;  // --> x86_64MSVC小端模式
//	unsigned char b = *(unsigned char*)&a;
//	printf("%x", b);
//}

//work 3
/*
	程序执行结果
*/
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;	//-->是char类型，因此只会读取低八位，因此寻找低八位为0
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//work 4
/*
	杨辉三角
*/

//void Triangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("  1\n"); //第一行就直接打印了
//	for (i = 1; i < n; i++) //从第二行开始
//	{
//		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
//		{
//			data[j] += data[j - 1]; 
//		}
//
//		for (j = 0; j <= i; j++) 
//		{
//			printf("%3d ", data[j]);
//		}
//		putchar('\n');
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Triangle(n);
//	return 0;
//}

//work 5
/*
	日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
	A说：不是我。
	B说：是C。
	C说：是D。
	D说：C在胡说
已知3个人说了真话，1个人说的是假话。
*/
//void who_is_killer()
//{
//	for (char killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//			printf("killer is %c", killer);
//	}
//}
//
//int main()
//{
//	who_is_killer();
//}

//work 6
/*
	
*/
int checkData(int* p)
{
	int tmp[6] = { 0 }; //标记表，实际是哈希表的思路。一开始每个元素都是0。
	for (size_t i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //如果这个位置的标记已经是1，则代表重复，直接返回0。
			return 0;
		tmp[p[i]] = 1; //如果不是，则给这个位置标记为1。
	}
	return 1; //全部标记完毕也没有出现重复的情况，代表OK。
}

int main()
{
	int p[5]; //0 1 2 3 4分别代表a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
		for (p[1] = 1; p[1] <= 5; p[1]++)
			for (p[2] = 1; p[2] <= 5; p[2]++)
				for (p[3] = 1; p[3] <= 5; p[3]++)
					for (p[4] = 1; p[4] <= 5; p[4]++) //五层循环遍历
					{
						//这里是五个人的描述，由于比较表达式只有0和1两个结果，如果要两个条件有且只有一个为真，则可以用比较表达式的值总和为1的方式直接判定。别忘了还要判定不能并列。
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
							(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
							(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
							(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
							(p[4] == 4) + (p[0] == 1) == 1 && //我第四，A第一
							checkData(p) //不能并列
							)
						{
							for (int i = 0; i < 5; i++)
								printf("%d ", p[i]);
							printf("\n");
						}
					}
}