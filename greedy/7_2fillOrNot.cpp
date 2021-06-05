#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float distance_D;
float tank;
float averageD;
int station_num;

struct station
{
    float price;
    float location;

    station();
    station(float p, float l);
    void dump();
};

station::station(){
    price = 0;
    location = 0;
}

station::station(float p, float l){
    price = p;
    location = l;
}

void station::dump(){
    printf("price:%f, loc:%f\n", price, location);
}

bool compare(station s1, station s2){
    if (s1.location < s2.location) return true;
    else return false;
}

int main(){
    //init
    scanf("%f %f %f %d", &tank, &distance_D, &averageD, &station_num);
    vector<station> stations;

    for (int i=0; i<station_num; i++){
        float in_p;
        float in_d;
        scanf("%f%f", &in_p, &in_d);
        station tmp(in_p, in_d);
        stations.push_back(tmp);
    }
    sort(stations.begin(),stations.end(),compare);
    station End(0, distance_D);
    stations.push_back(End);
    station_num ++;
    //debug
    for (int i=0; i<station_num; i++){
        stations[i].dump();
    }

    //simulate
    float sum_price = 0;
    float current_loc = 0;
    float current_tank_oil = 0;
    float tank_max_mile = tank * averageD;

    float single_price = 0;
    float single_loc = -1;
    float left_in_tank = 0;

    printf("\n%f\n", stations[0].location);
    if (stations[0].location > 0) {
        printf("error");
        return 0;
    }
    float current_price = stations[0].price;
    float max_loc;
    if (stations[stations.size()-2].location + tank_max_mile < distance_D ) {
        float maxL = tank_max_mile;
        int i = 0;
        while (maxL >= stations[i].location)
        {   maxL = stations[i].location + tank_max_mile; 
            i++;
        }
        
        printf ("%.2f", maxL);
        return 0;
    }

    else {
        for (int i=0; i<station_num && current_loc<distance_D; i++){
            printf("loop\n");
            max_loc = current_loc + tank_max_mile;

            //开到下一个比该站价格低的站
            if (stations[i].location <= max_loc && stations[i].price <= current_price){
                //use all the left gas
                current_loc += left_in_tank * averageD;
                left_in_tank = 0;
                

                //load gas to move to this station
                sum_price += (stations[i].location - current_loc) * current_price / averageD;
                printf("expenditure:%f, miles:%f price:%f\n", sum_price, stations[i].location - current_loc, current_price);
                current_loc = stations[i].location;
                current_price = stations[i].price;
                single_price = 0;
                single_loc = -1;
                max_loc = current_loc + tank_max_mile;
                
            }

            else if (stations[i].price > current_price && stations[i].location <= max_loc ) {
                //record the info to in case that no stations has the lower price
                if (single_price == 0) { //init
                    single_price = stations[i].price;
                    single_loc = stations[i].location;

                }
                else {
                    if (stations[i].price < single_price) {
                        single_price = stations[i].price;
                        single_loc = stations[i].location;

                    }
                }


            }

            else if (stations[i].location > max_loc) {
                // load all the tank at the beginning and drive to the lowest station along the road
                float fill_num = tank - left_in_tank;
                sum_price += fill_num * current_price;
                current_price = single_price;
                left_in_tank = tank - (single_loc - current_loc)/averageD;
                current_loc = single_loc;
                single_loc = -1;
                single_price = 0;
                i--;
            }

            printf("current_price:%f, current_loc:%f, max_loc:%f, sum_price:%f, left_gas:%f\n", current_price, current_loc, max_loc, sum_price, left_in_tank);
        }

    
    }

    
    return 0;
}