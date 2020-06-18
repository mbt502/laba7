#include <string>
#include <stdexcept>
#include "list.h"
#include "flower.h"
#include "bouquet.h"

Bouquet::Bouquet(bool is_in_water_)
{
    is_in_water = is_in_water_;
    Flowers_All_To();
}

void Bouquet::Add_Flower(const Flower flower)
{
    bouquet_list.push_back(flower);
}

void Bouquet::Remove_Flower(size_t index)
{
    if (index > bouquet_list.size()) throw invalid_argument("no more than the number of flowers");
    index--;
    auto element = bouquet_list.begin();
    advance(element, index);

    bouquet_list.erase(element);
}

void Bouquet::Flowers_All_To()
{
    for (Flower flower : bouquet_list)
    {
        if (flower.Is_In_Water() != is_in_water) flower.Water_Move();
    }
}

void Bouquet::Bouquet_Water_Move()
{
   
    for (Flower flower : bouquet_list)
    {
        flower.Water_Move();
    }
    is_in_water == !is_in_water;
}

double Bouquet::Get_Base_Price()
{
    double base_price = min_price;

    for (Flower flower : bouquet_list)
    {
        base_price += flower.Get_Base_Price();
    }
    return base_price;
}

double Bouquet::Get_Real_Price()
{
    double real_price = min_price;

    for (Flower flower : bouquet_list)
    {
        real_price += flower.Get_Real_Price();
    }

    return real_price;
}

double Bouquet::State()
{
    double state = min_state;
    size_t count = 0;
    for (Flower flower : bouquet_list)
    {
        count += 1;
        state += flower.Get_State();
    }

    return state / count;
}

size_t Bouquet::Count_Flowers()
{
    return bouquet_list.size();
}

size_t Bouquet::Count_Spoiled()
{
    size_t count_spoiled = 0;

    for (Flower flower : bouquet_list)
    {
        if (flower.Get_State() == 0) count_spoiled++;
    }
    return count_spoiled;
}

void Bouquet::Change_Speed(double t)
{
    for (Flower flower : bouquet_list)
    {
        flower.Change_Speed(t);
    }
}