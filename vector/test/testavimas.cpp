#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../headers/zmogus.h"
#include "../headers/studentas.h"
#include "../headers/function.h"

int programos_veikimas;

TEST_CASE("vector and class tests", "[vector][studentas]") {
    SECTION("vector with studentas - Member Functions") {
        vector<studentas> studentai;
        for (int i = 0; i < 10; i++) {
            studentai.push_back(studentas());
        }
        REQUIRE(studentai.size() == 10);
        REQUIRE(studentai.capacity() == 16);
        studentai.shrink_to_fit();
        REQUIRE(studentai.capacity() == 10);
        REQUIRE(studentai.empty() == false);
    }

    SECTION("vector with studentas - Default Constructor") {
        vector<studentas> studentas;
        REQUIRE(studentas.size() == 0);
        REQUIRE(studentas.capacity() == 0);
        REQUIRE(studentas.empty() == true);
    }

    SECTION("Copy Constructor") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        vector<studentas> studentas2(studentas1);
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.size() == 1);
        REQUIRE(studentas1.capacity() == 1);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Studentas Default Constructor") {
        studentas studentas;
        REQUIRE(studentas.getName() == "");
        REQUIRE(studentas.getSurname() == "");
        REQUIRE(studentas.ndSize() == 0);
        REQUIRE(studentas.getEgz() == 0);
        REQUIRE(studentas.getVid() == 0.0);
        REQUIRE(studentas.getMed() == 0.0);
    }

    SECTION("Move Constructor") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        vector<studentas> studentas2;
        studentas2 = std::move(studentas1);
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.capacity() == 0);
        REQUIRE(studentas1.size() == 0);
        REQUIRE(studentas1.empty() == true);
    }

    SECTION("Copy Assignment Operator") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        vector<studentas> studentas2;
        studentas2 = studentas1;
        REQUIRE(studentas2.size() == 1);
        REQUIRE(studentas2.capacity() == 1);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.size() == 1);
        REQUIRE(studentas1.capacity() == 1);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Initializer List") {
        vector<studentas> studentas1 = {studentas("Gytis", "Malinauskas"), studentas("Petras", "Petraitis"), studentas("Marius", "Majonezius")};
        REQUIRE(studentas1.size() == 3);
        REQUIRE(studentas1.capacity() == 3);
        REQUIRE(studentas1.empty() == false);
    }

    SECTION("Move Assignment Operator") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Petras", "Petraitis"));
        studentas1.push_back(studentas("Petras", "Petraitis"));
        vector<studentas> studentas2(std::move(studentas1));
        REQUIRE(studentas2.size() == 3);
        REQUIRE(studentas1.size() == 0);
        REQUIRE(studentas2.capacity() == 4);
        REQUIRE(studentas1.capacity() == 0);
        REQUIRE(studentas2.empty() == false);
        REQUIRE(studentas1.empty() == true);
    }

    SECTION("Front Function") {
        vector<studentas> vector;
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Marius", "Majonezius");
        vector.push_back(studentas1);
        vector.push_back(studentas2);
        REQUIRE(vector.front().getName() == "Gytis");
        REQUIRE(vector.front().getSurname() == "Malinauskas");
    }

    SECTION("Back Function") {
        vector<studentas> vector;
        studentas studentas1("Gytis", "Malinauskas");
        studentas studentas2("Marius", "Majonezius");
        vector.push_back(studentas1);
        vector.push_back(studentas2);
        REQUIRE(vector.back().getName() == "Marius");
        REQUIRE(vector.back().getSurname() == "Majonezius");
    }

    SECTION("Reserve Function") {
        vector<studentas> studentas1;
        REQUIRE(studentas1.capacity() == 0);
        studentas1.reserve(10);
        REQUIRE(studentas1.capacity() == 10);
    }

    SECTION("Clear Function") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Marius", "Majonezius"));
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        REQUIRE(studentas1.size() == 2);
        studentas1.clear();
        REQUIRE(studentas1.size() == 0);
    }


    SECTION("Pop Back Function") {
        vector<studentas> studentas1;
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Marius", "Majonezius"));
        studentas1.push_back(studentas("Petras", "Petraitis"));
        REQUIRE(studentas1.size() == 3);
        studentas1.pop_back();
        REQUIRE(studentas1.size() == 2);
        REQUIRE_THROWS_AS(studentas1.at(2), std::out_of_range);
    }

    SECTION("Swap Function") {
        vector<studentas> studentas1;
        studentas1.reserve(10);
        studentas1.push_back(studentas("Gytis", "Malinauskas"));
        studentas1.push_back(studentas("Marius", "Majonezius"));
        vector<studentas> studentas2;
        studentas2.push_back(studentas("Petras", "Petraitis"));
        studentas2.push_back(studentas("Ieva", "Ievaite"));
        studentas1.swap(studentas2);
        REQUIRE(studentas1.size() == 2);
        REQUIRE(studentas1.capacity() == 2);
        REQUIRE(studentas2.size() == 2);
        REQUIRE(studentas2.capacity() == 10);
        REQUIRE(studentas1[0].getName() == "Petras");
        REQUIRE(studentas1[0].getSurname() == "Petraitis");
        REQUIRE(studentas1[1].getName() == "Ieva");
        REQUIRE(studentas1[1].getSurname() == "Ievaite");

        REQUIRE(studentas2[0].getName() == "Gytis");
        REQUIRE(studentas2[0].getSurname() == "Malinauskas");
        REQUIRE(studentas2[1].getName() == "Marius");
        REQUIRE(studentas2[1].getSurname() == "Majonezius");
    }

    SECTION("Studentas Parameterized Constructor") {
        studentas studentas("Gytis", "Malinauskas");
        REQUIRE(studentas.getName() == "Gytis");
        REQUIRE(studentas.getSurname() == "Malinauskas");
        REQUIRE(studentas.ndSize() == 0);
        REQUIRE(studentas.getEgz() == 0);
        REQUIRE(studentas.getVid() == 0.0);
        REQUIRE(studentas.getMed() == 0.0);
    }

    SECTION("Studentas Move Constructor") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3(std::move(studentas2));
        REQUIRE(studentas2.getName() == "");
        REQUIRE(studentas2.getSurname() == "");
        REQUIRE(studentas2.getMed() == 0.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Copy Constructor") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3(studentas2);
        REQUIRE(studentas2.getName() == "Gytis");
        REQUIRE(studentas2.getSurname() == "Malinauskas");
        REQUIRE(studentas2.getMed() == 8.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Copy Assignment Operator") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3 = studentas2;
        REQUIRE(studentas2.getName() == "Gytis");
        REQUIRE(studentas2.getSurname() == "Malinauskas");
        REQUIRE(studentas2.getMed() == 8.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Move Assignment Operator") {
        studentas studentas2("Gytis", "Malinauskas");
        studentas2.setMed(8.0);
        studentas studentas3 = std::move(studentas2);
        REQUIRE(studentas2.getName() == "");
        REQUIRE(studentas2.getSurname() == "");
        REQUIRE(studentas2.getMed() == 0.0);
        REQUIRE(studentas3.getName() == "Gytis");
        REQUIRE(studentas3.getSurname() == "Malinauskas");
        REQUIRE(studentas3.getMed() == 8.0);
    }

    SECTION("Studentas Setters and Getters") {
        studentas studentas;
        studentas.setName("Gytis");
        REQUIRE(studentas.getName() == "Gytis");
        studentas.setSurname("Malinauskas");
        REQUIRE(studentas.getSurname() == "Malinauskas");
        studentas.setND(10);
        studentas.setND(5);
        REQUIRE(studentas.ndSize() == 2);
        REQUIRE(studentas.getLastND() == 5);
        studentas.setEgz(10);
        REQUIRE(studentas.getEgz() == 10);
        studentas.setVid(7.5);
        REQUIRE(studentas.getVid() == 7.5);
        studentas.setMed(8.0);
        REQUIRE(studentas.getMed() == 8.0);
        studentas.deleteLastNd();
        REQUIRE(studentas.ndSize() == 1);
        REQUIRE(studentas.getLastND() == 10);
    }
}