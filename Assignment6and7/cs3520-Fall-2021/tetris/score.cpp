#include "score.hpp"

int compute_score(int previous_score, int lines_cleared) {
    return previous_score + lines_cleared;
}