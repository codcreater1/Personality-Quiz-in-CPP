#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct  Question
{
	string text;
	vector<string>options;
	vector<int>scoresIntro;
	vector<int>scoresExtro;
	vector<int>scoresAmbi;
};


struct IntrovertQuestions {
    vector<Question> questions;

    IntrovertQuestions() {
        questions.push_back({ "Do you prefer spending your weekends alone rather than going to a party?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {2,0,0},{0,0,0},{0,0,0} });

        questions.push_back({ "Do you feel drained or tired after a long social gathering?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {2,0,0},{0,0,0},{0,0,0} });

        questions.push_back({ "Do you usually think deeply before you share your opinion?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {2,0,0},{0,0,0},{0,0,0} });

        questions.push_back({ "Is your ideal night a quiet one with a book or a movie?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {2,0,0},{0,0,0},{0,0,0} });

        questions.push_back({ "Do you prefer having 2-3 close friends over a large social circle?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {2,0,0},{0,0,0},{0,0,0} });
    }
};


struct ExtrovertQuestions {
    vector<Question> questions;

    ExtrovertQuestions() {
        questions.push_back({ "Do you feel energized and excited when you are around many people?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{2,0,0},{0,0,0} });

        questions.push_back({ "Do you find it easy to start a conversation with a complete stranger?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{2,0,0},{0,0,0} });

        questions.push_back({ "Do you prefer to think out loud when solving a problem?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{2,0,0},{0,0,0} });

        questions.push_back({ "Do you enjoy being the center of attention in a group?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{2,0,0},{0,0,0} });

        questions.push_back({ "Do you get bored or restless when you spend too much time alone?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{2,0,0},{0,0,0} });
    }
};


struct AmbivertQuestions {
    vector<Question> questions;

    AmbivertQuestions() {
        questions.push_back({ "Do you enjoy parties but also feel the need to go home early to recharge?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{0,0,0},{2,0,0} });

        questions.push_back({ "Are you comfortable with both small talk and deep, meaningful conversations?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{0,0,0},{2,0,0} });

        questions.push_back({ "Do you change your social behavior depending on the people around you?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{0,0,0},{2,0,0} });

        questions.push_back({ "Are you okay with being the leader, but also happy to let someone else lead?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{0,0,0},{2,0,0} });

        questions.push_back({ "Do you find that some days you are very social, while other days you want silence?",
                             {"A) Strongly agree", "B) Neutral", "C) Disagree"},
                             {0,0,0},{0,0,0},{2,0,0} });
    }
};


class PersonalityResult {
public:
	virtual void printResult() {

		cout << "Personality result." << endl;
	}
	virtual ~PersonalityResult() {};


};

class Introvert : public PersonalityResult {
public:
	void printResult() override {
		cout << "RESULT : INTROVERT"
			<< "Enjoy solitude: They feel recharged when spending time alone."
			<< "Small social circles: They prefer a few close friends over large groups."
			<< "Think before speaking: They process information deeply before sharing."
			<< "Value deep conversations: They usually dislike small talk and prefer meaningful topics."
			<< "Easily overstimulated: Crowded or noisy environments can be draining for them."
			<< endl;




	}


};

class Extrovert : public PersonalityResult {
public:
	void printResult() override {
		cout << "RESULT : EXTROVERT"
			<< "Gain energy from others: They feel energized and excited after spending time with people."
			<< "Large social circles: They enjoy meeting new people and usually have many friends."
			<< "Think out loud: They often process their thoughts by talking through them."
			<< "Love being the center of attention: They are generally comfortable in the spotlight."
			<< "Risk-takers: They are often more open to new experiences and spontaneous actions."
			<<endl;

	}



};

class Ambivert : public PersonalityResult {
public:
	void printResult() override {
		cout << "Adaptable: They can be outgoing or quiet depending on the situation."
			<< "Adaptable: They can be outgoing or quiet depending on the situation."
			<< "Balanced energy: They enjoy social events but also value their downtime."
			<< "Flexible social style: They are comfortable in both large groups and one-on-one settings."
			<< "Moderate risk-takers: They weigh the pros and cons before jumping into new things."
			<< endl;





	}




};

	class Quiz {
	private:
		vector<Question>questions;
		int introScore = 0;
		int extroScore = 0;
		int ambiScore = 0;
	public:
		Quiz() {
			loadQuestions();

		}

        void loadQuestions() {
            IntrovertQuestions intro;
            ExtrovertQuestions extro;
            AmbivertQuestions ambi;


            questions.insert(questions.end(), intro.questions.begin(), intro.questions.end());
            questions.insert(questions.end(), extro.questions.begin(), extro.questions.end());
            questions.insert(questions.end(), ambi.questions.begin(), ambi.questions.end());


        }
        void askQuestions() {
            cout << "----PERSONALITY QUIZ----" << endl;

            for (size_t i = 0; i < questions.size(); i++)
            {
                cout << "Q" << i + 1 << ": " << questions[i].text << endl;

                for (size_t j = 0; j < questions[i].options.size(); j++)
                {
                    cout << questions[i].options[j] << endl;
                }

                char answer;
                cout << "Please choose (A,B,C): ";
                cin >> answer;

                int idx;

                if (answer == 'A' || answer == 'a') idx = 0;
                else if (answer == 'B' || answer == 'b') idx = 1;
                else idx = 2;

                introScore += questions[i].scoresIntro[idx];
                extroScore += questions[i].scoresExtro[idx];
                ambiScore += questions[i].scoresAmbi[idx];
            }
        }


        void calculateResult() {
            PersonalityResult* result;

            if (introScore >= extroScore && introScore >= ambiScore) {

                result = new Introvert();


            }
            else if (extroScore >= introScore && extroScore >= ambiScore)
            {
                result = new Extrovert();
            }
            else {
                result = new Ambivert();
            }

            result->printResult();
            delete result;

        }
        ~Quiz() {
            cout << "QUIZ ENDED.Destructor called:" << endl;
        }




};

    int main() {
        while (true) {
            Quiz quiz;
            quiz.askQuestions();
            quiz.calculateResult();
            return 0;
        }
    }