#pragma once
#include <string>
class TextureConverter
{
private:

	std::wstring ConvertMultiByteStringToWideString(const std::string& mString);



public:

	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& mString);


	

};

