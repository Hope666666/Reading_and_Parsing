#include<bits/stdc++.h>
#include<direct.h>
#include<io.h>
using namespace std;
string Reading(string str,char road[10005],int i,int len)
{
	if(i>=str.size())return "?";
	road[len++]='/';
	road[len++]=str[i];
	//cout<<road<<" "<<"已进入递归"<<endl;
	if(_access(road,0)==-1)return "?";
	//cout<<road<<" "<<"存在"<<endl;
	string temp2=Reading(str,road,i+1,len);
	if(temp2!="?")return temp2;
	road[len++]='/';
	road[len++]='t';
	road[len++]='e';
	road[len++]='x';
	road[len++]='t';
	road[len++]='.';
	road[len++]='t';
	road[len++]='x';
	road[len++]='t';
	//cout<<road<<" "<<"正在寻找text"<<endl;
	ifstream In(road);
	if(!In)return "?";
	getline(In,temp2);
	//cout<<road<<" "<<"text存在"<<endl;
	return temp2;
}
string Parsing(string str)
{
	string sum="";
	char ch[10005]="database";
	string temp=Reading(str,ch,0,8);
	string this_str;
	int flag=0;//0non 1str 2this
	string temp2="";
	for(int i=0;i<temp.size();i++)
	{
		if(flag==0)
		{
			this_str+=temp[i];
			if(this_str=="str")
			{
				flag=1;
				this_str="";
			}
			if(this_str=="this")
			{
				flag=2;
				this_str="";
			}
			continue;
		}
		if(flag==1)
		{
			if(temp[i]=='(')continue;
			if(temp[i]==')')
			{
				sum+=this_str;
				this_str="";
				flag=0; 
				continue;
			}
			this_str+=temp[i];
			continue;
		}
		if(flag==2)
		{
			if(temp[i]=='(')continue;
			if(temp[i]==',')
			{
				temp2=this_str;
				this_str="";
				continue;
			}
			if(temp[i]==')')
			{
				int num1=0;
				int num2=0;
				for(int i=0;i<temp2.size();i++)num1+=pow(temp2[i]-'0',temp2.size()-i);
				for(int i=0;i<this_str.size();i++)num2+=pow(this_str[i]-'0',this_str.size()-i);
				for(int i=num1-1;i<num2;i++)sum+=str[i];
				this_str="";
				temp2="";
				flag=0;
				continue;
			}
			this_str+=temp[i];
		}
	}
	return sum;
    return 0;
}

