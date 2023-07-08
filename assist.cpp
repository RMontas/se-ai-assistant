#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cmath>
// MM MD EH FZ FN PS CN
static const std::vector<int> timeNv1 {90, 84, 324, 2674, 100000, 136, 50000}; // first level construction time in seconds

struct cost
{
    int level;
    int metal;
    int diamond;
    int hidro;
    int zion;
    int nanite;
    int energy;
    int robots;
    float time;
};

struct prod
{
    int level;
    int metal;
    int diamond;
    int hidro;
    int zion;
    int nanite;
};

class building {       
public:      
    std::string type;        
    std::vector<cost> totalCostPerLevel;
    std::vector<prod> totalProdPerLevel;
private:
};

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

void processInFile(char *inFile, std::vector<building>& allBuildings)
{
    std::ifstream infile(inFile);
    std::string line;

    int numBuilds = 0;
    int currBuild = -1;

    std::cout << "processInFile" << std::endl;

    while (std::getline(infile, line))
    {
        std::vector<std::string> row_values;
        split(line, '\t', row_values);
        int column_idx = 0;
        if(row_values[0] == "MM" || 
        row_values[0] == "MD" || 
        row_values[0] == "EH" || 
        row_values[0] == "FZ" || 
        row_values[0] == "FN" || 
        row_values[0] == "PS" || 
        row_values[0] == "CN")
        {
            building newBuild;
            newBuild.type = row_values[0];
            allBuildings.push_back(newBuild);
            numBuilds++;
            currBuild++;
        }
        if(row_values[0] == "Niv")
        {
            for (auto v: row_values){
                if(v != "Niv")
                {
                    cost c;
                    c.level = std::stoi( v );
                    c.metal = 0;
                    c.diamond = 0;
                    c.hidro = 0;
                    c.zion = 0;
                    c.nanite = 0;
                    c.energy = 0;
                    c.robots = 0;
                    c.time =  timeNv1[currBuild] * (0.0028*pow(c.level,4)-0.0074*pow(c.level,3)+0.0972*pow(c.level,2)+0.2296*c.level+0.6778); // estim
                    allBuildings[currBuild].totalCostPerLevel.push_back(c);
                    prod p;
                    p.level = std::stoi( v );
                    p.metal = 0;
                    p.diamond = 0;
                    p.hidro = 0;
                    p.zion = 0;
                    p.nanite = 0;
                    allBuildings[currBuild].totalProdPerLevel.push_back(p);
                }
            }
            continue;
        }
        if(row_values[0] == "M")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "M")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].metal = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "D")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "D")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].diamond = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "H")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "H")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].hidro = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "Z")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "Z")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].zion = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "N")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "N")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].nanite = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "E")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "E")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].energy = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "R")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "R")
                {
                    allBuildings[currBuild].totalCostPerLevel[currIdx].robots = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "PM")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "PM")
                {
                    allBuildings[currBuild].totalProdPerLevel[currIdx].metal = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "PD")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "PD")
                {
                    allBuildings[currBuild].totalProdPerLevel[currIdx].diamond = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "PH")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "PH")
                {
                    allBuildings[currBuild].totalProdPerLevel[currIdx].hidro = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "PZ")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "PZ")
                {
                    allBuildings[currBuild].totalProdPerLevel[currIdx].zion = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
        if(row_values[0] == "PN")
        {
            int currIdx = 0;
            for (auto v: row_values){
                if(v != "PN")
                {
                    allBuildings[currBuild].totalProdPerLevel[currIdx].nanite = std::stoi( v );
                    currIdx++;
                }
            }
            continue;
        }
     }

}

void printInfo(std::vector<building>& allBuildings)
{
    std::cout << "printInfo" << std::endl;
    for (auto build: allBuildings){
        std::cout << build.type << std::endl;
        std::cout << "totalCostPerLevel" << std::endl;
        for (auto cost: build.totalCostPerLevel){
            std::cout << cost.level << " " << cost.metal << " "<< cost.diamond << " "<< cost.hidro << " "<< cost.zion << " "<< cost.nanite << " "<< cost.energy << " "<< cost.robots << " " << cost.time << std::endl;
        }
        std::cout << "totalProdPerLevel" << std::endl;
        for (auto prod: build.totalProdPerLevel){
            std::cout << prod.level << " " << prod.metal << " "<< prod.diamond << " "<< prod.hidro << " "<< prod.zion << " "<< prod.nanite << std::endl;
        }
    }
}

int main() {
    
    char inBuildCostProd[256] = "building_costs_new.txt";
    std::vector<building> allBuildings;
    processInFile(inBuildCostProd, allBuildings);
    printInfo(allBuildings);


    return 0;
}