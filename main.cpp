#include <iostream>
#include <random>
#include <ctime>

using namespace std;
//global variables are declared at the top of code to use them in functions.
int Q_NO = 1;
int CORRECT = 0;
int WRONG =0;
bool ask[10]={true, true, true, true, true, true, true, true, true, true};


//function declarations

void display_random_quesion();/*in this function randomly it will check the remaining questions are asked or not and it will call question function using switch case. after coming out ofswitch case the display_random_quesion will call result function*/

void display();/*this function is to display count of questions, correct answers and wrong answers and then it will call display_random_quesion function*/

void question(string question , string a , string b , string c , string d , char correct_answer);/*in this function it will pass question and options as arguments and correct option as char variable then using if condition it will find the user's input is correct or wrong at last it will call display function*/

void result();/*the result function will display the count of questions, correct answers and wrong answers and then it will give the resultof quiz is pass or failortieusing else if condition*/

int main()
{
    display();//function call
    return 0;
exit;
}


void display()
{
    system("cls");
    cout<<"Question No:"<< Q_NO << "\t\tCorrect Answers:"<< CORRECT << "\t\tWrong Answers:" << WRONG <<  endl <<endl;
    display_random_quesion();//function call
}


void display_random_quesion()
{
    srand(time(0));/*standard random time function to set the random number value to 0*/
    bool is_question_remaining = false;
    for(int i=0; i<10; i++){
        if(ask[i]){
            is_question_remaining = true;/*the loop will continue until 10 questions are asked without repeatition of same question*/
            break;
        }
    }
    while(is_question_remaining){
        int no = rand()%10;/*this will make sure that questions asked are the remainder of modulus 10 so that the no number of questions will be below 10*/

        if(ask[no])
        {
            ask[no] = false;/*if the remainder number is not asked(called) then it will call that number case function*/
            switch(no)
            {         //queestion function calls
             case 0:
                   question("1.Which language supports the Object Oriented Programming Technique" , "C language" , "C++ language" , "Cobal language" , "Fortran Language" , 'b');
                   break;
             case 1:
                question("2.What is a variable?" , "A empty container in which we store data" , "box" , "Data Type" , "language" , 'a');
                case 2:
                   question("3. Wrapping data and its related functionality into a single entity is known as _____________" , "Abstraction" , "Encapsulation" , "Polymorphism" , "Modularity" , 'b');
                   break;
             case 3:
                question(". What does polymorphism in OOPs mean?" , " Concept of allowing overiding of functions" , "Concept of hiding data" , "Concept of keeping things in differnt modules/files" , " Concept of wrapping things into a single unit" , 'a');
                case 4:
                   question("5.Which language supports the Object Oriented Programming Technique" , "C language" , "C++ language" , "Cobal language" , "Fortran Language" , 'b');
                   break;
             case 5:
                question("6. Which concept allows you to reuse the written code?" , "Encapsulation" , "Abstraction" , "Inheritance" , " Polymorphism" , 'c');
                case 6:
                   question("7. C++ is ______________" , "procedural programming language" , "object oriented programming language" , "Cobal language" , "Fortran Language" , 'b');
                   break;
             case 7:
                question("8.What does modularity mean?" , "Hiding part of program" , "Overriding parts of program" , "Wrapping things into single unit" , "Subdividing program into small independent parts" , 'd');
                case 8:
                   question("9. Which of the following class allows to declare only one object of it?" , "Abstract class" , "Virtual class" , "Singleton class" , "Friend class" , 'c');
                   break;
             case 9:
                question("10. Which of the following is not a type of Constructor?" , "Friend constructor" , " Copy constructor" , "Default constructor" , "Parameterized constructor" , 'a');
                break;
            }
        }
    }
    result();
}


void result()
{
    system("cls");
    cout << "Total Question = " << Q_NO-1 << endl;
    cout << "\nCorrect Answers ="  << CORRECT << endl;
    cout << "\nWrong Answers =" << WRONG << endl;
    if(CORRECT > WRONG)/*this condition will decide the result is pass or fail*/
       cout << "\nResult = PASS" <<endl;
       else if(WRONG > CORRECT)
          cout << "\nResult = FAIL" << endl;
       else
          cout << "\nResult = tie" << endl;
}


void question(string question , string a , string b , string c , string d , char correct_answer)
{
    cout << question <<endl;//this will display the question
    cout << "A.\t" << a <<endl;/*these will display answers*/
    cout << "B.\t" << b <<endl;
    cout << "C.\t" << c <<endl;
    cout << "D.\t" << d << "\n" <<endl;
    char answer;
    cin >> answer;
    if(answer == correct_answer)/*this conditon will checkthe answer is correct or not*/
        CORRECT++;
    else
        WRONG++;
    Q_NO++;
    display();//function call
}
