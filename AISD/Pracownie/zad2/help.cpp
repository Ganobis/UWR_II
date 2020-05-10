#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct Punkt
{
public:

    double x;
    double y;
    Punkt(int x,int y)
    {
        this->x=x;
        this->y=y;
    };
    Punkt() : x(0.0), y(0.0) {};
};

struct odp
{
    Punkt a;
    Punkt b;
    Punkt c;
    double obwod;
};
bool porownaniex(Punkt p1, Punkt p2)
{
        return (p1.x<p2.x);
}

bool porownaniey(Punkt p1, Punkt p2)
{
        return (p1.y<p2.y);
}

double odleglosc(Punkt p1,Punkt p2)
{
    double jeden=pow((p1.x-p2.x),2);
    double dwa=pow((p1.y-p2.y),2);
    return sqrt(jeden+dwa);
}



odp min_obw(vector<Punkt> &pos_X,vector<Punkt> &pos_Y,int l, int r)
{
    odp odpowiedz;
    odpowiedz.obwod=124132423523;
    double obwod;

    cout<<l<<" "<<r<<endl;

    if (r-l<6)
    {
        for (int i=l;i<pos_X.size()-2;i++)
        {
            for (int j=i+1;j<pos_X.size()-1;j++)
            {
                for (int k=j+1;k<pos_X.size();k++)
                {
                    obwod=odleglosc(pos_X[i],pos_X[j])+odleglosc(pos_X[j],pos_X[k])+odleglosc(pos_X[k],pos_X[i]);
                    if (obwod<odpowiedz.obwod)
                    {
                        odpowiedz.obwod=obwod;
                        odpowiedz.a=pos_X[i];
                        odpowiedz.b=pos_X[j];
                        odpowiedz.c=pos_X[k];
                    }
                }
            }
        }
        cout<<"GIT"<<endl;
        return odpowiedz;
    }
    else
    {
        int mid;
        odp o1,o2;
        mid=(l+r)/2;
        vector<Punkt> YLewe;
        vector<Punkt> YPrawe;
        for (int i=0;i<pos_Y.size();i++)
        {
            if (pos_Y[i].x<=pos_X[mid].x)
            {
                YLewe.push_back(pos_Y[i]);
            }
            else
            {
                YPrawe.push_back(pos_Y[i]);
            }
        }
        o1=min_obw(pos_X,YLewe,l,mid);
        o2=min_obw(pos_X,YPrawe,mid+1,r);
        if (o1.obwod<odpowiedz.obwod)
        {
            odpowiedz=o1;
        }
        else if (o2.obwod<odpowiedz.obwod)
        {
            odpowiedz=o2;
        }
        double d=odpowiedz.obwod/2;
        vector<Punkt> Y_prim;
        for (int i=0;i<pos_Y.size();i++)
        {
            if (pos_Y[i].x>pos_X[mid].x-d && pos_Y[i].x<pos_Y[mid].x+d)
            {
                cout<<"jestem";
                Y_prim.push_back(pos_Y[i]);
                cout<<"pushnolem";
            }
        }
        cout<<"Y_prim size: "<<Y_prim.size()<<endl;
        if (Y_prim.size() < 3)
        {
            return odpowiedz;
        }
        for (int i=0;i<Y_prim.size()-2;i++)
        {
            cout<<i<<endl;
            for (int j=i+1; (j<Y_prim.size()-1) && ((Y_prim[j].y - Y_prim[i].y) < d);j++)
            {
                cout<<i<<" "<<j<<endl;
                for (int k=j+1;(k<Y_prim.size()) && ((Y_prim[k].y - Y_prim[j].y) < d);k++)
                {
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    obwod=odleglosc(Y_prim[i],Y_prim[j])+odleglosc(Y_prim[j],Y_prim[k])+odleglosc(Y_prim[k],Y_prim[i]);
                    if (obwod<odpowiedz.obwod)
                    {
                        odpowiedz.obwod=obwod;
                        odpowiedz.a=Y_prim[i];
                        odpowiedz.b=Y_prim[j];
                        odpowiedz.c=Y_prim[k];
                    }
                }
            }
        }

    return odpowiedz;
    }
}


int main()
{
    int n;
    double x,y;
    cin>>n;
    vector<Punkt> punkty;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        cin>>y;
        punkty.push_back(Punkt(x,y));
    }
    vector<Punkt> Pos_X = punkty;
    vector<Punkt> Pos_Y = punkty;
    sort(Pos_X.begin(),Pos_X.end(),porownaniex);
    sort(Pos_Y.begin(),Pos_Y.end(),porownaniey);
    odp odpowiedz;
    odpowiedz=min_obw(Pos_X,Pos_Y,0,Pos_X.size()-1);
    cout<<odpowiedz.a.x<<" "<<odpowiedz.a.y<<endl;
    cout<<odpowiedz.b.x<<" "<<odpowiedz.b.y<<endl;
    cout<<odpowiedz.c.x<<" "<<odpowiedz.c.y<<endl;
}