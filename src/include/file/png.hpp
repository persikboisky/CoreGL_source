#ifndef INCLUDE_FILE_PNG_HPP_
#define INCLUDE_FILE_PNG_HPP_

namespace core
{
	struct png
	{
		static int width;
		static int height;
		static int channels;

		static unsigned char* load(const char* path, int& width, int& height, int& channels);
		static unsigned char* load(const char* path);

		static void Delete(unsigned char* png);

		//static unsigned char* myLoader(const char* path, int& width, int& height, int& channels);
	};
}
#endif // !INCLUDE_FILE_PNG_HPP_