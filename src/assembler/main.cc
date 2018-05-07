#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

#include <numeric>
#include <valarray> //accumulate()

template <typename T>
   std::string to_string(T value)
   {
     //create an output string stream
     std::ostringstream os ;

     //throw the value into the string stream
     os << value ;

     //convert the string stream into a string and return
     return os.str() ;
   }

void printvv(std::vector< std::vector<std::string> > v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v[i].size(); j++){
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> split(std::string s, char delim){
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while(std::getline(ss, item, delim)){
        if(item!=""){
            elems.push_back(item);
        }
    }
    return elems;
}
int main(int argc, char** argv) { 
    
    //Dictionary of known key words
    //The integer values indicate the total number of words that 
    //   belong to that keyword.
    //   e.g. "sense" takes in 2 arguments, such as "sense ahead food"
    //      which takes up 3 words. 
    
    std::map<std::string, int> known;
    known["sense"] = 3; //sense sensedir cond 
    known["move"] = 1; // move 
    known["pickup"] = 1; // pickup
    known["flip"] = 2; // flip p
    known["turn"] = 2; // turn lr
    known["drop"] = 1; // drop
    known["mark"] = 2; // mark i
    known["unmark"] = 2; // unmark i
    known["direction"] = 2; // direction d
    known["goto"] = 1; // goto
    known["else"] = 1; // else
            
    
    //Vector for storing all the lines, word by word 
    std::vector< std::vector<std::string> > rawlines;
    
    //Map for storing position values of labels
    std::map<std::string, int> labels;
    
    //Vector for storing answer strings to be spit out
    std::vector< std::vector<std::string> > answers;
    answers.resize(100);
    std::vector< std::vector<std::string> > answerorg;
    for (int i = 0; i < 100; i++) {
        answers[i].resize(0);
    }
    std::fstream outfile;
    outfile.open("output.txt", std::ios::out);
    if(outfile.fail()) {
        std::cout << "output.txt is not accessible." << std::endl;
        return (int)'O';
    }
    //Keeps track of occasions where there is an else statement and a goto right after.
    bool elseflag = 0;
    std::string c;
    std::fstream infile;
    infile.open("bug.buggy", std::ios::in);
    if(infile.fail()) {
        std::cout << "Buggy file is not accessible." << std::endl;
        return (int)'B';
    }
    while (getline(infile, c)) {
        if(c[0] != ';' && c[0] != '_') {
            std::vector<std::string> temp = split(c, ' ');
            rawlines.push_back(temp);
        }
        if(c[0] == '_') { //we assume that all labels start with _ to remove ambiguity 
            std::string label = c.substr(0, c.size() - 1);
            rawlines.push_back(split(label, ' '));
            labels[label] = -1;
        }
    }
    
    int line_count = 0;
    //Processing the input file
    for (int i = 0; i < rawlines.size(); i++) {
        bool senseflag = false;
        std::string sensearg = "";
        int next_line = line_count + 1;
        //detect the first word, see if it is a label
        if(i == 0 && rawlines[0][0][0] == '_') {
            labels[rawlines[0][0]] = 0;
            std::cout << "First label detected." << std::endl;
        }
        
        else if(i != 0 && rawlines[i][0][0] == '_') {
            labels[rawlines[i][0]] = line_count;
            std::cout << "Label detected; Assigning new line number..." << std::endl;
        }
        
        //if it's not a label, then parse it 
        else{
            for (int j = 0; j < rawlines[i].size(); j++) {
                std::string *next_step;
                if(rawlines[i][j] != "else") {
                    int chunksize = known[rawlines[i][j]];

                    switch (chunksize) {
                        case 1:
                            //move, pickup, drop, goto, else (no arg)
                            answers[line_count].push_back(rawlines[i][j]);
                            answers[line_count].push_back(to_string(next_line));
                            next_step = &answers[line_count][j+1];
                            break;
                        case 2:
                            //flip, turn take one arg
                            answers[line_count].push_back(rawlines[i][j]);
                            answers[line_count].push_back(rawlines[i][j+1]);
                            answers[line_count].push_back(to_string(next_line));
                            next_step = &answers[line_count][j+2];
                            j++; //skip the next word
                            break;
                        case 3:
                            //sense takes 2 arg 
                            answers[line_count].push_back(rawlines[i][j]);
                            answers[line_count].push_back(rawlines[i][j+1]);
                            //we want the last arg of sense to be at the end
                            answers[line_count].push_back(to_string(next_line));
                            next_step = &answers[line_count][j+2];
                            senseflag = 1;
                            sensearg = rawlines[i][j+2];
                            j+=2; //skip the next 2 words
                            break;
                        default:
                            throw ("Chunksize cannot be 0! ");
                            return (int)'C';
                            break;
                    }
                }
                else{
                    //processing else
                    std::cout << "else found\n";
                    answers[line_count].push_back(rawlines[i][j+1]);
                   // cout << rawlines[i][j+1] << endl;
                    j++;
                    elseflag = true;
                    if (senseflag) {
                        //cout << sensearg;
                        answers[line_count].push_back(sensearg);
                    }
                    line_count++;
                }
                
    
                if(i+1 < rawlines.size() && rawlines[i+1][0] == "goto") {
                    std::cout << "Processing goto" << std::endl;
                    *next_step =  rawlines[i+1][1];
                    if(rawlines[i].size() >  2){
                        if(elseflag && rawlines[i][rawlines[i].size()-2] == "else") {
                            std::cout << "elseflag is up "<< std::endl;
                            *next_step = rawlines[i+1][1] + " " + (rawlines[i][rawlines[i].size()-1]);
                            elseflag = false;
                        }
                    }
                    i++;
                    j++;
                    line_count++;
                }
            }
        }
    }
    std::cout << std::endl;
    
    //Verify that the buggy file has been parsed correctly 
    //Write the outcome to output.txt
    
    for(int a = 0; a < line_count; a++) {
        //cout << "[" <<  a << "] ";
        for(int b = 0; b < answers[a].size(); b++) {
            //cout << answers[a][b] << " ";
            outfile << answers[a][b] << " ";
            if(answers[a][b] == "_home"){
          //      cout << a << b ;
            }
        }
        outfile << std::endl;
    }
    outfile.close();
    /////////////////////////////////////////
    
    /////////////////////////////////////////
    //Process the output text: replace _ keywords with respective ints from label map
    std::fstream step2;
    step2.open("output.txt", std::ios::in);
    if(step2.fail()){
        std::cout << "Step 2: output.txt is not available for secondary processing.\n";
        return (int)'S';
    }
    
    while (getline(step2, c)){
        
        std::vector<std::string> temp = split(c, ' ');
        answerorg.push_back(temp);
    }
    
    for (int i = 0; i < line_count; i++){
        for(int j = 0; j < answerorg[i].size(); j++){
            if(answerorg[i][j][0] == '_'){
                std::cout << answerorg[i][j] << std::endl;
                answerorg[i][j] = to_string(labels[answerorg[i][j]]);
            }
        }
    }
    
    printvv(answerorg);
    
    //Rewrite the result into final.txt
    outfile.open("final.txt", std::ios::out);
    if(outfile.fail()){
        std::cout << "final.txt failed to be created. \n";
        return (int)'F';
    }
    
    for (int i = 0; i < answerorg.size(); i++){
        for (int j = 0; j < answerorg[i].size(); j++){
            outfile << answerorg[i][j] << " ";
        }
        outfile << std::endl;
    }
    return 0;
}