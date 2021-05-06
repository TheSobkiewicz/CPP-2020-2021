#include "Table.h"



void Table::operator+=(const Expense &day){
	if(size == 0 || size > day.getSize()) size=day.getSize();
	vec.push_back(day);
}

void Table::print()const {
for (auto a : vec) {
	a.print();
}
std::cout<<std::endl;
}

bool cmp(const Expense &one, const Expense &two, int kol){
	if(one.getValueAt(kol) < two.getValueAt(kol) )return true;
	return false;
}

Table& Table::sort(int kol){
	if(kol > size -1){
		std::cout<<"Indeks "<<kol<<" nieprawidlowy!\n";
		return *this;
	}
	auto compare = std::bind(cmp, std::placeholders::_1,std::placeholders::_2,kol);
	std::sort(vec.begin(),vec.end(),compare);
	return *this;

}


Table& Table::sortByMean(){

std::sort(vec.begin(),vec.end(),[](const Expense &a, const Expense &b){
	return a.mean() < b.mean();
});

	return *this;
}