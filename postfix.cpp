#include<iostream>

#include "StackLinked.cpp"

using namespace std;
//I want to change this whole thing
//i am supposed to use the linked stack implementation
class Postfix {
    public:
 	double item;

     

     int isItAnOperand(char potentialOperand) 
     {
             if (potentialOperand >= 0x0030 && potentialOperand <= 0x0039){
				
               return 1;
			}
          else if(potentialOperand==' '){
               return 2;
			}
          return 0;
     }

     int pow(double x, double y){
          if (y == 0){
               return 1;
		}
          else{
               return (x * pow(x, y-1));
		}
		
     }
	void enterParenthesis(string *a) //i found this on google
     {
          (*a)[(*a).length()]=')';
     }


     double Evaluate(string post)
     {
          enterParenthesis(&post);
          StackLinked<double> s;
          int check = 0; 
          double operand1, operand2, result;
          for (int i = 0; post[i] != ')'; i++)
          {
			
			//cout << post[i] << endl;
               int ans = isItAnOperand(post[i]);
               if (ans==1)
               {
                    item = post[i] - '0'; 
				s.push(item);
               }
               else if(ans==0)
               {
                    operand1 = s.pop();
				//s.showStructure();
                    operand2 = s.pop();
				//s.showStructure();
                    switch (post[i]) 
                    {
                    case '+':
						//cout << operand2 << "+" << operand1 << endl;
                              result = operand2 + operand1;
                              break;
                    case '-':
						//cout << operand2 << "-" << operand1 << endl;
                              result = operand2 - operand1;
                              break;
                    case '*':
						//cout << operand2 << "*" << operand1 << endl;
                              result = operand2*operand1;
                              break;
                    case '/':
						//cout << operand2 << "/" << operand1 << endl;
                              result = operand2 / operand1;
                              break;
                    case '^':
						//cout << operand2 << "^" << operand1 << endl;
                              result = pow(operand2, operand1);
                              break;
                    default:
                              cout << "Sorry, " << post[i] << " is not an operator or operand.\n";
                              check = 1;
                    }
                    if (check == 1)
                         break;
                    item = result;
                    s.push(item); 
               }
          }

          
          if (check == 0)
          {
               double returnIt = s.pop();
               return returnIt;          
          }
          
          return -1;
     }
};

int main()
{
     Postfix post;
     string str;
	int userInput = -1;
	cout << "Would you like to input your own expressions or iterate through my test cases? 1. input through your own, 2.iterate over the test cases" << endl;
	cin >> userInput;
	if (userInput == 1){
	cout << "Please input your postfix expression for evaluation: " << endl;
     getline(cin,str);
	cout << "for testing " << str << endl;
     double result= post.Evaluate(str);
     cout << result << endl;
	}

	else if (userInput == 2){
		string str1, str2, str3, str4, str5;
			str1 = "56+43^/";
			cout << "input: " << str1 << endl;
			double result1 = post.Evaluate(str1);
			cout << "The result is: " << result1 << endl;
			str2 = "34+52-/";
			cout << "input: " << str2 << endl;
			double result2 = post.Evaluate(str2);
			cout << "The result is: " << result2 << endl;
			str3 = "35*56^*";
			cout << "input: " << str3 << endl;
			double result3 = post.Evaluate(str3);
			cout << "The result is: " << result3 << endl;
			str4 = "44*44//";
			cout << "input: " << str4 << endl;
			double result4 = post.Evaluate(str4);
			cout << "The result is: " << result4 << endl;
			str5 = "55^78*+";
			cout << "input: " << str5 << endl;
			double result5 = post.Evaluate(str5);
			cout << "The result is: " << result5 << endl;
		}
return 0;



}

