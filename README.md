# QuizMaster Command Line Quiz Application

## Description:
QuizMaster is a command-line quiz application written in C that lets users test their knowledge across multiple subjects with a series of multiple-choice questions. The program currently features three categories: Science, Math, and Computer Science, each with 15 carefully selected questions.

This project aims to be both educational and fun while showcasing key programming concepts in C, such as file handling, loops, conditional statements, functions, and structured program design. By incorporating user input validation and score tracking, QuizMaster provides a smooth and interactive experience for players.

## Purpose of the Project:
The main goal of QuizMaster is to create an engaging learning tool that encourages users to recall information and practice problem-solving skills in various fields. Beyond its educational benefits, the application also serves as a practical demonstration of C programming skills, making it an excellent portfolio piece for beginner and intermediate programmers.

- The project demonstrates:
   - How to read and process data from files.
   - How to validate user inputs for correctness.
   - How to implement a modular design for maintainable code.
   - How to calculate and present results in a clear, user-friendly way.

## Key Features
1. **Multiple Categories**
   - Users can choose from Science, Math, and Computer Science quizzes.
   - Each category is saved in a separate text file, making it simple to add or change questions without altering the code.
2. **File Handling**
   - Questions and their correct answers are read directly from text files (science.txt, math.txt, cs.txt).
   - This setup allows for easy content management and flexibility.
3. **Input Validation**
   - Ensures that only valid answer options (a, b, c, d) are accepted.
   - Prevents program crashes from unexpected inputs.

4. **Scoring System**
   - Tracks the number of correct answers.
   - Calculates the percentage and assigns a grade (A, B, C, etc.).
   - Displays results at the end of the quiz.

5. **Result Logging**
   - Records each quiz attempt in Result.txt for record-keeping.
   - Captures player name, subject, score, percentage, and grade.

6. **Modular Code Design**
   - Organized into functions for different tasks (subject selection, question display, scoring, result writing).
   - Enhances readability and simplifies debugging.

## How It Works
1. **User Name Input**
   - The application starts by asking the user to enter their name.
   - This name will be stored in Result.txt along with the quiz results.
2. **Subject Selection**
   - A menu is displayed with three options: Science, Math, Computer Science.
   - The program ensures that only valid options are accepted before continuing.
3. **Quiz Execution**
   - After selecting a subject, the program reads the relevant text file.
   - Each question appears with four answer options labeled a, b, c, and d.
   - The player selects an answer, and the program checks if it is correct immediately.
4. **Scoring and Grading**
   - For each correct answer, the score increases by one point.
   - At the end of the quiz, the total score, along with the percentage, is displayed.
   - The grading system assigns A for 90% and above, B for 80-89%, C for 70-79%, D for 60-69%, and F for below 60%.
5. **Result Storage**
   - The user’s name, chosen subject, score, percentage, and grade are saved to Result.txt.

## Files in the Project
- **quiz.c**: Contains the main program logic, including subject selection, quiz flow, and score calculation.
- **science.txt**: Holds 15 Science questions and their answer keys.
- **math.txt**: Holds 15 Math questions and their answer keys.
- **cs.txt**: Holds 15 Computer Science questions and their answer keys.
- **README.md**: Documentation that explains the project structure and usage.

## Technologies Used:
- **Language**: C
- **Data Structures**: Structures for storing questions and answers.
- **Programming Concepts**:
  1. Loops (for iterating through questions).
  2. Conditionals (for input checks and grading).
  3. Arrays (for storing multiple questions).
  4. Functions (for modular programming).
  5. File I/O (for reading and writing data).

## To Compile
```
gcc quiz.c -o quiz
```
## To Run
```
./quiz
```
## Sample Output
```
Enter your name: John
Select Course:
1. Science
2. Math
3. Computer Science
Enter choice:
```
```
Please Select Course:
1. Science
2. Math
3. Computer Science
Enter choice: 3

Computer Science Quiz Starts

Q1: Which language is known as the mother of all programming languages?
a. C
b. FORTRAN
c. Assembly
d. Python
Your answer (a/b/c/d): b
Correct!
```
```
CONGRATS YOU GOT A GRADE WELL DONE

Tony, your score: 15/15
Percentage: 100.00%
Grade: A
```
## Example Result.txt Output
```
Name: Nisar
Course: Computer Science
Score: 15/15
Percentage: 100.00%
Grade: A
--------------------------
```
 ## Conclusion

QuizMaster is a straightforward but effective example of how a command-line application in C can be educational and interactive. It’s easy to customize by adding new subjects or updating question files. Its modular design makes it a valuable resource for students learning C programming.

This project shows important coding principles by using file handling, structured programming, and input validation. These principles can be applied to larger software projects. Whether it serves as a fun quiz tool or a study aid, QuizMaster provides a solid base for more advanced quiz applications in the future.

