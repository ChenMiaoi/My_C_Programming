#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//work 1
/*
	�����ִ�н��
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
	��32λ�������ϴ��ģʽ��b��ֵΪ
*/
//int main()
//{
//	unsigned int a = 0x1234;  // --> x86_64MSVCС��ģʽ
//	unsigned char b = *(unsigned char*)&a;
//	printf("%x", b);
//}

//work 3
/*
	����ִ�н��
*/
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;	//-->��char���ͣ����ֻ���ȡ�Ͱ�λ�����Ѱ�ҵͰ�λΪ0
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//work 4
/*
	�������
*/

//void Triangle(int n)
//{
//	int data[30] = { 1 };
//
//	int i, j;
//	printf("  1\n"); //��һ�о�ֱ�Ӵ�ӡ��
//	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ
//	{
//		for (j = i; j > 0; j--) //�Ӻ���ǰ�������һ�е�������ʹ��ǰ�ͱ�����
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
	�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
����Ϊ4�����ɷ��Ĺ���:
	A˵�������ҡ�
	B˵����C��
	C˵����D��
	D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
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
	int tmp[6] = { 0 }; //��Ǳ�ʵ���ǹ�ϣ���˼·��һ��ʼÿ��Ԫ�ض���0��
	for (size_t i = 0; i < 5; i++)
	{
		if (tmp[p[i]]) //������λ�õı���Ѿ���1��������ظ���ֱ�ӷ���0��
			return 0;
		tmp[p[i]] = 1; //������ǣ�������λ�ñ��Ϊ1��
	}
	return 1; //ȫ��������Ҳû�г����ظ������������OK��
}

int main()
{
	int p[5]; //0 1 2 3 4�ֱ����a b c d e

	for (p[0] = 1; p[0] <= 5; p[0]++)
		for (p[1] = 1; p[1] <= 5; p[1]++)
			for (p[2] = 1; p[2] <= 5; p[2]++)
				for (p[3] = 1; p[3] <= 5; p[3]++)
					for (p[4] = 1; p[4] <= 5; p[4]++) //���ѭ������
					{
						//����������˵����������ڱȽϱ��ʽֻ��0��1������������Ҫ������������ֻ��һ��Ϊ�棬������ñȽϱ��ʽ��ֵ�ܺ�Ϊ1�ķ�ʽֱ���ж��������˻�Ҫ�ж����ܲ��С�
						if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
							(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
							(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
							(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
							(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
							checkData(p) //���ܲ���
							)
						{
							for (int i = 0; i < 5; i++)
								printf("%d ", p[i]);
							printf("\n");
						}
					}
}