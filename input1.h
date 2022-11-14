
#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include<vector>
#include<dirent.h>
using namespace std;


vector<string> cush(string PATH)
{
    struct dirent *ptr;    
    DIR *dir;
    dir=opendir(PATH.c_str()); 
    vector<string> files;
    cout << "文件列表: "<< endl;
    while((ptr=readdir(dir))!=NULL)
    {
 
        if(ptr->d_name[0] == '.')
            continue;
        files.push_back(ptr->d_name);
    }
    
    for (int i = 0; i < files.size(); ++i)
    {
        cout << files[i] << endl;
    }
 
    closedir(dir);
    return files;
}