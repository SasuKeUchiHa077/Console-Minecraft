#ifndef COLLECT_H

#include <map>
#include <string>

void CollectResources(std::map<std::string, int> &inventory); 

void CollectTheItem(const std::string &itemName, int &itemAmmount);

#endif // !COLLECT_H

