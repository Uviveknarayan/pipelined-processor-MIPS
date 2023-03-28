#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include<sstream>
using namespace std;
int clk=0;
int i=1;
int PC=0;
int zero=0;
string l1,l3;
string INS,s2;
stringstream ss1; 
stringstream ss2;
stringstream ss3;
stringstream ss4;
stringstream ss5;
stringstream ss6;
stringstream ss7;
stringstream ss8;
stringstream ss9; 
stringstream ss10;       
int z1,z7,z8,z6, a1,a2,a3;
long long int z2,z5,z3,z4,z9;
int l,m,writere,j,d,memread,aluop,regdes,mtr,memwrite,branches,jup,regwrite;
int ctrol;
string b1,b2,b3,b4,b5,b6,b7,b8,b9;
int l2,h;
int x1,x2,x3,x4,x5;
vector<int>v0(1);
vector<int>v5(1);
vector<string>v01(1);
vector<string>v51(1);
vector<int>v1(10);
vector<string>v11(1);
vector<int>v2(10);
vector<int>v3(6);
vector<int>v4(3);
int Registers[32];
string Ins[1024*64];
int mem[1024*512];
bool jmp=0;
int arr=0;
int stall=0;
class Decode;
class ALU;
class dmemory;
class writeback;
void fetch(){
cin>>INS;
PC=PC+4;
v01.push_back(INS);
v0.push_back(PC);
}
void if_id(){
    v5=v0;
    v51=v01;
}
int RegDst(int in){
    if((in==100011)||(in==101011)){
        return 0;
    }
    else{
       return 1;
    }
}
    int branch(int in){
        if(in==101){
            return 1;
        }else if(in==11){
            return 2;
        }return 0;
    }
    int jump(int in){
        if(in==1001){
            return 1;
        }
        return 0;
    }
    int Memread(int in){
        if(in==100011){
            return 1;
        }return 0;
    }
    int MemtoReg(int in){
        if(in==100011){
            return 1;
        }
        else if(in==1){
            return 0;
        }
        else if(in==10){
            return 0;
        }
        else if(in==100){
            return 0;
        }
        else if(in==1000){
            return 0;
        }
        else if(in==10000){
            return 0;
        }
        else if(in==100000){
            return 0;
        }
        else if(in==1){
            return 3;
        }
        else{
            return 4;
        }
    }
    int ALUop(int in){
        if(in==100011 || in==101011){
            return 0;
        }
        else if(in==100){
            return 1;
        }
        else if(in==0){
                return 10;
            }
        else{
            return 2;
        }
    }
    int MemWrite(int in){
        if(in==100001){
            return 1;
        }else{
            return 0;
        }
    }
    int ALUsrc(int in){
        if(in==100011 || in==101011){
            return 1;
        }else if(in==1001){
            return 3;
        }else{
            return 0;
        }
    }
    int Regwrite(int in){
         if((in==100001)||(in==1001)||(in==101)||(in==11)){
            return 0;
        }
        else{
            return 1;
        }
    }
int andr (int branch){
    if(zero && branch==1){
        return 1;
    }
    return 0;
}
int bintodec(long long int a,int n){
    int k;
    int s=0;int c=0;
    while(c<n){
        k=a%10;
        s=s+(int)(k*pow(2,c));
        c++;
        a=a/10;
    }
    return s;
} 
class Decode{
    
