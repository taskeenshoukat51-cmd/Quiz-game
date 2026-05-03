#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

int Total = 0; // Initialize Total to zero

// Question Class
class Question
{
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    int Correct_Answer;
    int Question_Score;

public:
    // Setter Function
    void setValues(string, string,
                   string, string,
                   string, int, int);

    // Function to ask questions
    void askQuestion();
};

// Function to set the values of the questions
void Question::setValues(
    string q, string a1,
    string a2, string a3,
    string a4, int ca, int pa)
{
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

// Function to ask question
void Question::askQuestion()
{
    cout << endl;
    // Print the questions
    cout << Question_Text << endl;
    cout << "1. " << Answer_1 << endl;
    cout << "2. " << Answer_2 << endl;
    cout << "3. " << Answer_3 << endl;
    cout << "4. " << Answer_4 << endl;
    cout << endl;

    // Display the answer
    int userAnswer;
    cout << "What is your answer? (in number)" << endl;
    cin >> userAnswer;

    // If the answer is correct
    if (userAnswer == Correct_Answer)
    {
        cout << endl;
        cout << "Correct !" << endl;

        // Update the correct score
        Total = Total + Question_Score;
        cout << "Score = " << Question_Score
             << " out of "
             << Question_Score
             << "!" << endl;
        cout << endl;
    }
    // Otherwise
    else
    {
        cout << endl;
        cout << "Wrong !" << endl;
        cout << "Score = 0"
             << " out of "
             << Question_Score
             << "!" << endl;
        cout << "Correct answer = "
             << "Option " << Correct_Answer
             << ": " << "Answer_" << Correct_Answer
             << "." << endl;
        cout << endl;
    }
}

// Driver code
int main()
{
	system("color 30");
    // Player details input
    string Name;
    int Age;
    string DateOfBirth;

    // Input the details
    cout << "What is your name?" << endl;
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, Name);
    cout << endl;

    cout << "How old are you?" << endl;
    cin >> Age;
    cout << endl;

    cout << "What is your date of birth? (Format: DD/MM/YYYY)" << endl;
    cin >> DateOfBirth;
    cout << endl;

    cout << "Are you ready to take the quiz, " << Name << "? (yes/no)" << endl;
    string Respond;
    cin >> Respond;

    if (Respond == "yes")
    {
        cout << endl;
        cout << "Good Luck, " << Name << "!" << endl;
    }
    else
    {
        cout << "Okay, Goodbye, " << Name << "!" << endl;
        return 0;
    }

    // Objects of Question Class
    Question q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    q1.setValues("What is the capital of Japan?", "Tokyo", "Beijing", "Seoul", "Bangkok", 1, 10);
    q2.setValues("Who wrote Romeo and Juliet?", "William Shakespeare", "Jane Austen", "Charles Dickens", "Mark Twain", 1, 10);
    q3.setValues("What is the largest planet in our solar system?", "Mars", "Jupiter", "Saturn", "Earth", 2, 10); // Correct answer is Jupiter
    q4.setValues("What is the chemical symbol for gold?", "Au", "Ag", "Fe", "Hg", 1, 10);
    q5.setValues("What is the powerhouse of the cell?", "Nucleus", "Ribosome", "Mitochondria", "Endoplasmic reticulum", 3, 10); // Correct answer is Mitochondria
    q6.setValues("In the movie The Shawshank Redemption, what is Andy Dufresne's profession before going to prison?", "Lawyer", "Banker", "Doctor", "Journalist", 2, 10); // Correct answer is Banker
    q7.setValues("Who directed the movie Inception?", "Christopher Nolan", "Quentin Tarantino", "Steven Spielberg", "James Cameron", 1, 10);
    q8.setValues("Who is the co-founder of Microsoft?", "Steve Jobs", "Bill Gates", "Mark Zuckerberg", "Jeff Bezos", 2, 10); // Correct answer is Bill Gates
    q9.setValues("Which programming language was created by Guido van Rossum?", "Java", "Python", "C++", "Ruby", 2, 10); // Correct answer is Python
    q10.setValues("What does the acronym HTML stand for?", "Hyperlink and Text Markup Language", "Hypertext Markup Language", "High-Level Text Markup Language", "Home Tool Markup Language", 2, 10); // Correct answer is Hypertext Markup Language

    // Ask each question
    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();
    q6.askQuestion();
    q7.askQuestion();
    q8.askQuestion();
    q9.askQuestion();
    q10.askQuestion();

    // Display the total score
    cout << "Total Score = " << Total
         << " out of 100" << endl;

    // Display the results
    // If the player passes the quiz
    if (Total >= 70)
    {
        cout << "Congratulations, " << Name << "! You passed the quiz!" << endl;
    }
    // Otherwise
    else
    {
        cout << "Unfortunately, " << Name << ", you didn't pass the quiz." << endl;
        cout << "Better luck next time." << endl;
    }

    return 0;
}

