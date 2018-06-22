#include<bits/stdc++.h>
using namespace std;
/*---------------------------------------------------*/
/*共享单车调度*/
const int maxn  = 999;
typedef long long ll;

struct Bike_info
{
    int n,m;
    int num_n[maxn];
    int num_m[maxn];
    int In_id[maxn];
    int Out_id[maxn];

} info;
class BIKE
{
public:
    int  n;
    int num[maxn];//每个点现存的自行车数目
    int num_pre[maxn];//每个点之前的自行车数目
    int num_change[maxn];//每个点
    double num_by[maxn];//每个点的流量值
    int num_shift[maxn];//每个点要移动的车辆数
    int total_num;//总共的自行车数目
    int date;//模拟天数
    double Dx_pre[maxn];//记录前一次的方差
    int state;//修改参数时辅助的状态码
    int Fa,Fb;
} Bike;

//共享单车记录
void bike_memo(int s,int e,int path[],int path_size,BIKE Bike)
{
    Bike.num[s]++;
    Bike.num[e]++;
    double One = 5;
    for(int i=0; i<path_size/2; i++)
    {
        if(One>=0)
        {
            Bike.num_by[path[i]]+=One;
            One = One-0.5;
        }
        else break;
    }
    for(int i=path_size-1; i>=path_size/2; i--)
    {
        if(One>=0)
        {
            Bike.num_by[path[i]]+=One;
            One = One-0.5;
        }
        else break;
    }
}
//int Bike_num[maxn],Bike_num_change[maxn];
double cal_Dx(int Bike_num[],int Bike_num_change[])
{
    double rel=0;
    for(int i=0; i<Bike.n; i++)
    {
        double temp = 0;
        temp = (Bike_num_change[i]-Bike_num[i])*(Bike_num_change[i]-Bike_num[i]);
        rel += temp;
    }
    rel = rel/(Bike.n*1.0);
    return rel;
}
BIKE Bike_shift_plan(BIKE Bike)
{
    double Ratio1 = Bike.Fa/(Bike.Fa+Bike.Fb);
    double Ratio2 = 1-Ratio1;
    double Ratio_deno=0;
    for(int i=0; i<Bike.n; i++)
    {
       // printf("%lf %d\n",Bike.num_by[i],Bike.num[i]);
        Ratio_deno += (Ratio2*Bike.num_by[i]+Ratio1*Bike.num[i]);
    }
    cout<<Ratio_deno<<endl;
    for(int i=0; i<Bike.n; i++)
    {
        double temp;
        temp =  (Ratio2*Bike.num_by[i]+Ratio1*Bike.num[i])/Ratio_deno*Bike.total_num;
        Bike.num_pre[i] = Bike.num[i];
        Bike.num_change[i] = temp;
        Bike.num_shift[i] = temp - Bike.num[i];
        Bike.num[i] = temp;
    }
    //修改参数
    Bike.Dx_pre[Bike.date++] = cal_Dx(Bike.num,Bike.num_change);
    if(Bike.state!=0)
    {
        if(Bike.date>=2&&Bike.Dx_pre[Bike.date-1]>Bike.Dx_pre[Bike.date-2])
        {
            int x = Bike.state;
            switch(x)
            {
            case 1:
                Bike.Fa--;
                break;
            case 2:
                Bike.Fb--;
                break;
            case 3:
                Bike.Fa++;
                break;
            case 4:
                Bike.Fb++;
                break;
            case 5:
                Bike.Fa--,Bike.Fb--;
                break;
            case 6:
                Bike.Fa--,Bike.Fb++;
                break;
            case 7:
                Bike.Fa++,Bike.Fb--;
                break;
            case 8:
                Bike.Fa++,Bike.Fb++;
                break;
            default:
                break;
            }

        }
        else
        {
            Bike.state = 0;
        }
    }
    else
    {
        if(Bike.date>=2&&Bike.Dx_pre[Bike.date-1]>Bike.Dx_pre[Bike.date-2])
        {
            srand(time(NULL));
            int x = rand()%8+1;
            switch(x)
            {
            case 1:
                Bike.Fa++;
                break;
            case 2:
                Bike.Fb++;
                break;
            case 3:
                Bike.Fa--;
                break;
            case 4:
                Bike.Fb--;
                break;
            case 5:
                Bike.Fa++,Bike.Fb++;
                break;
            case 6:
                Bike.Fa++,Bike.Fb--;
                break;
            case 7:
                Bike.Fa--,Bike.Fb++;
                break;
            case 8:
                Bike.Fa--,Bike.Fb--;
                break;
            default:
                break;
            }
            Bike.state = x;
        }
        else
        {
            Bike.state = 0;
        }
    }
    return Bike;
}




/*---------------------------------------------------*/
int Read_data()
{
    ifstream infile;
    infile.open("Bike_data.txt");//打开数据文件
    if(!infile)
    {
        cerr<<"error: unable to open input file: "
            << infile << endl;
        return 1;
    }
    infile>>Bike.n;
    infile>>Bike.total_num;
    infile>>Bike.date;
    infile>>Bike.state;
    infile>>Bike.Fa;
    infile>>Bike.Fb;
    int n = Bike.n;
    for(int i=0; i<n; i++)
        infile>>Bike.num[i];
    for(int i=0; i<n; i++)
        infile>>Bike.num_pre[i];
    for(int i=0; i<n; i++)
        infile>>Bike.num_by[i];
    for(int i=0; i<n; i++)
        infile>>Bike.Dx_pre[i];
    infile.close();
    return 1;
}
int main()
{
    Read_data();

    int road[]={1,2,3,4,5};
    bike_memo(1,5,road,5,Bike);
    Bike = Bike_shift_plan(Bike);

    for(int i=0;i<52;i++)
    {
        printf("%d ",Bike.num_shift[i]);
    }
    return 0;
}
