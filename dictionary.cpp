#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class dictionary
{
private:
  char meaning[300];
  char pron[100];
public:
    char word[100];
    void accept()
    {
        cout<<endl<<"enter word";
        cin>>word;
        cout<<endl<<"enter meaning";
        cin>>meaning;
        cout<<endl<<"pronounce";
        cin>>pron;
    }
    void display()
    {
        cout<<endl<<"word:"<<word;
        cout<<endl<<"meaning:"<<meaning;
        cout<<endl<<"pronounced as:"<<pron;
    }
    dictionary obj;
    //class ends here
    void addrecord()
    {
        obj.accept();
        fstream wr;
        wr.open("D:\\words\\dic.txt",ios::app);
        wr.write((char *)&obj,sizeof(obj));
        cout<<endl<<"object written successfully";
    }
    void viewrecord()
    {
        fstream rd("D:\\words\\dic.txt",ios::in);
        rd.seekg(0,ios::end);
        int size=rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=size;i++)
        {
            rd.read((char *)&obj,sizeof(obj));
            obj.display();
        }
    }
};
