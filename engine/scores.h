#ifndef SCORES_H
#define SCORES_H
//@formatter:off

/**
 * Class allows to operate on scores. Two main functions are setScore and getScore.
 */
class Scores {
private:
    int scores[8][3];

public:
    Scores();
    int setScore(int, int);
    int getScore(int, int);

private:
    void loadScores();
    void saveScores();
};

#endif //SCORES_H
