#include <iostream>
#include <fstream>

#include<iostream>
using namespace std;

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)
#define nil NULL

typedef int infotype;
typedef struct elmtSingle *adrSingle;

struct elmtSingle{
    infotype info;
    adrSingle next;
};

struct List{
    adrSingle first;
};

void create_list(List &L){
    first(L) = nil;
}

adrSingle alokasi(infotype x){
    adrSingle p = new elmtSingle;
    info(p) = x;
    next(p) = nil;
    return p;
}

void insertLast(List &L, adrSingle p){
    adrSingle q;
    if (first(L) == nil){
        first(L) = p;
    }else {
        q = first(L);
        while (next(q) != nil){
            q = next(q);
        }
        next(q) = p;
    }
}

void add_N_data(List &L){
    adrSingle p;
    infotype x;
    for(int i=0;i<5;i++){
        cin >> x;
        p = alokasi(x);
        insertLast(L, p);
    }
}

void sortingAscending(List &L){
    adrSingle current = first(L);
    adrSingle index = nil;

    if (first(L) == nil){
        return;
    }else{
        while (current != nil){
            index = next(current);

            while (index != nil){
                if (info(current) > info(index)){
                    infotype temp = info(current);
                    info(current) = info(index);
                    info(index) = temp;
                }
                index = next(index);
            }
            current = next(current);
        }
    }
}

void sortingDescending(List &L){
    adrSingle current = first(L);
    adrSingle index = nil;

    if (first(L) == nil){
        return;
    }else{
        while (current != nil){
            index = next(current);

            while (index != nil){
                if (info(current) < info(index)){
                    infotype temp = info(current);
                    info(current) = info(index);
                    info(index) = temp;
                }
                index = next(index);
            }
            current = next(current);
        }
    }
}

void show(List L){
    if (first(L) != nil) {
        adrSingle p = first(L);
        while (p != nil){
            cout << info(p) << " ";
            p = next(p);
        }
        cout << endl;
    }
}

adrSingle deleteLast(List &L){
    adrSingle p, q;
    if (first(L) == nil){
        p = nil;
    }else if (next(first(L)) == nil){
        p = first(L);
        first(L) = nil;
    }else{
        q = first(L);
        p = first(L);
        while(next(p) != nil){
            q = p;
            p = next(p);
        }
        next(q) = nil;
    }
    return p;
}

int main()
{
    string y;
    List L;
    create_list(L);
    while (y != "#"){
        cin >> y;
        add_N_data(L);
        if (y == "DECREASING"){
            sortingDescending(L);
            show(L);
            while (first(L) != nil){
                deleteLast(L);
            }
            cout << endl;
        }else if (y == "INCREASING"){
            sortingAscending(L);
            show(L);
            while (first(L) != nil){
                deleteLast(L);
            }
            cout << endl;
        }
    }
}
