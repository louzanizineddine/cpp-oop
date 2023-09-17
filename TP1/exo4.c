#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// define an Enum for the 3 colors
enum Color {
    BLUE,
    BROWN,
};

std::string read_file(std::string file_name) {
    std::ifstream file(file_name);
    std::string line;
    std::string file_content;

    if (file.is_open()) {
        while (getline(file, line)) {
            file_content += line;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }

    return file_content;
}

// function that reurns the color of the eyes
Color get_color(std::string adn, std::string blue_gene, std::string brown_gene) {
    Color color = BLUE;

    if (adn.find(blue_gene) != std::string::npos) {
        color = BLUE;
    } else if (adn.find(brown_gene) != std::string::npos) {
        color = BROWN;
    }

    return color;
}


int hamming_distance(std::string adn1, std::string adn2) {
    int distance = 0;

    for (int i = 0; i < adn1.length(); i++) {
        if (adn1[i] != adn2[i]) {
            distance++;
        }
    }

    return distance;
}

int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();

    // Créer une matrice pour stocker les distances partielles
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Initialiser la première colonne
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    // Initialiser la première ligne
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Remplir la matrice
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                std::vector<int> v = { dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] };
                std::vector<int>::iterator result = std::min_element(v.begin(), v.end()); 
                dp[i][j] = 1 + *result;
            }
        }
    }

    return dp[m][n];
}

int main () {

    std::string human_adn, fifi_adn, blue_gene, brown_gene;
    std::string child1, child2, child3, child4;

    human_adn = read_file("data/adn_humain.txt");
    fifi_adn = read_file("data/adn_fifi.txt");
    blue_gene = read_file("data/gene_bleu.txt");
    brown_gene = read_file("data/gene_marron.txt");
    child1 = read_file("data/adn_1.txt");
    child2 = read_file("data/adn_2.txt");
    child3 = read_file("data/adn_3.txt");
    child4 = read_file("data/adn_4.txt");

    Color color = get_color(human_adn, blue_gene, brown_gene);

    std::cout << "The color of the eyes is: " << color << std::endl;

    int adn1_distance = hamming_distance(fifi_adn, child1);
    int adn2_distance = hamming_distance(fifi_adn, child2);
    int adn3_distance = hamming_distance(fifi_adn, child3);
    int adn4_distance = hamming_distance(fifi_adn, child4);

    std::cout << "The distance between fifi and child1 is: " << adn1_distance << std::endl;
    std::cout << "The distance between fifi and child2 is: " << adn2_distance << std::endl;
    std::cout << "The distance between fifi and child3 is: " << adn3_distance << std::endl;
    std::cout << "The distance between fifi and child4 is: " << adn4_distance << std::endl;

    int lev_1 = minDistance(fifi_adn, child1);
    int lev_2 = minDistance(fifi_adn, child2);
    int lev_3 = minDistance(fifi_adn, child3);
    int lev_4 = minDistance(fifi_adn, child4);

    std::cout << "The Levenshtein distance between fifi and child1 is: " << lev_1 << std::endl;
    std::cout << "The Levenshtein distance between fifi and child2 is: " << lev_2 << std::endl;
    std::cout << "The Levenshtein distance between fifi and child3 is: " << lev_3 << std::endl;
    std::cout << "The Levenshtein distance between fifi and child4 is: " << lev_4 << std::endl;


    return (0);
}