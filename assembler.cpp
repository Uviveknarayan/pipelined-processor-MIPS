#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

bool b=false;
bool b2=false;
bool b3=false;
string t="";
 
string s2="";
string s1="";
string passfunction(string s){
	int k;
	for(int i=0;i<s.size();i++){
		if(s[i]==' '){
			k=i;
			break;
		}
	}
	s1=s1+s.substr(0,k);
	int x=s1.size();
		if(s1=="add") {
		t=t+"000000";
		}
		if(s1=="sub") {
		t=t+"000000";
		}
		if(s1=="mul") {
		t=t+"000000";
		}
		if(s1=="and") {
		t=t+"000000";
		}
		if(s1=="or") {
		t=t+"000000";
		}
		if(s1=="nor") {
		t=t+"000000";
		}
		if(s1=="beq") {
		t=t+"000100";
		b=true;
		}
		if(s1=="j") {
		t=t+"000010";
		b2=true;
		}
		if(s1=="lw") {
		t=t+"100011";
		b3=true;
		}
		if(s1=="sw") {
		t=t+"101011";
		b=true;
	}
	s2=s.erase(0,s1.size());
	s2=s2.erase(0,1);
	//s2=removeLastN(s,x);
	//s2=removeLastN(s,1);
	//s2=s-s1;
	//s2=s2-" ";
	return t;
 
}
 
string rs(){
	int k;
	for(int i=0;i<s2.size();i++){
		if(s2[i]==','){
			k=i;
			break;
		}
		if(i==s2.size()-1){
			k=i+1;
		}
	}	
 
	string s3=s2.substr(0,k);
	s2=s2.erase(0,s3.size());
	s2=s2.erase(0,1);
	//s2=removeLastN(s2,s3.size());
	//s2=s2-s3;
	//s2=removeLastN(s2,1);
	//s2=s2-",";
		if(s3=="$0"){
		t=t+"00000";
	}
	if(s3=="$1"){
		t=t+"00001";
	}
	if(s3=="$2"){
		t=t+"00010";
	}
	if(s3=="$3"){
		t=t+"00011";
	}if(s3=="$4"){
		t=t+"00100";
	}
	if(s3=="$5"){
		t=t+"00101";
	}
	if(s3=="$6"){
		t=t+"00110";
	}
	if(s3=="$7"){
		t=t+"00111";
	}
	if(s3=="$8"){
		t=t+"01000";
	}
	if(s3=="$9"){
		t=t+"01001";
	}
	return t;
}
string funct(){
	if(b==false&&b3==false&&b2==false ){
		    t=t+"00000";
			if(s1=="add"){
			t=t+"100000";
			}
			if(s1=="sub") {
			t=t+"100010";
			}
			if(s1=="mul") {
			t=t+"100001";
			}
			if(s1=="and") {
			t=t+"100100";
			}
			if(s1=="or") {
			t=t+"101000";
			}
			if(s1=="nor") {
			t=t+"110000";
		}
	}
	return t;
}
string address(){
	if(b2==true){
		t=t+"0000000000";
	}
	int i=0;
       while(s2[i])
    {
            if(s2[i]=='0')
                t=t+"0000";
            if(s2[i]=='1')
                t=t+"0001";
            if(s2[i]=='2')
                t=t+"0010";
            if(s2[i]=='3')
                t=t+"0011";
            if(s2[i]=='4')
                t=t+"0100";
            if(s2[i]=='5')
                t=t+"0101";
            if(s2[i]=='6')
                t=t+"0110";
            if(s2[i]=='7')
                t=t+"0111";
            if(s2[i]=='8')
                t=t+"1000";
            if(s2[i]=='9')
                t=t+"1001";
            if(s2[i]=='a'||s2[i]=='A')
                t=t+"1010";
           if(s2[i]=='b'||s2[i]=='B')
                t=t+"1011";
            if(s2[i]=='c'||s2[i]=='C')
                t=t+"1100";
            if(s2[i]=='d'||s2[i]=='D')
                t=t+"1101";
            if(s2[i]=='E'||s2[i]=='e')
                t=t+"1110";
            if(s2[i]=='F'||s2[i]=='f')
                t=t+"1111";
        i++;
    } 
    return t;
}
string bin(string s){
	string e=passfunction(s);
	if(b2==false){
	   e=rs();
	   e=rs();
	}
	if(b==true||b2==true||b3==true){
		e = address();
	}
	if(b==false&&b2==false&&b3==false){
		e=rs();
		e = funct();
	}return e;
}
string Haz(string s){
	string g = passfunction(s);
	g = rs();
	string j = rs();
	if(b3==true){
		j=j.erase(0,g.size());
		return j;
	}	
	else{
		string h = rs();
		h=h.erase(0,j.size());
		return h;
	}
}
string readreg1(string s){
	string g = passfunction(s);
	string j =rs();
       j=j.erase(0,g.size());
	   return j;
}
string readreg2(string s){
	string g = passfunction(s);
	g=rs();
	string j= rs();
    j=j.erase(0,g.size());
	return j;
}
void clear(){
	/*b=false;
      b2=false;*/
	  t="";
      s2="";
      s1="";
}
void clearb(){
	b=false;
	b2=false;
	b3=false;
}
int equal(vector<pair<string,vector<string>>> q,int i){
	string m=q[i].first;
	int xxx;
 for(int y=1;(y<4)&&(y<=(q.size()-i));y++){
	vector<string>a=q[i+y].second;
	for(int j=0;j<a.size();j++){
		if(a[j]==m){
			xxx = 4-y;
			return xxx;
		}
	}
 }
  return 0;
}
int main() {
    string s,m;
	vector<pair<string,vector<string>>> n(4);
	int i=0;
	vector<bool> jbstall;
    ifstream input ("C:/Users/koushik/Downloads/input.txt");
	ofstream output;
	output.open("C:/Users/koushik/Downloads/output.txt");
    while (getline(input, s)){
	  //cout<<s<<endl;
	  vector<string>x;
	  m=bin(s);
	 output<<m<<endl;
	 if(s[0]=='j'||s[0]=='b'){
        jbstall.push_back(1);
	 }
	 else{
		jbstall.push_back(0);
	 }
	  clear();
	  if(b2==false){
	  x.push_back(readreg1(s));
	  clear();
	  if(b3==false){
        x.push_back(readreg2(s));
		clear();
	  }if(b==false){
	  n.push_back(make_pair(Haz(s),x));
	  clear();
	  }else {
		n.push_back(make_pair("-1",x));
	  }
	  i++;
	  }else{
		x.push_back("-1");
		n.push_back(make_pair("-1",x));
		i++;
	  }clearb();
    }
	output.close();
	ofstream o;
	o.open("C:/Users/koushik/Downloads/output2.txt");
	int d[i]={0};
    for(int j=0;j<i;j++){
		if(jbstall[j]==0){
		   d[j]=equal(n,j);
		   o<<d[j]<<endl;
		}
		else{
			o<<3<<endl;
		}
	}
	o.close();
    input.close();
	
    return 0;
}