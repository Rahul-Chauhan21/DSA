/*
Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
*/
#include <iostream>
#include <unordered_map>
using namespace std;

//O(n) time | O(n) space
void printSequence(unordered_map<string, string> dataSet)
{
    unordered_map<string, string> reversemap;
    unordered_map<string, string>::iterator it;

        for (it = dataSet.begin(); it!= dataSet.end(); it++)
            reversemap[it->second] = it->first;

    string start;

        for (it = dataSet.begin(); it!= dataSet.end(); it++)
        {
            if (reversemap.find(it->first) == reversemap.end())
            {
                start = it->first;
                break;
            }
        }

     if (start.empty())
     {
        cout << "Invalid Input" << endl;
        return;
     }
    it = dataSet.find(start);
    while (it != dataSet.end())
    {
        cout << it->first << "->" << it->second << endl;
        it = dataSet.find(it->second);
    }

}


int main(){
    unordered_map<string, string> fromTo;
    fromTo["Chennai"] = "Banglore";
    fromTo["Bombay"] = "Delhi";
    fromTo["Goa"] = "Chennai";
    fromTo["Delhi"] = "Goa";

    printSequence(fromTo);
    return 0;
}
