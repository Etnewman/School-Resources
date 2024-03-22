#ifndef TEXT_H
#define TEXT_H


using namespace std;


	class Text
	{
		private:
		const char* textArray;
		int textLength;
		
		public:
		void displayText();
		
		const char* getText() const;
		
		int getLength();
		
		Text(const char*);
		~Text();
	};

#endif
