#pragma once
#include "Person.h"


class Woman: public Person{
	public:
		Woman(std::string name, bool hair , bool umal ):Person(name,hair,false),_umalowana(umal){}
		Woman(std::string name):Person(name,true,false){}

		void print() const;
		bool done() const;
 		void makeup();
		void shave(){}
		~Woman();
	private:
	bool _umalowana = true;



};



class Man : public Person{
	public:
	Man(std::string name, bool hair , bool beard ):Person(name,hair,true),needShaving(beard){}
	Man(std::string name):Person(name){}
	void print() const ;
     bool done() const {
		return !needShaving && !_haircut;
	} // czy gotowy do opuszczenia zakładu
     void makeup(){} // dla kobiet
     void shave(){
		needShaving = false;
	} 

	~Man();
	private:
	bool needShaving = true;
	
};