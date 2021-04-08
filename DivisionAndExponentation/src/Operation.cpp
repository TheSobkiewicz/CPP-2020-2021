#include "Operation.h"
void operator >>= (const std::string label, const Operation& operation)
{
    std::cout << label << " ";
    operation.print();
    std::cout << " " << label << "\n";
}
