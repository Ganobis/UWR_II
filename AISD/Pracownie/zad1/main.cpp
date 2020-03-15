#include <iostream>
#include <vector>

int bricks[10001];
short counter;
bool is_use[10001];

bool find_x(std::vector<int64_t> v[10001], short wanted){
    if (wanted == 0 && counter != 0)
        return true;
    else{
        counter++;
        if (!is_use[wanted])
            return false;
        else{
            is_use[wanted] = false;
            int x = v[wanted].size();
            for (int i = 0; i < x; ++i)
            {
                if (find_x(v, v[wanted][i] >> 32))
                {
                    counter--;
                    bricks[counter] = v[wanted][i];
                    if(bricks[counter] == 0)
                        bricks[counter] = -1;
                    return true;
                }
                else
                    counter--;
            }
        }
    }
    return false;
}

bool is_sidewalk(int n, short data[][3]){
    std::vector<int64_t> end_bridge[10001];
    int64_t temp;
    for (int i = 0; i < n ; i++) {
        is_use[data[i][0]] = true;
        temp = data[i][2];
        temp <<= 32;
        temp += i;
        end_bridge[data[i][0]].push_back(temp);
    }
    if(find_x(end_bridge, 0))
        return true;
    return false;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    short data[n][3];
    for (int i = 0; i < n; ++i)
        std::cin>>data[i][0]>>data[i][1]>>data[i][2];
    if(!is_sidewalk(n, data)){
        std::cout<<"BRAK";
        return 0;
    }
    n = 0;
    while(bricks[n] != 0)
        n++;
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        if (bricks[i] == -1)
            std::cout << data[0][0] << " " << data[0][1] << " " << data[0][2] << "\n"; 
        else
            std::cout << data[bricks[i]][0] << " " << data[bricks[i]][1] << " " << data[bricks[i]][2] << "\n";
    }
    return 0;
}