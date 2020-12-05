#include <iostream>
#include "MapIncTag.h"
#include "MapMltTag.h"
#include "AggSumTag.h"
#include "AggProTag.h"
#include "SrtOrdTag.h"
#include "SrtSlcTag.h"
#include "SrtDstTag.h"
#include <unordered_set>

int main()
{
    SrtTag* inc = new SrtDstTag();
    std::list<double> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(12);
    lst.push_back(7);
    lst.push_back(7);
    lst.push_back(12);



    std::list<double> res = inc->evaluate(lst, "40");
    std::unordered_set<double> dst(lst.begin(), lst.end());
    std::list<double> lst2(dst.begin(), dst.end());

}
