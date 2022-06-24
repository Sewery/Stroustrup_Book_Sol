
/*
	Simple calculator 
	
	History:
		
		Corrected by: Seweryn Tasior, 5.02.2021
	Author: Bjarne Stroustrup


	This program is a implementation of calculator with basic expressions.
	It takes input from stream cin and print result to stream cout

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.


	
*/

#include "../../std_lib_facilities.h"
//Token keeps all input data
class Token {
	public:
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n): kind(ch), name(n){}
};
// This class proccess data
class Token_stream {
	bool full;
	Token buffer;
	istream isa;
public:
	Token_stream() :full(0), buffer(0) {}//, &istream{}

	Token get();
	void putback(Token t){buffer =t; full=true;};

	void ignore(char);
};
// constans literals responsible for operations
const char number = '8';    // t.kind==number means that t is a number Token
const char quit   = 'q';    // t.kind==quit means that t is a quit Token
const char print  = ';';    // t.kind==print means that t is a print Token
const char name   = 'a';    // name token;
const char decl    = 'D'; 
const char ab = 'b';
const char let = 'l';   // declaration token
const char sq = '$';
const char po = '^';
const char c = '@';
const char hel = '[';
const char absv= '|';
const string declkey = "#";// declaration keyword 
const string prompt  = "> ";
const string letting = "letbe";
const string help = "help";
const string result  = "= ";
const string con = "const"; // used to indicate that what follows is a result

Token Token_stream::get()
//Takes char from input stream and creates Token object3 
{
	if (full) { full = false; return buffer; }
	char ch;
	cin>>ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case print:
	case '=':
	case sq:
	case po:
	case quit:
	case absv:
	case ',':
		return Token(ch); //Return operators as tokens
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
	cin.putback(ch);
	double val;
	cin >> val;
	return Token(number, val);//Returns token object where number is represented by '8' char and val is a value of loaded number  
	}
	default:
		if (isalpha(ch)|| ch=='#'|| ch=='_' || ch=='|') { //Checks if ch is letter and procces it
			string s;
			s += ch;
			while (cin.get(ch) && ( isalpha(ch) || isdigit(ch) || ch=='#' || ch=='_')) s += ch;//Checks is it a correct name of variable
			cin.putback(ch);
			if (s == declkey) return Token(decl);
			if(s== letting) return Token(let);
			if(s == con) return Token(c);
			if(s==help) return Token(hel);
			return Token(name, s);
		}
		
		error("Bad token");
	}
}
//Eats garbage input
void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch =0;
	while (cin >> ch)
		if (ch == c) return;
}


 
//It stores created by user variables
class Variable {
	
	public:
	string name;
	double value;

	Variable(string n, double v) :name(n), value(v) {

	}
	//Variable(string n, const double v) :name(n), value(v) {}
};

class Symbol_table{
		vector<Variable> names;
			
		public:
			vector<Variable> constans;
			double get_value(string s);
			void set_value(string s, double d);
			bool is_declared(string s);
			double define_name(string var, double val);
};
//get value of variable by reference
double Symbol_table::get_value(string s)
{
	for (int i = 0; i < names.size(); ++i){
		if (names[i].name == s) return names[i].value;}
	for (int i = 0; i < constans.size(); ++i){
		if (constans[i].name == s) return constans[i].value;}	
	error("get: undefined name ", s);
}
//Set value of variable by reference
void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s ) {
			names[i].value = d;
			return;
		}
	error("set: undefined name  or constant variable-", s);
}
//Check if variable with the same name, was earlier declareted
bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i){
		if (names[i].name == s) return true;}
	for (int i = 0; i < constans.size(); ++i){
		if (constans[i].name == s) return true;}
	return false;
}

