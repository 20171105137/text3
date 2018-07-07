/*

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc,const char * argv[])
{
    
    //csv文件写入部分
    ofstream oFile;  //定义文件输出流
    
    oFile.open("sdata.csv", ios::out | ios::trunc);    //打开要输出的文件，文件不存在会自动新建一个
    //写入数据
    // 写文件
    
    oFile << "name" << ',' << "age" << ',' << "hobby" << endl;
    oFile << "Mike" << ',' << 18 << ',' << "paiting" << endl;
    oFile << "Tom" << ',' << 25 << ',' << "football" << endl;
    oFile << "Jack" << ',' << 21 << ',' << "music" << endl;
    oFile.close();

    
  /*
    //csv文件读取部分
    
    string value;//临时字符串/Users/s20171105137/Desktop/text3/text3/studentdata.csv
    ifstream iFile("三维坐标.csv");//打开要读入的文件
    //循环行读取
    while (iFile.good())
    {
        getline(iFile,value);
        //getline(iFile,value,','); //.csv文件用","作为分隔符
        cout<<value<<endl;
    }

   
    // 读文件
    ifstream inFile("studentdata.csv", ios::in);
    string lineStr;
    vector<vector<string>> strArray;
    while (getline(inFile, lineStr))
    {
        // 打印整行字符串
        cout << lineStr << endl;
        // 存成二维表结构
        stringstream ss(lineStr);
        string str;
        vector<string> lineArray;
        // 按照逗号分隔
        while (getline(ss, str, ','))
            lineArray.push_back(str);
        strArray.push_back(lineArray);
    }
    
    getchar(); b8
    return 0;
}

*/




#include <cstdlib>
#include<stdio.h>

struct student
{
    
    int numbers;
    char name[10];
    char sex[10];
    int dateofbirt;
    char class1[15];
    char phoneNo[15];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;
};
int main()
{
    struct student s[100];
    FILE *fp1,*fp2;
    int i=0,j;
    
    fp1 =fopen("student1.csv","r");
    if(fp1==NULL)
    {
        printf("error");
        exit(-1);
    }
    else
    {
        fscanf(fp1,"%*[^\n]%*c");
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%d,%d,%d,%d",
                   &s[i].numbers,&s[i].name,&s[i].sex,&s[i].dateofbirt,&s[i].class1,
                   &s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            i++;
        }
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d\n",s[i].numbers,
                   s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo,
                   s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);
        }
        
        fclose(fp1);
    }
    j=i;
    int max[100],min[100];
    
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }
    j=i;
    
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;
    }
    j=i;
    i=0;
    
    fp2=fopen("student2.csv","w");
    fprintf(fp2,"numbers,name,sex,dateofbirth,class,phoneNo,judge1,judge2,judge3,judge4,judge5,score\n");
    
    while(i<j)
    {
        fprintf(fp2,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",s[i].numbers,s[i].name,s[i].sex,s[i].dateofbirt,s[i].class1,s[i].phoneNo,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].score);
        i++;
    }
    fclose(fp2);
    
    return 0; 
}


