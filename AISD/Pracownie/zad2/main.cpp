#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <limits>



struct point
{
    int x;
    int y;
};

int n;
point pX[500000];
point pY[500000];

point a;
point b;
point c;
double obwod;

void bf(int left, int right)
{
    double temp;
    for(int i = left; i < right - 2; i++)
    {
        for (int j = i + 1; j < right - 1; j++)
        {
            for (int k = j + 1; k < right; k++)
            {
                temp = (sqrt(pow((pX[i].x - pX[j].x), 2) + pow((pX[i].y - pX[j].y), 2)) 
                       + sqrt(pow((pX[k].x - pX[j].x), 2) + pow((pX[k].y - pX[j].y), 2)) 
                       + sqrt(pow((pX[i].x - pX[k].x), 2) + pow((pX[i].y - pX[k].y), 2)));
                if (obwod > temp)
                {
                    a.x = pX[i].x;
                    a.y = pX[i].y;
                    b.x = pX[j].x;
                    b.y = pX[j].y;
                    c.x = pX[k].x;
                    c.y = pX[k].y;
                    obwod = temp;
                }
            }
        }
    }
}

void bf_vec(std::vector<point> v){
    double temp;
    int zakres = v.size();
    for(int i = 0; i < zakres - 2; i++)
    {
        for (int j = i + 1; j < zakres - 1; j++)
        {
            for (int k = j + 1; k < zakres; k++)
            {
                temp = (sqrt(pow((v[i].x - v[j].x), 2) + pow((v[i].y - v[j].y), 2)) 
                       + sqrt(pow((v[k].x - v[j].x), 2) + pow((v[k].y - v[j].y), 2)) 
                       + sqrt(pow((v[i].x - v[k].x), 2) + pow((v[i].y - v[k].y), 2)));
                if (obwod > temp)
                {
                    a.x = v[i].x;
                    a.y = v[i].y;
                    b.x = v[j].x;
                    b.y = v[j].y;
                    c.x = v[k].x;
                    c.y = v[k].y;
                    obwod = temp;
                }
            }
        }
    }
}

void solve_fiu(std::vector<point> v){
    int s = v.size();
    int h = (s-1)/2;
    int mid; 
    if(! (s-1 % 2))
        mid = v[h + 1].y;
    else
        mid = (v[h].y + v[h +1].y)/2;

    std::vector<point> v2;
    for (int i = 0; i < h; ++i)
    {
        v2[i] = v[i];
    }
    std::vector<point> v3;
    for (int i = h; i < s; ++i)
    {
        v3[i] = v[i];
    }
    if(h < 6){
        bf_vec(v2);
    }
    else{
        solve_fiu(v2);
    }
    if(s-1 - h < 6)
        bf_vec(v3);
    else{
        solve_fiu(v3);
    }
    std::vector<point> v5;
    for (int i = 0; i < n; i++)
    {
        if(!(mid + obwod/2 > pY[i].y || mid - obwod/2 < pY[i].y)){
            v5.push_back(pY[i]);
        }
    }
    if(v5.size() >= 3)
        solve_fiu(v5);
}


bool sortX(point p1, point p2){
    return (p1.x < p2.x);
}

bool sortY(point p1, point p2){
    return (p1.y < p2.y);
}

void solve(int left, int right){
    int h = (right + left)/2;
    int mid; 
    if(!(left + right)%2)
        mid = pX[h + 1].y;
    else
        mid = (pX[h].y + pX[h +1 ].y)/2;

    if(right - left - h < 6)
        bf(left, h);
    else{
        solve(left, h);
    }
    if(right - left - (right + left - h) < 6)
        bf(h + 1, right);
    else{
        solve(h + 1, right);
    }
    std::vector<point> v;
    for (int i = 0; i < n; i++)
    {
        if(!(mid + obwod/2 > pY[i].y || mid - obwod/2 < pY[i].y)){
            v.push_back(pY[i]);
        }
    }
    if(v.size() >= 3)
        solve_fiu(v);
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    obwod = DBL_MAX;
    n = 3;
    int x, y;

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        pX[i].x = x;
        pX[i].y = y;
        pY[i].x = x;
        pY[i].y = y;
    }

    a.x = pX[0].x;
    a.y = pX[0].y;
    b.x = pX[1].x;
    b.y = pX[1].y;
    c.x = pX[2].x;
    c.y = pX[2].y;

    if(n < 6)
        bf(0, n - 1);
    else{
        std::sort(pX, pX+n, sortX);
        std::sort(pY, pY+n, sortY);
        solve(0, n - 1);
    }

    std::cout << a.x << " " << a.y << '\n';
    std::cout << b.x << " " << b.y << '\n';
    std::cout << c.x << " " << c.y << '\n';
}