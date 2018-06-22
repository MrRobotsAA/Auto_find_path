#define MaxVnum 60
#define Max 40

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string.h>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;
void shouye();
void denglu();
void cishouye();
void xiugai();
void hongbo1();
void erchou1();
void erchou2();
void color(short x);
struct node
{
    string name;
    string key;
} stu[100000];

typedef struct Arc //边的权值信息
{
    int dis;//距离
} matrix[MaxVnum][MaxVnum]; //邻接矩阵
typedef struct Vinfo//顶点信息
{
    int id;//顶点编号；
    char name[111];//顶点名称；
    char introduction[1111];//顶点介绍；

} Vinfo;
typedef struct graph //图结构信息；
{
    Vinfo V[MaxVnum];//顶点数组；
    matrix Arc;//邻接矩阵；
    int Vnum, Arcnum;
    int length;
} graph;
graph initgraph()
{
    int i,j;
    graph c;
    c.length = 52;//顶点个数
    c.Vnum = 52;
    for(i = 1; i <= c.Vnum; i++)
        c.V[i].id = i;
    strcpy(c.V[1].name,"四体");
    strcpy(c.V[1].introduction,"第四体育场位于学校西北角的一个体育场");
    strcpy(c.V[2].name,"四餐");
    strcpy(c.V[2].introduction,"第四餐厅位于山东理工大学西校区西北面，双层建筑食堂，菜样丰富，味道可口，为西校区广大学子提供了良好的饮食环境");
    strcpy(c.V[3].name,"15教");
    strcpy(c.V[3].introduction,"主要是理学院上课的地方");
    strcpy(c.V[4].name,"校医院");
    strcpy(c.V[4].introduction,"山东理工大学医院是集医疗、预防保健于一体的综合性医疗单位，医院本部设在西校区，东校区设有分院，医院坐落在环境优美的校园内，建筑面积5290平方米");
    strcpy(c.V[5].name,"21号宿舍");
    strcpy(c.V[5].introduction,"学生住宿的地方");
    strcpy(c.V[6].name,"13号宿舍");
    strcpy(c.V[6].introduction,"学生住宿的地方");
    strcpy(c.V[7].name,"学生公寓");
    strcpy(c.V[7].introduction,"学生住宿的地方");
    strcpy(c.V[8].name,"北门");
    strcpy(c.V[8].introduction,"只能行人通过，在人民路与重庆路（西九路）的丁字路口");
    strcpy(c.V[9].name,"三餐");
    strcpy(c.V[9].introduction,"餐厅共有三层，第三层是竹园餐厅，风景优美");
    strcpy(c.V[10].name,"农行");
    strcpy(c.V[10].introduction,"存取款处");
    strcpy(c.V[11].name,"大学生艺术中心");
    strcpy(c.V[11].introduction,"分为四个楼层，四个楼层分布有序：一层除了演出舞台和观众席外，还有舞厅、茶室、自行车库等；二层有团委办公室、网站和大学生就业指导中心、勤工助学中心等；三层分布着校学生会、社团联合会、心理健康中心等部；四层主要是一些为保证工作正常运作的监控设备等。远处看我们的艺术中心，还像是一双张开手的双臂，等待着被同学们拥抱的模样，与逸夫图书馆遥相呼应，形成一个漂亮的椭圆");
    strcpy(c.V[12].name,"浴池");
    strcpy(c.V[12].introduction,"学生沐浴中心");
    strcpy(c.V[13].name,"地下超市");
    strcpy(c.V[13].introduction,"位于三餐附近，因在地下，故得名地下超市");
    strcpy(c.V[14].name,"大坑");
    strcpy(c.V[14].introduction,"在稷下湖的西面就是大学生艺术广场（俗称大坑）。这是个非常活跃的地方，很多的大型晚会都是在这里举行的，是理工大的一个标志性地方，可以容纳上千观众，举办的节目当然也是相当的精彩了");
    strcpy(c.V[15].name,"稷下湖");
    strcpy(c.V[15].introduction,"这是学校的花园，清澈的湖水和环绕着湖水的山坡，绿树成荫，风景很美，是个聚会散步的好地方");
    strcpy(c.V[16].name,"10教");
    strcpy(c.V[16].introduction,"音乐学院学生上课的地方");
    strcpy(c.V[17].name,"8教");
    strcpy(c.V[17].introduction,"外国语学院学生上课的地方");
    strcpy(c.V[18].name,"9教");
    strcpy(c.V[18].introduction,"计算机科学与技术学院学生上课的地方");
    strcpy(c.V[19].name,"11教");
    strcpy(c.V[19].introduction,"美术学院学生上课的地方");
    strcpy(c.V[20].name,"6教");
    strcpy(c.V[20].introduction,"学生上课的地方");
    strcpy(c.V[21].name,"长廊");
    strcpy(c.V[21].introduction,"内有餐馆，超市，理发店等等");
    strcpy(c.V[22].name,"三体");
    strcpy(c.V[22].introduction,"主要是篮球场,也是新生报道的场所");
    strcpy(c.V[23].name,"山丘");
    strcpy(c.V[23].introduction,"位于三体北侧，主要是小山丘和小树林");
    strcpy(c.V[24].name,"博大花园");
    strcpy(c.V[24].introduction,"内有农业银行，超市和教师公寓楼等等");
    strcpy(c.V[25].name,"东门");
    strcpy(c.V[25].introduction,"在共青团路的西尽头，也在西八路（南京路）西边，机动车可以驶入");
    strcpy(c.V[26].name,"西门");
    strcpy(c.V[26].introduction,"在西十路（北京路东），也就是体育中心东边");
    strcpy(c.V[27].name,"校产");
    strcpy(c.V[27].introduction,"东理工大学校办产业总公司是学校经营性资产的管理部门，代表学校行使股东权利；对学校经营性资产承担安全、保值、增值责任；承担科技成果转化和产业化任务");
    strcpy(c.V[28].name,"食物");
    strcpy(c.V[28].introduction,"是学校后勤行政管理职能部门，日常工作管理机构有综合科、工程技术科和房地产管理科；管理六个后勤实体");
    strcpy(c.V[29].name,"5号实验");
    strcpy(c.V[29].introduction,"实验楼");
    strcpy(c.V[30].name,"4号实验");
    strcpy(c.V[30].introduction,"实验楼");
    strcpy(c.V[31].name,"工科实验");
    strcpy(c.V[31].introduction,"工科同学做实验的地方");
    strcpy(c.V[32].name,"交通实验");
    strcpy(c.V[32].introduction,"机械、交通学院同学做实验的地方");
    strcpy(c.V[33].name,"13教");
    strcpy(c.V[33].introduction,"体育、化工学院同学上课的地方");
    strcpy(c.V[34].name,"12教");
    strcpy(c.V[34].introduction,"机械、交通学院同学上课的地方");
    strcpy(c.V[35].name,"5教");
    strcpy(c.V[35].introduction,"学生上自习和上课的地方");
    strcpy(c.V[36].name,"图书馆");
    strcpy(c.V[36].introduction,"建筑面积3.8万平方米，外立面的石材犹如一排排书架，北侧的退台寓意着攀登的阶梯，图书馆建筑宛如伸开的双臂，欢迎渴求知识，勤奋学习的莘莘学子走进这座知识的殿堂");
    strcpy(c.V[37].name,"4教");
    strcpy(c.V[37].introduction,"学生上自习和上课的地方");
    strcpy(c.V[38].name,"2体");
    strcpy(c.V[38].introduction,"是山东理工大学主体育场，是学校标志性建筑之一。始建于2000年，多年来为淄博市及学校举行重大庆典及运动会做出了重大贡献");
    strcpy(c.V[39].name,"杏园");
    strcpy(c.V[39].introduction,"环境优雅宜人，清新自然。是集学术交流、教育培训、举办会议、住宿、餐饮等功能于一体的现代化宾馆");
    strcpy(c.V[40].name,"信息楼");
    strcpy(c.V[40].introduction,"山东理工大学原图书馆，后来成为了机房");
    strcpy(c.V[41].name,"三教");
    strcpy(c.V[41].introduction,"学生上自习和上课的地方");
    strcpy(c.V[42].name,"1号实验");
    strcpy(c.V[42].introduction,"各种实验均可在这里进行");
    strcpy(c.V[43].name,"鸿远楼");
    strcpy(c.V[43].introduction,"这是学校的办公区域，也是学校的门面，在学校南门，也是正门。鸿远楼前有个广场，适合一些小型的活动");
    strcpy(c.V[44].name,"1号公寓");
    strcpy(c.V[44].introduction,"学生住宿的地方");
    strcpy(c.V[45].name,"3号公寓");
    strcpy(c.V[45].introduction,"学生住宿的地方");
    strcpy(c.V[46].name,"2号公寓");
    strcpy(c.V[46].introduction,"学生住宿的地方");
    strcpy(c.V[47].name,"2餐");
    strcpy(c.V[47].introduction,"分为两层，二楼有自选餐");
    strcpy(c.V[48].name,"1餐");
    strcpy(c.V[48].introduction,"该餐厅共一层");
    strcpy(c.V[49].name,"一体");
    strcpy(c.V[49].introduction,"学校四大体育场之一，位于学校东北角");
    strcpy(c.V[50].name,"2教");
    strcpy(c.V[50].introduction,"国防生的聚居地");
    strcpy(c.V[51].name,"1教");
    strcpy(c.V[51].introduction,"学生上自习和上课的地方");
    strcpy(c.V[52].name,"南门");
    strcpy(c.V[52].introduction,"学校的主门，位于新村路（原张周路）北边");
    for(i = 1; i <= c.Vnum; i++)
        for(j = 1; j <= c.Vnum; j++)
            c.Arc[i][j].dis = 0x3f3f3f3f;//初始化距离
    c.Arc[1][2].dis = 150;
    c.Arc[1][3].dis = 240;
    c.Arc[2][4].dis = 100;
    c.Arc[2][5].dis = 100;
    c.Arc[3][26].dis = 800;
    c.Arc[4][21].dis = 50;
    c.Arc[5][6].dis = 50;
    c.Arc[6][7].dis = 50;
    c.Arc[7][8].dis = 100;
    c.Arc[7][9].dis = 150;
    c.Arc[8][15].dis = 500;
    c.Arc[8][23].dis = 300;
    c.Arc[9][10].dis = 50;
    c.Arc[9][12].dis = 40;
    c.Arc[9][11].dis = 70;
    c.Arc[10][11].dis = 100;
    c.Arc[11][20].dis = 200;
    c.Arc[11][19].dis = 30;
    c.Arc[11][14].dis = 100;
    c.Arc[11][16].dis = 300;
    c.Arc[12][13].dis = 10;
    c.Arc[13][15].dis = 80;
    c.Arc[14][19].dis = 150;
    c.Arc[14][16].dis = 150;
    c.Arc[15][16].dis = 200;
    c.Arc[15][22].dis = 150;
    c.Arc[15][24].dis = 20;
    c.Arc[15][25].dis = 1300;
    c.Arc[16][19].dis = 150;
    c.Arc[16][17].dis = 50;
    c.Arc[17][18].dis = 150;
    c.Arc[17][35].dis = 500;
    c.Arc[17][37].dis = 500;
    c.Arc[18][19].dis = 50;
    c.Arc[22][24].dis = 200;
    c.Arc[22][23].dis = 50;
    c.Arc[23][24].dis = 20;
    c.Arc[24][25].dis = 600;
    c.Arc[25][26].dis = 1800;
    c.Arc[25][46].dis = 1000;
    c.Arc[26][27].dis = 300;
    c.Arc[26][29].dis = 600;
    c.Arc[26][33].dis = 700;
    c.Arc[27][28].dis = 100;
    c.Arc[27][30].dis = 100;
    c.Arc[27][29].dis = 90;
    c.Arc[28][31].dis = 80;
    c.Arc[28][52].dis = 1400;
    c.Arc[29][33].dis = 100;
    c.Arc[29][30].dis = 500;
    c.Arc[30][34].dis = 100;
    c.Arc[30][31].dis = 600;
    c.Arc[31][32].dis = 600;
    c.Arc[31][36].dis = 800;
    c.Arc[32][52].dis = 1200;
    c.Arc[33][35].dis = 800;
    c.Arc[33][34].dis = 100;
    c.Arc[34][35].dis = 600;
    c.Arc[35][37].dis = 150;
    c.Arc[35][36].dis = 500;
    c.Arc[36][37].dis = 500;
    c.Arc[36][38].dis = 800;
    c.Arc[36][42].dis = 1000;
    c.Arc[37][38].dis = 400;
    c.Arc[38][39].dis = 100;
    c.Arc[38][40].dis = 500;
    c.Arc[39][40].dis = 200;
    c.Arc[40][44].dis = 600;
    c.Arc[40][41].dis = 500;
    c.Arc[41][43].dis = 700;
    c.Arc[41][42].dis = 200;
    c.Arc[42][52].dis = 500;
    c.Arc[43][52].dis = 600;
    c.Arc[43][44].dis = 400;
    c.Arc[43][50].dis = 700;
    c.Arc[44][45].dis = 100;
    c.Arc[44][48].dis = 100;
    c.Arc[45][46].dis = 100;
    c.Arc[46][47].dis = 200;
    c.Arc[47][49].dis = 100;
    c.Arc[49][50].dis = 500;
    c.Arc[50][51].dis = 200;
    c.Arc[51][52].dis = 800;
    for(i = 1; i <= c.Vnum; i++)
        for(j = 1; j <= c.Vnum; j++)
            c.Arc[j][i].dis = c.Arc[i][j].dis;
    return c;
}
void initXml()
{
    TiXmlDocument *doc = new TiXmlDocument();
    TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "ANSI", "yes");
    doc->LinkEndChild(decl);
    doc->SaveFile("./main2/bin/Debug/buildings.xml");
}

