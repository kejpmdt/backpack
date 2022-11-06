#ifndef _MPAIR_H
#define _MPAIR_H
template<class A,class B>struct mpair{mutable A first;mutable B second;bool operator <(const mpair&o)const{return first>o.first;}};
#endif