    int diri(){
        //cout<<v51.back()<<endl;
        l1 = v51.back();
        l2 = v5.back();
        return 0;
    }
    int king=diri(); 
    public:
    int assign(){
      b1 = l1.substr(0,6);
     // cout<<b1<<endl;
      b2 = l1.substr(6,5);
      b3 = l1.substr(11,5);
      b4 = l1.substr(16,5);
      b5 = l1.substr(16,16);
      b6 =l1.substr(26,6);
      b7 = l1.substr(6,13);
      b8 =l1.substr(19,13);
      b9 =l1.substr(16,16);
      ss1<<b9;
      ss1>>z9;
      ss2<<b7;
      ss2>>z7;
      ss3<<b1;
      ss3>>z1;
      ss4<<b8;
      ss4>>z8; 
      ss5<<b6;
      ss5>>z6;
      ss6<<b5;
      ss6>>z5;
      ss7<<b2;
      ss7>>z2;
      ss8<<b3;
      ss8>>z3;
      ss10<<b4;
      ss10>>z4;
      ss1.str("");
      ss1.clear();
      ss2.str("");
      ss2.clear();
      ss3.str("");
      ss3.clear();
      ss4.str("");
      ss4.clear();
      ss5.str("");
      ss5.clear();
      ss6.str("");
      ss6.clear();
      ss7.str("");
      ss7.clear();
      ss8.str("");
      ss8.clear();
      ss10.str("");ss10.clear();
      //cout<<z4<<endl;
     return 0;
     
    }
    int asss = assign();
    int cucall(){
     j = jump(z1);
     d = ALUsrc(z1);
     memread= Memread(z1);
     aluop = ALUop(z1);
     regdes=RegDst(z1);
     mtr=MemtoReg(z1);
     memwrite = MemWrite(z1); 
     branches = branch(z1);
     jup = jump(z1);
     regwrite = Regwrite(z1);
    return 0;
    }
    int cccal = cucall();
    
    int readreg1(){
        a1=bintodec(z2,5);
       // cout<<a1<<endl;
       return Registers[a1];
    }
     int readreg2(){
        a2=bintodec(z3,5);
//        cout<<a2<<endl;

       return Registers[a2];
    }
    
    int writereg(){
        if(regdes==1){
            a3 =bintodec(z4,5);
            //cout<<a3<<endl;
            return a3;
        }
        else{
            return a2;
        }
    }
    void jumpad(int b){
        int a7=bintodec(z7,13);
        int a8=bintodec(z8,13);
        a8=a8*pow(2,13);
        a8=a8+a7;
        a8=a8*4;
        if(b==1){
            PC=PC+a8;
        }
    }
   void jmux(int j){
       jumpad(j);
   }
void shift(int b){
     int a5= bintodec(z5,16);
     a5=a5*4;
     if(b==1){
        PC=PC+a5;
     }
}  

int reg(){
    l =readreg1();
    m = readreg2();
    writere = writereg();
    v1.push_back(writere);
    v1.push_back(regwrite);
    v1.push_back(memwrite);
    v1.push_back(memread);
    v1.push_back(mtr);
    v1.push_back(d);
    v1.push_back(l);
    v1.push_back(m);
    v1.push_back(z6);
    v1.push_back(aluop);
    return 0;
   
}
    int j1 = reg();
};
void id_alu(){
    v2=v1;
    v11=v51;

}

class ALU{
    public:
    int func(int f){
        int control;
        if(f==100000){
            control=10;
        }else if(f==100010){
            control=110;
        }else if(f==100001){
            control=100;
        }else if(f==100100){
            control=0;
        }else if(f==101000){
            control=1;
        }else if(f==110000){
            control=1000;
        }return control;
    }
    int CTRL(int Aluop,int fnc){
        if(Aluop==0){
           ctrol = 10;
        }
        if(Aluop==1){
           ctrol =110;
        }
        if(Aluop==10){
           ctrol=func(fnc);
        }
        return ctrol;
    }

