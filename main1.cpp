#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<dirent.h>
#include"input1.h"
using namespace std;




char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m'
            ,'o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F'
            ,'G','H','I','J','K','L','M','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void stdin2input(string path)
{
    string aa = "./input/"+path+"/stdin_format.txt";
    ifstream in_file(aa,ios::in);
    if(!in_file)exit(-1);


    ofstream out_file("./input.txt",ios::trunc);
    if(!out_file)exit(-1);


    string in;
    while(in_file >> in)
    {

        int length = in.length();
        if(in[0]=='i')
        {
            int flag1,flag2,flag3;
            for(int i=0;i<length;i++)
            {
                if(in[i]=='(')
                {
                    flag1=i;
                }
                if(in[i]==',')flag2=i;
                if(in[i]==')')flag3=i;
            }
            string x1 = in.substr(flag1+1,flag2-flag1-1);
            string x2 = in.substr(flag2+1,flag3-flag2-1);
            int x11= atoi(x1.c_str());
            int x22= atoi(x2.c_str());
            
            int count = 1;
            for(int i=0;i<count;i++)
            {
                int ans = x11 + rand() % (x22-x11+1);
                out_file<<ans<<endl;
            }
        }
        else if(in[0]=='c')
        {
            int count = 1;
            for(int i=0;i<count;i++)
            {
                int ans = rand() % 51;
                out_file<<arr[ans]<<endl;
            }
        }
        else if(in[0]=='s')
        {
            int flag1,flag2,flag3;
            for(int i=0;i<length;i++)
            {
                if(in[i]=='(')
                {
                    flag1=i;
                }
                if(in[i]==',')flag2=i;
                if(in[i]==')')flag3=i;
            }
            string x1 = in.substr(flag1+1,flag2-flag1-1);
            string x2 = in.substr(flag2+1,flag3-flag2-1);
            int x11= atoi(x1.c_str());
            int x22= atoi(x2.c_str());
            int count = 1;
            for(int i=0;i<count;i++)
            {
                int stringlength = x11 + rand() % (x22-x11+1);
                string ans;
                for(int j=0;j<stringlength;j++)
                {
                    int ces = rand()%51;
                    ans+=arr[ces];
                }
                out_file<<ans<<endl;
            }
        }
    }
    return;
}









int main()
{

    ofstream ofs;
    ofs.open("output/equal.csv",ios::trunc);
    ofstream ofs1;
    ofs1.open("output/equal.csv",ios::trunc);
    vector<string>Onestepfiles = cush("./input");
    int Onestepfilescount = Onestepfiles.size();
    for(int i=0;i<Onestepfilescount;i++)
    {
        string filename = "./input/"+Onestepfiles[i];
        vector<string>Twostepfiles = cush(filename);
        int Twostepfilescount = Twostepfiles.size();
        for(int j=0;j<Twostepfilescount;j++)
        {

            string filename1 = Twostepfiles[j];
            if(filename1=="stdin_format.txt")continue;
            string cmd1 = "g++ ./input/"+Onestepfiles[i]+"/"+filename1;
            cout<<cmd1;
            int lengthoffilename1=filename1.size();       
            for(int k=j+1;k<Twostepfilescount;k++)
            {
                string filename2 = Twostepfiles[k];
                if(filename2=="stdin_format.txt")continue;
                string cmd2 = "g++ ./input/"+Onestepfiles[i]+"/"+filename2;
                int flag=1;
                for(int h=0;h<10;h++)
                {
                    stdin2input(Onestepfiles[i]);

                    system(cmd1.c_str());
                    system("./a.out <input.txt >ouput1.txt"); 

                    system(cmd2.c_str());
                    system("./a.out <input.txt >ouput2.txt");
                    ifstream out_file1("./ouput1.txt");
                    if(!out_file1)exit(-1);
                    ifstream out_file2("./ouput2.txt");
                    if(!out_file2)exit(-1);
                    char out1,out2;
                    while((out1=out_file1.get())!=EOF||(out2=out_file2.get())!=EOF)
                    {
                        if (out1!=out2)
                        {
                            flag=0;
                            break;
                        }
                    }
                    if(flag==0)break;
                }
                cout<<"flag="<<flag;
                if(flag==1)
                {
                    //ofstream ofs;
                    //ofs.open("output/equal.csv",ios::trunc);
                    string outa = "input/"+Onestepfiles[i]+"/"+Twostepfiles[j]+" "+"input/"+Onestepfiles[i]+"/"+Twostepfiles[k];
                    ofs<<outa<<endl;
                }
                else
                {
                    //ofstream ofs;
                    //ofs.open("output/inequal.csv",ios::trunc);
                    string outa = "input/"+Onestepfiles[i]+"/"+Twostepfiles[j]+" "+"input/"+Onestepfiles[i]+"/"+Twostepfiles[k];
                    ofs1<<outa<<endl;
                }
                
            }
        }
    }
    return 0;
}
