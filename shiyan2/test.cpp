#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define scanf_s scanf
#define fscanf_s fscanf

typedef struct GUIZI
{
    char dongxi[100];
    int mima;
    int bianhao;
    struct GUIZI *next;
} guizi; // 结构体 也就是一个柜子，里面有物品名，密码，编号，下一个柜子的地址
int CreateCode()
{
    int a = 0;
    srand(time(NULL));
    do
    {
        int digit = rand() % 10;
        a = a * 10 + digit;
    } while (a < 100000);
    return a;
}
// 创建密码
guizi *createJiedian(int guizinumber)
{
    guizi *new1 = (guizi *)malloc(sizeof(guizi));
    if (new1 == NULL)
    {
        printf("创建新节点失败");
        return {0};
    }
    new1->mima = CreateCode();                // 给密码
    new1->bianhao = rand() % guizinumber + 1; // 给编号
    printf("请输入物品的名称:");
    getchar(); // 隔开回车键
    scanf_s("%s", new1->dongxi, 100);
    new1->next = NULL;
    return new1;
}
// 创建节点,创建编号并将信息放进节点(主动存储时)
void checkthesame(guizi *head, guizi *newguizi, int guizinumber)
{
    guizi *same1 = head;
    guizi *same2 = head; // same1查密码,same2查编号
    while (same1->next != NULL)
    {
        while (newguizi->mima != same1->mima)
        {
            same1 = same1->next;
            if (same1->next == NULL) // 即same==newguizi
                break;
        }
        if (same1->next == NULL)
            break; // 没有重复的密码就跳出查找重复密码的循环
        newguizi->mima = CreateCode();
        same1 = head; // 让same回到head的位置再查找一遍有没有重复的密码
    }
    while (same2->next != NULL) // 和前面same1一样的格式
    {
        while (newguizi->bianhao != same2->bianhao)
        {
            same2 = same2->next;
            if (same2->next == NULL)
                break;
        }
        if (same2->next == NULL)
            break;
        newguizi->bianhao = rand() % guizinumber + 1;
        same2 = head;
    }
}
// 找到是否有重复的密码和编号并且改掉
void storage(guizi *head, int guizinumber, int number)
{
    guizi *newguizi = createJiedian(guizinumber); // 创造一个节点，生成密码以及物品信息
    guizi *now = head;
    while (now->next != NULL) // 找到此时的尾结点或者是中间断开的位置
        now = now->next;
    now->next = newguizi; // 找到尾结点并且接在尾结点后面，保证新节点为最后一个节点
    checkthesame(head, newguizi, guizinumber);
    printf("密码是:%d\n", newguizi->mima); // 显示出当前柜子的物品信息和密码
    printf("物品名称为:%s\n", newguizi->dongxi);
    printf("放在%d号柜子里\n", newguizi->bianhao);
}
// 接进链表里并找是否存在重复的密码（新存储而不是读取原有文件）
void deletejiedian(guizi *head, guizi *check)
{
    guizi *last = head; // 要删掉的节点的前一个节点  先从head开始找
    while (last->next != check)
        last = last->next; // while结束后last就指向check的前一个节点
    last->next = check->next;
    printf("删除成功\n");
    free(check);
}
// 取出后将该节点删掉并将后面的节点和前面的接上
int checkcode(guizi *head, int c)
{
    guizi *check = head; // 新建一个用来查找密码的指针check
    while (check != NULL)
    {
        if (check->mima != c)
            check = check->next;
        else
        {
            printf("您的柜子编号为%d号,里面的物品是%s,请及时取出\n", check->bianhao, check->dongxi);
            deletejiedian(head, check);
            return 1; // 找到了对应的就直接显示信息然后退出这个函数
        }
    }
    return 0; // 运行到了return 0就说明没找到密码
}
// 取出时从头到尾查找密码 没找到就return 0，找到了就return 1，并且输出几号柜子和里面物品的名称
void shanchusuoyouguizi(guizi *head)
{
    guizi *delete1 = head; // delete1是要释放的节点
    while (1)
    {
        if (delete1->next == NULL) // 若head后面没有节点就直接结束这个函数
            break;
        delete1 = delete1->next;    // 指向head后面一个节点
        head->next = delete1->next; // 让head指向delete1后面的那个节点
        free(delete1);
        delete1 = head; // 让delete1重新指向head
    }
    printf("内存已经全部释放");
}
// 删掉所有的柜子,清除内存,该函数不释放head
void write_into_document(guizi *head, FILE *fp)
{
    fclose(fp);
    fopen_s(&fp, "柜子.txt", "w+"); // 清空文件
    if (head->next == NULL)
        return; // 如果head后面没有节点就可以直接结束写入文件
    guizi *current = head->next;
    while (1)
    {
        fprintf(fp, "%s %d %d\n", current->dongxi, current->mima, current->bianhao); // 一个柜子的所有信息就写在一行
        current = current->next;
        if (current == NULL)
            break;
    }
    printf("已将已有柜子的所有信息写入文件中\n");
}
// 将已有的柜子全部写入文件里面
void read_the_document(guizi *head, FILE *fp, int number)
{
    guizi *current = head;
    while (!feof(fp))
    {
        guizi *read = (guizi *)malloc(sizeof(guizi));
        if (read == NULL)
        {
            printf("文件读取错误");
            free(read);
            return;
        }
        if (fscanf_s(fp, "%s", read->dongxi, 100) != 1)
            break;
        if (fscanf_s(fp, "%d", &read->mima) != 1)
            break;
        if (fscanf_s(fp, "%d", &read->bianhao) != 1)
            break;
        read->next = NULL;
        {
            current->next = read;
            current = read;
        }
        number++;
    }
    printf("目前已存储的柜子有%d个\n", number);
}
// 将已有文件内的柜子信息读取并放进链表中.并读取已存储的柜子数
void start_manage(FILE *fp1)
{
    printf("原来并没有管理文件，现在开始创建文件\n");
    fopen_s(&fp1, "管理.txt", "w"); // 创建这个文件
    if (!fp1)
        return;
    int guizinumber = 0;
    int managecode = 123456;
    printf("现在需要更改进入管理模式的密码，初始密码为%d,请输入要更改的密码:", managecode);
    scanf_s("%d", &managecode);
    printf("更改管理密码成功\n");
    printf("现在需要确定总柜子数，请输入总柜子数：");
    scanf_s("%d", &guizinumber);
    printf("柜子的总数为%d个，在有柜子存放物品的时候不可以修改柜子总数", guizinumber);
    fprintf(fp1, "%d %d", managecode, guizinumber); // 先是管理模式密码，后面是柜子总数
    // fprintf(fp1, "%d", guizinumber);
}
// 若管理文件不存在就进行初始化，包括柜子总数和管理密码
int main()
{
    FILE *fp;
    FILE *fp1;
    int guizinumber = 0; // 柜子的总数
    int managecode = 0;  // 进入管理模式的密码
    fopen_s(&fp1, "管理.txt", "r+");
    if (!fp1)
        start_manage(fp1);
    fscanf_s(fp1, "%d %d", &managecode, &guizinumber);

    guizi *head = (guizi *)malloc(sizeof(guizi)); // 创建一个head节点
    head->next = NULL;
    head->mima = 0;
    head->bianhao = 0;
    int number = 0; // 记录已存储的柜子数

    fopen_s(&fp, "柜子.txt", "r+"); // 打开文件，判断现在有没有这个文件
    if (!fp)                        // 目前没有这个文件的情况
    {
        printf("原来并没有柜子文件，现在开始创建文件\n");
        fopen_s(&fp, "柜子.txt", "w"); // 创建这个文件
        fclose(fp);
        fopen_s(&fp, "柜子.txt", "r+"); // 关掉文件后再用想要的读写模式打开
    }
    else
        read_the_document(head, fp, number);

    while (1) // 让这个循环一直进行，直到主动退出
    {
        printf("1.存储\n2.取出\n3.退出\n4.管理\n");
        int a;
        scanf_s("%d", &a);
        switch (a)
        {
        case 1:
        {
            storage(head, guizinumber, number);
            break;
            // 存储
        }
        case 2: // 取出
        {
            int c;
            printf("请输入密码:");
            scanf_s("%d", &c);
            for (int d = 2; d >= 0; d--) // d为剩余输入密码的次数
            {
                if (checkcode(head, c) == 0)
                    if (d == 0)
                    {
                        printf("机会已经用完，请退出程序后重试");
                        return 0;
                    }
                    else
                    {
                        printf("没有查询到该密码所对应的柜子，您还有%d次机会，请重新输入密码\n", d);
                        scanf_s("%d", &c); // 重新输入密码
                    }
                else
                    break;
            }
            break;
        }
        case 3: // 退出时需要将现有链表里的所有数据存入文件里
        {
            fclose(fp1);
            fopen_s(&fp1, "管理.txt", "w+");
            if (!fp1)
            {
                printf("管理文件出错");
                return 0;
            }
            fprintf(fp1, "%d %d", managecode, guizinumber);
            write_into_document(head, fp);
            fclose(fp1);
            shanchusuoyouguizi(head);
            free(head);
            fclose(fp);
            return 0;
        }
        case 4:
        {
            break;
        }
        default:
        {
            printf("输入格式错误，请关掉程序后重试\n");
            return 0;
        }
            system("pause");
            return 0;
        }
    }
}
// 现在已经初始化控制了柜子的总数，下次需要写当柜子数满的时候不能再往里面存了，和为管理模式更改密码