    int ALUoper(int ALUctrl,int a,int b){
    int c;
    if(ALUctrl==10){ 
       c=a+b;
    }
    else if(ALUctrl==110){
        c=a-b;   
    }
    else if(ALUctrl==0){
        c=a&&b;
    }
    else if(ALUctrl==1){
        c=a||b;
    }
    else if(ALUctrl==100){
        c=a*b;
    }
    else if(ALUctrl==1000){
        c=~(a||b);
    }
    if(c==0){
      zero=1;
    }
    //cout<<c<<endl;
    return c;
}
int ifreg(){
    l3 = v11.back();
    x1 =v2.back();
    v2.pop_back();
    x2  = v2.back();
    v2.pop_back();
    x3 = v2.back();
    v2.pop_back();
    x4 = v2.back();
    v2.pop_back();
    x5 = v2.back();
    v2.pop_back();
    return 0;
}

int j = ifreg();
int assignalu(){
   ctrol =CTRL(x1,x2);
   //cout<<ctrol<<endl;
    s2 = l3.substr(16,16);
    ss9<<s2;
    ss9>>z9;
    ss9.str("");
    ss9.clear();
    h= bintodec(z9,16);
    d=x5;
    return 0;
}
int assalu = assignalu();
int rety(int d){
    int g;
      if (d==1){
       g= ALUoper(ctrol,x3,h);
   }
   else{
        g=ALUoper(ctrol,x4,x3);
   }
   return g;
   }
 int dreg(){
    v2.push_back(rety(x5));
    return 0;
 }
 int fff= dreg();
};
void alu_dmem(){
    v3=v2;
}
class dmemory{
    public:
    int RAdress(int x){
        return mem[x];
   }
   void WAdress(int y,int memo){
       mem[memo]=y;
   }
   int dreg(){
    x1 = v3.back();
    v3.pop_back();
    x2 = v3.back();
    v3.pop_back();
    x4 = v3.back();
    v3.pop_back();
    x5 = v3.back();
    v3.pop_back();
    return 0;
   }
   int oo =dreg();
   int retu(int k1,int k2){
    int y;
    if (k1==1){
     y =RAdress(x1);
   }
   else if (k2==1){
     WAdress(x3,x1);
   }
   return y;
   }
   int ramasetu(int y){
    if (x2==1){
     return y;
   }
   else{
     return x1;
   }
   }
   int wreg(){
    v3.push_back(ramasetu(retu(x4,x5)));
    return 0;
   }
   int w = wreg();
};
void dmem_wb(){
    v4=v3;
}
class writeback{
    public:
    int wwreg(){
       x1 =v4.back();
       v4.pop_back();
       x2 =v4.back();
       v4.pop_back();
       x3=v4.back();
       v4.pop_back();
       return 0;
    }
    int wwwww=wwreg();
    int  writedata(int d){
        int  regwrit =x2 ;
        if(regwrit==1){
            Registers[x3]=d;
        }
        return 0;
    }
   int ii= writedata(x1);
};
int  stallcheck(int a){
        if(a==0){}
        else {
            while(a!=4){
                stall=1;
                a++;
                clk++;
            }
        }
        return 0;
    }
    
/*void callonstall(int stall){
    if(stall==4){
        AA;
        alu_dmem();
        de;
        dmem_wb();
        clk++;
        www;
        clk++;
        t;
        id_alu();
        fetch();
    }
    else if(stall==3){
        de;
        dmem_wb();
        AA;
        alu_dmem();
        clk++;
        www;
        de;
        dmem_wb();
        clk++;
        t;
        id_alu();
        fetch();
    }
    else if(stall==2){
        www;
        de;
        dmem_wb();
        AA;
        alu_dmem();
        clk++;
        t;
        id_alu();
        fetch();
    }
}*/

int main(){
    mem[2]=3;
    Registers[1]=0;
    Registers[5]=3;
    Registers[4]=4;
    Registers[6]=0;
    Registers[7]=9;
    Registers[9]=3;
    Registers[8]=2;
    fetch();
    if_id();
    Decode t;
    int i =t.assign();
    int cal = t.cucall();
    int sss =t.reg();
    id_alu();
    fetch();
    //cout<<INS<<endl;
    if_id();
    ALU AA;
    alu_dmem();
    i =t.assign();
    cal = t.cucall();
    sss =t.reg();
    id_alu();
    fetch();
    if_id();
    dmemory de;
    dmem_wb();
    ALU AA1;
    alu_dmem();
    Decode t2;
    id_alu();
    fetch();
    if_id();
    writeback www1;
    dmemory de1;
    dmem_wb();
    ALU AA2;
    alu_dmem();
    Decode t3;
    id_alu();
    writeback www2;
    dmemory de2;
    dmem_wb();
    ALU AA3;
    alu_dmem();
    writeback www3;
    dmemory de3;
    dmem_wb();
    writeback www4;

    
    cout<<Registers[4]<<endl;
    cout<<Registers[6]<<endl;
}