#ifndef SCORES_H
#define SCORES_H

//@formatter:off
class Scores {
private:
    int scores[8][3];

public:
    Scores();
    int setScore(int, int);
    int getScore(int, int);

private:
    void readScores();
    void saveScores();
};

#endif //SCORES_H