void writeXml(graph b)
{
    TiXmlDocument *doc = new TiXmlDocument();
    TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "ANSI", "yes");
    doc->LinkEndChild(decl);
    TiXmlElement *rootElement = new TiXmlElement("buildings");
    for(int i=1; i<=b.length; i++)
    {
        TiXmlElement *buildElement = new TiXmlElement("building");
        TiXmlElement *idElement = new TiXmlElement("id");
        char string[100];
        itoa((b.V[i].id) , string, 10);
        TiXmlText *text1 = new TiXmlText(string);
        idElement->LinkEndChild(text1);
        TiXmlElement *nameElement = new TiXmlElement("name");
        TiXmlText *text2 = new TiXmlText(b.V[i].name);
        nameElement->LinkEndChild(text2);
        TiXmlElement *desElement = new TiXmlElement("introduction");
        TiXmlText *text3 = new TiXmlText(b.V[i].introduction);
        desElement->LinkEndChild(text3);
        buildElement->LinkEndChild(idElement);
        buildElement->LinkEndChild(nameElement);
        buildElement->LinkEndChild(desElement);
        rootElement->LinkEndChild(buildElement);
    }
    doc->LinkEndChild(rootElement);
    doc->SaveFile("../main2/bin/Debug/buildings.xml");
    doc->SaveFile("../main2/buildings.xml");
    doc->SaveFile("buildings.xml");
}


