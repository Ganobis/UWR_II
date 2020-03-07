#include <iostream>
#include <vector>

bool is_sidewalk(int n, short data[][3]){
    std::vector<bool> is_use;
    if(n > 10000)
        is_use.resize(10000);
    else
        is_use.resize(n);
    std::cout<<is_use[0]<<is_use[450]<<is_use[9999];
    return false;
}

int main(){
    int n;
    std::cin>>n;
    short data[n][3];
    //for (int i = 0; i < n; ++i)
    //    std::cin>>data[i][0]>>data[i][1]>>data[i][2];
    if(!is_sidewalk(n, data))
        std::cout<<"BRAK";
    return 0;
}

