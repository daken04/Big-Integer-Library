#include<iostream>
#include<string>
using namespace std;

string str_add(string s1,string s2)
{
    if(s1=="0" && s2=="0")
    {
        return "0";
    }
    
    int n = s1.length();
    int m = s2.length();
    
    string s3;
    
    if(m>n)
    {
        string temp(m+1,'0');
        s3 = temp;
    }
    else
    {
        string temp(n+1,'0');
        s3 = temp;
    }
    
    int i=n-1;
    int j=m-1;
    int z =0;
    
    while(i>=0 && j>=0)
    {
        int add = (s1[i]-'0')+(s2[j]-'0')+(s3[z]-'0');
        s3[z] = (add%10)+'0';
        s3[z+1] = (add/10)+'0';
        i--;
        j--;
        z++;
    }
    
    while(i>=0)
    {
        int add = (s1[i]-'0')+(s3[z]-'0');
        s3[z] = (add%10)+'0';
        s3[z+1] = (add/10)+'0';
        i--;
        z++;
    }
    
    while(j>=0)
    {
        int add = (s2[j]-'0')+(s3[z]-'0');
        s3[z] = (add%10)+'0';
        s3[z+1] = (add/10)+'0';
        j--;
        z++;
    }
    
    int size = s3.length();
    
    for(int k=0;k<size/2;k++)
    {
        char t = s3[k];
        s3[k] = s3[size-1-k];
        s3[size-1-k]= t;
    }
    
    j=0;
    
    while(s3[j]=='0')
    {
        j++;
    }
    
    s3 = s3.substr(j);
    
    return s3;
}

string str_sub(string s1,string s2)
{
    if(s1==s2)
    {
        return "0";
    }
    
    int n=s1.length();
    int m = s2.length();
    
    string s3;
    
    int i=n-1;
    int j=m-1;
    
    while(i>=0 && j>=0)
    {
        int sub;
        if(s1[i]<s2[j])
        {
            int z = i-1;
            while(s1[z]=='0')
            {
                s1[z]='9';
                z--;
            }
            
            s1[z]=(((s1[z]-'0')-1)+'0');
            
            sub = 10+(s1[i]-'0')-(s2[j]-'0');
        }
        else
        {
            sub = (s1[i]-'0')-(s2[j]-'0');
        }
        
        s3.push_back(sub+'0');
        i--;
        j--;
    }
    
    while(i>=0)
    {
        s3.push_back(s1[i]);
        i--;
    }
    
    while(j>=0)
    {
        s3.push_back(s2[j]);
        j--;
    }
    
    int size = s3.length();
    
    for(int k=0;k<size/2;k++)
    {
        char t = s3[k];
        s3[k] = s3[size-1-k];
        s3[size-1-k] = t;
    }
    
    j=0;
    
    while(s3[j]=='0')
    {
        j++;
    }
    
    s3 = s3.substr(j);
    
    return s3;
}

string str_mul(string s1,string s2)
{
    if(s1=="0" || s2=="0")
    {
        return "0";
    }
    
    int n = s1.length();
    int m = s2.length();
    
    if(m>n)
    {
        return str_mul(s2,s1);
    }
    
    string s3(m+n,'0');
    
    for(int j=m-1;j>=0;j--)
    {
        int t1 = (s2[j]-'0');
        for(int i=n-1;i>=0;i--)
        {
            int t2 = (s1[i]-'0');
            
            int mul = t1*t2 + (s3[i+j+1]-'0');
            s3[i+j+1] = ((mul%10)+'0');
            s3[i+j] = (((s3[i+j]-'0') + (mul/10))+'0');
        }
    }
    
    int j=0;
    
    while(s3[j]=='0')
    {
        j++;
    }
    
    s3 = s3.substr(j);
    
    return s3;
}

bool compare(string s1,string s2)
{
    if(s1==s2)
    {
        return true;
    }
    
    int n = s1.length();
    int m = s2.length();
    
    if(n>m) 
    {return true;}
    
    if(m>n) 
    {return false;}
    
    for(int i=0;i<n;i++)
    {
        if(s1[i]<s2[i])
        {
            return false;
        }
        else if(s1[i]>s2[i])
        {
            return true;
        }
        else
        {
            continue;
        }
        
    }
    
    return false;
}

string str_rem(string s1,string s2)
{
    if(s2=="1")
    {
        return s1;
    }
    
    string s3 = "0";
    string one = "1";
    
    while(compare(s1,s2))
    {
        s1 = str_sub(s1,s2);
        s3 = str_add(s3,one);
    }
    
    return s1;
}

string str_div(string s1,string s2)
{
    if(s2=="1")
    {
        return s1;
    }
    
    string s3 = "0";
    string one = "1";
    
    while(compare(s1,s2))
    {
        s1 = str_sub(s1,s2);
        s3 = str_add(s3,one);
    }
    
    return s3;
}

