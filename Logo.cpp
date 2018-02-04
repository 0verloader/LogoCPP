#include "Logo.h"

Var::Var(int s) {

	this->valb = s;
	this->type = 1;
}

Var::Var(double s) {
	this->valb = s;
	this->type = 1;
}

Var::Var(string s) {
	this->s = s;
	this->type = 0;
}

Var::Var(bool bl) {
	this->bl = bl;
	this->type = 2;

}

ValVal 	ValVal::operator<<=(Var v){
	printvs(v);
	ValVal temp;
	return temp;

}

bool Var::operator<<=(Var v){
	
	return v.bl;
}

Var Var::operator==(Var v){
	Var a;
	Var sd$$$;

	if(compare_Vars_equal(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;
	
}



Var Var::operator!=(Var v){
	Var a;
	Var sd$$$;

	if(compare_Vars_different(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;
}



Var Var::operator<=(Var v){
	Var a;
	Var sd$$$;

	if(compare_Vars_lesseq(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;
}

Var Var::operator>=(Var v){
	Var a;
	Var sd$$$;
	if(compare_Vars_moreeq(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;
}


Var Var::operator>(Var v){
	Var a;
	Var sd$$$;

	if(compare_Vars_more(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;

}


Var Var::operator<(Var v){
	Var a;
	Var sd$$$;

	if(compare_Vars_less(*this,v))
		a=B00LEAN:TRUE;
	else
		a=B00LEAN:FALSE;
	return a;
}

Var::Var(void * sv) {}




Var Var:: operator[](Var v) {
		this->my_vector.clear();

			this->type =3;

		if( v.my_vector.size() == 0) { 
			this->my_vector.push_back(v);
		}
		else if(v.type == 9){
			this->my_vector={};
			for(int i=0;i<v.my_vector.size();i++){
				this->my_vector.push_back(v.my_vector[i]);
			}
		}
		else{
			this->my_vector={};
			this->my_vector.push_back(v);
		}

		return *this;
	
	}

Var Var::operator,(Var v) {
	if(this->type == 0 ||this->type == 1 ||this->type == 2 ){
		Var z={};
		z.type =9;
		z.my_vector.push_back(*this);
		z.my_vector.push_back(v);
		return z;
	}
	else if (this->type == 9){
		this->my_vector.push_back(v);
		return *this;
	}
	else if(this->type == 3 || this->type ==4 || this->type== 5){
		Var x ;
		x.type =this->type;
		x.size = this->size;
		for (int i=0;i<this->my_vector.size();i++){
			x.my_vector.push_back(this->my_vector[i]);
		}
		this->my_vector={};
		this->my_vector.push_back(x);
		this->my_vector.push_back(v);	
		this->type = 9;
		return *this;
	}
}


	Var Var::operator=(Var v) {

		this->type = v.type;
		this->size = v.size;
		this->my_vector.clear();  /* isws petaxei thema*/
		if (this->type == 0) {
			if((v.s).compare("ZERO_$$__DEAD_aA__LOCK__***$$$$")==0){
				this->type=3;
				return *this;
			}
			this->s = v.s;
		}
		else if (this->type == 1) {
			this->valb = v.valb;
		}
		else if (this->type == 2) {
			this->bl = v.bl;
		}
		else if (this->type == 3) {
			this->my_vector = v.my_vector;
		}
		else{

			for (unsigned i = 0; i < v.my_vector.size(); i++) {
				this->my_vector.push_back(v.my_vector[i]);
			}
		}

		
		return *this;
	}

 Var z_mod(Var a, Var b){
	Var c = 0;
	c.valb = (int)a.valb % (int)b.valb;
	return c;
}

Var z_quot(Var a , Var b){
	Var c=0;
	c.valb = a.valb / b.valb;
	return c;
}
Var::Var(ValVal v ){
	this->size = v.size;
	this->type =4 ;
	for(int i =0;i<this->size;i++){
		Var t;
		t.type =9;
		this->my_vector.push_back(t);
	}
}


Var z_minus(Var a){
	Var b = 3;
	b.valb = -a.valb;
	return b;
}

Var z_item(vector<int> vv ,Var z){
	Var b =z;
	for(int i : vv){
		if ((b.type ==3 ||b.type==4 ||b.type ==5)&& i<=b.my_vector.size() && i>0)
			b=b.my_vector[i-1];
		else
		{
			cerr<<"\033[1;31mERROR: Cannot find " <<i<<"th element of ::\n";printvs(b);cout<<"\033[0m" << endl;
			exit(0);	
		}
	}

	return b;
}


Var get_back(Var v,int x){
	if (x>=1 && x<=v.my_vector.size())
		return v.my_vector[x-1];
	else{
		cerr<<"\033[1;31mERROR: Cannot get " <<x<<"th arguement from ::\n";printvs(v);cout<<"\033[0m" << endl;
		exit(0);	

	}

}


Var get_size(Var v){
	Var a = (int)v.my_vector.size();
	return a;


}



void z_set(vector<int> vv ,Var& z,Var m){
	Var *b =&z;

	for(int i : vv){
		if ((b->type ==3 ||b->type==4 ||b->type ==5)&& i<=b->my_vector.size() && i>0  )
			b=&(b->my_vector[i-1]);
		else
		{
			cerr<<"\033[1;31mERROR: Cannot change " <<vv[0]<<"th element of ::\n";printvs(*b);cout<<"\033[0m" << endl;
			exit(0);	
		}
	}
	*b=m;
}


Var::Var(initializer_list<Var> vv) {
	this->my_vector.clear();
	this->size = vv.size();
	this->my_vector = vv;
	this->type = 4;

}

Var::Var() {
	this->type = -1;
}


Var::Var(vector<Var*> vv){
	this->type =5;
	this->size = vv.size();
	for (int i=0;i< vv.size();i++){
		if(vv[i]->type!=5){
			if(vv[i]->type==0){
				Var temp =Var(*vv[i]);
				this->my_vector.push_back(temp);
			}
			else{
				cerr<<"\033[1;31mERROR: SENTENCEs accept only WORDS or other SENTENCEs\033[0m"<<endl;
				exit(0);
			}
		}
		else{
			for(int y=0;y<vv[i]->my_vector.size();y++){
				Var temp =Var((vv[i]->my_vector[y]));
				this->my_vector.push_back(temp);
			}
		}
	}

	

}
Var z_diff (Var a,Var b){
	Var c =0;
	c.valb = a.valb - b.valb;
	return c;
}

Var::Var(const Var& v) {
	this->size = v.size;
	this->type = v.type;
	if (v.type == 0) {
		this->s = v.s;
	}
	else if (v.type == 1) {
		this->valb = v.valb;
	}
	else if (v.type == 2) {
		this->bl = v.bl;
	}
	for (unsigned i = 0; i < v.my_vector.size(); i++) {
		this->my_vector.push_back(v.my_vector[i]);
	}
	//cout << "const var :" <<v.type << endl;
}

vector<Var> Var::operator|(Var v){
	vector<Var> gg;
	for (auto i : v.my_vector){
		gg.push_back(i);
	}
	return gg;
}

ValVal::ValVal(int a){
	this->size = a;
}

void printvs(int k,Var v,int m){
	int zz=1;
	for( int mm =0;mm<k;mm++){
		cout<<" ";
	}
	if(m!=-1)
		cout<<"["<<m<<"]";
	if(v.type ==0)
		cout<<"WORD     "<<":   "<<v.s<<endl;
	else if(v.type ==1)
		cout<<"NUMBER   "<<":   "<<v.valb<<endl;
	else if(v.type ==2){
		if(v.bl)
			cout<<"BOOLEAN  "<<":   "<<"TRUE"<<endl;
		else
			cout<<"BOOLEAN  "<<":   "<<"FALSE"<<endl;
	}else if(v.type==3){
		//cout<<"ARRAY ["<<this->size<<"] {"<<endl;
		cout<<"LIST {"<<endl;
		for(Var i : v.my_vector)
			printvs(k+8,i);
		for( int mm =0;mm<k;mm++){
			cout<<" ";
		}
		cout<<"}"<<endl;

	}else if(v.type == 4){
		cout<<"ARRAY ["<<v.size<<"] {"<<endl;
		for(Var i : v.my_vector){
			printvs(k+12,i,zz);
			zz++;
		}

			for( int mm =0;mm<k;mm++){
		cout<<" ";
	}
				cout<<"}"<<endl;

	}
	else if(v.type ==5){
		cout<<"SENTENCE :   ";
		for(Var i : v.my_vector){
			cout << i.s <<" ";	
		}
		cout<<endl;
	}
	else if (v.type ==9){
		cout<<endl;
	}

}

void printvs(int k,Var v){

printvs(k,v,-1);

}


void printvs(Var v){

printvs(0,v,-1);

}







void pipo::operator|=(Var  v){
  set_pen_color(v.my_vector[0].valb,v.my_vector[1].valb,v.my_vector[2].valb);
}

void pipo::operator%=(Var  v){
  set_screen_color(v.my_vector[0].valb,v.my_vector[1].valb,v.my_vector[2].valb);
}

pipo pipo::operator!=(Var  v){
	pipo zz;
	zz.type = 6;
	return zz;
}

pipo pipo::operator>>(Var v){
	pipo zz;
	zz.type = 0;
	return zz;
}


pipo pipo::operator<<(Var v){
	pipo zz;
	zz.type = 1;
	return zz;
 
}

void pipo::operator<<=(Var v){
	turtle_rotate(360-v.valb);
}

void pipo::operator>>=(Var v){
	turtle_rotate(v.valb);
}

pipo pipo::operator<=(Var v){
  	pipo zz;
	zz.type = 4;
	return zz;
}

void pipo::operator=(float v){

	if (this->type==0){
		turtle_mv_forward(v);
	}
	else if(this->type==1){
		turtle_mv_backward(v);
	}
	else if(this->type==4){
		for (int i = 0; i < 360; i++)
  		{
		    turtle_mv_forward(v);
		    turtle_rotate(1);
 		}
	}
	else if(this->type ==6){
		  set_pen_thickness(v);   

	}

}

void pipo::operator=(Var v){
	if (this->type==0){
		turtle_mv_forward(v.valb);
	}
	else if(this->type==1){
		turtle_mv_backward(v.valb);
	}
	else if(this->type==4){
		for (int i = 0; i < 360; i++)
  		{
		    turtle_mv_forward(v.valb);
		    turtle_rotate(1);
 		}
	}
	else if(this->type==5){

		const char *msg;
	 	if(v.type == 0){
		    msg = (v.s).c_str();
		    turtle_draw_label(msg);
	  	}
	  	else if (v.type ==1){
	  		string temp;
	  		if (floor(v.valb) == v.valb){
	  			int p = (int)v.valb;
		     	temp = to_string(p);
		    }else
		    	temp = to_string(v.valb);
		    msg = (temp).c_str();
		    turtle_draw_label(msg);
	  	}
	  	else if (v.type == 2){
	  		string temp;
	  		if(v.bl)
		     	temp = "TRUE";
		     else
		     	temp = "FALSE";

		    msg = (temp).c_str();
		    turtle_draw_label(msg);
		}
		else if(v.type ==5 ){
			string s ="";
			for (Var p : v.my_vector){

				s = s + p.s +" ";
			}
			msg = (s).c_str();
			turtle_draw_label(msg);
		}

	}
	else if(this->type ==6){
		set_pen_thickness(v.valb);   
	}

}


pipo pipo::operator-=(float v){
  pipo zz;
  zz.x=v;
  return zz;

}



pipo pipo::operator-=(Var v){
  pipo zz;
  zz.x=v.valb;
  return zz;

}

pipo pipo::operator||(Var v){
  	pipo zz;
	zz.type = 5;
	return zz;

}

void pipo::operator||(char * c){
  turtle_draw_label(c);
}

void pipo::operator,(float v){
  turtle_go_to_position(this->x,v);
  
}

void pipo::operator,(Var v){
  turtle_go_to_position(this->x,v.valb);
  
}


pipo::pipo(string s ){
  const char *msg = s.c_str();
  turtle_draw_label(msg);
  }

pipo::pipo(int z){  
  const char *msg;
  string temp = to_string(z);
  msg = (temp).c_str();
  turtle_draw_label(msg);
}

pipo::pipo(){}


bool compare_Vars_equal(Var a,Var b){

	if(a.type!=b.type || a.my_vector.size()!=b.my_vector.size()) {
		return false;
	}
	if(a.type == 0){
		if((a.s).compare(b.s)==0)
			return true;
		else 
			return false;
	}
	else if(a.type ==1 ){
		if(a.valb == b.valb)
			return true;
		else
			return false;

	}
	else if(a.type==2){
		if(a.bl == b.bl)
			return true;
		else
			return false;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;
		for (int i =0;i<a.my_vector.size();i++){
			if (!(compare_Vars_equal(a.my_vector[i] , b.my_vector[i])))
				return false;
		}
		return true;
	}
	else{
		return false;
	}

	}

bool compare_Vars_different(Var a,Var b){

	if(a.type!=b.type || a.my_vector.size()!=b.my_vector.size()) {
		return true;
	}
	if(a.type == 0){
		if((a.s).compare(b.s)==0)
			return false;
		else 
			return true;
	}
	else if(a.type ==1 ){
		if(a.valb == b.valb)
			return false;
		else
			return true;

	}
	else if(a.type==2){
		if(a.bl == b.bl)
			return false;
		else
			return true;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;
		for (int i =0;i<a.my_vector.size();i++){
			if (!(compare_Vars_different(a.my_vector[i] , b.my_vector[i])))
				return true;
		}
		return false;
	}
	else{
		return false;
	}

	}


bool compare_Vars_less(Var a,Var b){

	if(a.type!=b.type ) {
		return false;
	}

	if(a.type == 0){
		if((a.s).compare(b.s)<0)
			return true;
		else 
			return false;
	}
	else if(a.type ==1 ){			

		if(a.valb < b.valb)
			return true;
		else
			return false;

	}
	else if(a.type==2){

		if(a.bl < b.bl)
			return true;
		else
			return false;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;
		int k = min(a.my_vector.size(),b.my_vector.size());
		int num =0;
		for (int i =0;i<k;i++){
			if (!(compare_Vars_lesseq(a.my_vector[i] , b.my_vector[i])))
				return false;
			if(compare_Vars_less(a.my_vector[i] , b.my_vector[i]))
				num++;
		}

		if(a.my_vector.size()<b.my_vector.size())
			return true;
		else if((a.my_vector.size()==b.my_vector.size()) && num>0)
			return true;
		else
			return false;
		
	}
	else{
		return false;
	}

}



bool compare_Vars_lesseq(Var a,Var b){

	if(a.type!=b.type ) {
		return false;
	}


	
	if(a.type == 0){
		if((a.s).compare(b.s)<=0)
			return true;
		else 
			return false;
	}
	else if(a.type ==1 ){			

		if(a.valb <= b.valb)
			return true;
		else
			return false;

	}
	else if(a.type==2){

		if(a.bl <= b.bl)
			return true;
		else
			return false;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;
		int k = min(a.my_vector.size(),b.my_vector.size());

		for (int i =0;i<k;i++){
			if (!(compare_Vars_lesseq(a.my_vector[i] , b.my_vector[i])))
				return false;
		}
		if(a.my_vector.size()<=b.my_vector.size())
			return true;
		else
			return false;
	}
	else{
		return false;
	}

	}



	bool compare_Vars_more(Var a,Var b){

	if(a.type!=b.type ) {
		return false;
	}



	if(a.type == 0){
		if((a.s).compare(b.s)>0)
			return true;
		else 
			return false;
	}
	else if(a.type ==1 ){			

		if(a.valb > b.valb)
			return true;
		else
			return false;

	}
	else if(a.type==2){

		if(a.bl > b.bl)
			return true;
		else
			return false;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;
		int k = min(a.my_vector.size(),b.my_vector.size());
		int num =0;
		for (int i =0;i<k;i++){
			if (!(compare_Vars_moreeq(a.my_vector[i] , b.my_vector[i])))
				return false;
			if(compare_Vars_more(a.my_vector[i] , b.my_vector[i]))
				num++;
		}

		if(a.my_vector.size()>b.my_vector.size())
			return true;
		else if((a.my_vector.size()==b.my_vector.size()) && num>0)
			return true;
		else
			return false;
		
	}
	else{
		return false;
	}

	}


	bool compare_Vars_moreeq(Var a,Var b){

	if(a.type!=b.type ) {
		return false;
	}

	if(a.type == 0){
		if((a.s).compare(b.s)>=0)
			return true;
		else 
			return false;
	}
	else if(a.type ==1 ){			

		if(a.valb >= b.valb)
			return true;
		else
			return false;

	}
	else if(a.type==2){

		if(a.bl >= b.bl)
			return true;
		else
			return false;
	}
	else if(a.type == 3 || a.type == 4 || a.type == 5){
		int i=0;

		int k = min(a.my_vector.size(),b.my_vector.size());

		for (int i =0;i<k;i++){
			if (!(compare_Vars_moreeq(a.my_vector[i] , b.my_vector[i])))
				return false;
		}
		if(a.my_vector.size()>=b.my_vector.size())
			return true;
		else
			return false;
	}
	else{
		return false;
	}

	}
