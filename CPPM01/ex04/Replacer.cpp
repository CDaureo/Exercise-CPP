#include "Replacer.hpp"

Replacer::Replacer(const std::string& filename, const std::string& text1, const std::string& text2)
    : filename(filename), text1(text1), text2(text2) 
{
}

Replacer::~Replacer()
{
}

void Replacer::process() const {
    std::size_t position = 0;
    std::size_t found = 0;

    if (text1.empty())
    {
        throw std::runtime_error("La cadena no puede estar vacia");
    }
    std::ifstream infile(filename.c_str()); //Esto lee el fichero de entrada
    if (!infile)
    {
        throw std::runtime_error("No se puede leer el fichero: " + filename);
    }
    std::ostringstream buffer;
    buffer << infile.rdbuf(); // donde se va a leer el contenido
    std::string content = buffer.str(); // Lee el contenido del buffer
std::string replacer = filename + ".replace"; // Nombre del fichero de salida (añade extensión)
    std::ofstream ofs(replacer.c_str()); // Abre/crea el fichero de salida para escribir
    if (!ofs)
    {
        throw std::runtime_error("No se pudo crear el fichero de salida: " + replacer); // Error si no puede crearlo
    }
    
    while ((found = content.find(text1,position)) != std::string::npos) // Busca text1 desde 'position' hasta encontrar todas las ocurrencias
    {
        ofs << content.substr(position, found - position); // Escribe en el fichero la parte entre 'position' y la ocurrencia encontrada
        ofs << text2; // Escribe text2 (reemplazo) en lugar de text1
        position = found + text1.length(); // Avanza 'position' justo después de la ocurrencia encontrada
    }
    ofs << content.substr(position); // Escribe el resto del contenido después de la última ocurrencia
}
