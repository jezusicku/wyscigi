#include "scores.h"

Scores::Scores() {
    readScores();
    saveScores();
}

int Scores::setScore(int player, int score) {
    if (scores[player][0] < score) {
        scores[player][2] = scores[player][1];
        scores[player][1] = scores[player][0];
        scores[player][0] = score;
        saveScores();
        return 1;
    } else if (scores[player][1] < score) {
        scores[player][2] = scores[player][1];
        scores[player][1] = score;
        saveScores();
        return 2;
    } else if (scores[player][2] < score) {
        scores[player][2] = score;
        saveScores();
        return 3;
    }
    return 0;
}

int Scores::getScore(int player, int place) {
    return scores[player][place];
}


void Scores::readScores() {
    std::ifstream file("scores.txt");
    std::string line;

    if (!file.fail()) {
        int counter = 0;
        while (getline(file, line)) {
            if (counter == 24) break;
            scores[counter / 3][counter % 3] = std::stoi(line);
            counter++;
        }
        file.close();

        if (counter < 24) {
            for (auto &player : scores)
                for (int &score : player)
                    score = 0;
        }
    } else {
        for (auto &player : scores)
            for (int &score : player)
                score = 0;
    }
}

void Scores::saveScores() {
    std::ofstream file("scores.txt");
    for (auto &player : scores)
        for (int score : player)
            file << score << '\n';
    file.close();
}