#include <algorithm>
#include <format>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

static int const MAX_NAMES = 20000;
static int const SCORE_AMOUNT = 8;
struct Student {
    std::string name;
    std::vector<unsigned> scores;
    double avg;
};

using Students = std::vector<Student>;

Students readStudents(std::istream &);

Students generateStudents(std::istream &);

void readScore(std::istream &, std::vector<unsigned> &scores);

void generateScore(std::vector<unsigned> &scores);

double average(std::vector<unsigned> const &scores);

unsigned randInt(unsigned start, unsigned stop);

void print(std::ostream &, Students const &);


int main() {
    auto students = readStudents(std::cin);
    std::sort(
            students.begin(), students.end(),
            [](Student const &a, Student const &b) { return a.avg > b.avg; });

    print(std::cout, students);

    return 0;
}

// implement all functions
Students readStudents(std::istream &in) {
    Students students;
    students.reserve(MAX_NAMES);
    std::string name;
    while (in >> name) {
        Student stu;
        stu.name = name;
        readScore(in, stu.scores);
        stu.avg = average(stu.scores);
        students.push_back(stu);
    }

    return students;
}

Students generateStudents(std::istream &in) {
    Students students;
    students.reserve(MAX_NAMES);
    std::string sname;
    while (in >> sname) {
        Student stu;
        stu.name = sname;
        generateScore(stu.scores);
        students.push_back(stu);
    }

    return students;
}

void readScore(std::istream &in, std::vector<unsigned> &scores) {
    unsigned score;
    for (int i = 0; i < SCORE_AMOUNT; i++) {
        if (in >> score) {
            scores.push_back(score);
        }
    }
}

void generateScore(std::vector<unsigned> &scores) {
    scores.push_back(randInt(60, 90));
    scores.push_back(randInt(50, 85));
    for (auto i = 0; i < 6; i++) {
        scores.push_back(randInt(70, 95));
    }
}

double average(std::vector<unsigned> const &scores) {
    auto tmp = scores;
    auto it = tmp.begin() + 2;
    std::sort(it, tmp.end());
    double median = 0.5 * (scores[4] + scores[5]);
    double avg = 0.4 * scores[0] + 0.4 * scores[1] + 0.2 * median;

    return avg;
}

unsigned randInt(unsigned start, unsigned stop) {
    std::random_device rd;
    std::uniform_int_distribution<int> dis(start, stop);
    return (unsigned) dis(rd);
}

void print(std::ostream &out, Students const &students) {
    for (const auto &stu: students) {
        out << stu.name << ' ';
        out << std::fixed << std::setprecision(1) << stu.avg << ' ';
        for (const auto score: stu.scores) {
            out << score << ' ';
        }
        out << '\n';
    }
}

