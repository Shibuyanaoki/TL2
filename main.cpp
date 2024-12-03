#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <Windows.h>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument,
	__END__

};

int main(int argc, char * argv[]) {

	assert(argc >= NumArgument);

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	system("pause");

	return 0;

}