#include<iostream>
using namespace std;

int Boyer(string &a,int asize,string &b)
{
	//finding size of alphabets excluding the repitition
	int size=0;
	for(int i=0;i<asize;i++)
	{
		int condition=0;
		int j=i-1;
		for(j;j>=0;j--)
		{
			if(a[i]==a[j])
			{
				condition++;
		    }
		}
		if(condition==0)
		{
			size++;
		}
	}
	
	//making an array of alphabets without repition
	int k=0;
	char temp[size];
	for(int i=0;i<asize;i++)
	{
		int condition=0;
		int j=i-1;
		for(j;j>=0;j--)
		{
			if(a[i]==a[j])
			{
				condition++;
		    }
		}
		if(condition==0)
		{
			temp[k]=a[i];
			k++;
		}
	}
	
	//Bad Match Table and giving values
	int value[size];
	for(int i=0;i<asize;i++)
	{
		int val=asize-i;
		if(i==asize-1)            //as the last alphabet holds value equal to length
		{
			val=asize;
		}
		
		for(int j=0;j<size;j++)
		{
			if(a[i]==temp[j])
			{
				value[j]=val;
			}
		}
	}
	
	//values given, implementation
	k=0;
	for(int i=0;;i++)
	{
		if(a[asize-1]==b[asize+k-1])
		{
			int c=0;
			int condition1=0;
			for(int j=asize-1;j>=0 && condition1==0 ;j--)
			{
				if(a[j]!=b[asize+k-c-1] && condition1==0)
				{
					k+=asize;
					condition1++;
				}
				c++;
			}
			if(condition1==0)
			{
				return k;
			}
		}
		else
		{
			int condition2=0;
			for(int i=0;i<size;i++)
			{
				if(b[asize+k]==temp[i])
				{
					k+=value[i];
					condition2++;
				}
			}
			if(condition2==0)
			{
				k+=asize;
			}
			
		}
	}
}

int main()
{
	cout<<"The code will give the index of position of the sequence in a paragraph"<<endl;
	string a="abc";
	string b="abababc";
	int position=Boyer(a,3,b);
	cout<<"So, position is "<<position<<endl;
	return 0;
}
