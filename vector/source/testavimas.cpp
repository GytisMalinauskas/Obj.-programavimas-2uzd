#include "../headers/testavimas.h"


void test_default_constructor() {
    studentas st;

    assert(st.getName().empty());
    assert(st.getSurname().empty());
    assert(st.getEgz() == 0);
    assert(st.getMed() == 0.0);
    assert(st.getVid() == 0.0);
    assert(st.getND().empty());
    
    std::cout << "Default constructor test passed!" << std::endl;
}

void test_parametrized_constructor() {
    std::string vard = "Jonas";
    std::string pavard = "Jonaitis";
    studentas st(vard, pavard);

    assert(st.getName() == vard);
    assert(st.getSurname() == pavard);
    assert(st.getEgz() == 0);
    assert(st.getMed() == 0.0);
    assert(st.getVid() == 0.0);
    assert(st.getND().empty());
    
    std::cout << "Parametrized constructor test passed!" << std::endl;
}

void test_copy_constructor() {
    std::string vard = "Jonas";
    std::string pavard = "Jonaitis";
    studentas st(vard, pavard);
    st.setEgz(10);
    st.setMed(8.5);
    st.setVid(9.0);
    st.setND(9);
    st.setND(10);

    studentas st_copy(st);

    assert(st_copy.getName() == st.getName());
    assert(st_copy.getSurname() == st.getSurname());
    assert(st_copy.getEgz() == st.getEgz());
    assert(st_copy.getMed() == st.getMed());
    assert(st_copy.getVid() == st.getVid());
    assert(st_copy.getND() == st.getND());

    std::cout << "Copy constructor test passed!" << std::endl;
}

void test_move_constructor() {
    std::string vard = "Jonas";
    std::string pavard = "Jonaitis";
    studentas st(vard, pavard);
    st.setEgz(10);
    st.setMed(8.5);
    st.setVid(9.0);
    st.setND(9);
    st.setND(10);

    studentas st_moved(std::move(st));

    assert(st_moved.getName() == vard);
    assert(st_moved.getSurname() == pavard);
    assert(st_moved.getEgz() == 10);
    assert(st_moved.getMed() == 8.5);
    assert(st_moved.getVid() == 9.0);
    assert(st_moved.getND().size() == 2);
    assert(st_moved.getND()[0] == 9);
    assert(st_moved.getND()[1] == 10);

    assert(st.getName().empty());
    assert(st.getSurname().empty());
    assert(st.getND().empty());

    std::cout << "Move constructor test passed!" << std::endl;
}
void test_get_set_methods() {
    studentas st;

    // Testuojame vardą ir pavardę
    st.setName("Jonas");
    st.setSurname("Jonaitis");
    assert(st.getName() == "Jonas");
    assert(st.getSurname() == "Jonaitis");

    // Testuojame egzaminą
    st.setEgz(10);
    assert(st.getEgz() == 10);

    // Testuojame medianą
    st.setMed(8.5);
    assert(st.getMed() == 8.5);

    // Testuojame vidurkį
    st.setVid(9.0);
    assert(st.getVid() == 9.0);

    // Testuojame namų darbus
    st.setND(9);
    st.setND(10);
    std::vector<int> nd = st.getND();
    assert(nd.size() == 2);
    assert(nd[0] == 9);
    assert(nd[1] == 10);

    std::cout << "Get and set methods test passed!" << std::endl;
}
void test_input_operator() {
    std::istringstream input("Jonas Jonaitis 9 10 8");
    studentas st;
    input >> st;

    assert(st.getName() == "Jonas");
    assert(st.getSurname() == "Jonaitis");
    assert(st.getND().size() == 2);
    assert(st.getND()[0] == 9);
    assert(st.getND()[1] == 10);
    assert(st.getEgz() == 8);

    std::cout << "Input operator test passed!" << std::endl;
}
void test_output_operator() {
    studentas st("Gytis", "Malinauskas");
    st.setVid(8);
    st.setMed(9);
    st.setND(10);
    st.setEgz(7);

    std::ostringstream output;
    output << st;
    std::string actual_output = output.str();
    std::string expected_output = "Gytis               Malinauskas         8.00                9.00                ";

    if (actual_output != expected_output) {
        std::cerr << "Test failed!" << std::endl;
        std::cerr << "Expected: \"" << expected_output << "\"" << std::endl;
        std::cerr << "Actual:   \"" << actual_output << "\"" << std::endl;
    }

    assert(actual_output == expected_output);

    std::cout << "Output operator test passed!" << std::endl;
}
