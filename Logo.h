#ifndef LOGO_H
#define LOGO_H
#include "hy352_gui.h"
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cmath>
using namespace std;


class Var;
void printvs(Var v);

template <typename T> 
void print(vector<Var*>  *v,const T t) {  
Var * temp = new Var(t);
    v->push_back(new Var(t));
}  

template <typename First, typename... Rest> 
void print(vector<Var*> *v ,const First first, const Rest... rest) {  
    v->push_back(new Var(first));
    Var * temp = new Var(first);

    print(v,rest...); // recursive call using pack expansion syntax  
}  


template<typename First, typename ... Rest>
vector<Var*> piperino(const First first, const Rest... rest){
	vector <Var*> vv;
	print(&vv,first,rest...);
	
	return vv;
}
#define ASSIGN ;
#define FORWARD ;pipe$$$ >> ssp$$ =
#define BACK    ;pipe$$$ << ssp$$ =
#define RIGHT ;pipe$$$ >>= ssp$$ =
#define LEFT ;pipe$$$ <<= ssp$$ =
#define CENTER ;turtle_go_to_center();
#define CIRCLE ;pipe$$$ <= ssp$$ =
#define PRINT ;tmppp$$$=WORD:"ZERO_$$__DEAD_aA__LOCK__***$$$$";   pipe$$$ || ssp$$ =
#define SETXY ;pipe$$$ -=
#define SETPENCOLOR ;pipe$$$ |= 
#define SETSCREENCOLOR ;pipe$$$ %= 
#define SETPENSIZE ;pipe$$$ != ssp$$ =
#define PENDOWN ;pen_down();
#define PENUP ;pen_up();
#define START_PROGRAM int main(int argc, char **argv){int zzz$$$$sss;Var ssp$$; pipo pipe$$$; Var ttpp$$$$;Var ssss$$;cout<<"-START-"<<endl<<endl; Var zp$$$$$;ValVal pppp$$$$;   Var zz$$$$$ ;int kk$$$=0;vector<int> vvv$$$ ;vvv$$$.push_back(0); ValVal tmpp$$$; Var tmppp$$$; string s$$$; Var sd$$$; init_GUI();
#define END_PROGRAM ;destroy_GUI();  cout<<endl<<"-END-"<<endl;}
#define MAKE ; tmppp$$$=WORD:"ZERO_$$__DEAD_aA__LOCK__***$$$$"; Var 
#define NUMBER sd$$$=(double)false?10
#define WORD sd$$$ = s$$$ = false?"nope"
#define B00LEAN sd$$$=(bool)false?true
#define SENTENCE piperino
#define TRUE true
#define FALSE false
#define LIST sd$$$=tmppp$$$
#define ARRAY sd$$$=
#define SIZE tmpp$$$ = (int)false?10
#define ITEM sd$$$=z_item
#define SETITEM ; tmppp$$$=WORD:"ZERO_$$__DEAD_aA__LOCK__***$$$$";z_set
#define MINUS z_minus
#define SUM z_sum
#define DIFFERENCE z_diff
#define PRODUCT z_product
#define QUOTIENT z_quot
#define MODULO z_mod
#define AND z_and
#define OR z_or
#define IF ;if(kk$$$==(vvv$$$.size()-1))vvv$$$.push_back(0); zzz$$$$sss=vvv$$$[kk$$$]; kk$$$++; vvv$$$[kk$$$]=zzz$$$$sss-1; if( zp$$$$$<<=
#define DO ){ vvv$$$[kk$$$]++;
#define END ;}vvv$$$[kk$$$]=0; kk$$$--;
#define ELIF ;}else if( zp$$$$$<<=
#define ELSE ;}else if(true){
#define REPEAT ;if(kk$$$==(vvv$$$.size()-1))vvv$$$.push_back(0); kk$$$++; for(vvv$$$[kk$$$]= 0;vvv$$$[kk$$$]<
#define TIMES ;
#define REPCOUNT vvv$$$[kk$$$]
#define WHILE -100;vvv$$$[kk$$$]++){} while( zp$$$$$<<=
#define FOREACH  ; if(kk$$$==(vvv$$$.size()-1))vvv$$$.push_back(0); kk$$$++;for (Var k$$: zz$$$$$|
#define SHOW ; tmppp$$$=WORD:"ZERO_$$__DEAD_aA__LOCK__***$$$$";  pppp$$$$ <<= false?zp$$$$$
#define ELEM k$$
#define RETURN ;return;
#define TO ;template<typename First, typename ... Rest> void
#define WITH ( const First first$$$$$, const Rest...
#define FSTART  ){int zzz$$$$sss; Var ssp$$;pipo pipe$$$;  Var ttpp$$$$;Var ssss$$; Var zp$$$$$;ValVal pppp$$$$;   Var zz$$$$$ ;int kk$$$=0; vector<int> vvv$$$;vvv$$$.push_back(0); ValVal tmpp$$$; Var tmppp$$$; string s$$$; Var sd$$$;
#define FEND ;}
#define FDEF );
#define ARG(X) get_back(first$$$$$,X)
#define CALL ;tmppp$$$=WORD:"ZERO_$$__DEAD_aA__LOCK__***$$$$";
#define ARGS_NUM get_size(first$$$$$);
class Var;
class ValVal{
public:
	int size;
	vector<Var> m_vector;
	ValVal(){}
	ValVal(int a);
	ValVal operator<<=(Var);
};