Symbol_table ta;
double expression(Token_stream&);
//Responsible for procces of (), numbers, - and +s
double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '-'://It only chnage the sign of s(7number
		return -primary(ts);
	case '+':
		return primary(ts);
	case number:
		return t.value;
	case name:
		return ta.get_value(t.name);
	case sq:{
		char e = ts.get().kind;
		if(e!='(')error("Zle wpisales funkcje");
		double d = primary(ts);
		if(d<0)error("positive number expected");
		char f = ts.get().kind;
		if(f!=')')error("Zle wpisales funkcje");
		return sqrt(d);
	}
	case po:{
		char e = ts.get().kind;
		if(e!='(')error("Zle wpisales funkcje");
		double d = primary(ts);
		char k = ts.get().kind;
		if(k!=',')error("Zle wpisales funkcje");
		int i = narrow_cast<int>(primary(ts));
		char f = ts.get().kind;
		if(f!=')')error("Zle wpisales funkcje");
		return pow(d,i);
	}	
	case '|':
	{	double d = expression(ts);
		t = ts.get();
		if (t.kind != '|') error("'|' expected");
		return abs(d);
	}
	default:
		error("primary expected");
	}
}
//Responsible for procces of %, * and /
double term(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();
	while (true) {
			
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			t = ts.get();
			break;
		case '/':
		{	double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
		  	t = ts.get();
			break;
		}
		case'%':{
			int i1= narrow_cast<int>(left);
			int i2=narrow_cast<int>(term(ts));
			if(i2==0) error("%: dzieleni przez zero.");
			left= i1%i2;
			t =ts.get();
			break;


		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double Symbol_table::define_name(string var, double val)
    // add (var,val) to var_table
{
    if (is_declared(var)) error(var," declared twice");
    names.push_back(Variable(var,val));
    return val;
}
//Responsible for procces of + and - (add and substract)
double expression(Token_stream& ts)
{
	double left = term(ts);
	Token t = ts.get();
	while (true) {
		
		switch (t.kind) {
		case '+':
			left += term(ts);
			 t = ts.get();
			break;
		case '-':
			left -= term(ts);
			 t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}
//Procces declarations
double declaration(Token_stream& ts)
{

	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);

	double d = expression(ts);
	ta.define_name(var_name,d);
	return d;
}
double change(Token_stream& ts){
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression(ts);
	try{
		ta.set_value( var_name,d);

	}catch(exception& e) {
		cerr << "exception: " << e.what() << endl;
		return -1;
	}
	
	return d;

}
double consta(Token_stream& ts){
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression(ts);
	if(!ta.is_declared(var_name)){ta.constans.push_back(Variable(var_name,d));}
	else{error("Stala jest o takiej nazwie juz zadeklarowana");}
	return d;

}
//Responsible for variables
double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case decl:
		return declaration(ts);
	case let:
		return change(ts);
	case c:
		return consta(ts);
	case hel:
		cout<<"Pomoc\nOperacje w programie ():\n -dodawanie np. 7+9;\n -odejmowanie np. 9-8;\n -mnozenie np. 7*9;\n -dzielenie np. 7/9;\n -modulo np. 7%9;\n -potegowanie np. ^(8,2) [wynik bedzie 64];\n -pierwiastkowanie drugiego stopnie np. s(9);\n -deklarowanie zmiennych ktorych potem mozna uzyc w programie np. # x = 50;\n -zmienianie wartoscie zadeklarowanym zmiennych np. letbe x = 20;\n -tworzenie stalych np. const pi =3.14;\n -za kazdym razem dawaj po dzialaniu dawaj ; by uzyskac wynik\n -napisz q; aby wyjsc z programu\n";
		return -1;	
	default:
		ts.putback(t);
		return expression(ts);
	}
}
//Cleaning code
void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}



void calculate(Token_stream& ts)// Loop which calculates results of expressions
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		if(t.kind !=hel){
			ts.putback(t);
			cout << result << statement(ts) << endl;
		}else{
		ts.putback(t);
		double ko=statement(ts);
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main(){


try {
	Token_stream ts;
	ta.define_name("k",1000.0);
	calculate(ts);
	keep_window_open(); 
	return 0;
	
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	 keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "exception\n";
	 keep_window_open("~~");
	return 2;
}
}