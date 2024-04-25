#include<iostream>



class A{
protected://только для наследования, можео изменять только в дочернем классе и нигде больше, из мейна доступа нет
    int _y;

private:
int _x;
void fun2(){
    std::cout<<"fun2"<<::std::endl;
}

public:
    int _z;
    A(){

        std::cout<<"default constructor a"<<std::endl;
    }
    A(int x){
        _x=x;
        std::cout<<"x constructor a"<<std::endl;

    }

    void fun1(){
        std::cout<<"fun1 a"<<::std::endl;


    }

};


class B:public A{//private закрывает доступ ко всем полям род класса из мейна, но не из 1го дочернего класса, к следующим насл доступа нет
private://protected закрывает доступ ко всем полям род класса из мейна, но не из остальных дочерних классов
int _xB;


protected:
int _yB;

public:
    int _zB;
    B(){
        _z=10;
        _y=10;
        
        
        //приватные поля родительского класса нельзя менять даже при привате
        std::cout<<"default constructor b"<<std::endl;
    }

    B(int x):A(x){
        std::cout<<"x constructor b"<<std::endl;

    }

    void fun1(){
        std::cout<<"fun1 b"<<::std::endl;


    }
    
};


class C : public B{
    public:
    C(){
        _y=10;
        _z=10;
        _yB=456;
        _zB=45;
        std::cout<<"default constructor c"<<std::endl;
    }





};

class AA{


};

class BB:public AA{


};



int main(){
    //C c;

    A c =B(10);
    
    

    

    return 0;
}