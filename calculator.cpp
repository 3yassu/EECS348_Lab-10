#include "calculator.hpp"
using namespace std;
bool isdig(char x){
    return (0x30 <= x && x <= 0x39);
}
bool isNum(string numb){
    int decimalPoint = 0;
    if(numb[0] == '+' || numb[0] == '-'){
        if(numb[1] == '.'){return false;}
        int numbSize = numb.size();
        if(numbSize == 1){
            return false;
        }
        if(numb[numbSize - 1] == '.'){
            return false;
        }
        for(int i = 1; i < numbSize; i++){
            if(!isdig(numb[i]) && (decimalPoint == 1 || numb[i] != '.')){
                return false;
            }
            if(numb[i] == '.'){
                decimalPoint++;
            }
        }
    }else{
        int dec_check = 0;
        if(numb[0] == '.'){return false;}
        for(char x : numb){
            if(!isdig(x) && (decimalPoint == 1 || x != '.')){
                return false;
            }else if(x == '.'){
                decimalPoint++; dec_check = 1;
            }else{
                dec_check = 0;
            }
        }
        if(dec_check == 1) {
            return false;
        }
    }
    return true;
}
double parse_number(const string &expression){
    double return_num = 0; double dec_check = 1; double neg_check = 1; int stop = 0;
    if(expression[0] == '-'){neg_check *= -1;}
    for(char x : expression){
        if(dec_check == 1){
            return_num *= 10;
        }else if (dec_check == 10 && stop == 0){
            return_num /= 10; stop = 1;
        }else{
            dec_check *= 10;
        }
        if(x == '.'){
            dec_check = 10;
        }else if(isdig(x)){
            return_num += (x-'0')/dec_check;
        }
    }
    return_num*=neg_check;
    return return_num;
}
string str_adder(string operand_one, string operand_two){
    int neg_one = 1; int neg_two = 1;
    if(operand_one[0] == '+'){operand_one.erase(0, 1);}
    else if(operand_one[0] == '-'){operand_one.erase(0, 1); neg_one *= -1;}
    if(operand_two[0] == '+'){operand_two.erase(0, 1);}
    else if(operand_two[0] == '-'){operand_two.erase(0, 1); neg_two *= -1;}
    int decimal_one = 0;  int decimal_two = 0;
    int size_one = operand_one.size(); int size_two = operand_two.size();
    for(;decimal_one<size_one;decimal_one++){
        if(operand_one[decimal_one] == '.'){break;}
    }
    for(;decimal_two<size_two;decimal_two++){
        if(operand_two[decimal_two] == '.'){break;}
    }
    size_one = operand_one.size(); size_two = operand_two.size();   
    if(decimal_one == size_one && decimal_two != size_two){operand_one += ".0";}
    else if(decimal_two == size_two && decimal_one != size_one){operand_two += ".0";}
    if(decimal_one<decimal_two){
        for(int i = 0; i<(decimal_two-decimal_one); i++){
            operand_one = "0" + operand_one;
        }
    }else if(decimal_two<decimal_one){
        for(int i = 0; i<(decimal_one-decimal_two); i++){
            operand_two = "0" + operand_two;
        }
    }
    while(operand_one.size() > operand_two.size()){operand_two += "0";}
    while(operand_two.size() > operand_one.size()){operand_one += "0";}
    string returner = "";
    int decimal = operand_one.size() + 3;
    int size = operand_one.size();
    for(int i = 0; i < size; i++){
        if(operand_one[i] == '.'){decimal = i; returner += '.'; continue;}
        char checker = '0' + (neg_one)*(operand_one[i] - 0x30) + (neg_two)*(operand_two[i] - 0x30);
        returner += checker;
    }
    char return_neg = 0;
    while(returner[0] == '0' && returner.size() > 1){returner.erase(0, 1); decimal--;}
    if(returner[0] < '0'){
        return_neg = '-';
        int ret_size = returner.size();
        for(int i = 0; i < ret_size; i++){
            if(i == decimal){continue;}
            returner[i] += (('0' - returner[i])*2);
        }
    }
    returner = '0' + returner; decimal++;
    for(int i =(returner.size() - 1); i >= 0; i--){
        if(i == decimal){continue;}
        if(returner[i] < '0'){
            returner[i] += 10;
            if((i - 1) == decimal){returner[i - 2] -= 1;}
            else{returner[i - 1] -= 1;} 
        }else if(returner[i] > '9'){
            returner[i] -= 10;
            if((i - 1) == decimal){returner[i - 2] += 1;}
            else{returner[i - 1] += 1;} 
        }
    }
    while(returner[0] == '0' && returner.size() > 1){returner.erase(0, 1);}
    if(returner[0] == '.'){returner = '0' + returner;}
    returner = return_neg + returner;
    return returner;
}
