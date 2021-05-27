#pragma once
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
template<typename K, typename V>
class Assoc {
public:

void insert(K key, V value) {
	vec.push_back(key);
	map.insert({key,value});
}


V &operator[](K key) {
	if(vec.empty()) {
		vec.push_back(key);
	}
	else if(!vec.empty() && std::find (vec.begin(), vec.end(),key) == vec.end()) {
	vec.push_back(key);
	}
	return map[key];
}

V operator[](K key) const {
	return map[key];
}

bool contains(K key)const {
	return (!vec.empty() && std::find (vec.begin(), vec.end(),key) != vec.end());
}


void print(std::string chain) {
	for(auto a: vec){
			std::cout<<"--- "<<chain<<"--- klucz: "<<a<<" wartosc: "<<map[a]<<"\n";
	}
}



private:
mutable std::map<K,V> map;
std::vector<K> vec;
};


std::string print(bool bol ){
	std::string chain ="";
	if(bol){
		chain+="Znaleziono";
	}
	else{
		chain+="Nie znaleziono";
	}
	return chain;
}

std::string operator*(std::string chain , int n){
	std::string dummy ="";
	for(int i =0;i<n;i++){
		dummy +=chain;
	}
	return dummy;
}

std::string operator*(int n,std::string chain){
	std::string dummy ="";
	for(int i =0;i<n;i++){
		dummy +=chain;
	}
	return dummy;
} 