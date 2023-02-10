#include<bits/stdc++.h>
#include<direct.h>
#include<io.h>
using namespace std;
string Reading(string str,char road[10005],int i,int len)
{
	if(i>=str.size())return "?";
	road[len++]='/';
	road[len++]=str[i];
	road[len++]=str[i+1];
	//cout<<road<<" "<<"已进入递归"<<endl;
	if(_access(road,0)==-1)return "?";
	//cout<<road<<" "<<"存在"<<endl;
	string temp2=Reading(str,road,i+2,len);
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
	char ch[10005]="数据库";
	string temp=Reading(str,ch,0,6);
	string this_str;
	int flag=0;//0non 1str
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
	}
	return sum;
    return 0;
}

