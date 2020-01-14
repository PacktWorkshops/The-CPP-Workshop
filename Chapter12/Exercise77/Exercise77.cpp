#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Question 
{
public:
	Question(int questionNumber, string question, int 
	answerIndex) : m_questionNumber(questionNumber), m_question(question), 
	m_answerIndex(answerIndex) {}
	int getQuestionNumber() const 
	{
		return m_questionNumber;
	}
	
	string getQuestion() const 
	{
		return m_question;
	}
	int getAnswerIndex() const 
	{
		return m_answerIndex;
	}

private:
	int m_questionNumber;
	string m_question;
	int m_answerIndex;
};

struct QuestionCompare 
{
	bool operator()(const Question& lhs,
		const Question& rhs) const 
	{
		return lhs.getQuestionNumber() < rhs.getQuestionNumber();
	}
};

int main() 
{
	map < Question, vector < string >, QuestionCompare > quiz;
	Question question1(1, "Which two actors directed themselves in movies and won Oscars for Best Actor?", 2);
	vector < string > question1Answers = 
	{
		"Al Pacino and Timothy Hutton",
	    "Jack Nicholson and Kevin Spacey",
	    "Laurence Olivier and Roberto Benigni",
	    "Tom Hanks and Paul Newman"
	};
	
	Question question2(2, "\"After all, tomorrow is another day!\" was the last line in which Oscar-winning Best Picture?", 0);
	vector < string > question2Answers = 
	{
		"Gone With the Wind",
	    "Great Expectations",
	    "Harold and Maude",
	    "The Matrix"
	};
	
	quiz.insert(make_pair(question1, question1Answers));
	quiz.insert(make_pair(question2, question2Answers));
	cout << "Welcome to the movie quiz" << endl;
	cout << "Type your answer between 1-4 and press enter:" << endl;
	map < Question, vector < string >> ::iterator quizIterator = quiz.begin();
	vector < bool > correctAnswers;
	
	while (quizIterator != quiz.end()) 
	{
		cout << quizIterator->first.getQuestion() << endl;
		int answerIndex = 1;
		
		for (auto answer : quizIterator->second) 
		{
			cout << answerIndex << " : " << answer << endl;
			answerIndex++;
		}
		
		int answer;
		cin >> answer;
		int correctAnswer = quizIterator->first.getAnswerIndex();
		bool wasCorrect = answer - 1 == correctAnswer;
		cout << (wasCorrect ? "CORRECT!" : "INCORRECT!") << " Correct answer is: " << quizIterator->second[correctAnswer] << endl;
		
		if (wasCorrect)
			correctAnswers.push_back(answer);
		quizIterator++;
	}
	
	cout << "Your score was " << correctAnswers.size() << " out of " << quiz.size() << endl;
	cout << "done";
}
