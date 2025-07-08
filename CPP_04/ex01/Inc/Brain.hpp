#pragma once

#include <iostream>

class Brain {

    protected:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& brain);
        ~Brain();

        std::string getIdeas(int const index)const;
        void setIdeas(int const index, std::string const idea);
};
