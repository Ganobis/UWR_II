#include <iostream>
#include <vector>

bool is_sidewalk(int n, short data[][3]){
    bool is_use[10000];
    std::vector<short[3]> end_bridge[10000];
    short temp[3];
    for (int i = 0; i < n ; i++) {
        temp[0]=0;
        temp[1]=data[i][1];
        temp[2]=data[i][2];
        end_bridge[data[i][0]].push_back(temp);
    }
    return false;
}

int main(){
    int n;
    std::cin>>n;
    short data[n][3];
    for (int i = 0; i < n; ++i)
        std::cin>>data[i][0]>>data[i][1]>>data[i][2];
    if(!is_sidewalk(n, data))
        std::cout<<"BRAK";
    return 0;
}

