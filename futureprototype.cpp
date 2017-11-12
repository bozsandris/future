#include <iostream>
#include "Eigen/Eigen/Dense"
using namespace std;

int main()
{
    typedef Eigen::Matrix<float,13,12> FloatMatrix1;
    typedef Eigen::Matrix<int,12,12> IntesMatrix;
     Eigen::VectorXf b(12);
    FloatMatrix1 a(13,12);
    IntesMatrix c(12,12);
    FloatMatrix1 d(13,12);
    string foglalkozasok[12] = {"Hallgato'","Tanulo'","Dia'k","Hivatalnok","Mezo''gazdasa'gi",
    "Kereskedo''","E'rtelmise'gi","Nyugdi'jas","Katona","Ipari","Született","Halott"};
    c <<
     0,0,0,1,1,1,1,1,1,1,0,1,
     1,0,1,1,1,1,1,1,1,1,0,1,
     1,0,0,1,1,1,1,1,1,1,0,1,
     0,0,0,0,1,1,1,1,1,1,0,1,
     0,0,0,0,0,1,0,1,0,1,0,1,
     0,0,0,0,1,0,0,1,0,1,0,1,
     0,0,0,1,0,0,0,1,1,0,0,1,
     0,0,0,0,0,0,0,0,0,0,0,1,
     0,0,0,0,0,0,0,1,0,0,0,1,
     0,0,0,0,1,1,0,1,0,0,0,1,
     1,1,1,1,1,1,1,1,1,1,0,1,
     0,0,0,0,0,0,0,0,0,0,0,0;
    int lelekszam[12] = {20000,15000,15000,8000,40000,15000,10000,30000,12000,40000,10,10};
    int sum=0;
    for(int i=0;i<12;i++)
    {
        sum+=lelekszam[i];
    }
    cout<<sum<<endl;
    cout<<"Valse'gek:"<<endl;
    int szamlalo[12]={0,0,0,0,0,0,0,0,0,0,0,0};

    for(int k=0;k<=12;k++)
    {
           for(int i=0;i<12;i++)
            {
                if(k==0) a(k,i)=lelekszam[i];
                else a(k,i)=c(k-1,i);
                if(k>0 && c(k-1,i)==1) szamlalo[k-1]++;
            }
    }
    d=a;
    float valseg;
    for(int k=1;k<=12;k++)
    {
        valseg=(float)1/szamlalo[k-1];
           for(int i=0;i<12;i++)
            {
               if(d(k,i)==1) d(k,i)=valseg;
            }
    }
    cout<<"Gra'fos ma'trix:"<<endl<<a<<endl;
    cout<<"Valse'ges ma'trix"<<endl<<d<<endl;
    cout<<endl<<"vektor = vektor * matrix:"<<endl;
    for(int i=0;i<12;i++)
    {
        b(i)=(float)lelekszam[i]/sum;
    }
    float counter;
    for(int z=0;z<300;z++)
    {
        counter=0;
        cout<<z+1<<". iteration: ";
        for(int i=0;i<12;i++)
            {
                for(int k=1;k<=12;k++)
            {
                if(d(k,i)!=0) b(i)=b(i)*d(k,i);
            }
        }
        for(int i=0;i<11;i++)
            {
                cout<<b(i)<<" ";
                counter+=b(i);

            }
            cout<<counter<<endl;
    }
    return 0;
}
