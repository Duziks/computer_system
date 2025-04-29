#include <stdio.h>

// 定义枚举类型
enum Week { Mon, Tue, Wed };

// 定义结构体类型
struct Student {
    int id;
    float score;
    char grade;
};

// 定义联合体类型
union Data {
    int i;
    float f;
    char str[4];
};

int main() {
    // 基本数据类型
    int student_id = 20230101;       // 学号数字部分
    char name[] = "张三";            // 姓名
    float id_number = 44030819990101.0f; // 身份证号部分数字
    
    // 指针类型
    int *p_id = &student_id;
    char (*p_name)[4] = &name;
    
    // 数组类型
    int scores[] = {90, 85, 95};
    
    // 结构体实例
    struct Student stu = {20230101, 98.5, 'A'};
    
    // 联合体实例
    union Data data;
    data.i = 0x12345678;
    
    // 枚举实例
    enum Week today = Mon;

    // 打印基本类型信息
    printf("变量名: 学号（整数）\n值: %d\n地址: %p\n内存字节: ", student_id, &student_id);
    for(size_t i=0; i<sizeof(student_id); i++)
        printf("%02x ", ((unsigned char*)&student_id)[i]);
    printf("\n\n");

    printf("变量名: 姓名（字符串）\n值: %s\n地址: %p\n内存字节: ", name, name);
    for(size_t i=0; i<sizeof(name); i++)
        printf("%02x ", (unsigned char)name[i]);
    printf("\n\n");

    printf("变量名: 身份证号（浮点数）\n值: %f\n地址: %p\n内存字节: ", id_number, &id_number);
    for(size_t i=0; i<sizeof(id_number); i++)
        printf("%02x ", ((unsigned char*)&id_number)[i]);
    printf("\n\n");

    // 打印指针信息
    printf("变量名: 指针id\n值: %p\n地址: %p\n内存字节: ", (void*)p_id, &p_id);
    for(size_t i=0; i<sizeof(p_id); i++)
        printf("%02x ", ((unsigned char*)&p_id)[i]);
    printf("\n\n");

    // 打印数组信息
    printf("变量名: 分数（数组）\n值: ");
    for(int i=0; i<3; i++) printf("%d ", scores[i]);
    printf("\n地址: %p\n内存字节: ", scores);
    for(size_t i=0; i<sizeof(scores); i++)
        printf("%02x ", ((unsigned char*)scores)[i]);
    printf("\n\n");

    // 打印结构体信息
    printf("变量名: stu（结构体）\n值: {id=%d, score=%.1f, grade=%c}\n地址: %p\n内存字节: ",
           stu.id, stu.score, stu.grade, &stu);
    for(size_t i=0; i<sizeof(stu); i++)
        printf("%02x ", ((unsigned char*)&stu)[i]);
    printf("\n\n");

    // 打印联合体信息
    printf("变量名: data（union）\n值: {i=%d, f=%.2f}\n地址: %p\n内存字节: ",
           data.i, data.f, &data);
    for(size_t i=0; i<sizeof(data); i++)
        printf("%02x ", ((unsigned char*)&data)[i]);
    printf("\n\n");

    // 打印枚举信息
    printf("变量名: today（enum）\n值: %d\n地址: %p\n内存字节: ", today, &today);
    for(size_t i=0; i<sizeof(today); i++)
        printf("%02x ", ((unsigned char*)&today)[i]);
    printf("\n\n");

    // 打印函数地址
    printf("main函数地址: %p\n", main);
    printf("printf函数地址: %p\n", printf);

    return 0;
}