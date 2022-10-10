#include <stdio.h>
#include <stddef.h>
//offsetof()

//第四站：自定义类型-结构体  枚举  联合体


//声明一个结构体类型
struct student {
    //结构体的成员变量
    char name[20];
    char tele[20];
    char sex[10];
    int age;
} ss; //此时的ss 就是一个全局的结构体变量

struct student structstudent; //全局的结构体变量  具有默认值


//2：匿名的结构体类型
struct {
    char name[20];
} sn; // 只能通过此种方式 创建结构体变量

struct {
    char name[20];
} *sp; //匿名的结构体指针类型

typedef struct Node
{
    int data;  //数据域
    //存放下一个节点的地址,构成链表
    struct Node* next; //指针域
}Node;
//typedef 将结构体定义为 Node
int main1() {


    struct student s1 = {"张三", "10086", "男", 20};

    printf("%d\n", structstudent.age); //默认值
    printf("%s\n", s1.name);

    struct Node n1;
    Node n2; //重新命名的类型

    return 0;
}


//结构体的指针对齐
struct s1
{
    char c1;//对齐数1
    int a; //对齐数 4 都要对齐对齐数的整数倍数
    char c2; //对齐数 1
    //最后看 整体是否是最大对齐数的整数倍数
};
struct s2
{
    int a;  //对齐数4
    char c1;
    char c2;
};
struct s3
{
    double d;//0-7
    char c; //8 。。。
    int i; //12 13 14 15
};
#pragma pack(4)  //设置默认对齐数为4，最大对齐数就是4
struct s4
{
    char c;
    struct s3 s; //对齐数就是8  占用16
    double d;
};
#pragma pack() //取消默认对齐数

//技巧： 让占用空间小得的字段尽量放在一起(减少浪费空间)

int main()
{
    //内存对齐问题？计算结构体大小
    //1：结构体的第一个成员在与结构体偏量为0的地址处
    //2：其他成员变量要对其个数字(对齐数)的整数倍的地址处
    //对齐数：编译器默认的一个对齐数与该成员大小的较小值(vs中的默认值为8)
    //3:结构体的总大小为最大对齐数(每一成员都有一个对齐数)的整数倍
    //4:如果出现了嵌套结构体的情况，嵌套结构体对齐到自己的最大对齐数的整数倍。结构体的整体大小就是所有最大对齐数(含嵌套结构体对齐数)的整数倍
    printf("%d\n",sizeof(struct s1)); //12
    printf("%d\n",sizeof(struct s2)); //8
    printf("%d\n",sizeof(struct s3)); //16
    printf("%d\n",sizeof(struct s4)); //32

    printf("%d\n",offsetof(struct s3,d));  //计算结构体相对于结构体的偏移量是多少?
    printf("%d\n",offsetof(struct s3,c));
    printf("%d\n",offsetof(struct s3,i));


}