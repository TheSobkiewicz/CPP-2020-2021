#include "Team.h"
#include <algorithm>
std::ostream& operator<<(std::ostream& o, const Team& m) {
  m.print(o);
  return o;
} 

  Team Team::operator - (Team const &a) const {
    Team result;
    std::set_intersection(crew.begin(), crew.end(), a.crew.begin(), a.crew.end(), std::inserter(result.crew,result.crew.begin()));

    return result;
  }

    Team Team::operator + (Team const &a) const {
    Team result;
    std::set_union(crew.begin(), crew.end(), a.crew.begin(), a.crew.end(), std::inserter(result.crew,result.crew.begin()));
    return result;
  }

  void Team::kill(std::function<bool(const Member&a)> f) {
    std::set<Member> newTeam;

    std::for_each(crew.begin(), crew.end(),[&](const Member &a) {//pozwolilem sobie uzyc foreacha, gdyz kopiowanie do innej struktury, nastepnie uzywanie remove_if, a nastepnie kopiowanie znowu do set wystepujacego w klasie wydawaje sie zbyt kosztowne
      if(!f(a)) newTeam.insert(a);
    });

    crew.clear();
    crew=newTeam;
  }