#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <random>
#include <string>
#include <vector>

static int const MAX_NAMES = 20000;
struct Student {
    std::string name;
    std::vector<unsigned> scores;
};

using Students = std::vector<Student>;

Students generateStudents(std::istream &);
void generateScore(std::vector<unsigned> &scores);

unsigned randInt(unsigned start, unsigned stop);
void print(std::ostream &, Students const &);

int main() {
    auto students = generateStudents(std::cin);
    std::sort(
        students.begin(), students.end(),
        [](Student const &a, Student const &b) { return a.name < b.name; });

    print(std::cout, students);

    return 0;
}

// todo: implement all functions
unsigned randInt(unsigned start, unsigned stop){
    std::random_device rd;
    std::uniform_int_distribution<int> dis(start, stop);
    return (unsigned)dis(rd);
}

void generateScore(std::vector<unsigned> &scores){
    scores.push_back(randInt(60, 90));
    scores.push_back(randInt(50, 85));
    for(auto i = 0; i < 6; i++){
        scores.push_back(randInt(70, 95));
    }
}

Students generateStudents(std::istream &in){
    Students students;
    students.reserve(MAX_NAMES);
    std::string sname;
    while(in >> sname){
        Student stu;
        stu.name = sname;
        generateScore(stu.scores);
        students.push_back(stu);
    }

    return students;
}

void print(std::ostream &out, Students const &students){
    for(auto &stu : students){
        out << stu.name;
        for(const auto &score : stu.scores){
            out << ' ' << score;
        }
        out << '\n';
    }
}
