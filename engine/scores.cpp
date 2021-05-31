#include "scores.h"

Scores::Scores() {
    loadScores();
    saveScores();
}

/**
 * If the score is one of top 3 scores achieved in the given vehicle then the score is saved to file and the podium
 * position is returned. Otherwise function returns 0.
 * @param vehicle Vehicle id from range 0-7
 * @param score Score achieved in a given vehicle
 * @return Position on the podium or 0 if the score is worse than score on third place
 */
int Scores::setScore(int vehicle, int score) {
    if (scores[vehicle][0] < score) {
        scores[vehicle][2] = scores[vehicle][1];
        scores[vehicle][1] = scores[vehicle][0];
        scores[vehicle][0] = score;
        saveScores();
        return 1;
    } else if (scores[vehicle][1] < score) {
        scores[vehicle][2] = scores[vehicle][1];
        scores[vehicle][1] = score;
        saveScores();
        return 2;
    } else if (scores[vehicle][2] < score) {
        scores[vehicle][2] = score;
        saveScores();
        return 3;
    }
    return 0;
}

/**
 * @param vehicle Vehicle id from range 0-7
 * @param place Place from range 0-2 (0 - first, 1 - second, 2 - third)
 * @return One of top 3 scores achieved in a given vehicle
 */
int Scores::getScore(int vehicle, int place) {
    return scores[vehicle][place];
}

/**
 * Function reads scores from file to array. If file doesn't exists or file is in incorrect format then all scores in
 * array are set to 0.
 */
void Scores::loadScores() {
    std::ifstream file("scores.txt");
    std::string line;
    bool success = false;

    if (!file.fail()) {
        int counter = 0;
        while (getline(file, line)) {
            if (counter == 24) break;
            scores[counter / 3][counter % 3] = std::stoi(line);
            counter++;
        }
        file.close();
        if (counter == 24) success = true;
    }
    if (success) return;

    for (auto &player : scores)
        for (int &score : player)
            score = 0;
}

/**
 * Function saves scores from array to file.
 */
void Scores::saveScores() {
    std::ofstream file("scores.txt");
    for (auto &player : scores)
        for (int score : player)
            file << score << '\n';
    file.close();
}