string new_str_div(string s1,string s2)
{
    if(!compare(s1,s2))
    {
        return "0";
    }
    
    if(s2=="1")
    {
        return s1;
    }
    
    string str1="";
    string ans="";
    int i=0;
    
    while(i<s1.length())
    {
        str1+=s1[i];
        int j=0;
        while(str1[j]=='0')
        {
            j++;
            if(j==str1.length())
            {
                str1 = "0";
                break;
            }
            else if(str1[j]!='0')
            {
                str1 = str1.substr(j);
                break;
            }
        }
        ans+=str_div(str1,s2);
        i++;
        string temp = str_rem(str1,s2);
        str1 = temp;
    }
    
    int j=0;
    while(ans[j]=='0')
    {
        j++;
        if(j==ans.length())
        {
            ans = "0";
            break;
        }
        else if(ans[j]!='0')
        {
            ans = ans.substr(j);
            break;
        }
    }
    
    return ans;
}

string exponential(string s1,string s2)
{
    if(s2=="1")
    {
        return s1;
    }
    
    if(s2=="0")
    {
        return "1";
    }
    
    string x = exponential(s1,new_str_div(s2,"2"));
    
    int size = s2.length();
    char temp = s2[size-1];
    
    if((temp-'0')%2==0)
    {
        return str_mul(x,x);
    }
    else
    {
        return str_mul(str_mul(x,x),s1);
    }
}

string gcd(string s1,string s2)
{
    if(s1=="0")
    {
        return s2;
    }
    if(s2=="0")
    {
        return s1;
    }
 
    if(s1==s2)
    {
        return s1;
    }
    
    if(compare(s1,s2))
    {
        return gcd(str_sub(s1,s2),s2);
    }
    return gcd(s1,str_sub(s2,s1));
}

string fact(string s1)
{
    if(s1=="0" || s1=="1")
    {
        return s1;
    }
    
    string s2 = "1";
    
    while(s1!="1")
    {
        s2 = str_mul(s2,s1);
        s1 = str_sub(s1,"1");
    }
    
    return s2;
}

void section1()
{
	cout<<endl;
	string input;
    cin>>input;
    
    string s1;
    string s2;
    string s3;
    string s4;
    
    int start =-1;
    int point = 0;
    
    while(point<input.length())
    {
        if(input[point]=='/' || input[point]=='x')
        {
            int op = point;
            point++;
            
            while(point<input.length() && input[point]!='+' && input[point]!='-' && input[point]!='x' && input[point]!='/')
            {
                s2.push_back(input[point]);
                point++;
            }
            
            int end = point;
            
            if(input[op]=='x')
            {
                s3 = str_mul(s1,s2);
            }
            else if(input[op]=='/')
            {
                s3 = new_str_div(s1,s2);
            }
            
            input = input.substr(0,start+1)+s3 + input.substr(end);
            s2 = s4;
            
            s1=s3;
            point = start+s3.length()+1;
        }
        else if(input[point]=='+' || input[point]=='-')
        {
            start = point;
            s1 = s4;
            point++;
        }
        else
        {
            s1.push_back(input[point]);
            point++;
        }
    }
    
    start =-1;
    point = 0;
    s1 = s4;
    s2= s4;
    
    while(point<input.length())
    {
        if(input[point]=='+' || input[point]=='-')
        {
            int op = point;
            point++;
            
            while(point<input.length() && input[point]!='+' && input[point]!='-' && input[point]!='x' && input[point]!='/')
            {
                s2.push_back(input[point]);
                point++;
            }
            
            int end = point;
            
            if(input[op]=='+')
            {
                s3 = str_add(s1,s2);
            }
            else if(input[op]=='-')
            {
                s3 = str_sub(s1,s2);
            }
            
            input = input.substr(0,start+1)+s3+input.substr(end);
            s2 = s4;
            
            s1=s3;
            point = start+s3.length()+1;
        }
        else if(input[point]=='x' || input[point]=='/')
        {
            start = point;
            s1 = s4;
            point++;
        }
        else
        {
            s1.push_back(input[point]);
            point++;
        }
    }
    
    cout<<input<<endl;
}

void section2()
{
	cout<<endl;
	string s1,s2;
    cin>>s1>>s2;
    cout<<exponential(s1,s2)<<endl;
}

void section3()
{
	cout<<endl;
	string s1;
    string s2;
    
    cin>>s1>>s2;
    
    cout<<gcd(s1,s2)<<endl;
}

void section4()
{
	cout<<endl;
	string s1;
    cin>>s1;
    
    cout<<fact(s1)<<endl;
}

int main()
{
	int option;
	cin>>option;
	
	switch(option)
	{
		case 1:
			section1();
			break;
		case 2: 
			section2();
			break;
		case 3:
			section3();
			break;
		case 4: 
			section4();
			break;
		default:
			break;
	}
}