class Var{
public:
	int size;
	int type;
	string s;
	double valb;
	bool bl;
	vector<Var> my_vector;

	Var();
	Var(ValVal);
	Var(void * s);
	Var(double s);
	Var(int s);
	Var(string s);
	Var(bool bl);
	Var(vector<Var*> vv);
	Var(initializer_list<Var> vv);
	Var(const Var& v);

	Var operator=(Var v);
	Var operator[](Var v);
	Var operator,(Var v);
	
	Var operator==(Var v);
	Var operator<=(Var v);
	Var operator>=(Var v);
	Var operator!=(Var v);
	Var operator<(Var v);
	Var operator>(Var v);
	bool operator<<=(Var v);
	vector<Var> operator|(Var v);

};


class pipo{
public:
	int type;
	int y;
	int x;

	pipo(string s );
	pipo(int z);
	pipo();

	void operator|=(Var  v);
	void operator%=(Var  v);
	pipo operator!=(Var  v);
	pipo operator>>(Var v);
	pipo operator<<(Var v);
	void operator<<=(Var v);
	void operator>>=(Var v);
	pipo operator<=(Var v);
	void operator=(float v);
	void operator=(Var v);
	pipo operator-=(float v);
	pipo operator-=(Var v);
	pipo operator||(Var v);
	void operator||(char * c);
	void operator,(float v);
	void operator,(Var v);
};


Var z_item(vector<int> vv ,Var z);
void z_set(vector<int> vv ,Var& z,Var m);
Var z_minus(Var a);
Var z_diff (Var a,Var b);
Var z_quot(Var a , Var b);
Var z_mod(Var a, Var b);
void printvs(int,Var);
void printvs(Var v);

template<typename First, typename ... Rest>
Var z_sum(const First first, const Rest... rest){
	//vector<Var> vv;
	vector <Var*> vv;
	print(&vv,first,rest...);
	Var a = 0;
	for (auto & i : vv){
		a.valb = a.valb +i->valb;
	}
	return a;
}

template<typename First, typename ... Rest>
Var z_product(const First first, const Rest... rest){
	//vector<Var> vv;
	vector <Var*> vv;
	print(&vv,first,rest...);
	Var a = 1;
	for (auto & i : vv){
		a.valb = a.valb *i->valb;
	}
	return a;
}

template<typename First, typename ... Rest>
bool z_and(const First first, const Rest... rest){
	//vector<Var> vv;
	vector <Var*> vv;
	Var sd$$$;

	print(&vv,first,rest...);
	
	for (auto & i : vv){
		if((i->bl)==false){
			return false;
		}
		
	}
	return true;
}

template<typename First, typename ... Rest>
bool z_or(const First first, const Rest... rest){
	//vector<Var> vv;
	vector <Var*> vv;
	Var sd$$$;

	print(&vv,first,rest...);
	for (auto & i : vv){
		if((i->bl)==true){
			return true;
		}
		
	}
	return false;
}

bool compare_Vars_equal(Var a,Var b);
bool compare_Vars_different(Var a,Var b);
bool compare_Vars_less(Var a ,Var b);
bool compare_Vars_lesseq(Var a,Var b);
bool compare_Vars_more(Var a,Var b);
bool compare_Vars_moreeq(Var a,Var b);



Var get_back(Var v,int x);
Var get_size(Var v);


#endif