int we=0,yanzheng,count1=0,count2=0;
const int inf = 0x3f3f3f3f;
void add_node()
{
    color(16);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"增加节点信息";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    int n,tu[99][99];
    color(16);
    cout<<"                       ";
    color(13);
    ifstream infile("Graph_data.txt");
    infile>>n;
    printf("该节点ID为:%d",n+1);
    printf("\n请输入该该节点与剩余%d个节点间的路径（两数之间用空格隔开，按回车键结束）。\n",n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            infile>>tu[i][j];
        }
    }
    n++;
    int u;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&u);
        tu[n-1][i] = u;
        tu[i][n-1] = u;
    }
    tu[n-1][n-1] = 0;
    infile.close();
    ofstream outfile("Graph_data.txt");
    outfile<<n;
    outfile<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            outfile<<tu[i][j];
            outfile<<" ";
        }
        outfile<<"\n";
    }
    outfile.close();
    printf("***增加节点成功***\n");
    cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }
}
void delete_node()
{
    color(16);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"删除节点信息";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    color(16);
    cout<<"                       ";
    color(13);
    int n,tu[99][99],i,x;
    printf("请输入要删除的节点id:");
    scanf("%d",&x);
   // printf("\n");
    ifstream infile("Graph_data.txt");
    infile>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            infile>>tu[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
       tu[x][i] = inf;
       tu[i][x] = inf;
    }
    infile.close();
    ofstream outfile("Graph_data.txt");
    outfile<<n;
    outfile<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            outfile<<tu[i][j];
            outfile<<" ";
        }
        outfile<<"\n";
    }
    outfile.close();
    printf("***删除完成***\n");
    cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }
}
void change_node()
{cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }
    color(16);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"修改路径信息";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    int n,tu[99][99],i,x;
    color(16);
    cout<<"                       ";
    color(13);
    printf("请输入要修改的节点id:");
    scanf("%d",&x);
   // printf("\n");
    ifstream infile("Graph_data.txt");
    infile>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            infile>>tu[i][j];
        }
    }
    infile.close();
    printf("\n请输入该该节点与剩余%d个节点间的路径（两数之间用空格隔开，按回车键结束）。\n",n);
    int u;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&u);
        tu[x][i] = u;
        tu[i][x] = u;
    }


    ofstream outfile("Graph_data.txt");
    outfile<<n;
    outfile<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            outfile<<tu[i][j];
            outfile<<" ";
        }
        outfile<<"\n";
    }
    outfile.close();
    printf("***修改完成***\n");
    cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }
}
void print_graph()
{
    color(16);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"输出地图信息";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    int n,tu[99][99];
    color(16);
    cout<<"                       ";
    color(13);
    ifstream infile("Graph_data.txt");
    infile>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            infile>>tu[i][j];
        }
    }
    infile.close();
    printf("图的节点数:%d\n",n);
    printf("下面是图的临接矩阵:\n");
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
           printf("%d ",tu[i][j]);
       }
       printf("\n");
    }
     cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }

}
void update_bus_road()
{
    color(16);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"录入公交路线";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    color(16);
    cout<<"                       ";
    color(13);
    int m,k,kk;
//    freopen("Bus_data.txt","w",stdin);
    ofstream outfile("Bus_data.txt");
    printf("请输入公交路线条数:");
    scanf("%d",&m);
    outfile<<m;
    outfile<<"\n";
    for(int i=1;i<=m;i++)
    {
        printf("\n请输入%d号线路站点数：",i);
        scanf("%d",&k);
            outfile<<k;
            outfile<<" ";
            printf("\n请依次输入%d号线路站点编号（用空格隔开，换行结束）：",i);
            for(int j=0;j<k;j++)
            {
               scanf("%d",&kk);
               outfile<<kk;
               outfile<<" ";

            }
               outfile<<"\n";
    }
    outfile.close();
    cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入1返回上一层:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        hongbo1();
    }
}
void color(short x) //自定义函根据参数改变颜色
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //只有一个参数，改变字体颜色
    else//默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void xiugai()
{
    string name1,key,key1;
    count1=0;count2=0;
    int sum=0;
    color(16);
    system("cls");
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"密码修改";
    color(16);
    cout<<"                                  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入学号(3次错误自动返回首页):";
    while(1)
    {

        cin>>name1;
        int m=0;
        we =0 ;
        inf.open("登录注册.txt");
        while(inf>>stu[we].name)
        {
            inf>>stu[we].key;
            we++;
        }
        for(int i=0; i<we; i++)
        {
            if(name1==stu[i].name)
            {
                yanzheng=i;
                m=1;
                break;
            }
        }
        if(m==0)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"无该学号，请重新输入:";
            count1++;
        }
        if(count1==3) shouye();
        if(m==1)
        {
            sum++;
            break;
        }
    }
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入密码(3次错误自动返回首页):";
    while(1)
    {
        cin>>key;
        int n=0;
        if(key==stu[yanzheng].key) n=1;
        if(key!=stu[yanzheng].key)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"密码不正确，请重新输入:";
            count2++;
            if(count2==3) shouye();
        }
        if(n==1)
        {
            sum++;
            break;
        }
    }
    color(16);
    cout<<"                          ";
    color(14);
    cout<<"请输入新密码(长度在6和11之间):";
    while(1)
    {
        cin>>key1;
        int z=0;
        for(int i=0; i<(int)key1.length(); i++)
        {
            if(key1[i]<'0'||key1[i]>'z')
            {
                z=1;
                break;
            }
        }
        if(z==1)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"输入不合法，请重新输入:";
        }
        else if((int)key1.length()>=11||(int)key1.length()<6)
        {
            color(16);
            cout<<"                           ";
            color(14);
            cout<<"输入长度不合法，请重新输入:";
        }
        else
        {
            sum++;
            break;
        }
    }
    if(sum==3)
    {
        color(16);
        cout<<endl<<"                                  ";
        color(14);
        cout<<"☆☆修改成功☆☆"<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
        for(int i=0; i<40; i++)
        {
            Sleep(20);
            cout<<"※";
        }
        stu[yanzheng].key=key1;
        ofstream out("登录注册.txt");
        for(int i=0; i<we; i++)
        {
            out<<stu[i].name;
            out<<"\n";
            out<<stu[i].key;
            out<<"\n";
        }
        out.close();
    }
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"1：用户登录";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";

    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"2：返回首页";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                 ";
    color(14);
    cout<<"请选择下一步操作:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        {
            color(16);
            denglu();
        }
        if(xuanze=="2")
        {
            color(16);
            shouye();
        }
    }
}
void zhuxiao()
{
    string xuanze;
    string name1,key,key1;
    int sum=0;
    color(16);
    system("cls");
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"用户注销";
    color(16);
    cout<<"                                  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入学号(3次错误自动返回首页):";
    while(1)
    {
        cin>>name1;
        int m=0;
        we =0 ;
        inf.open("登录注册.txt");
        while(inf>>stu[we].name)
        {
            inf>>stu[we].key;
            we++;
        }
        inf.close();
        for(int i=0; i<we; i++)
        {
            if(name1==stu[i].name)
            {
                yanzheng=i;
                m=1;
                break;
            }
        }
        if(m==0)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"无该学号，请重新输入:";
            count1++;
        }
        if(count1==3) {count1=count2=0;shouye();}
        if(m==1)
        {
            sum++;
            break;
        }
    }
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入密码(3次错误自动返回首页):";
    while(1)
    {
        cin>>key;
        int n=0;
        if(key==stu[yanzheng].key) n=1;
        if(key!=stu[yanzheng].key)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"密码不正确，请重新输入:";
            count2++;
            if(count2==3) {count1=count2=0;shouye();}
        }
        if(n==1)
        {
            sum++;
            break;
        }
    }
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"是否确认注销(1：确认2：取消):";
       while(1)
    {
        string k;
        cin>>k;
        if(k!="1"&&k!="2")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(k=="1") {sum++;break;}
        if(k=="2") shouye();
    }
    if(sum==3)
    {
        color(16);
        cout<<endl<<"                                  ";
        color(14);
        cout<<"☆☆注销成功☆☆"<<endl<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
        for(int i=0; i<40; i++)
        {
            Sleep(20);
            cout<<"※";
        }
        ofstream out("登录注册.txt");
        for(int i=0; i<we; i++)
        {
            if(i==yanzheng) i++;
            out<<stu[i].name;
            out<<"\n";
            out<<stu[i].key;
            out<<"\n";
        }
        out.close();
    }
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"1：用户登录";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";

    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"2：返回首页";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                 ";
    color(14);
    cout<<"请选择下一步操作:";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        {
            color(16);
            denglu();
        }
        if(xuanze=="2")
        {
            color(16);
            shouye();
        }
    }
}
void denglu()
{
    string name1,key;
    color(16);
    system("cls");
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"用户登录";
    color(16);
    cout<<"                                  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入学号(3次错误自动返回首页):";
    while(1)
    {
        cin>>name1;
        int m=0;
        we = 0;
        inf.open("登录注册.txt");
        while(inf>>stu[we].name)
        {
            inf>>stu[we].key;
            we++;
        }
        inf.close();
        for(int i=0; i<we; i++)
        {
            if(name1==stu[i].name)
            {
                yanzheng=i;
                m=1;
                break;
            }
        }
        if(m==1) break;
        if(m==0)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"无该学号，请重新输入:";
            count1++;
        }
        if(count1==3) {count1=0;
    count2=0;shouye();}
    }
    color(16);
    cout<<"                       ";
    color(14);
    cout<<"请输入密码(3次错误自动返回首页):";
    while(1)
    {
        cin>>key;
        if(key!=stu[yanzheng].key)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"密码不正确，请重新输入:";
            count2++;
            if(count2==3) {count1=0;
    count2=0;shouye();}
        }
        else
        {
            color(16);
            cout<<endl<<"                                  ";
            color(14);
            cout<<"☆☆登录成功☆☆"<<endl<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
            for(int i=0; i<40; i++)
            {
                Sleep(20);
                cout<<"※";
            }
            cishouye();
        }
    }
}
void cishouye()
{
    color(16);
    system("cls");
    ofstream outfile;
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"用户选择";
    color(16);
    cout<<"                                  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆   1：程序主页   ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 2：修改路径信息 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 3：录入景点信息 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 4：  返回首页   ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                   ";
    color(14);
    cout<<"请输入选择：";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2"&&xuanze!="3"&&xuanze!="4")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        /*if(xuanze=="1")
        {
            char cc[30];
            sprintf(cc,"%s","../main2/bin/Debug/ererchou.exe meta");
            system(cc);
            //system("");
        }*/
        if(xuanze=="2")
        hongbo1();
        if(xuanze=="3")
        {
        graph gh= initgraph();
        writeXml(gh);
        cout<<"初始化成功！"<<endl;
        }

        if(xuanze=="4")
            shouye();
    }
}
void hongbo1()
{
    color(16);
    system("cls");
    ofstream outfile;
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                ";
    color(14);
    cout<<"修改路径信息";
    color(16);
    cout<<"                                ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 1：修改节点信息 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 2：录入公交路线 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 3：输出地图信息 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 4：删除节点信息 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 5：增加节点信息 ☆"<<endl;
    color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆ 6： 返回上一层  ☆"<<endl;
     color(16);
    cout<<"                             ";
    color(14);
    cout<<"☆                 ☆"<<endl;
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                   ";
    color(14);
    cout<<"请输入选择：";
    while(1)
    {
        string xuanze;
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2"&&xuanze!="3"&&xuanze!="4"&&xuanze!="5"&&xuanze!="6")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        change_node();
        if(xuanze=="2")
        update_bus_road();
        if(xuanze=="3")
         print_graph();
        if(xuanze=="4")
         delete_node();
        if(xuanze=="5")
          add_node();
        if(xuanze=="6")
            cishouye();
    }
}
void zhuce()
{
    string name,key,key2;
    string xuanze;
    int sum=0;
    color(16);
    system("cls");
    ofstream outfile;
    ifstream inf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"用户注册";
    color(16);
    cout<<"                                  ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※";
    color(16);
    cout<<"                                                                            ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                 ";
    color(14);
    cout<<"请输入学号:";
    while(1)
    {
        cin>>name;
        int n=0,m=0;
        we=0;
        for(int i=0; i<(int)name.length(); i++)
        {
            if(name[i]<'0'||name[i]>'9')
            {
                n=1;
                break;
            }
        }
        inf.open("登录注册.txt");
        while(inf>>stu[we].name)
        {
            inf>>stu[we].key;
            we++;
        }
        inf.close();
        for(int i=0; i<we; i++)
        {
            if(name==stu[i].name)
                m=1;
        }
         if(m==1)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"已有学号，请重新输入:";
        }
        if(m==0)
        {
            if(n==1)
            {
                color(16);
                cout<<"                             ";
                color(14);
                cout<<"输入不合法，请重新输入:";
            }
            else if(n==0&&(int)name.length()!=11)
            {
                color(16);
                cout<<"                           ";
                color(14);
                cout<<"输入长度不合法，请重新输入:";
            }
            else
            {
                sum++;
                break;
            }
        }
    }
    color(16);
    cout<<"                          ";
    color(14);
    cout<<"请输入密码(长度在6和11之间):";
    while(1)
    {
        cin>>key;
        int n=0;
        for(int i=0; i<(int)key.length(); i++)
        {
            if(key[i]<'0'||key[i]>'z')
            {
                n=1;
                break;
            }
        }
        if(n==1)
        {
            color(16);
            cout<<"                             ";
            color(14);
            cout<<"输入不合法，请重新输入:";
        }
        else if(n==0&&((int)key.length()>=11||(int)key.length()<6))
        {
            color(16);
            cout<<"                           ";
            color(14);
            cout<<"输入长度不合法，请重新输入:";
        }
        else
        {
            sum++;
            break;
        }
    }
    color(16);
    cout<<"                                 ";
    color(14);
    cout<<"请再次输入密码:";
    while(1)
    {
        cin>>key2;
        if(key!=key2)
        {
            color(16);
            cout<<"                           ";
            color(14);
            cout<<"密码不一致，请重新输入:";
        }
        else
        {
            sum++;
            break;
        }
    }
    if(sum==3)
    {
        outfile.open("登录注册.txt",ios::app);//(输入流) （变量）（输出文件流）
        if(!outfile) cout<<"error"<<endl;
        outfile<<name;
        outfile<<"\r\n";
        outfile<<key;
        outfile<<"\r\n";
        outfile.close();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<endl;
    for(int i=0; i<40; i++)
    {
        Sleep(20);
        cout<<"※";
    }
    color(16);
    cout<<endl<<"                                  ";
    color(14);
    cout<<"☆☆注册成功☆☆"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    for(int i=0; i<40; i++)
    {
        Sleep(20);
        cout<<"※";
    }
    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"1：用户登录";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";

    cout<<"※";
    color(16);
    cout<<"                                  ";
    color(14);
    cout<<"2：返回首页";
    color(16);
    cout<<"                               ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"※";
    cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
    color(16);
    cout<<"                                 ";
    color(14);
    cout<<"请选择下一步操作:";
    while(1)
    {
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        {
            color(16);
            denglu();
        }
        if(xuanze=="2")
        {
            color(16);
            shouye();
        }
    }
}
void shouye()
{
    color(16);
    system("cls");
    string xuanze;
    color(13);
    cout<<"                                   ☆"<<endl;
    color(13);
    cout<<"                                 ☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                             ☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                         ☆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                     ☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                   ☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋";
    color(14);
    cout<<"导游图";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"              ◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆━";
    color(11);
    cout<<"┋┋";
    color(14);
    cout<<"新生选择界面";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"━◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"                ◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"╔════════╗";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"                  ◆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"║";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"  1：新生注册   ";
    color(11);
    cout<<"║";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"                    ☆◆◆";
    color(11);
    cout<<"║                ║";
    color(13);
    cout<<"◆◆☆"<<endl;
    color(13);
    cout<<"                      ☆◆";
    color(11);
    cout<<"║";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"  2：新生登录   ";
    color(11);
    cout<<"║";
    color(13);
    cout<<"◆☆"<<endl;
    color(13);
    cout<<"                        ☆";
    color(11);
    cout<<"║                ║";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                      ☆◆";
    color(11);
    cout<<"║";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"  3：修改密码   ";
    color(11);
    cout<<"║";
    color(13);
    cout<<"◆☆"<<endl;
    color(13);
    cout<<"                    ☆◆◆";
    color(11);
    cout<<"║                ║";
    color(13);
    cout<<"◆◆☆"<<endl;
    color(13);
    cout<<"                  ◆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"║";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15 | 8 | 128 | 64);
    cout<<"  4：信息注销   ";
    color(11);
    cout<<"║";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"                ◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"╚════════╝";
    color(13);
    cout<<"◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"              ◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆━";
    color(11);
    cout<<"┋┋";
    color(11);
    cout<<"☆☆☆☆☆☆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"━◆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"◆"<<endl;
    color(13);
    cout<<"                   ☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋";
    color(11);
    cout<<"☆☆☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                     ☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                         ☆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"☆━";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"━☆";
    color(11);
    cout<<"┋┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                             ☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                                 ☆";
    color(11);
    cout<<"┋";
    color(13);
    cout<<"☆"<<endl;
    color(13);
    cout<<"                                   ☆"<<endl;
    cout<<"                             ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
    cout<<"输入您的选择:";
    while(1)
    {
        cin>>xuanze;
        if(xuanze!="1"&&xuanze!="2"&&xuanze!="3"&&xuanze!="4")
        {
            color(16);
            cout<<"                             ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            cout<<"输入不合法请重新输入：";
        }
        if(xuanze=="1")
        zhuce();
        if(xuanze=="2")
        denglu();
        if(xuanze=="3")
        xiugai();
        if(xuanze=="4")
        zhuxiao();
    }
}
int main()
{
    shouye();
    return 0;
}
