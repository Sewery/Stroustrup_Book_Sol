#include "../../std_lib_facilities.h"

class Point {
public:
    Point(double x, double y);
    Point();
    double x() const { return m_x; }
    double y() const { return m_y; }
private:
    double m_x;
    double m_y;
};
Point::Point(): m_x{0}, m_y{0} {  };
Point::Point(double x, double y)
: m_x{x}, m_y{y} {  };

ostream& operator<<(ostream& os , Point p){
    os << '(' << p.x() << ", " << p.y() << ')' << '\n';
    return os;
}
istream& operator>>(istream& is , Point& p){
    double x,y;
    char k , k1 , k2;
    is>> k >> x >>k1>> y >> k2;
    if(k=='(' && k1==',' && k2==')')  p = Point(x,y);
    else is.clear(ios_base::failbit);
    return is;
}
int fibo(int n){
	return n<=2?1:fibo(n-1)+fibo(n-2);
}
bool operator==(const  Point &a,const Point &b){
    return a.x()== b.x() && a.y()==b.y();
}

bool operator==(const  vector<Point> &a,const vector<Point> &b){
    int o =0;
    for(auto la: a){
        if(la==b[o]){
            return false;
        }
        o++;

    }
    return a.size()==b.size();
}

int main()
try{
    vector<Point> orignal_points;
    cout<<"Insert seven points\n";
    int i= 0;
    
    while(i!=4){
        Point p;
        cin>>p;
        orignal_points.push_back(p);
        if(cin.fail()){
            cout<<"Not a point\n";
            cin.clear();
           break;
        }
                
            i++;   
        
        
       
       
    }
    
    cout<<"Fibonacci sum="<<fibo(10)<<"\n";
    for(auto k:  orignal_points){
        cout<<k;
    }
    cout<<"Daje  dane do pliczek.txt \n";
    ofstream ost{"pliczek.txt"};
    if(!ost) error("Nie mozna odtworzyc pliku niestety \n");
    for(auto k: orignal_points){
        ost<<k;
    }

    ost.clear();
    ost.close();
    cout<<"Biore dane z pliczek.txt \n";
    ifstream ist{"pliczek.txt"};
    if(!ist) error("Nie mozna odtworzyc pliku niestety \n");
    vector<Point> points;
    for(Point point;ist>>point;){
        if(ist){
                 points.push_back(point);
        }
        else {
            cout << "Not a point!\n";
            ist.clear();
            ist.ignore(numeric_limits<streamsize>::max(), '\n');
        }
       
    }
    cout<<points.size()<<'\n';
     for( const Point& k:  points){
        cout<<k;
    }
    if(!(points== orignal_points)){
        error("Cos sie pojebalo");
    }
    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}