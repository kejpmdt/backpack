#ifndef _SQUAD_H
#define _SQUAD_H
template<class T>
class squad {
private:
    T& operator()(const int x, const int y) {
        return data[x][y];
    }
    int length, width;
    struct u{int length,width;};
    T** data;
public:
    u* operator ->()const{
        return new u({length,width});
    }
    squad(int l, int w, T** inp= nullptr) : length(l), width(w) {
        data= new T*[length];
        for (int i= 0; i < length; ++i) data[i]= new T[width];
        if (inp == nullptr)
            for (int i= 0; i < length; ++i)
                for (int j= 0; j < width; ++j) data[i][j]=0;
        else
            for (int i= 0; i < length; ++i)
                for (int j= 0; j < width; ++j) data[i][j]= inp[i][j];
    }
    T* operator[](const int x) const {
        return  data[x] ;
    }
    void resize(int l, int w) {
        length= l, width= w;
        delete data;
        data= new T*[length];
        for (int i= 0; i < length; ++i) data[i]= new T[width];
        for (int i= 0; i < length; ++i)
            for (int j= 0; j < width; ++j) data[i][j]=0;
    }
    friend squad operator*(const squad& a, const squad& b) {
        if (a.width != b.length) exit(1);
        squad res(a.length, b.width);
        for (int i= 0; i < a.length; ++i) {
            for (int j= 0; j < b.width; ++j) {
                res(i, j)= 0;
                for (int k= 0; k < a.width; ++k) 
                    res(i, j)= (res(i, j) + a[i][k] * b[k][j]) ;
            }
        }
        return res;
    }
    friend void operator *=(squad&a,const squad&b){
        a=a*b;
    }
};
#endif