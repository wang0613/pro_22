#include <stdio.h>
#include <stddef.h>
//offsetof()

//����վ���Զ�������-�ṹ��  ö��  ������


//����һ���ṹ������
struct student {
    //�ṹ��ĳ�Ա����
    char name[20];
    char tele[20];
    char sex[10];
    int age;
} ss; //��ʱ��ss ����һ��ȫ�ֵĽṹ�����

struct student structstudent; //ȫ�ֵĽṹ�����  ����Ĭ��ֵ


//2�������Ľṹ������
struct {
    char name[20];
} sn; // ֻ��ͨ�����ַ�ʽ �����ṹ�����

struct {
    char name[20];
} *sp; //�����Ľṹ��ָ������

typedef struct Node
{
    int data;  //������
    //�����һ���ڵ�ĵ�ַ,��������
    struct Node* next; //ָ����
}Node;
//typedef ���ṹ�嶨��Ϊ Node
int main1() {


    struct student s1 = {"����", "10086", "��", 20};

    printf("%d\n", structstudent.age); //Ĭ��ֵ
    printf("%s\n", s1.name);

    struct Node n1;
    Node n2; //��������������

    return 0;
}


//�ṹ���ָ�����
struct s1
{
    char c1;//������1
    int a; //������ 4 ��Ҫ�������������������
    char c2; //������ 1
    //��� �����Ƿ���������������������
};
struct s2
{
    int a;  //������4
    char c1;
    char c2;
};
struct s3
{
    double d;//0-7
    char c; //8 ������
    int i; //12 13 14 15
};
#pragma pack(4)  //����Ĭ�϶�����Ϊ4��������������4
struct s4
{
    char c;
    struct s3 s; //����������8  ռ��16
    double d;
};
#pragma pack() //ȡ��Ĭ�϶�����

//���ɣ� ��ռ�ÿռ�С�õ��ֶξ�������һ��(�����˷ѿռ�)

int main()
{
    //�ڴ�������⣿����ṹ���С
    //1���ṹ��ĵ�һ����Ա����ṹ��ƫ��Ϊ0�ĵ�ַ��
    //2��������Ա����Ҫ���������(������)���������ĵ�ַ��
    //��������������Ĭ�ϵ�һ����������ó�Ա��С�Ľ�Сֵ(vs�е�Ĭ��ֵΪ8)
    //3:�ṹ����ܴ�СΪ��������(ÿһ��Ա����һ��������)��������
    //4:���������Ƕ�׽ṹ��������Ƕ�׽ṹ����뵽�Լ����������������������ṹ��������С����������������(��Ƕ�׽ṹ�������)��������
    printf("%d\n",sizeof(struct s1)); //12
    printf("%d\n",sizeof(struct s2)); //8
    printf("%d\n",sizeof(struct s3)); //16
    printf("%d\n",sizeof(struct s4)); //32

    printf("%d\n",offsetof(struct s3,d));  //����ṹ������ڽṹ���ƫ�����Ƕ���?
    printf("%d\n",offsetof(struct s3,c));
    printf("%d\n",offsetof(struct s3,i));


}