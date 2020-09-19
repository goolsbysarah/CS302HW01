//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>

#include "StackLinked.cpp"

//--------------------------------------------------------------------

bool delimitersOk ( const string & );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
    << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
        << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;

        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below
bool delimitersOk (const string &expression ) {

    StackLinked<char> stack;
    // string start = "({[";
    // string end = ")}]";
    // for (char ch: expression.toCharArray()) {
    //     if (start.indexOf(ch) != -1)
    //         stack.push(ch);
    //     else if (end.indexOf(ch) != -1)
    //     {
    //         if (stack.isEmpty())
    //             return false;
    //         else if (start.indexOf(stack.pop()) != end.indexOf(ch))
    //             return false;
    //     }
    // }

    char currentChar;
    for (int i = 0; i < expression.length(); i++)
    {
        switch(expression[i])
        {
            case '(':
            case '{':
            case '[': stack.push(expression[i]);
                      break;
            case ')': currentChar = stack.pop();
                      if (currentChar != '(')
                        return false;
                      break;
            case '}': currentChar = stack.pop();
                      if (currentChar != '{')
                        return false;
                      break;
            case ']': currentChar = stack.pop();
                      if (currentChar != '[')
                        return false;
                      break;
        }
    }

    if(stack.isEmpty())

        return true;

    return false;

}



