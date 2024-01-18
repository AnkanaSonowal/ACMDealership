#include <iostream>
#include<vector>
using namespace std;

class Car{
private:
    int id;
    int model;
    int type;
    int color;

public:
    Car(int id, int model, int type, int color){
        this->id=id;
        this->model=model;
        this->type=type;
        this->color=color;
    }
    int getId(){
        return id;
    }
};

class Dealership{
public:
    vector<Car> carList;
    int buyCar(Car car);
    void sellCar(Car car);
};

int Dealership::buyCar(Car car) {
    carList.push_back(car);
    return carList.size();
}
void Dealership::sellCar(Car car) {
    int src = car.getId();
    int dest;
    int index = -1;

    for(int i =0 ;i < carList.size();i++){
        dest = carList[i].getId();
        if(src == dest){
            index=i;
            break;
        }
    }

    if(index == -1){
        cout<<"Invalid Car with id: "<< car.getId() <<" not present"<<endl;
    }else{
        carList.erase(carList.begin()+index);
        cout<<" Sold Car at position "<<index<<endl;
    }
}

int main() {

    Car c1(1,201,301,401);
    Car c2(2,202,302,402);
    Car c3(3,203,303,403);
    Car c4(4,204,304,404);
    Car c5(5,205,305,405);

    Dealership deal;
    cout<<"After adding car: "<<deal.buyCar(c1)<<endl;
    cout<<"After adding car: "<<deal.buyCar(c2)<<endl;
    cout<<"After adding car: "<<deal.buyCar(c3)<<endl;
    cout<<"After adding car: "<<deal.buyCar(c4)<<endl;
    cout<<"After adding car: "<<deal.buyCar(c5)<<endl;
    Car c6(6,206,306,406);
    deal.sellCar(c6);
    deal.sellCar(c3);

    cout<<"After selling car c3"<<endl;
    for(int i=0;i<deal.carList.size();i++){
        cout<<"Id: "<<deal.carList[i].getId()<<" present"<<endl;
    }


    return 0;
}
