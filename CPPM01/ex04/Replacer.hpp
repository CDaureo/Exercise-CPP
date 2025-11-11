#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

class Replacer {
    private:
		
        const std::string& filename;
        const std::string& text1;
        const std::string& text2;
    public:
		void process() const;
		Replacer(const std::string& filename, const std::string& text1, const std::string& text2);		
		~Replacer();
		const std::string& getFilename() const;
    	const std::string& getS1() const;
    	const std::string& getS2() const;
};