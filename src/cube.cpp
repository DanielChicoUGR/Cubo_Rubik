#include "cube.hpp"



cube::cube(){
    fill_face_default(white);
    fill_face_default(green);
    fill_face_default(red);
    fill_face_default(blue);
    fill_face_default(orange);
    fill_face_default(yellow);
}

cube::cube(const char ***state){
    Color **aux=create_matrix(DIM);
        
}



cube::~cube(){
    for(auto i =faces.begin();i!=faces.end();++i){
        delete_matrix(i->second,DIM);
    }

    faces.clear();
}





void cube::fill_face_default(Color color){
    Color **aux=create_matrix(DIM);

    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)
            aux[i][j]=color;

    faces.insert(std::pair{color,aux});
}





Color** create_matrix(int tam){
    Color **aux;
    aux=new Color*[tam];
    for(int i=0;i<tam;i++) aux[i]=new Color[tam];
}





void delete_matrix(Color **m,int tam){
    for(int i=0;i<tam;i++)delete [] m[i];

    delete [] m;
} 