#ifndef __cube__
#define __cube__




#include <map>
#include <vector>
using namespace std;
enum Color {white,green,red,blue,orange,yellow};


/**
 * @brief Represent a state of a Rubik's cube 
 * 
 */
class cube{

public: 


    // @brief Contains the dimension of the cube
    static const unsigned int  DIM=3;


private:
    

    // @brief Represents  the rubik cube itself 
    map<Color,Color**> faces;

public:

    
/**
 * @brief Constructor the solve state of the cube 
 * 
 */
    cube();

/**
 * @brief Construct a new cube object
 * 
 * @param state state that is goning to be stroaged
 * 
 * @pre Dimensions of the table must be 6X3X3 obligatory !!!!
 */
    cube(const char ***state );

/**
 * @brief Copy construct a new cube object
 * 
 * @param a state that is goning to be stroaged
 */
    cube(const cube &a );

/**
 * @brief Destroy the cube object
 * 
 */
    ~cube();

/**
 * @brief equal operator
 * 
 * @param a 
 * @return true if the objetc \e a is equal to \e this
 * @return false if the objetc \e a is not equal to \e this
 */
    bool operator==(const cube &a) const;

/**
 * @brief assigment operator
 * 
 * @param a Object to copy
 * @return cube& 
 */
    cube & operator =(cube &a) const;

/**
 * @brief assignment operator

 * 
 * @param a Objet to copy
 * @return const cube& 
 */
    const cube & operator =(const cube &a) const;

/**
 * @brief Get the matrix of the face 
 * 
 * @param face Color of the face
 * @return const vector<vector<Color>> 
 */
    const vector<vector<Color>> &get_face(const Color &face) const;


/**
 * @brief Aply the moove to the actual state
 * 
 * @param face Color of the face where to apply the movement 
 * @param rot Boolean tha codifies if me moove is: clockwise or anticlockwise
 *              \e True ->  clockwise 
 *              \e False -> anticlockwise
 * @return cube 
 */
    cube & apply_move (Color &face,bool rot); 


/**
 * @brief Check if the state of the cube is valid
 * 
 * @return true State valid
 * @return false State invalid
 */

    bool valid_state() const;    

private:

/**
 * @brief fll a face with an specific color
 * 
 * @param color face to fill
 */
    void fill_face_default(Color color);

};







#endif